#ifndef DISTANCE_MAP_HPP_
#define DISTANCE_MAP_HPP_

#include <cstdint>
#include <vector>

namespace simple_mppi_planner
{

struct GridView
{
  const std::int8_t * cells = nullptr;
  int width = 0;
  int height = 0;
  double resolution = 0.0;
  double origin_x = 0.0;
  double origin_y = 0.0;
  int occupied_threshold = 0;
};

// Distance to the nearest occupied cell center, built once per grid so that a footprint check is
// one array read per circle.
class DistanceMap
{
public:
  void build(const GridView & grid);

  // 0 outside the grid: nothing is known there, so a trajectory may not leave it.
  double at(double x, double y) const
  {
    const double col = (x - origin_x_) * inverse_resolution_;
    const double row = (y - origin_y_) * inverse_resolution_;
    if (col < 0.0 || row < 0.0 || col >= width_ || row >= height_) {
      return 0.0;
    }
    return distance_[static_cast<std::size_t>(row) * width_ + static_cast<int>(col)];
  }

private:
  int width_ = 0;
  int height_ = 0;
  double inverse_resolution_ = 0.0;
  double origin_x_ = 0.0;
  double origin_y_ = 0.0;
  std::vector<float> distance_;
};

}  // namespace simple_mppi_planner

#endif  // DISTANCE_MAP_HPP_
