#ifndef TEST_PATTERN_HPP_
#define TEST_PATTERN_HPP_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace sensor_dummy
{

// A fixed background with one vertical bar that moves with seq, so that consumers can tell a live
// stream from a frozen one. Depth encodings show a plane with the bar nearer.
class TestPattern
{
public:
  TestPattern(int width, int height, const std::string & encoding, double plane_m, double bar_m);

  std::size_t step() const { return width_ * pixel_size_; }
  void render(std::uint64_t seq, std::vector<std::uint8_t> & data) const;

private:
  void fill_color_background();
  void fill_pixel_row(std::size_t pixels, const std::uint8_t * pixel, std::uint8_t * out) const;

  std::size_t width_;
  std::size_t height_;
  std::size_t pixel_size_;
  std::vector<std::uint8_t> background_;
  std::vector<std::uint8_t> bar_pixel_;
};

}  // namespace sensor_dummy

#endif  // TEST_PATTERN_HPP_
