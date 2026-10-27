#include "loam_fgo_localization/global_localization/se2_branch_and_bound.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <utility>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

namespace loam_fgo_localization
{
namespace
{

constexpr double kPi = 3.14159265358979323846;

struct DiscretePoint
{
  int x{0};
  int y{0};
};

struct Candidate
{
  int scan_index{0};
  int x{0};
  int y{0};
  float score{0.0f};
};

bool higherScore(const Candidate & lhs, const Candidate & rhs)
{
  return lhs.score > rhs.score;
}

class SlidingMaximumGrid
{
public:
  SlidingMaximumGrid(const cv::Mat1f & base, int width)
  : padding_(width - 1)
  {
    if (width <= 0) {
      throw std::invalid_argument("precomputation width must be positive");
    }
    cv::Mat1f padded = cv::Mat1f::zeros(
      base.rows + 2 * padding_, base.cols + 2 * padding_);
    base.copyTo(padded(cv::Rect(padding_, padding_, base.cols, base.rows)));
    if (width == 1) {
      values_ = std::move(padded);
      return;
    }
    const cv::Mat kernel = cv::getStructuringElement(
      cv::MORPH_RECT, cv::Size(width, width));
    cv::dilate(
      padded, values_, kernel, cv::Point(0, 0), 1,
      cv::BORDER_CONSTANT, cv::Scalar(0.0f));
  }

  float value(int x, int y) const
  {
    const int padded_x = x + padding_;
    const int padded_y = y + padding_;
    if (padded_x < 0 || padded_y < 0 ||
      padded_x >= values_.cols || padded_y >= values_.rows)
    {
      return 0.0f;
    }
    return values_(padded_y, padded_x);
  }

private:
  int padding_{0};
  cv::Mat1f values_;
};

}  // namespace

class Se2BranchAndBoundMatcher::Impl
{
public:
  explicit Impl(const Se2BranchAndBoundOptions & options)
  : options_(options)
  {
    validateOptions();
  }

  void setMap(const std::vector<Se2Point> & map_points)
  {
    if (map_points.empty()) {
      throw std::invalid_argument("SE(2) BBS map must not be empty");
    }

    double min_x = std::numeric_limits<double>::infinity();
    double min_y = std::numeric_limits<double>::infinity();
    double max_x = -std::numeric_limits<double>::infinity();
    double max_y = -std::numeric_limits<double>::infinity();
    for (const auto & point : map_points) {
      if (!std::isfinite(point.x) || !std::isfinite(point.y)) {
        continue;
      }
      min_x = std::min(min_x, point.x);
      min_y = std::min(min_y, point.y);
      max_x = std::max(max_x, point.x);
      max_y = std::max(max_y, point.y);
    }
    if (!std::isfinite(min_x) || !std::isfinite(min_y)) {
      throw std::invalid_argument("SE(2) BBS map has no finite points");
    }

    origin_x_ = min_x - options_.map_padding_m;
    origin_y_ = min_y - options_.map_padding_m;
    width_ = static_cast<int>(
      std::ceil(
        (max_x - min_x + 2.0 * options_.map_padding_m) /
        options_.resolution_m)) + 1;
    height_ = static_cast<int>(
      std::ceil(
        (max_y - min_y + 2.0 * options_.map_padding_m) /
        options_.resolution_m)) + 1;
    if (width_ <= 0 || height_ <= 0 ||
      static_cast<std::uint64_t>(width_) * static_cast<std::uint64_t>(height_) >
      100000000ULL)
    {
      throw std::runtime_error("SE(2) BBS map grid dimensions are invalid or too large");
    }

    cv::Mat1b distance_input(height_, width_, static_cast<unsigned char>(255));
    std::size_t inserted = 0;
    for (const auto & point : map_points) {
      if (!std::isfinite(point.x) || !std::isfinite(point.y)) {
        continue;
      }
      const int x = worldToGridX(point.x);
      const int y = worldToGridY(point.y);
      if (x >= 0 && x < width_ && y >= 0 && y < height_) {
        distance_input(y, x) = 0;
        ++inserted;
      }
    }
    if (inserted == 0) {
      throw std::runtime_error("SE(2) BBS map rasterization produced no occupied cells");
    }

    cv::Mat1f distances;
    cv::distanceTransform(distance_input, distances, cv::DIST_L2, cv::DIST_MASK_PRECISE);
    cv::Mat1f likelihood(height_, width_, 0.0f);
    const double sigma2 = options_.score_sigma_m * options_.score_sigma_m;
    for (int y = 0; y < height_; ++y) {
      for (int x = 0; x < width_; ++x) {
        const double distance_m = distances(y, x) * options_.resolution_m;
        if (distance_m <= options_.score_cutoff_m) {
          likelihood(y, x) = static_cast<float>(
            std::exp(-0.5 * distance_m * distance_m / sigma2));
        }
      }
    }

    max_grids_.clear();
    max_grids_.reserve(options_.branch_and_bound_depth);
    for (int level = 0; level < options_.branch_and_bound_depth; ++level) {
      max_grids_.emplace_back(likelihood, 1 << level);
    }
    ready_ = true;
  }

