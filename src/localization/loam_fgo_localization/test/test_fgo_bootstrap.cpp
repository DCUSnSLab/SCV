#include <cmath>
#include <iostream>

#include "loam_fgo_localization/fusion/fgo_core.hpp"

int main()
{
  loam_fgo_localization::FgoParams params;
  params.gps_use_float = false;
  loam_fgo_localization::FgoCore core(params);
  const gtsam::Pose2 odom_pose(0.0, 0.0, 0.0);
  const gtsam::Pose2 map_pose(80.0, -60.0, 0.27);
  core.addOdom({0.0, odom_pose});

  loam_fgo_localization::PcdMeasurement pcd;
  pcd.t = 0.0;
  pcd.pose = map_pose;
  pcd.covariance = Eigen::Vector3d(0.01, 0.01, 0.0004).asDiagonal();
  if (!core.addPcd(pcd) || !core.anchored()) {
    std::cerr << "first PCD was not accepted for initialization\n";
    return 1;
  }
  core.update(0.0);

  const auto estimate = core.latestMapPose();
  if (!estimate) {
    std::cerr << "first solve produced no map pose\n";
    return 1;
  }
  const double xy_error = std::hypot(
    estimate->x() - map_pose.x(), estimate->y() - map_pose.y());
  const double yaw_delta = estimate->theta() - map_pose.theta();
  const double yaw_error = std::abs(std::atan2(std::sin(yaw_delta), std::cos(yaw_delta)));
  if (!std::isfinite(xy_error) || !std::isfinite(yaw_error) ||
    xy_error >= 0.10 || yaw_error >= 0.01)
  {
    std::cerr << "100 m initial offset did not converge in the first solve\n";
    return 1;
  }

  // 초기화 이후에는 기존 PCD 이상치 게이트를 우회하지 않는다.
  core.addOdom({0.5, odom_pose});
  pcd.t = 0.5;
  pcd.pose = gtsam::Pose2(100.0, -60.0, 0.27);
  if (core.addPcd(pcd) || core.pcdRejected() != 1) {
    std::cerr << "outlier gate was bypassed after initialization\n";
    return 1;
  }
  pcd.pose = map_pose;
  if (!core.addPcd(pcd) || core.pcdAccepted() != 2) {
    std::cerr << "consistent PCD was rejected after initialization\n";
    return 1;
  }
  // GPS 팩터의 Pose2 자코비안도 현재 GTSAM에서 계산되어야 한다.
  core.addGps({0.5, gtsam::Point2(80.0, -60.0), 0.05, 0.05, true});
  core.update(0.5);
  const auto tracked = core.latestMapPose();
  if (!tracked || !tracked->matrix().allFinite() ||
    std::hypot(tracked->x() - map_pose.x(), tracked->y() - map_pose.y()) >= 0.10)
  {
    std::cerr << "PCD/RTK tracking failed after initialization\n";
    return 1;
  }
  std::cout << "PASS: bootstrap xy=" << xy_error << " m, yaw=" << yaw_error
            << " rad; subsequent PCD gate and RTK update preserved\n";
  return 0;
}
