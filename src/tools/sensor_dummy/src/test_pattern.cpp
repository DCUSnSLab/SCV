#include "test_pattern.hpp"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

namespace sensor_dummy
{
namespace
{
constexpr std::size_t kBarWidth = 32;
constexpr std::size_t kBarSpeed = 8;

std::size_t pixel_size_of(const std::string & encoding)
{
  if (encoding == "rgb8" || encoding == "bgr8") {
    return 3;
  }
  if (encoding == "bgra8" || encoding == "32FC1") {
    return 4;
  }
  if (encoding == "16UC1") {
    return 2;
  }
  throw std::invalid_argument("unsupported encoding: " + encoding);
}
}  // namespace

TestPattern::TestPattern(
  int width, int height, const std::string & encoding, double plane_m, double bar_m)
: width_(width), height_(height), pixel_size_(pixel_size_of(encoding))
{
  background_.resize(width_ * height_ * pixel_size_);
  bar_pixel_.assign(pixel_size_, 255);
  if (encoding == "16UC1" || encoding == "32FC1") {
    std::vector<std::uint8_t> plane(pixel_size_);
    if (encoding == "16UC1") {
      const auto plane_mm = static_cast<std::uint16_t>(plane_m * 1000.0);
      const auto bar_mm = static_cast<std::uint16_t>(bar_m * 1000.0);
      std::memcpy(plane.data(), &plane_mm, sizeof(plane_mm));
      std::memcpy(bar_pixel_.data(), &bar_mm, sizeof(bar_mm));
    } else {
      const auto plane_f = static_cast<float>(plane_m);
      const auto bar_f = static_cast<float>(bar_m);
      std::memcpy(plane.data(), &plane_f, sizeof(plane_f));
      std::memcpy(bar_pixel_.data(), &bar_f, sizeof(bar_f));
    }
    fill_pixel_row(width_ * height_, plane.data(), background_.data());
  } else {
    fill_color_background();
  }
}

void TestPattern::fill_color_background()
{
  for (std::size_t row = 0; row < height_; ++row) {
    for (std::size_t col = 0; col < width_; ++col) {
      std::uint8_t * pixel = &background_[(row * width_ + col) * pixel_size_];
      pixel[0] = static_cast<std::uint8_t>(255 * col / width_);
      pixel[1] = static_cast<std::uint8_t>(255 * row / height_);
      pixel[2] = 96;
      if (pixel_size_ == 4) {
        pixel[3] = 255;
      }
    }
  }
}

void TestPattern::fill_pixel_row(
  std::size_t pixels, const std::uint8_t * pixel, std::uint8_t * out) const
{
  for (std::size_t i = 0; i < pixels; ++i) {
    std::memcpy(out + i * pixel_size_, pixel, pixel_size_);
  }
}

void TestPattern::render(std::uint64_t seq, std::vector<std::uint8_t> & data) const
{
  data.assign(background_.begin(), background_.end());
  const std::size_t bar = std::min(kBarWidth, width_);
  const std::size_t start = (seq * kBarSpeed) % (width_ - bar + 1);
  for (std::size_t row = 0; row < height_; ++row) {
    fill_pixel_row(bar, bar_pixel_.data(), &data[(row * width_ + start) * pixel_size_]);
  }
}

}  // namespace sensor_dummy