  bool ready() const
  {
    return ready_;
  }

  Se2BranchAndBoundResult match(
    const std::vector<Se2Point> & input_scan,
    const Se2SearchWindow * search_window) const
  {
    if (!ready_) {
      throw std::logic_error("SE(2) BBS match requested before setting a map");
    }

    Se2BranchAndBoundResult result;
    const std::vector<Se2Point> scan = filteredScan(input_scan);
    result.scan_points = scan.size();
    if (scan.empty()) {
      return result;
    }

    int min_x = 0;
    int min_y = 0;
    int max_x = width_ - 1;
    int max_y = height_ - 1;
    if (search_window != nullptr) {
      if (!std::isfinite(search_window->center_x) ||
        !std::isfinite(search_window->center_y) ||
        !std::isfinite(search_window->radius_m) || search_window->radius_m < 0.0 ||
        !std::isfinite(search_window->center_yaw_rad) ||
        !std::isfinite(search_window->yaw_half_range_rad) ||
        search_window->yaw_half_range_rad < 0.0 ||
        search_window->yaw_half_range_rad > kPi)
      {
        throw std::invalid_argument("invalid SE(2) search window");
      }
      min_x = std::max(
        0, static_cast<int>(std::ceil(
          (search_window->center_x - search_window->radius_m - origin_x_) /
          options_.resolution_m)));
      min_y = std::max(
        0, static_cast<int>(std::ceil(
          (search_window->center_y - search_window->radius_m - origin_y_) /
          options_.resolution_m)));
      max_x = std::min(
        width_ - 1, static_cast<int>(std::floor(
          (search_window->center_x + search_window->radius_m - origin_x_) /
          options_.resolution_m)));
      max_y = std::min(
        height_ - 1, static_cast<int>(std::floor(
          (search_window->center_y + search_window->radius_m - origin_y_) /
          options_.resolution_m)));
      if (min_x > max_x || min_y > max_y) {
        return result;
      }
    }

    std::vector<double> yaw_values;
    if (search_window == nullptr || search_window->yaw_half_range_rad >= kPi) {
      const int yaw_count = std::max(
        1, static_cast<int>(std::ceil(2.0 * kPi / options_.yaw_step_rad)));
      const double yaw_step = 2.0 * kPi / static_cast<double>(yaw_count);
      yaw_values.reserve(yaw_count);
      for (int yaw_index = 0; yaw_index < yaw_count; ++yaw_index) {
        yaw_values.push_back(-kPi + static_cast<double>(yaw_index) * yaw_step);
      }
    } else if (search_window->yaw_half_range_rad == 0.0) {
      yaw_values.push_back(normalizeAngle(search_window->center_yaw_rad));
    } else {
      const int interval_count = std::max(
        1, static_cast<int>(std::ceil(
          2.0 * search_window->yaw_half_range_rad / options_.yaw_step_rad)));
      const double yaw_step =
        2.0 * search_window->yaw_half_range_rad / static_cast<double>(interval_count);
      yaw_values.reserve(interval_count + 1);
      for (int yaw_index = 0; yaw_index <= interval_count; ++yaw_index) {
        yaw_values.push_back(
          normalizeAngle(
            search_window->center_yaw_rad - search_window->yaw_half_range_rad +
            static_cast<double>(yaw_index) * yaw_step));
      }
    }

    const int yaw_count = static_cast<int>(yaw_values.size());
    std::vector<std::vector<DiscretePoint>> discrete_scans;
    discrete_scans.reserve(yaw_count);
    for (int yaw_index = 0; yaw_index < yaw_count; ++yaw_index) {
      const double yaw = yaw_values[yaw_index];
      const double cos_yaw = std::cos(yaw);
      const double sin_yaw = std::sin(yaw);
      std::vector<DiscretePoint> rotated;
      rotated.reserve(scan.size());
      for (const auto & point : scan) {
        rotated.push_back(
          {
            static_cast<int>(std::lround(
              (cos_yaw * point.x - sin_yaw * point.y) / options_.resolution_m)),
            static_cast<int>(std::lround(
              (sin_yaw * point.x + cos_yaw * point.y) / options_.resolution_m))});
      }
      discrete_scans.push_back(std::move(rotated));
    }

    std::uint64_t translation_leaf_count = 0;
    if (search_window == nullptr) {
      translation_leaf_count =
        static_cast<std::uint64_t>(max_x - min_x + 1) *
        static_cast<std::uint64_t>(max_y - min_y + 1);
    } else {
      for (int x = min_x; x <= max_x; ++x) {
        for (int y = min_y; y <= max_y; ++y) {
          if (nodeIntersectsCircle(x, y, 0, *search_window, max_x, max_y)) {
            ++translation_leaf_count;
          }
        }
      }
    }
    result.exhaustive_leaf_count =
      static_cast<std::uint64_t>(yaw_count) * translation_leaf_count;
    const int max_level = options_.branch_and_bound_depth - 1;
    const int root_step = 1 << max_level;
    // 시간 예산: 열화 환경에서 가지치기가 실패하면 준-전수 탐색이 되므로
    // 상한 초과 시 best-so-far 로 중단한다 (호출자는 투표로 일관성을 재확인).
    const bool deadline_enabled = options_.max_match_seconds > 0.0;
    const auto deadline = std::chrono::steady_clock::now() +
      std::chrono::duration_cast<std::chrono::steady_clock::duration>(
      std::chrono::duration<double>(options_.max_match_seconds));
    bool timed_out = false;
    std::vector<Candidate> roots;
    const std::size_t roots_per_scan =
      static_cast<std::size_t>((max_x - min_x + root_step) / root_step) *
      static_cast<std::size_t>((max_y - min_y + root_step) / root_step);
    roots.reserve(roots_per_scan * discrete_scans.size());
    for (int scan_index = 0; scan_index < yaw_count && !timed_out; ++scan_index) {
      for (int x = min_x; x <= max_x && !timed_out; x += root_step) {
        for (int y = min_y; y <= max_y; y += root_step) {
          if (deadline_enabled && (roots.size() & 0x3F) == 0 &&
            std::chrono::steady_clock::now() >= deadline)
          {
            timed_out = true;
            break;
          }
          if (search_window != nullptr &&
            !nodeIntersectsCircle(x, y, max_level, *search_window, max_x, max_y))
          {
            continue;
          }
          Candidate candidate;
          candidate.scan_index = scan_index;
          candidate.x = x;
          candidate.y = y;
          candidate.score = scoreCandidate(
            discrete_scans[scan_index], candidate, max_level, result);
          roots.push_back(candidate);
        }
      }
    }
    std::sort(roots.begin(), roots.end(), higherScore);
    result.timed_out = timed_out;
    if (roots.empty()) {
      return result;
    }
    result.score = roots.front().score;

    Candidate best;
    best.score = static_cast<float>(options_.min_score);
    for (const auto & root : roots) {
      if (timed_out || root.score <= best.score) {
        break;
      }
      branchAndBound(
        discrete_scans, root, max_level, min_x, max_x, min_y, max_y,
        search_window, deadline_enabled, deadline, timed_out, best, result);
    }
    result.timed_out = timed_out;
    if (best.score <= options_.min_score) {
      return result;
    }

    result.found = true;
    result.score = best.score;
    result.x = origin_x_ + static_cast<double>(best.x) * options_.resolution_m;
    result.y = origin_y_ + static_cast<double>(best.y) * options_.resolution_m;
    result.yaw = yaw_values[best.scan_index];
    return result;
  }

private:
  static double normalizeAngle(double angle)
  {
    return std::atan2(std::sin(angle), std::cos(angle));
  }

