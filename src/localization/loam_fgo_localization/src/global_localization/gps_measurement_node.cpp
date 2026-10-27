#include <cmath>
#include <memory>
#include <string>

#include <GeographicLib/UTMUPS.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <sensor_msgs/msg/nav_sat_status.hpp>
#include <std_msgs/msg/string.hpp>

#include "loam_fgo_localization/global_localization/gps_frontend.hpp"

namespace loam_fgo_localization
{

// GPS 측정 추출 노드 (FGO 파이프라인의 GPS frontend).
//  담당: NavSatFix -> UTM - datum -> map 좌표 변환 + fix-type 분류 + σ floor.
//  발행:
//    /gps/measurement     : FGO 팩터용 위치 측정 (공분산 = floor 적용, cov[14]=fix class 코드)
//    /gps/fix_state       : "RTK_FIXED"/"FLOAT"/"NONE" (latched, 변화 시)
//    /gps/coarse_position : 기존 규약 그대로 (raw σ) — PCD BBS 전역초기화 prior 용
//  안 함: EKF/필터링, map->odom (전부 FGO 몫). 기존 gps_global_localizer(src/temp) 대체.
class GpsMeasurementNode : public rclcpp::Node
{
public:
  GpsMeasurementNode()
  : Node("gps_measurement")
  {
    gps_topic_ = declare_parameter<std::string>("topics.gps", "/ublox_gps_node/fix");
    measurement_topic_ = declare_parameter<std::string>(
      "topics.measurement", "/gps/measurement");
    coarse_position_topic_ = declare_parameter<std::string>(
      "topics.coarse_position", "/gps/coarse_position");
    fix_state_topic_ = declare_parameter<std::string>(
      "topics.fix_state", "/gps/fix_state");
    map_frame_ = declare_parameter<std::string>("frames.map", "map");

    map_origin_easting_ = declare_parameter<double>("map_origin.easting", 0.0);
    map_origin_northing_ = declare_parameter<double>("map_origin.northing", 0.0);
    map_utm_zone_ = declare_parameter<int>("map_origin.utm_zone", 52);
    map_utm_north_ = declare_parameter<bool>("map_origin.northern_hemisphere", true);

    classifier_.rtk_status_min = declare_parameter<int>("gps.rtk_status_min", 2);
    classifier_.rtk_sigma_max = declare_parameter<double>("gps.rtk_sigma_max", 0.05);
    classifier_.rtk_sigma_floor = declare_parameter<double>("gps.rtk_sigma_floor", 0.05);
    classifier_.float_sigma_floor = declare_parameter<double>("gps.float_sigma_floor", 1.5);
    classifier_.unknown_sigma = declare_parameter<double>("gps.unknown_sigma", 5.0);

    measurement_publisher_ =
      create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(
      measurement_topic_, rclcpp::SensorDataQoS());
    coarse_position_publisher_ =
      create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(
      coarse_position_topic_, rclcpp::SensorDataQoS());
    fix_state_publisher_ = create_publisher<std_msgs::msg::String>(
      fix_state_topic_, rclcpp::QoS(1).transient_local().reliable());

    gps_subscription_ = create_subscription<sensor_msgs::msg::NavSatFix>(
      gps_topic_, rclcpp::SensorDataQoS(),
      std::bind(&GpsMeasurementNode::gpsCallback, this, std::placeholders::_1));

    publishFixState(GpsFixClass::None);
    RCLCPP_INFO(
      get_logger(),
      "GPS measurement frontend: origin UTM zone=%d %s e=%.3f n=%.3f, "
      "rtk(status>=%d, sigma<%.2f), floors rtk=%.2f float=%.2f",
      map_utm_zone_, map_utm_north_ ? "north" : "south",
      map_origin_easting_, map_origin_northing_,
      classifier_.rtk_status_min, classifier_.rtk_sigma_max,
      classifier_.rtk_sigma_floor, classifier_.float_sigma_floor);
  }

private:
  void publishFixState(GpsFixClass c)
  {
    if (have_last_class_ && c == last_class_) {
      return;
    }
    if (have_last_class_) {
      RCLCPP_INFO(
        get_logger(), "GPS fix state: %s -> %s",
        gpsFixClassName(last_class_), gpsFixClassName(c));
    }
    last_class_ = c;
    have_last_class_ = true;
    std_msgs::msg::String message;
    message.data = gpsFixClassName(c);
    fix_state_publisher_->publish(message);
  }

