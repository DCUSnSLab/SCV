#include "lidar_model.hpp"

#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

namespace sensor_dummy
{
namespace
{
void write_point(
  std::uint8_t * out, float x, float y, float z, float intensity, std::uint16_t ring, float time)
{
  std::memcpy(out, &x, sizeof(x));
  std::memcpy(out + 4, &y, sizeof(y));
  std::memcpy(out + 8, &z, sizeof(z));
  std::memcpy(out + 12, &intensity, sizeof(intensity));
  std::memcpy(out + kRingOffset, &ring, sizeof(ring));
  std::memcpy(out + kTimeOffset, &time, sizeof(time));
}

Eigen::Isometry3d row_pose(
  const Pose2d & start, const Pose2d & end, double fraction,
  const Eigen::Isometry3d & base_to_lidar)
{
  const double dyaw = std::remainder(end.yaw - start.yaw, 2.0 * M_PI);
  Eigen::Isometry3d base = Eigen::Isometry3d::Identity();
  base.translation() = Eigen::Vector3d(
    start.x + fraction * (end.x - start.x), start.y + fraction * (end.y - start.y), 0.0);
  base.linear() =
    Eigen::AngleAxisd(start.yaw + fraction * dyaw, Eigen::Vector3d::UnitZ()).toRotationMatrix();
  return base * base_to_lidar;
}
}  // namespace

std::vector<LaserBeam> load_beams(const std::string & calibration_path, double firing_step_s)
{
  const YAML::Node lasers = YAML::LoadFile(calibration_path)["lasers"];
  std::vector<double> vertical;
  std::vector<LaserBeam> beams;
  for (const auto & laser : lasers) {
    const double angle = laser["vert_correction"].as<double>();
    vertical.push_back(angle);
    const auto laser_id = laser["laser_id"].as<int>();
    // Lasers fire in pairs: rawdata.cpp, "dataPointIndex = y / 2".
    beams.push_back(
      {std::sin(angle), std::cos(angle), laser["rot_correction"].as<double>(), 0,
       firing_step_s * (laser_id / 2)});
  }
  std::vector<std::size_t> order(beams.size());
  std::iota(order.begin(), order.end(), 0);
  std::sort(order.begin(), order.end(), [&vertical](std::size_t a, std::size_t b) {
    return vertical[a] < vertical[b];
  });
  for (std::size_t rank = 0; rank < order.size(); ++rank) {
    beams[order[rank]].ring = static_cast<std::uint16_t>(rank);
  }
  return beams;
}

void render_scan(
  const LidarConfig & config, const std::vector<LaserBeam> & beams, const WorldMap & map,
  const Pose2d & start, const Pose2d & end, const Eigen::Isometry3d & base_to_lidar,
  std::vector<std::uint8_t> & data)
{
  const float nan = std::numeric_limits<float>::quiet_NaN();
  const double rotation_rate = config.rpm / 60.0 * 2.0 * M_PI;
  data.resize(config.blocks * beams.size() * kPointStep);

  for (int row = 0; row < config.blocks; ++row) {
    const double row_time = row * config.block_period_s;
    const double rotation = rotation_rate * row_time;
    const Eigen::Isometry3d pose =
      row_pose(start, end, static_cast<double>(row) / config.blocks, base_to_lidar);
    for (const auto & beam : beams) {
      // The sensor spins clockwise from +x: rawdata.cpp x_coord = y, y_coord = -x.
      const double azimuth = rotation - beam.rot_correction;
      const Eigen::Vector3d local(
        beam.cos_vertical * std::cos(azimuth), -beam.cos_vertical * std::sin(azimuth),
        beam.sin_vertical);
      const Eigen::Vector3d direction = pose.linear() * local;

      std::uint8_t * out = &data[(row * beams.size() + beam.ring) * kPointStep];
      const auto time = static_cast<float>(row_time + beam.firing_s);
      RayHit hit{};
      if (
        map.raycast(pose.translation(), direction, config.max_range, hit) &&
        hit.range >= config.min_range) {
        const Eigen::Vector3f point = (hit.range * local).cast<float>();
        write_point(out, point.x(), point.y(), point.z(), hit.intensity, beam.ring, time);
      } else {
        write_point(out, nan, nan, nan, nan, beam.ring, time);
      }
    }
  }
}

}  // namespace sensor_dummy
