#include "savitzky_golay.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <numeric>
#include <random>
#include <vector>

namespace simple_mppi_planner
{
namespace
{

double step_rms(const std::vector<double> & values)
{
  double sum = 0.0;
  for (std::size_t i = 1; i < values.size(); ++i) {
    sum += (values[i] - values[i - 1]) * (values[i] - values[i - 1]);
  }
  return std::sqrt(sum / (values.size() - 1));
}

TEST(SavitzkyGolay, MatchesThePublishedFivePointTable)
{
  const std::vector<double> expected = {-3.0 / 35, 12.0 / 35, 17.0 / 35, 12.0 / 35, -3.0 / 35};
  const std::vector<double> coefficients = SavitzkyGolay(2).coefficients();
  ASSERT_EQ(coefficients.size(), expected.size());
  for (std::size_t i = 0; i < expected.size(); ++i) {
    EXPECT_NEAR(coefficients[i], expected[i], 1e-12);
  }
}

TEST(SavitzkyGolay, CoefficientsSumToOne)
{
  for (const int half_window : {2, 3, 4, 7, 12}) {
    const std::vector<double> c = SavitzkyGolay(half_window).coefficients();
    EXPECT_NEAR(std::accumulate(c.begin(), c.end(), 0.0), 1.0, 1e-12);
  }
}

TEST(SavitzkyGolay, ZeroHalfWindowChangesNothing)
{
  SavitzkyGolay filter(0);
  std::vector<double> values = {1.0, -2.0, 3.0};
  filter.smooth(nullptr, values.data(), 3, 1);
  EXPECT_EQ(values, (std::vector<double>{1.0, -2.0, 3.0}));
}

TEST(SavitzkyGolay, ReproducesACubicThroughPastAndInterior)
{
  const auto cubic = [](int i) { return 0.5 + 0.1 * i - 0.02 * i * i + 0.003 * i * i * i; };
  const int half_window = 3;
  std::vector<double> past;
  for (int i = -half_window; i < 0; ++i) {
    past.push_back(cubic(i));
  }
  std::vector<double> values;
  for (int i = 0; i < 20; ++i) {
    values.push_back(cubic(i));
  }
  SavitzkyGolay filter(half_window);
  filter.smooth(past.data(), values.data(), 20, 1);
  // The last values have repeated samples in their window, which no cubic fit can reproduce.
  for (int i = 0; i < 20 - half_window; ++i) {
    EXPECT_NEAR(values[i], cubic(i), 1e-9);
  }
}

TEST(SavitzkyGolay, ReducesTheJitterOfANoisySignal)
{
  std::mt19937 generator(1);
  std::normal_distribution<double> noise(0.0, 0.1);
  std::vector<double> values;
  for (int i = 0; i < 200; ++i) {
    values.push_back(std::sin(i * 0.05) + noise(generator));
  }
  const double before = step_rms(values);
  const std::vector<double> past(3, values.front());
  SavitzkyGolay filter(3);
  filter.smooth(past.data(), values.data(), 200, 1);
  EXPECT_LT(step_rms(values), 0.5 * before);
}

TEST(SavitzkyGolay, ReadsAndWritesAtTheStrideOnly)
{
  const std::vector<double> past = {1.0, 9.0, 1.0, 9.0, 1.0, 9.0};
  std::vector<double> values = {1.0, 7.0, 1.0, 7.0, 1.0, 7.0, 1.0, 7.0};
  SavitzkyGolay filter(3);
  filter.smooth(past.data(), values.data(), 4, 2);
  for (std::size_t i = 0; i < values.size(); i += 2) {
    EXPECT_NEAR(values[i], 1.0, 1e-12);
    EXPECT_EQ(values[i + 1], 7.0);
  }
}

}  // namespace
}  // namespace simple_mppi_planner