  bool nodeIntersectsCircle(
    int x, int y, int level, const Se2SearchWindow & search_window,
    int max_x, int max_y) const
  {
    const int width = (1 << level) - 1;
    const double box_min_x = origin_x_ + static_cast<double>(x) * options_.resolution_m;
    const double box_min_y = origin_y_ + static_cast<double>(y) * options_.resolution_m;
    const double box_max_x = origin_x_ +
      static_cast<double>(std::min(x + width, max_x)) * options_.resolution_m;
    const double box_max_y = origin_y_ +
      static_cast<double>(std::min(y + width, max_y)) * options_.resolution_m;
    const double nearest_x = std::clamp(search_window.center_x, box_min_x, box_max_x);
    const double nearest_y = std::clamp(search_window.center_y, box_min_y, box_max_y);
    const double dx = nearest_x - search_window.center_x;
    const double dy = nearest_y - search_window.center_y;
    return dx * dx + dy * dy <= search_window.radius_m * search_window.radius_m;
  }

  void validateOptions() const
  {
    if (!(options_.resolution_m > 0.0) || !(options_.score_sigma_m > 0.0) ||
      !(options_.score_cutoff_m > 0.0) || options_.map_padding_m < 0.0 ||
      !(options_.yaw_step_rad > 0.0) || options_.yaw_step_rad > 2.0 * kPi ||
      options_.branch_and_bound_depth < 1 || options_.branch_and_bound_depth > 12 ||
      options_.min_score < 0.0 || options_.min_score >= 1.0 ||
      options_.min_scan_range_m < 0.0 ||
      options_.max_scan_range_m <= options_.min_scan_range_m ||
      options_.max_scan_points <= 0 || options_.max_match_seconds < 0.0)
    {
      throw std::invalid_argument("invalid SE(2) branch-and-bound options");
    }
  }

