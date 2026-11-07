// Time of RollingGrid::insert on a full VLP-32C scan of flat ground, walls and boxes.
//     taskset -c <core> bench_grid_insert <clear_stride>

#include "rolling_grid.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <vector>

using simple_local_grid::ObstacleFilter;
using simple_local_grid::RawCloud;
using simple_local_grid::RollingGrid;
using Clock = std::chrono::steady_clock;

namespace
{

constexpr int kRings = 32;
constexpr int kFirings = 1812;
constexpr int kCycles = 500;
constexpr double kSensorHeight = 0.905;
constexpr double kWallDistance = 4.0;
constexpr double kBoxDistance = 6.0;
constexpr double kMaxRange = 200.0;

// Rings from -25 to +15 degrees, the spread of the VLP-32C, in the organized order of its driver.
std::vector<std::array<float, 4>> organized_scan()
{
  std::vector<std::array<float, 4>> points;
  points.reserve(std::size_t(kRings) * kFirings);
  const float nan = std::numeric_limits<float>::quiet_NaN();
  for (int firing = 0; firing < kFirings; ++firing) {
    const double azimuth = 2.0 * M_PI * firing / kFirings;
    const double cx = std::cos(azimuth);
    const double cy = std::sin(azimuth);
    for (int ring = 0; ring < kRings; ++ring) {
      const double elevation = (-25.0 + 40.0 * ring / (kRings - 1)) * M_PI / 180.0;
      const double down = -std::tan(elevation);
      double range = down > 0.0 ? kSensorHeight / down : kMaxRange;
      if (std::abs(cy) > 1e-6) {
        range = std::min(range, kWallDistance / std::abs(cy));
      }
      if (cx > 1e-6) {
        range = std::min(range, kBoxDistance / cx);
      }
      if (range >= kMaxRange) {
        points.push_back({nan, nan, nan, 0.0F});
        continue;
      }
      points.push_back(
        {static_cast<float>(range * cx), static_cast<float>(range * cy),
         static_cast<float>(-range * down), 0.0F});
    }
  }
  return points;
}

}  // namespace

int main(int, char ** argv)
{
  const int stride = std::atoi(argv[1]);
  const auto points = organized_scan();
  RawCloud cloud;
  simple_local_grid::set_field_offset(cloud, "x", 0);
  simple_local_grid::set_field_offset(cloud, "y", 4);
  simple_local_grid::set_field_offset(cloud, "z", 8);
  cloud.data = reinterpret_cast<const std::uint8_t *>(points.data());
  cloud.count = points.size();
  cloud.step = sizeof(points[0]);

  const ObstacleFilter filter{0.2, 1.8, -0.5, 0.6, -0.43, 0.43};
  const Eigen::Isometry3f base_from_sensor(Eigen::Translation3f(0.21F, 0.0F, kSensorHeight));
  RollingGrid grid(0.1, 200);
  grid.center_on(0.0, 0.0);

  std::vector<double> times;
  for (int i = 0; i < kCycles; ++i) {
    const auto start = Clock::now();
    grid.insert(cloud, base_from_sensor, Eigen::Isometry3d::Identity(), filter, stride);
    times.push_back(std::chrono::duration<double, std::milli>(Clock::now() - start).count());
  }
  std::sort(times.begin(), times.end());
  std::printf(
    "stride %d: insert p50 %.3f ms  p99 %.3f ms  max %.3f ms\n", stride, times[kCycles / 2],
    times[kCycles * 99 / 100], times.back());
  return 0;
}
