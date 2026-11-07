#include "savitzky_golay.hpp"

#include <algorithm>

namespace simple_mppi_planner
{

SavitzkyGolay::SavitzkyGolay(int half_window) : half_window_(half_window)
{
  const double m = half_window;
  const double scale = 3.0 / ((2.0 * m + 3.0) * (2.0 * m + 1.0) * (2.0 * m - 1.0));
  for (int j = -half_window; j <= half_window; ++j) {
    coefficients_.push_back(scale * (3.0 * m * m + 3.0 * m - 1.0 - 5.0 * j * j));
  }
}

void SavitzkyGolay::smooth(const double * past, double * values, int count, int stride)
{
  padded_.resize(2 * half_window_ + count);
  for (int i = 0; i < half_window_; ++i) {
    padded_[i] = past[i * stride];
  }
  for (int i = 0; i < count; ++i) {
    padded_[half_window_ + i] = values[i * stride];
  }
  const double last = padded_[half_window_ + count - 1];
  std::fill(padded_.begin() + half_window_ + count, padded_.end(), last);
  for (int i = 0; i < count; ++i) {
    double sum = 0.0;
    for (std::size_t j = 0; j < coefficients_.size(); ++j) {
      sum += coefficients_[j] * padded_[i + j];
    }
    values[i * stride] = sum;
  }
}

}  // namespace simple_mppi_planner
