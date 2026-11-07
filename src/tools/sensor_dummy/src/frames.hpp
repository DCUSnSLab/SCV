#ifndef FRAMES_HPP_
#define FRAMES_HPP_

#include "vehicle_model.hpp"

#include <Eigen/Geometry>

namespace sensor_dummy
{

// The base moves in the plane, so the mount height passes through unchanged.
Eigen::Vector3d map_position(const Pose2d & base, const Eigen::Vector3d & mount);
// pose, given in the map frame, in the frame of origin.
Pose2d relative_pose(const Pose2d & origin, const Pose2d & pose);

}  // namespace sensor_dummy

#endif  // FRAMES_HPP_
