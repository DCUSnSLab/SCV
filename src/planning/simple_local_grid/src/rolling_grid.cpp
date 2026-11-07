#include "rolling_grid.hpp"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <vector>

namespace simple_local_grid
{
namespace
{

// Below every beam, so an empty cell needs no case of its own in clear_beam.
const float kEmpty = -std::numeric_limits<float>::infinity();

float read_float(const std::uint8_t * point, std::uint32_t offset)
{
  float value;
  std::memcpy(&value, point + offset, sizeof(value));
  return value;
}

Eigen::Vector3f read_point(const RawCloud & cloud, std::size_t i)
{
  const std::uint8_t * point = cloud.data + i * cloud.step;
  return {read_float(point, cloud.x), read_float(point, cloud.y), read_float(point, cloud.z)};
}

}  // namespace

void set_field_offset(RawCloud & cloud, std::string_view name, std::uint32_t offset)
{
  if (name == "x") {
    cloud.x = offset;
  } else if (name == "y") {
    cloud.y = offset;
  } else if (name == "z") {
    cloud.z = offset;
  }
}

bool is_obstacle(const ObstacleFilter & filter, const Eigen::Vector3f & point_in_base)
{
  const double x = point_in_base.x();
  const double y = point_in_base.y();
  const double z = point_in_base.z();
  // Written so that the NaN of a missing return is rejected here.
  if (!(z >= filter.min_height && z <= filter.max_height)) {
    return false;
  }
  const bool on_vehicle = x >= filter.self_min_x && x <= filter.self_max_x &&
                          y >= filter.self_min_y && y <= filter.self_max_y;
  return !on_vehicle;
}

RollingGrid::RollingGrid(double resolution, int size_cells)
: resolution_(resolution), size_(size_cells), top_(std::size_t(size_cells) * size_cells, kEmpty)
{
}

void RollingGrid::center_on(double x, double y)
{
  const int64_t anchor_x = std::lround(std::floor(x / resolution_)) - size_ / 2;
  const int64_t anchor_y = std::lround(std::floor(y / resolution_)) - size_ / 2;
  const int64_t shift_x = anchor_x - anchor_x_;
  const int64_t shift_y = anchor_y - anchor_y_;
  if (shift_x == 0 && shift_y == 0) {
    return;
  }
  std::vector<float> moved(top_.size(), kEmpty);
  for (int64_t row = std::max(int64_t{0}, -shift_y);
       row < std::min<int64_t>(size_, size_ - shift_y); ++row) {
    for (int64_t col = std::max(int64_t{0}, -shift_x);
         col < std::min<int64_t>(size_, size_ - shift_x); ++col) {
      moved[index(col, row)] = top_[index(col + shift_x, row + shift_y)];
    }
  }
  top_.swap(moved);
  anchor_x_ = anchor_x;
  anchor_y_ = anchor_y;
}

void RollingGrid::add_hit(double x, double y, float z)
{
  const int64_t col = std::lround(std::floor(x / resolution_)) - anchor_x_;
  const int64_t row = std::lround(std::floor(y / resolution_)) - anchor_y_;
  if (col >= 0 && col < size_ && row >= 0 && row < size_) {
    float & top = top_[index(col, row)];
    top = std::max(top, z);
  }
}

void RollingGrid::clear_beam(const Eigen::Vector3d & from, const Eigen::Vector3d & to)
{
  const double start_col = from.x() / resolution_ - anchor_x_;
  const double start_row = from.y() / resolution_ - anchor_y_;
  const double col_span = to.x() / resolution_ - anchor_x_ - start_col;
  const double row_span = to.y() / resolution_ - anchor_y_ - start_row;
  const int return_col = static_cast<int>(std::floor(start_col + col_span));
  const int return_row = static_cast<int>(std::floor(start_row + row_span));
  // At most one cell per step along the longer axis, so that none is skipped.
  const int steps = static_cast<int>(std::ceil(std::max(std::abs(col_span), std::abs(row_span))));
  for (int i = 0; i < steps; ++i) {
    const double along = static_cast<double>(i) / steps;
    const int col = static_cast<int>(std::floor(start_col + along * col_span));
    const int row = static_cast<int>(std::floor(start_row + along * row_span));
    const bool outside = col < 0 || row < 0 || col >= size_ || row >= size_;
    if (outside || (col == return_col && row == return_row)) {
      return;
    }
    float & top = top_[index(col, row)];
    if (from.z() + along * (to.z() - from.z()) < top) {
      top = kEmpty;
    }
  }
}

void RollingGrid::clear_vehicle(
  const ObstacleFilter & filter, const Eigen::Isometry3d & grid_from_base)
{
  const Eigen::Isometry3d base_from_grid = grid_from_base.inverse();
  const double half_diagonal = std::max(
    std::hypot(filter.self_min_x, filter.self_min_y),
    std::hypot(filter.self_max_x, filter.self_max_y));
  const int reach = static_cast<int>(std::ceil(half_diagonal / resolution_));
  const int64_t center_col =
    std::lround(grid_from_base.translation().x() / resolution_) - anchor_x_;
  const int64_t center_row =
    std::lround(grid_from_base.translation().y() / resolution_) - anchor_y_;
  const int64_t last_row = std::min<int64_t>(center_row + reach, size_ - 1);
  const int64_t last_col = std::min<int64_t>(center_col + reach, size_ - 1);
  for (int64_t row = std::max(int64_t{0}, center_row - reach); row <= last_row; ++row) {
    for (int64_t col = std::max(int64_t{0}, center_col - reach); col <= last_col; ++col) {
      const Eigen::Vector3d cell(
        (anchor_x_ + col + 0.5) * resolution_, (anchor_y_ + row + 0.5) * resolution_,
        grid_from_base.translation().z());
      const Eigen::Vector3d in_base = base_from_grid * cell;
      if (
        in_base.x() >= filter.self_min_x && in_base.x() <= filter.self_max_x &&
        in_base.y() >= filter.self_min_y && in_base.y() <= filter.self_max_y) {
        top_[index(col, row)] = kEmpty;
      }
    }
  }
}

void RollingGrid::insert(
  const RawCloud & cloud, const Eigen::Isometry3f & base_from_sensor,
  const Eigen::Isometry3d & grid_from_base, const ObstacleFilter & filter, int clear_stride)
{
  const Eigen::Isometry3d grid_from_sensor = grid_from_base * base_from_sensor.cast<double>();
  const Eigen::Vector3d sensor = grid_from_sensor.translation();
  // Before the marks, so that no beam of this scan erases a hit of this scan.
  for (std::size_t i = scan_count_ % clear_stride; i < cloud.count; i += clear_stride) {
    const Eigen::Vector3f point = read_point(cloud, i);
    if (point.allFinite()) {
      clear_beam(sensor, grid_from_sensor * point.cast<double>());
    }
  }
  ++scan_count_;
  clear_vehicle(filter, grid_from_base);

  for (std::size_t i = 0; i < cloud.count; ++i) {
    const Eigen::Vector3f in_base = base_from_sensor * read_point(cloud, i);
    if (is_obstacle(filter, in_base)) {
      const Eigen::Vector3d in_grid = grid_from_base * in_base.cast<double>();
      add_hit(in_grid.x(), in_grid.y(), static_cast<float>(in_grid.z()));
    }
  }
}

std::vector<std::int8_t> RollingGrid::occupancy() const
{
  std::vector<std::int8_t> cells(top_.size());
  std::transform(top_.begin(), top_.end(), cells.begin(), [](float top) {
    return static_cast<std::int8_t>(top == kEmpty ? 0 : 100);
  });
  return cells;
}

}  // namespace simple_local_grid
