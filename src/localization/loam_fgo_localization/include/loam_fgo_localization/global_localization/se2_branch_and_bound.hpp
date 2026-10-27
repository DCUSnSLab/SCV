#ifndef SCV_LOCALIZATION__SE2_BRANCH_AND_BOUND_HPP_
#define SCV_LOCALIZATION__SE2_BRANCH_AND_BOUND_HPP_

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

namespace loam_fgo_localization
{

struct Se2Point
{
  double x{0.0};
  double y{0.0};
};

struct Se2BranchAndBoundOptions
{
  double resolution_m{0.5};
  double score_sigma_m{0.75};
  double score_cutoff_m{2.25};
  double map_padding_m{5.0};
  double yaw_step_rad{0.017453292519943295};
  int branch_and_bound_depth{6};
  double min_score{0.25};
  double min_scan_range_m{2.0};
  double max_scan_range_m{50.0};
  int max_scan_points{300};
  // match() 1회 시간 예산 [s]. 0 = 무제한. 열화 환경(개활지/복도)에서 가지치기가
  // 무력화되면 탐색이 준-전수화돼 수십 초를 넘길 수 있어 상한이 필요하다
  // (2026-08-19 DCU bag: 재초기화 루프가 이것 때문에 분 단위 무음 마비).
  // 예산 초과 시 그때까지의 best 를 반환하고 timed_out 을 표시한다.
  double max_match_seconds{0.0};
};

struct Se2BranchAndBoundResult
{
  bool found{false};
  bool timed_out{false};
  double x{0.0};
  double y{0.0};
  double yaw{0.0};
  double score{0.0};
  std::uint64_t scored_nodes{0};
  std::uint64_t leaf_nodes{0};
  std::uint64_t exhaustive_leaf_count{0};
  std::size_t scan_points{0};
};

struct Se2SearchWindow
{
  double center_x{0.0};
  double center_y{0.0};
  double radius_m{0.0};
  double center_yaw_rad{0.0};
  double yaw_half_range_rad{3.14159265358979323846};
};

// Exact branch-and-bound search over the configured discrete x/y/yaw grid.
// The input scan must already be gravity-aligned; only yaw and planar
// translation are searched here.
class Se2BranchAndBoundMatcher
{
public:
  explicit Se2BranchAndBoundMatcher(const Se2BranchAndBoundOptions & options);
  ~Se2BranchAndBoundMatcher();

  Se2BranchAndBoundMatcher(const Se2BranchAndBoundMatcher &) = delete;
  Se2BranchAndBoundMatcher & operator=(const Se2BranchAndBoundMatcher &) = delete;

  void setMap(const std::vector<Se2Point> & map_points);
  bool ready() const;
  Se2BranchAndBoundResult match(const std::vector<Se2Point> & scan_points) const;
  Se2BranchAndBoundResult match(
    const std::vector<Se2Point> & scan_points,
    const Se2SearchWindow & search_window) const;

private:
  class Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__SE2_BRANCH_AND_BOUND_HPP_
