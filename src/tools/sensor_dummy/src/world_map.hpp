#ifndef WORLD_MAP_HPP_
#define WORLD_MAP_HPP_

#include <Eigen/Core>

#include <string>
#include <vector>

namespace sensor_dummy
{

struct RayHit
{
  double range;
  float intensity;
};

// A yawed box standing on the ground. Walls and boxes both become one.
struct Obstacle
{
  Eigen::Vector2d center;
  Eigen::Vector2d half_size;
  double cos_yaw;
  double sin_yaw;
  double height;
  float intensity;
};

class WorldMap
{
public:
  static WorldMap load(const std::string & path);

  WorldMap(double ground_z, float ground_intensity, std::vector<Obstacle> obstacles);

  // Returns false when the ray hits nothing within max_range.
  bool raycast(
    const Eigen::Vector3d & origin, const Eigen::Vector3d & direction, double max_range,
    RayHit & hit) const;

private:
  bool hit_obstacle(
    const Obstacle & box, const Eigen::Vector3d & origin, const Eigen::Vector3d & direction,
    double & range) const;

  double ground_z_;
  float ground_intensity_;
  std::vector<Obstacle> obstacles_;
};

}  // namespace sensor_dummy

#endif  // WORLD_MAP_HPP_
