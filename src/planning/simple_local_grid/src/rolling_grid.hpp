#ifndef ROLLING_GRID_HPP_
#define ROLLING_GRID_HPP_

#include <Eigen/Geometry>

#include <cstddef>
#include <cstdint>
#include <string_view>
#include <vector>

namespace simple_local_grid
{

// Points read in place from a PointCloud2 buffer, a DDS message or a flux frame alike.
struct RawCloud
{
  const std::uint8_t * data = nullptr;
  std::size_t count = 0;
  std::uint32_t step = 0;
  std::uint32_t x = 0;
  std::uint32_t y = 0;
  std::uint32_t z = 0;
};

void set_field_offset(RawCloud & cloud, std::string_view name, std::uint32_t offset);

// All limits are in the base frame, whose z = 0 is the ground under the vehicle.
struct ObstacleFilter
{
  double min_height = 0.0;
  double max_height = 0.0;
  double self_min_x = 0.0;
  double self_max_x = 0.0;
  double self_min_y = 0.0;
  double self_max_y = 0.0;
};

bool is_obstacle(const ObstacleFilter & filter, const Eigen::Vector3f & point_in_base);

// Square window of cells aligned with the grid frame. Moving it keeps the cells that overlap.
// A cell stays occupied until a beam proves it free, however old its hit is: a low obstacle close
// to the vehicle sits under every beam of the lidar, and only its memory stops the vehicle.
class RollingGrid
{
public:
  RollingGrid(double resolution, int size_cells);

  void center_on(double x, double y);
  // z is in the grid frame. The cell keeps its highest hit.
  void add_hit(double x, double y, float z);
  // Frees the cells that the beam crosses below their top, except the cell of its return.
  void clear_beam(const Eigen::Vector3d & from, const Eigen::Vector3d & to);
  void clear_vehicle(const ObstacleFilter & filter, const Eigen::Isometry3d & grid_from_base);
  // Marks every obstacle point, and clears along one point in clear_stride. Each scan starts at
  // the next offset, so a vehicle at rest still tries every beam.
  void insert(
    const RawCloud & cloud, const Eigen::Isometry3f & base_from_sensor,
    const Eigen::Isometry3d & grid_from_base, const ObstacleFilter & filter, int clear_stride);

  // Row-major from the lower-left cell: 100 or 0.
  std::vector<std::int8_t> occupancy() const;

  double resolution() const { return resolution_; }
  int size_cells() const { return size_; }
  double origin_x() const { return anchor_x_ * resolution_; }
  double origin_y() const { return anchor_y_ * resolution_; }

private:
  std::size_t index(int col, int row) const { return std::size_t(row) * size_ + col; }

  double resolution_;
  int size_;
  // Absolute cell index of the lower-left cell: origin snaps to cells, so hits stay aligned.
  int64_t anchor_x_ = 0;
  int64_t anchor_y_ = 0;
  std::vector<float> top_;
  int scan_count_ = 0;
};

}  // namespace simple_local_grid

#endif  // ROLLING_GRID_HPP_
