#ifndef SAVITZKY_GOLAY_HPP_
#define SAVITZKY_GOLAY_HPP_

#include <vector>

namespace simple_mppi_planner
{

// Savitzky and Golay, 1964: the center of a cubic fit over 2 * half_window + 1 samples.
class SavitzkyGolay
{
public:
  explicit SavitzkyGolay(int half_window);

  int half_window() const { return half_window_; }
  const std::vector<double> & coefficients() const { return coefficients_; }

  // In place, on count values stride apart. past holds half_window values, oldest first, at the
  // same stride, so the first value has a centered window; the last value repeats past the end.
  void smooth(const double * past, double * values, int count, int stride);

private:
  int half_window_;
  std::vector<double> coefficients_;
  std::vector<double> padded_;
};

}  // namespace simple_mppi_planner

#endif  // SAVITZKY_GOLAY_HPP_