  int worldToGridX(double x) const
  {
    return static_cast<int>(std::lround((x - origin_x_) / options_.resolution_m));
  }

  int worldToGridY(double y) const
  {
    return static_cast<int>(std::lround((y - origin_y_) / options_.resolution_m));
  }

  std::vector<Se2Point> filteredScan(const std::vector<Se2Point> & input) const
  {
    std::vector<Se2Point> in_range;
    in_range.reserve(input.size());
    const double min_range2 = options_.min_scan_range_m * options_.min_scan_range_m;
    const double max_range2 = options_.max_scan_range_m * options_.max_scan_range_m;
    for (const auto & point : input) {
      const double range2 = point.x * point.x + point.y * point.y;
      if (std::isfinite(range2) && range2 >= min_range2 && range2 <= max_range2) {
        in_range.push_back(point);
      }
    }
    if (static_cast<int>(in_range.size()) <= options_.max_scan_points) {
      return in_range;
    }

    std::vector<Se2Point> sampled;
    sampled.reserve(options_.max_scan_points);
    for (int i = 0; i < options_.max_scan_points; ++i) {
      const std::size_t index = static_cast<std::size_t>(
        static_cast<double>(i) * static_cast<double>(in_range.size()) /
        static_cast<double>(options_.max_scan_points));
      sampled.push_back(in_range[std::min(index, in_range.size() - 1)]);
    }
    return sampled;
  }

