#include "test_pattern.hpp"

#include <gtest/gtest.h>

#include <cstring>
#include <vector>

namespace sensor_dummy
{
namespace
{
TEST(TestPatternTest, SizesFollowTheEncoding)
{
  std::vector<std::uint8_t> data;
  TestPattern rgb(64, 48, "rgb8", 3.0, 1.5);
  rgb.render(0, data);
  EXPECT_EQ(rgb.step(), 192u);
  EXPECT_EQ(data.size(), 192u * 48u);
  TestPattern bgra(64, 48, "bgra8", 3.0, 1.5);
  EXPECT_EQ(bgra.step(), 256u);
  TestPattern depth16(64, 48, "16UC1", 3.0, 1.5);
  EXPECT_EQ(depth16.step(), 128u);
}

TEST(TestPatternTest, FramesDiffer)
{
  std::vector<std::uint8_t> first;
  std::vector<std::uint8_t> second;
  TestPattern pattern(64, 48, "bgra8", 3.0, 1.5);
  pattern.render(0, first);
  pattern.render(1, second);
  EXPECT_NE(first, second);
}

TEST(TestPatternTest, Depth16IsInMillimeters)
{
  std::vector<std::uint8_t> data;
  TestPattern pattern(640, 8, "16UC1", 3.0, 1.5);
  pattern.render(0, data);
  std::uint16_t bar = 0;
  std::uint16_t plane = 0;
  std::memcpy(&bar, data.data(), sizeof(bar));
  std::memcpy(&plane, data.data() + 400 * sizeof(plane), sizeof(plane));
  EXPECT_EQ(bar, 1500);
  EXPECT_EQ(plane, 3000);
}

TEST(TestPatternTest, Depth32IsInMeters)
{
  std::vector<std::uint8_t> data;
  TestPattern pattern(640, 8, "32FC1", 3.0, 1.5);
  pattern.render(0, data);
  float plane = 0.0f;
  std::memcpy(&plane, data.data() + 400 * sizeof(plane), sizeof(plane));
  EXPECT_FLOAT_EQ(plane, 3.0f);
}

TEST(TestPatternTest, RejectsUnknownEncoding)
{
  EXPECT_THROW(TestPattern(64, 48, "yuv422", 3.0, 1.5), std::invalid_argument);
}

}  // namespace
}  // namespace sensor_dummy
