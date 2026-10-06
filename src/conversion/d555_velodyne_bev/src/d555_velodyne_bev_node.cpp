#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/image_encodings.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

using namespace std::chrono_literals;

class D555VelodyneBev : public rclcpp::Node
{
public:
  D555VelodyneBev()
  : Node("d555_velodyne_bev"), tf_buffer_(get_clock()), tf_listener_(tf_buffer_)
  {
    camera_topic_ = declare_parameter("camera_topic", "/camera/camera/depth/color/points");
    velodyne_topic_ = declare_parameter("velodyne_topic", "/velodyne_points");
    target_frame_ = declare_parameter("target_frame", "velodyne");
    output_topic_ = declare_parameter("output_topic", "/bev/d555_velodyne/image");
    mask_topic_ = declare_parameter("mask_topic", "/bev/d555_velodyne/mask");
    x_min_ = declare_parameter("x_min", -5.0);
    x_max_ = declare_parameter("x_max", 20.0);
    y_min_ = declare_parameter("y_min", -10.0);
    y_max_ = declare_parameter("y_max", 10.0);
    z_min_ = declare_parameter("z_min", -1.5);
    z_max_ = declare_parameter("z_max", 2.0);
    resolution_ = declare_parameter("resolution", 0.05);
    publish_rate_ = declare_parameter("publish_rate", 10.0);
    stale_timeout_ = declare_parameter("stale_timeout", 1.0);
    require_both_ = declare_parameter("require_both", true);
    camera_stride_ = declare_parameter("camera_stride", 2);
    velodyne_stride_ = declare_parameter("velodyne_stride", 1);
    velodyne_alpha_ = declare_parameter("velodyne_alpha", 0.8);
    velodyne_radius_ = declare_parameter("velodyne_point_radius", 1);
    validate_parameters();

    height_ = static_cast<int>(std::ceil((x_max_ - x_min_) / resolution_));
    width_ = static_cast<int>(std::ceil((y_max_ - y_min_) / resolution_));
    cv::setNumThreads(1);

    auto qos = rclcpp::SensorDataQoS().keep_last(1);
    camera_sub_ = create_subscription<sensor_msgs::msg::PointCloud2>(
      camera_topic_, qos,
      [this](sensor_msgs::msg::PointCloud2::ConstSharedPtr msg) {
        std::lock_guard<std::mutex> lock(input_mutex_);
        camera_.message = std::move(msg);
        camera_.received = now();
        ++camera_.generation;
      });
    velodyne_sub_ = create_subscription<sensor_msgs::msg::PointCloud2>(
      velodyne_topic_, qos,
      [this](sensor_msgs::msg::PointCloud2::ConstSharedPtr msg) {
        std::lock_guard<std::mutex> lock(input_mutex_);
        velodyne_.message = std::move(msg);
        velodyne_.received = now();
        ++velodyne_.generation;
      });

    image_pub_ = create_publisher<sensor_msgs::msg::Image>(output_topic_, 1);
    mask_pub_ = create_publisher<sensor_msgs::msg::Image>(mask_topic_, 1);
    timer_ = create_wall_timer(
      std::chrono::duration<double>(1.0 / publish_rate_),
      std::bind(&D555VelodyneBev::publish_bev, this));
  }

private:
  struct Input
  {
    sensor_msgs::msg::PointCloud2::ConstSharedPtr message;
    rclcpp::Time received{0, 0, RCL_ROS_TIME};
    uint64_t generation{0};
  };

  struct Layer
  {
    cv::Mat image;
    cv::Mat mask;
    builtin_interfaces::msg::Time stamp;
    uint64_t generation{0};
    bool valid{false};
  };

  struct Transform
  {
    float r[9];
    float t[3];
  };

  static int field_offset(
    const sensor_msgs::msg::PointCloud2 & msg, const std::string & name)
  {
    for (const auto & field : msg.fields) {
      if (field.name == name) {
        return static_cast<int>(field.offset);
      }
    }
    return -1;
  }

  static float read_float(const uint8_t * data, int offset)
  {
    float value;
    std::memcpy(&value, data + offset, sizeof(value));
    return value;
  }

  static uint32_t read_uint32(const uint8_t * data, int offset)
  {
    uint32_t value;
    std::memcpy(&value, data + offset, sizeof(value));
    return value;
  }

