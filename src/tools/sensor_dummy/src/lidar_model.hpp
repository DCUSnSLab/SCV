#ifndef LIDAR_MODEL_HPP_
#define LIDAR_MODEL_HPP_

#include "vehicle_model.hpp"
#include "world_map.hpp"

#include <Eigen/Geometry>

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace sensor_dummy
{

// velodyne_pointcloud OrganizedCloudXYZIRT: x y z intensity (float32), ring (uint16), time
// (float32) with no padding.
inline constexpr std::size_t kPointStep = 22;
inline constexpr std::size_t kRingOffset = 16;
inline constexpr std::size_t kTimeOffset = 18;

struct LaserBeam
{
  double sin_vertical;
  double cos_vertical;
  double rot_correction;
  std::uint16_t ring;  // rank by vertical angle, lowest first (calibration.cpp laser_ring)
  double firing_s;     // time from the start of the block
};

struct LidarConfig
{
  double rpm;
  int blocks;  // cloud height: one row per block
  double block_period_s;
  double firing_step_s;
  double min_range;
  double max_range;
};

std::vector<LaserBeam> load_beams(const std::string & calibration_path, double firing_step_s);

// Fills an organized cloud in the sensor frame, width = beams, height = config.blocks. Each row
// sees the world from its own pose, from start to end, so the cloud carries the motion distortion
// that the per-point time field describes.
void render_scan(
  const LidarConfig & config, const std::vector<LaserBeam> & beams, const WorldMap & map,
  const Pose2d & start, const Pose2d & end, const Eigen::Isometry3d & base_to_lidar,
  std::vector<std::uint8_t> & data);

}  // namespace sensor_dummy

#endif  // LIDAR_MODEL_HPP_
