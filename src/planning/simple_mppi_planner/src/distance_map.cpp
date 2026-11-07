#include "distance_map.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

constexpr double kFar = 1e12;

// Felzenszwalb and Huttenlocher, "Distance Transforms of Sampled Functions": lower envelope of
// the parabolas rooted at each cell, in place over `stride`-spaced values.
class Envelope
{
public:
  explicit Envelope(int size) : values_(size), roots_(size), bounds_(size + 1) {}

  void transform(double * line, int size, int stride)
  {
    for (int i = 0; i < size; ++i) {
      values_[i] = line[std::size_t(i) * stride];
    }
    build(size);
    int k = 0;
    for (int i = 0; i < size; ++i) {
      while (bounds_[k + 1] < i) {
        ++k;
      }
      const double gap = i - roots_[k];
      line[std::size_t(i) * stride] = gap * gap + values_[roots_[k]];
    }
  }

private:
  double crossing(int q, int root) const
  {
    return ((values_[q] + static_cast<double>(q) * q) -
            (values_[root] + static_cast<double>(root) * root)) /
           (2.0 * (q - root));
  }

  void build(int size)
  {
    int k = 0;
    roots_[0] = 0;
    bounds_[0] = -std::numeric_limits<double>::infinity();
    bounds_[1] = std::numeric_limits<double>::infinity();
    for (int q = 1; q < size; ++q) {
      double s = crossing(q, roots_[k]);
      while (s <= bounds_[k]) {
        --k;
        s = crossing(q, roots_[k]);
      }
      ++k;
      roots_[k] = q;
      bounds_[k] = s;
      bounds_[k + 1] = std::numeric_limits<double>::infinity();
    }
  }

  std::vector<double> values_;
  std::vector<int> roots_;
  std::vector<double> bounds_;
};

}  // namespace

void DistanceMap::build(const GridView & grid)
{
  width_ = grid.width;
  height_ = grid.height;
  inverse_resolution_ = 1.0 / grid.resolution;
  origin_x_ = grid.origin_x;
  origin_y_ = grid.origin_y;

  const std::size_t count = std::size_t(width_) * height_;
  std::vector<double> squared(count);
  for (std::size_t i = 0; i < count; ++i) {
    squared[i] = grid.cells[i] >= grid.occupied_threshold ? 0.0 : kFar;
  }
  Envelope envelope(std::max(width_, height_));
  for (int col = 0; col < width_; ++col) {
    envelope.transform(squared.data() + col, height_, width_);
  }
  for (int row = 0; row < height_; ++row) {
    envelope.transform(squared.data() + std::size_t(row) * width_, width_, 1);
  }
  distance_.resize(count);
  for (std::size_t i = 0; i < count; ++i) {
    distance_[i] = static_cast<float>(std::sqrt(squared[i]) * grid.resolution);
  }
}

}  // namespace simple_mppi_planner