  void validate_parameters() const
  {
    if (!(x_max_ > x_min_ && y_max_ > y_min_ && z_max_ > z_min_)) {
      throw std::invalid_argument("BEV max bounds must be greater than min bounds");
    }
    if (!(resolution_ > 0.0 && resolution_ <= 1.0)) {
      throw std::invalid_argument("resolution must be in (0, 1]");
    }
    if (!(publish_rate_ > 0.0 && publish_rate_ <= 60.0)) {
      throw std::invalid_argument("publish_rate must be in (0, 60]");
    }
    if (camera_stride_ < 1 || camera_stride_ > 16 ||
      velodyne_stride_ < 1 || velodyne_stride_ > 16)
    {
      throw std::invalid_argument("point strides must be from 1 to 16");
    }
  }

  Transform lookup_transform(const sensor_msgs::msg::PointCloud2 & msg)
  {
    if (msg.header.frame_id == target_frame_) {
      return Transform{{1, 0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 0}};
    }
    auto cached = transform_cache_.find(msg.header.frame_id);
    if (cached != transform_cache_.end()) {
      return cached->second;
    }
    const auto tf = tf_buffer_.lookupTransform(
      target_frame_, msg.header.frame_id, msg.header.stamp, 100ms);
    const auto & q_in = tf.transform.rotation;
    const double norm = std::sqrt(
      q_in.x * q_in.x + q_in.y * q_in.y + q_in.z * q_in.z + q_in.w * q_in.w);
    const float x = q_in.x / norm;
    const float y = q_in.y / norm;
    const float z = q_in.z / norm;
    const float w = q_in.w / norm;
    Transform result{
      {1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w),
        2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w),
        2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)},
      {static_cast<float>(tf.transform.translation.x),
        static_cast<float>(tf.transform.translation.y),
        static_cast<float>(tf.transform.translation.z)}};
    transform_cache_[msg.header.frame_id] = result;
    return result;
  }

  Layer render(
    const sensor_msgs::msg::PointCloud2 & msg, uint64_t generation,
    bool camera, int stride)
  {
    const int x_offset = field_offset(msg, "x");
    const int y_offset = field_offset(msg, "y");
    const int z_offset = field_offset(msg, "z");
    int rgb_offset = field_offset(msg, "rgb");
    if (rgb_offset < 0) {
      rgb_offset = field_offset(msg, "rgba");
    }
    if (x_offset < 0 || y_offset < 0 || z_offset < 0) {
      throw std::runtime_error("PointCloud2 has no XYZ fields");
    }

    Layer layer;
    layer.image = cv::Mat::zeros(height_, width_, CV_8UC3);
    layer.mask = cv::Mat::zeros(height_, width_, CV_8UC1);
    layer.stamp = msg.header.stamp;
    layer.generation = generation;
    std::vector<float> highest(
      static_cast<size_t>(height_) * width_, -std::numeric_limits<float>::infinity());
    const Transform tf = lookup_transform(msg);
    const size_t count = static_cast<size_t>(msg.width) * msg.height;

    for (size_t index = 0; index < count; index += static_cast<size_t>(stride)) {
      const uint8_t * raw = msg.data.data() + index * msg.point_step;
      const float x = read_float(raw, x_offset);
      const float y = read_float(raw, y_offset);
      const float z = read_float(raw, z_offset);
      if (!(std::isfinite(x) && std::isfinite(y) && std::isfinite(z))) {
        continue;
      }
      const float tx = tf.r[0] * x + tf.r[1] * y + tf.r[2] * z + tf.t[0];
      const float ty = tf.r[3] * x + tf.r[4] * y + tf.r[5] * z + tf.t[1];
      const float tz = tf.r[6] * x + tf.r[7] * y + tf.r[8] * z + tf.t[2];
      if (tz < z_min_ || tz > z_max_) {
        continue;
      }
      const int row = static_cast<int>(std::floor((x_max_ - tx) / resolution_));
      const int col = static_cast<int>(std::floor((y_max_ - ty) / resolution_));
      if (row < 0 || row >= height_ || col < 0 || col >= width_) {
        continue;
      }
      const size_t cell = static_cast<size_t>(row) * width_ + col;
      if (tz < highest[cell]) {
        continue;
      }
      highest[cell] = tz;
      cv::Vec3b color;
      if (camera && rgb_offset >= 0) {
        const uint32_t rgb = read_uint32(raw, rgb_offset);
        color = cv::Vec3b(rgb & 0xff, (rgb >> 8) & 0xff, (rgb >> 16) & 0xff);
      } else if (camera) {
        color = cv::Vec3b(255, 0, 255);
      } else {
        const float level = std::clamp(
          static_cast<float>((tz - z_min_) / (z_max_ - z_min_)), 0.0F, 1.0F);
        color = cv::Vec3b(
          static_cast<uint8_t>(255 * (1 - level)), 255,
          static_cast<uint8_t>(255 * level));
      }
      layer.image.at<cv::Vec3b>(row, col) = color;
      layer.mask.at<uint8_t>(row, col) = 255;
    }
    layer.valid = true;
    return layer;
  }

  cv::Mat grid_background() const
  {
    cv::Mat image(height_, width_, CV_8UC3, cv::Scalar(12, 12, 12));
    const int interval = std::max(1, static_cast<int>(std::lround(1.0 / resolution_)));
    for (int row = 0; row < height_; row += interval) {
      image.row(row).setTo(cv::Scalar(28, 28, 28));
    }
    for (int col = 0; col < width_; col += interval) {
      image.col(col).setTo(cv::Scalar(28, 28, 28));
    }
    return image;
  }

  void publish_bev()
  {
    Input camera;
    Input velodyne;
    {
      std::lock_guard<std::mutex> lock(input_mutex_);
      camera = camera_;
      velodyne = velodyne_;
    }
    const auto current_time = now();
    const bool camera_fresh = camera.message &&
      (current_time - camera.received).seconds() <= stale_timeout_;
    const bool velodyne_fresh = velodyne.message &&
      (current_time - velodyne.received).seconds() <= stale_timeout_;
    if ((require_both_ && !(camera_fresh && velodyne_fresh)) ||
      (!camera_fresh && !velodyne_fresh))
    {
      return;
    }

    bool changed = false;
    try {
      if (camera_fresh && camera.generation != camera_layer_.generation) {
        camera_layer_ = render(*camera.message, camera.generation, true, camera_stride_);
        changed = true;
      }
      if (velodyne_fresh && velodyne.generation != velodyne_layer_.generation) {
        velodyne_layer_ = render(
          *velodyne.message, velodyne.generation, false, velodyne_stride_);
        changed = true;
      }
    } catch (const std::exception & error) {
      RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000, "%s", error.what());
      return;
    }
    if (!changed || (require_both_ && !(camera_layer_.valid && velodyne_layer_.valid))) {
      return;
    }

    cv::Mat image = grid_background();
    cv::Mat union_mask = cv::Mat::zeros(height_, width_, CV_8UC1);
    if (camera_fresh && camera_layer_.valid) {
      camera_layer_.image.copyTo(image, camera_layer_.mask);
      cv::bitwise_or(union_mask, camera_layer_.mask, union_mask);
    }
    if (velodyne_fresh && velodyne_layer_.valid) {
      cv::Mat lidar_image = velodyne_layer_.image;
      cv::Mat lidar_mask = velodyne_layer_.mask;
      if (velodyne_radius_ > 0) {
        const int size = velodyne_radius_ * 2 + 1;
        const cv::Mat kernel = cv::Mat::ones(size, size, CV_8UC1);
        cv::dilate(lidar_image, lidar_image, kernel);
        cv::dilate(lidar_mask, lidar_mask, kernel);
      }
      cv::Mat blended;
      cv::addWeighted(
        image, 1.0 - velodyne_alpha_, lidar_image, velodyne_alpha_, 0.0, blended);
      blended.copyTo(image, lidar_mask);
      cv::bitwise_or(union_mask, lidar_mask, union_mask);
    }
    cv::putText(
      image, "D555 RGB + Velodyne height", cv::Point(10, 22),
      cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, cv::LINE_AA);

    std_msgs::msg::Header header;
    header.frame_id = target_frame_;
    header.stamp = camera_layer_.stamp;
    if (velodyne_layer_.stamp.sec > header.stamp.sec ||
      (velodyne_layer_.stamp.sec == header.stamp.sec &&
      velodyne_layer_.stamp.nanosec > header.stamp.nanosec))
    {
      header.stamp = velodyne_layer_.stamp;
    }
    image_pub_->publish(*cv_bridge::CvImage(
      header, sensor_msgs::image_encodings::BGR8, image).toImageMsg());
    mask_pub_->publish(*cv_bridge::CvImage(
      header, sensor_msgs::image_encodings::MONO8, union_mask).toImageMsg());
  }

  std::string camera_topic_;
  std::string velodyne_topic_;
  std::string target_frame_;
  std::string output_topic_;
  std::string mask_topic_;
  double x_min_, x_max_, y_min_, y_max_, z_min_, z_max_;
  double resolution_, publish_rate_, stale_timeout_, velodyne_alpha_;
  int camera_stride_, velodyne_stride_, velodyne_radius_;
  int height_, width_;
  bool require_both_;

  std::mutex input_mutex_;
  Input camera_;
  Input velodyne_;
  Layer camera_layer_;
  Layer velodyne_layer_;
  std::unordered_map<std::string, Transform> transform_cache_;
  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr camera_sub_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr velodyne_sub_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr mask_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<D555VelodyneBev>());
  rclcpp::shutdown();
  return 0;
}
