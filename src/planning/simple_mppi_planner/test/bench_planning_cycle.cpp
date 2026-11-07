// Time of one DistanceMap::build and one MppiSolver::solve on a scene with obstacles.
//     taskset -c <core> bench_planning_cycle <ackermann|diff> <threads> [samples]

#include "mppi_solver.hpp"
#include "scene.hpp"

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

using simple_mppi_planner::DistanceMap;
using simple_mppi_planner::GridView;
using simple_mppi_planner::MotionModel;
using simple_mppi_planner::MppiSolver;
using simple_mppi_planner::ReferencePath;
using simple_mppi_planner::State;
using Clock = std::chrono::steady_clock;

namespace
{

constexpr int kWarmup = 50;
constexpr int kCycles = 2000;

double milliseconds_since(Clock::time_point start)
{
  return std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void print(const char * name, std::vector<double> times)
{
  std::sort(times.begin(), times.end());
  std::printf(
    "%-12s p50 %.3f ms  p99 %.3f ms  max %.3f ms\n", name, times[times.size() / 2],
    times[times.size() * 99 / 100], times.back());
}

}  // namespace

int main(int argc, char ** argv)
{
  const bool ackermann = std::string(argv[1]) == "ackermann";
  const auto vehicle = ackermann ? simple_mppi_planner::hunter() : simple_mppi_planner::diff_base();
  auto mppi = simple_mppi_planner::mppi_of(vehicle, std::atoi(argv[2]));
  if (argc > 3) {
    mppi.sample_count = std::atoi(argv[3]);
  }
  MppiSolver solver(
    mppi, simple_mppi_planner::cost_params(vehicle), vehicle,
    simple_mppi_planner::footprint_of(vehicle));
  const std::vector<std::pair<double, double>> waypoints{{0.0, 0.0}, {12.0, 0.0}};
  const ReferencePath route(
    waypoints, simple_mppi_planner::kRouteSpacing, simple_mppi_planner::kCruiseSpeed,
    simple_mppi_planner::kStopDecel);

  // The 200 x 200 local grid with obstacles on the path and along both sides.
  std::vector<std::int8_t> cells(40000, 0);
  for (int i = 0; i < 40000; i += 97) {
    cells[i] = 100;
  }
  for (int row = 0; row < 200; ++row) {
    std::fill_n(cells.begin() + row * 200 + 130, row > 90 && row < 110 ? 8 : 0, std::int8_t{100});
  }
  std::fill(cells.begin() + 100 * 200 + 40, cells.begin() + 100 * 200 + 125, std::int8_t{0});
  const GridView grid{cells.data(), 200, 200, 0.1, -5.0, -10.0, 50};

  std::vector<double> build_times;
  DistanceMap map;
  for (int i = 0; i < 500; ++i) {
    const auto start = Clock::now();
    map.build(grid);
    build_times.push_back(milliseconds_since(start));
  }

  State state;
  state.speed = 1.0;
  std::vector<double> solve_times;
  for (int i = 0; i < kWarmup + kCycles; ++i) {
    const auto start = Clock::now();
    solver.solve(state, route, 0, map);
    if (i >= kWarmup) {
      solve_times.push_back(milliseconds_since(start));
    }
  }
  print("grid build", build_times);
  print("solve", solve_times);
  return 0;
}
