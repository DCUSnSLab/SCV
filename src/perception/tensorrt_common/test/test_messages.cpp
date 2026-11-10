#include "tensorrt_common/image.hpp"
#include "tensorrt_common/messages.hpp"

#include <opencv2/core.hpp>

#include <gtest/gtest.h>
#include <unistd.h>

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <memory>
#include <optional>
#include <string>
#include <thread>
#include <utility>
#include <vector>

namespace
{

class MessagesTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    rclcpp::init(0, nullptr);
    node_ =
      std::make_shared<rclcpp::Node>("messages", "/messages_test_" + std::to_string(::getpid()));
  }
  void TearDown() override
  {
    node_.reset();
    rclcpp::shutdown();
  }

  template <class F>
  void run_until(const std::atomic<bool> & done, F publish_once)
  {
    flux_wrapper::Executor ex;
    ex.add_node(node_);
    std::thread spinner([&ex] { ex.spin(); });
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(10);
    while (!done && std::chrono::steady_clock::now() < deadline) {
      publish_once();
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    ex.cancel();
    spinner.join();
  }

  rclcpp::Node::SharedPtr node_;
};

std_msgs::msg::Header header()
{
  std_msgs::msg::Header h;
  h.stamp.sec = 42;
  // An odd length: written before the data, it would leave the data off a 4-byte boundary.
  h.frame_id = "camera_optical";
  return h;
}

}  // namespace

TEST_F(MessagesTest, ImageIsWrittenInPlaceAndAlignedForFloats)
{
  std::optional<std::vector<float>> got;
  std::string frame;
  std::atomic<bool> done{false};
  flux_wrapper::Subscription<sensor_msgs::msg::Image> sub(
    *node_, "depth", rclcpp::QoS(4), [&](const flux_wrapper::View<sensor_msgs::msg::Image> & v) {
      std::vector<float> values(v.width() * v.height());
      std::memcpy(values.data(), v.data().data(), values.size() * sizeof(float));
      got = values;
      frame = std::string(v.frame_id());
      done = true;
    });
  flux_wrapper::Publisher<sensor_msgs::msg::Image> pub(*node_, "depth", rclcpp::QoS(4));
  run_until(done, [&] {
    auto loan = pub.loan();
    cv::Mat m = tensorrt_common::loan_image(loan, header(), {3, 2}, CV_32FC1, "32FC1");
    ASSERT_FALSE(m.empty());
    EXPECT_EQ(reinterpret_cast<std::uintptr_t>(m.data) % alignof(float), 0U);
    for (int i = 0; i < 6; ++i) {
      m.at<float>(i / 3, i % 3) = 0.5F * static_cast<float>(i);
    }
    pub.publish(std::move(loan));
  });
  ASSERT_TRUE(got);
  EXPECT_EQ(frame, "camera_optical");
  EXPECT_EQ(*got, (std::vector<float>{0.0F, 0.5F, 1.0F, 1.5F, 2.0F, 2.5F}));
}

TEST_F(MessagesTest, CloudIsAlignedForFloats)
{
  flux_wrapper::Publisher<sensor_msgs::msg::PointCloud2> pub(*node_, "points", rclcpp::QoS(4));
  for (const bool rgb : {false, true}) {
    auto loan = pub.loan();
    const auto layout = tensorrt_common::cloud_layout({5, 3}, 1, rgb);
    const auto * data = tensorrt_common::loan_cloud(loan, header(), layout);
    ASSERT_NE(data, nullptr);
    EXPECT_EQ(reinterpret_cast<std::uintptr_t>(data) % alignof(float), 0U);
  }
}

TEST_F(MessagesTest, TooLargeForTheSlotIsEmpty)
{
  flux_wrapper::PublisherOptions options;
  options.max_message_size = 1 << 20;
  flux_wrapper::Publisher<sensor_msgs::msg::Image> pub(*node_, "large", rclcpp::QoS(4), options);
  auto loan = pub.loan();
  const cv::Mat m = tensorrt_common::loan_image(loan, header(), {1024, 1024}, CV_32FC1, "32FC1");
  EXPECT_EQ(m.empty(), pub.uses_flux());
}

TEST_F(MessagesTest, GpuImageIsPreprocessedWhereItArrives)
{
  tensorrt_common::EngineOptions o;
  o.onnx_path = std::string(TEST_DATA_DIR) + "/identity_640x640.onnx";
  o.engine_path = testing::TempDir() + "identity_640x640.engine";
  o.workspace_bytes = 64 << 20;
  tensorrt_common::Engine engine(o);
  cv::Mat bgr(1080, 810, CV_8UC3);
  cv::randu(bgr, 0, 256);
  const auto box = tensorrt_common::fit_letterbox(bgr.cols, bgr.rows, 640, 640);
  const tensorrt_common::Placement place{box.left, box.top, box.width, box.height, 114.0F};
  const auto preprocess = [&](const tensorrt_common::ImageView & image) {
    engine.upload_image(
      "image", 0, image, place, tensorrt_common::Resize::Linear, {0, 0, 0}, {1, 1, 1});
    engine.infer();
    std::vector<float> out(engine.info("copy").elements);
    engine.download_float("copy", out.data());
    return out;
  };

  std::optional<std::vector<float>> got;
  bool on_device = false;
  std::atomic<bool> done{false};
  flux_wrapper::Subscription<sensor_msgs::msg::Image> sub(
    *node_, "gpu_image", rclcpp::QoS(4),
    [&](const flux_wrapper::View<sensor_msgs::msg::Image> & v) {
      const auto view = tensorrt_common::view_of(v);
      on_device = view.on_device;
      got = preprocess(view);
      done = true;
    },
    tensorrt_common::image_subscription(true));
  flux_wrapper::PublisherOptions options;
  options.device = flux_wrapper::Device::Cuda;
  flux_wrapper::Publisher<sensor_msgs::msg::Image> pub(
    *node_, "gpu_image", rclcpp::QoS(4), options);
  const std::size_t bytes = bgr.total() * bgr.elemSize();
  run_until(done, [&] {
    auto loan = pub.loan();
    auto buffer = loan.alloc_buffer(bytes);
    ASSERT_TRUE(loan && buffer && buffer.copy_from(bgr.data, bytes));
    loan.set_header(header());
    loan.set_height(static_cast<std::uint32_t>(bgr.rows));
    loan.set_width(static_cast<std::uint32_t>(bgr.cols));
    loan.set_encoding("bgr8");
    loan.set_is_bigendian(0);
    loan.set_step(static_cast<std::uint32_t>(bgr.step));
    pub.publish(std::move(loan));
  });
  ASSERT_TRUE(got);
  // On the ROS path the wrapper copies the GPU buffer to a host message at publish.
  EXPECT_TRUE(pub.uses_device());
  EXPECT_EQ(on_device, sub.uses_flux());
  const tensorrt_common::ImageView host{"bgr8", bgr.data, bgr.cols, bgr.rows, bgr.step};
  EXPECT_EQ(*got, preprocess(host));
}
