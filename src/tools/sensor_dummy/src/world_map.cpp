#include "world_map.hpp"

#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <string>
#include <utility>
#include <vector>

namespace sensor_dummy
{
namespace
{
Obstacle make_wall(const YAML::Node & node)
{
  const Eigen::Vector2d start(node["start"][0].as<double>(), node["start"][1].as<double>());
  const Eigen::Vector2d end(node["end"][0].as<double>(), node["end"][1].as<double>());
  const Eigen::Vector2d along = end - start;
  const Eigen::Vector2d center = 0.5 * (start + end);
  const double yaw = std::atan2(along.y(), along.x());
  return {
    center,
    Eigen::Vector2d(0.5 * along.norm(), 0.5 * node["thickness"].as<double>()),
    std::cos(yaw),
    std::sin(yaw),
    node["height"].as<double>(),
    node["intensity"].as<float>()};
}

Obstacle make_box(const YAML::Node & node)
{
  const double yaw = node["yaw"].as<double>();
  return {
    Eigen::Vector2d(node["center"][0].as<double>(), node["center"][1].as<double>()),
    Eigen::Vector2d(0.5 * node["size"][0].as<double>(), 0.5 * node["size"][1].as<double>()),
    std::cos(yaw),
    std::sin(yaw),
    node["height"].as<double>(),
    node["intensity"].as<float>()};
}

void clip_slab(
  double origin, double direction, double low, double high, double & near, double & far)
{
  if (direction == 0.0) {
    if (origin < low || origin > high) {
      far = -1.0;
    }
    return;
  }
  double a = (low - origin) / direction;
  double b = (high - origin) / direction;
  if (a > b) {
    std::swap(a, b);
  }
  near = std::max(near, a);
  far = std::min(far, b);
}
}  // namespace

WorldMap WorldMap::load(const std::string & path)
{
  const YAML::Node root = YAML::LoadFile(path);
  std::vector<Obstacle> obstacles;
  for (const auto & wall : root["walls"]) {
    obstacles.push_back(make_wall(wall));
  }
  for (const auto & box : root["boxes"]) {
    obstacles.push_back(make_box(box));
  }
  return WorldMap(
    root["ground"]["z"].as<double>(), root["ground"]["intensity"].as<float>(),
    std::move(obstacles));
}

WorldMap::WorldMap(double ground_z, float ground_intensity, std::vector<Obstacle> obstacles)
: ground_z_(ground_z), ground_intensity_(ground_intensity), obstacles_(std::move(obstacles))
{
}

bool WorldMap::hit_obstacle(
  const Obstacle & box, const Eigen::Vector3d & origin, const Eigen::Vector3d & direction,
  double & range) const
{
  const double dx = origin.x() - box.center.x();
  const double dy = origin.y() - box.center.y();
  const double ox = box.cos_yaw * dx + box.sin_yaw * dy;
  const double oy = -box.sin_yaw * dx + box.cos_yaw * dy;
  const double vx = box.cos_yaw * direction.x() + box.sin_yaw * direction.y();
  const double vy = -box.sin_yaw * direction.x() + box.cos_yaw * direction.y();

  double near = 0.0;
  double far = std::numeric_limits<double>::infinity();
  clip_slab(ox, vx, -box.half_size.x(), box.half_size.x(), near, far);
  clip_slab(oy, vy, -box.half_size.y(), box.half_size.y(), near, far);
  clip_slab(origin.z(), direction.z(), ground_z_, ground_z_ + box.height, near, far);
  if (near > far) {
    return false;
  }
  range = near;
  return true;
}

bool WorldMap::raycast(
  const Eigen::Vector3d & origin, const Eigen::Vector3d & direction, double max_range,
  RayHit & hit) const
{
  hit.range = max_range;
  bool found = false;
  if (direction.z() < 0.0) {
    const double range = (ground_z_ - origin.z()) / direction.z();
    if (range <= hit.range) {
      hit = {range, ground_intensity_};
      found = true;
    }
  }
  for (const auto & box : obstacles_) {
    double range = 0.0;
    if (hit_obstacle(box, origin, direction, range) && range <= hit.range) {
      hit = {range, box.intensity};
      found = true;
    }
  }
  return found;
}

}  // namespace sensor_dummy