  void gpsCallback(const sensor_msgs::msg::NavSatFix::SharedPtr message)
  {
    if (message->status.status == sensor_msgs::msg::NavSatStatus::STATUS_NO_FIX ||
      !std::isfinite(message->latitude) || !std::isfinite(message->longitude))
    {
      publishFixState(GpsFixClass::None);
      return;
    }

    const bool sigma_known = message->position_covariance_type !=
      sensor_msgs::msg::NavSatFix::COVARIANCE_TYPE_UNKNOWN;
    const double raw_sigma = sigma_known ?
      std::sqrt(std::max(
        {message->position_covariance[0], message->position_covariance[4], 0.0})) :
      classifier_.unknown_sigma;
    const GpsFixClass fix_class = classifyGpsFix(
      message->status.status, raw_sigma, sigma_known, classifier_);
    publishFixState(fix_class);
    if (fix_class == GpsFixClass::None) {
      return;
    }

    try {
      int zone = 0;
      bool north = true;
      double easting = 0.0;
      double northing = 0.0;
      double convergence = 0.0;
      double scale = 0.0;
      GeographicLib::UTMUPS::Forward(
        message->latitude, message->longitude, zone, north,
        easting, northing, convergence, scale, map_utm_zone_);
      if (zone != map_utm_zone_ || north != map_utm_north_) {
        RCLCPP_ERROR_THROTTLE(
          get_logger(), *get_clock(), 2000,
          "GPS fix projected outside configured UTM frame: got zone=%d %s",
          zone, north ? "north" : "south");
        return;
      }
      const double map_x = easting - map_origin_easting_;
      const double map_y = northing - map_origin_northing_;

      // coarse: 기존 규약(raw σ) — PCD BBS prior 용
      geometry_msgs::msg::PoseWithCovarianceStamped coarse;
      coarse.header = message->header;
      coarse.header.frame_id = map_frame_;
      coarse.pose.pose.position.x = map_x;
      coarse.pose.pose.position.y = map_y;
      coarse.pose.pose.orientation.w = 1.0;
      coarse.pose.covariance[0] = raw_sigma * raw_sigma;
      coarse.pose.covariance[7] = raw_sigma * raw_sigma;
      coarse_position_publisher_->publish(coarse);

      // measurement: FGO 팩터용 (floor 적용). cov[14](z 슬롯, 2D 미사용)에 fix class 코드.
      //   0=NONE, 1=FLOAT, 2=RTK_FIXED  (fgo_fusion_node 와의 규약)
      const double sigma = flooredSigma(fix_class, raw_sigma, sigma_known, classifier_);
      geometry_msgs::msg::PoseWithCovarianceStamped meas = coarse;
      meas.pose.covariance[0] = sigma * sigma;
      meas.pose.covariance[7] = sigma * sigma;
      meas.pose.covariance[14] =
        fix_class == GpsFixClass::RtkFixed ? 2.0 : 1.0;
      measurement_publisher_->publish(meas);
    } catch (const GeographicLib::GeographicErr & error) {
      RCLCPP_ERROR_THROTTLE(
        get_logger(), *get_clock(), 2000,
        "failed to project GPS fix to UTM: %s", error.what());
    }
  }

  std::string gps_topic_;
  std::string measurement_topic_;
  std::string coarse_position_topic_;
  std::string fix_state_topic_;
  std::string map_frame_;
  double map_origin_easting_{0.0};
  double map_origin_northing_{0.0};
  int map_utm_zone_{52};
  bool map_utm_north_{true};
  GpsClassifierParams classifier_;
  GpsFixClass last_class_{GpsFixClass::None};
  bool have_last_class_{false};

  rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr gps_subscription_;
  rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr
    measurement_publisher_;
  rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr
    coarse_position_publisher_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr fix_state_publisher_;
};

}  // namespace loam_fgo_localization

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<loam_fgo_localization::GpsMeasurementNode>());
  rclcpp::shutdown();
  return 0;
}
