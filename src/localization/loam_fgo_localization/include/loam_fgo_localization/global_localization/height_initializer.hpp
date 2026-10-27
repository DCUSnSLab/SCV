#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <limits>
#include <optional>

#include <Eigen/Geometry>

namespace loam_fgo_localization
{
struct HeightSearchParams
{
  double step{0.25};
  double score_sigma{0.75};
  double score_cutoff{2.25};
  double prior_half_range{4.0};
};

struct HeightSearchResult
{
  bool found{false};
  double z{0.0};
  double score{0.0};
  double lower{0.0};
  double upper{0.0};
  std::size_t evaluations{0};
};

inline std::optional<double> mappedPriorHeight(
  const std::optional<Eigen::Affine3f> & map_to_prior,
  const Eigen::Affine3f & scan_prior)
{
  // 앵커가 없으면 odom Z를 map Z로 간주할 수 없다.
  if (!map_to_prior || !map_to_prior->matrix().allFinite() ||
    !scan_prior.matrix().allFinite())
  {
    return std::nullopt;
  }
  const double z = ((*map_to_prior) * scan_prior).translation().z();
  return std::isfinite(z) ? std::optional<double>(z) : std::nullopt;
}

// scan은 roll/pitch/yaw 및 map XY를 적용하되 Z 이동은 0으로 둔 점군이다.
// 지도 표면 높이를 차량 높이로 가정하지 않고, 가능한 Z 이동량을 점수로 비교한다.
template<typename MapCloud, typename ScanCloud, typename Score>
HeightSearchResult searchMapHeight(
  const MapCloud & map, const ScanCloud & scan, const HeightSearchParams & params,
  std::optional<double> map_z_prior, Score score)
{
  HeightSearchResult result;
  if (!(params.step > 0.0) || !(params.score_sigma > 0.0) ||
    !(params.score_cutoff > 0.0) || !(params.prior_half_range >= 0.0) ||
    !std::isfinite(params.step) || !std::isfinite(params.score_sigma) ||
    !std::isfinite(params.score_cutoff) || !std::isfinite(params.prior_half_range))
  {
    return result;
  }
  const double inf = std::numeric_limits<double>::infinity();
  double xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
  double scan_zmin = inf, scan_zmax = -inf;
  for (const auto & p : scan) {
    if (!std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z)) {
      continue;
    }
    xmin = std::min(xmin, static_cast<double>(p.x));
    xmax = std::max(xmax, static_cast<double>(p.x));
    ymin = std::min(ymin, static_cast<double>(p.y));
    ymax = std::max(ymax, static_cast<double>(p.y));
    scan_zmin = std::min(scan_zmin, static_cast<double>(p.z));
    scan_zmax = std::max(scan_zmax, static_cast<double>(p.z));
  }
  if (!std::isfinite(xmin)) {
    return result;
  }
  double map_zmin = inf, map_zmax = -inf;
  for (const auto & p : map) {
    if (std::isfinite(p.x) && std::isfinite(p.y) && std::isfinite(p.z) &&
      p.x >= xmin - params.score_cutoff && p.x <= xmax + params.score_cutoff &&
      p.y >= ymin - params.score_cutoff && p.y <= ymax + params.score_cutoff)
    {
      map_zmin = std::min(map_zmin, static_cast<double>(p.z));
      map_zmax = std::max(map_zmax, static_cast<double>(p.z));
    }
  }
  if (!std::isfinite(map_zmin)) {
    return result;
  }
  result.lower = map_zmin - scan_zmax - params.score_cutoff;
  result.upper = map_zmax - scan_zmin + params.score_cutoff;
  if (!std::isfinite(result.upper - result.lower)) {
    return result;
  }
  auto evaluate = [&](double z) {
      if (!std::isfinite(z) || z < result.lower || z > result.upper) {
        return;
      }
      const double value = score(z);
      ++result.evaluations;
      if (std::isfinite(value) && value > result.score) {
        result.found = true;
        result.z = z;
        result.score = value;
      }
    };
  auto sweep = [&](double lower, double upper, double step) {
      const double steps = std::ceil((upper - lower) / step);
      if (!std::isfinite(steps) || steps >= static_cast<double>(
          std::numeric_limits<std::size_t>::max()))
      {
        return;
      }
      for (std::size_t i = 0; i <= static_cast<std::size_t>(steps); ++i) {
        evaluate(std::min(upper, lower + i * step));
      }
    };

  if (map_z_prior && std::isfinite(*map_z_prior)) {
    evaluate(*map_z_prior);
    const double lower = std::max(result.lower, *map_z_prior - params.prior_half_range);
    const double upper = std::min(result.upper, *map_z_prior + params.prior_half_range);
    if (lower <= upper) {
      sweep(lower, upper, params.step);
    }
  }
  // 평면 odom은 경사의 높이 변화를 놓칠 수 있으므로 앵커가 있어도 지도 후보를 본다.
  const double coarse_step = std::max(params.step, params.score_sigma);
  sweep(result.lower, result.upper, coarse_step);
  if (result.found) {
    const double center = result.z;
    sweep(
      std::max(result.lower, center - coarse_step),
      std::min(result.upper, center + coarse_step), params.step);
  }
  return result;
}
}  // namespace loam_fgo_localization
