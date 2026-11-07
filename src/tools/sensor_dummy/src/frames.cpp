#include "frames.hpp"

#include <cmath>

namespace sensor_dummy
{

Eigen::Vector3d map_position(const Pose2d & base, const Eigen::Vector3d & mount)
{
  const double c = std::cos(base.yaw);
  const double s = std::sin(base.yaw);
  return {
    base.x + c * mount.x() - s * mount.y(), base.y + s * mount.x() + c * mount.y(), mount.z()};
}

Pose2d relative_pose(const Pose2d & origin, const Pose2d & pose)
{
  const double c = std::cos(origin.yaw);
  const double s = std::sin(origin.yaw);
  const double dx = pose.x - origin.x;
  const double dy = pose.y - origin.y;
  return {c * dx + s * dy, -s * dx + c * dy, pose.yaw - origin.yaw};
}

}  // namespace sensor_dummy