  float scoreCandidate(
    const std::vector<DiscretePoint> & scan, const Candidate & candidate,
    int level, Se2BranchAndBoundResult & result) const
  {
    double sum = 0.0;
    const auto & grid = max_grids_[level];
    for (const auto & point : scan) {
      sum += grid.value(point.x + candidate.x, point.y + candidate.y);
    }
    ++result.scored_nodes;
    if (level == 0) {
      ++result.leaf_nodes;
    }
    return static_cast<float>(sum / static_cast<double>(scan.size()));
  }

  void branchAndBound(
    const std::vector<std::vector<DiscretePoint>> & scans,
    const Candidate & candidate, int level,
    int min_x, int max_x, int min_y, int max_y,
    const Se2SearchWindow * search_window,
    bool deadline_enabled, std::chrono::steady_clock::time_point deadline,
    bool & timed_out, Candidate & best,
    Se2BranchAndBoundResult & result) const
  {
    if (timed_out) {
      return;
    }
    if (deadline_enabled && (result.scored_nodes & 0x1FF) == 0 &&
      std::chrono::steady_clock::now() >= deadline)
    {
      timed_out = true;
      return;
    }
    if (candidate.score <= best.score) {
      return;
    }
    if (level == 0) {
      best = candidate;
      return;
    }

    const int half_width = 1 << (level - 1);
    std::vector<Candidate> children;
    children.reserve(4);
    for (const int dx : {0, half_width}) {
      const int x = candidate.x + dx;
      if (x < min_x || x > max_x) {
        continue;
      }
      for (const int dy : {0, half_width}) {
        const int y = candidate.y + dy;
        if (y < min_y || y > max_y) {
          continue;
        }
        if (search_window != nullptr &&
          !nodeIntersectsCircle(x, y, level - 1, *search_window, max_x, max_y))
        {
          continue;
        }
        Candidate child;
        child.scan_index = candidate.scan_index;
        child.x = x;
        child.y = y;
        child.score = scoreCandidate(scans[child.scan_index], child, level - 1, result);
        children.push_back(child);
      }
    }
    std::sort(children.begin(), children.end(), higherScore);
    for (const auto & child : children) {
      if (timed_out || child.score <= best.score) {
        break;
      }
      branchAndBound(
        scans, child, level - 1, min_x, max_x, min_y, max_y,
        search_window, deadline_enabled, deadline, timed_out, best, result);
    }
  }

  Se2BranchAndBoundOptions options_;
  double origin_x_{0.0};
  double origin_y_{0.0};
  int width_{0};
  int height_{0};
  bool ready_{false};
  std::vector<SlidingMaximumGrid> max_grids_;
};

Se2BranchAndBoundMatcher::Se2BranchAndBoundMatcher(
  const Se2BranchAndBoundOptions & options)
: impl_(new Impl(options))
{
}

Se2BranchAndBoundMatcher::~Se2BranchAndBoundMatcher() = default;

void Se2BranchAndBoundMatcher::setMap(const std::vector<Se2Point> & map_points)
{
  impl_->setMap(map_points);
}

bool Se2BranchAndBoundMatcher::ready() const
{
  return impl_->ready();
}

Se2BranchAndBoundResult Se2BranchAndBoundMatcher::match(
  const std::vector<Se2Point> & scan_points) const
{
  return impl_->match(scan_points, nullptr);
}

Se2BranchAndBoundResult Se2BranchAndBoundMatcher::match(
  const std::vector<Se2Point> & scan_points,
  const Se2SearchWindow & search_window) const
{
  return impl_->match(scan_points, &search_window);
}

}  // namespace loam_fgo_localization
