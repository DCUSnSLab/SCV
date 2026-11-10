#include "tensorrt_common/yolo.hpp"

#include <gtest/gtest.h>

#include <vector>

using tensorrt_common::decode_end2end;
using tensorrt_common::Letterbox;

TEST(Yolo, BoxesMapBackToTheSource)
{
  // A 1280x720 source letterboxed into 640x640: scale 0.5, 140 rows of padding on top.
  Letterbox box;
  box.scale = 0.5;
  box.top = 140;
  box.width = 640;
  box.height = 360;
  const std::vector<float> out = {100, 150, 200, 250, 0.9F, 2,  //
                                  0,   0,   10,  10,  0.1F, 0};
  const auto d = decode_end2end(out.data(), 2, 6, box, 1280, 720, 0.25F);
  ASSERT_EQ(d.size(), 1U);
  EXPECT_FLOAT_EQ(d[0].x1, 200.0F);
  EXPECT_FLOAT_EQ(d[0].y1, 20.0F);
  EXPECT_FLOAT_EQ(d[0].x2, 400.0F);
  EXPECT_FLOAT_EQ(d[0].y2, 220.0F);
  EXPECT_EQ(d[0].class_id, 2);
  EXPECT_EQ(d[0].row, 0U);
}

TEST(Yolo, BoxesInThePaddingAreClamped)
{
  Letterbox box;
  box.scale = 0.5;
  box.top = 140;
  const std::vector<float> out = {0, 100, 700, 600, 0.5F, 0, 7.0F};
  const auto d = decode_end2end(out.data(), 1, 7, box, 1280, 720, 0.25F);
  ASSERT_EQ(d.size(), 1U);
  EXPECT_FLOAT_EQ(d[0].y1, 0.0F);
  EXPECT_FLOAT_EQ(d[0].x2, 1280.0F);
  EXPECT_FLOAT_EQ(d[0].y2, 720.0F);
}

TEST(Yolo, ShortRowsThrow)
{
  const std::vector<float> out(5);
  EXPECT_THROW(decode_end2end(out.data(), 1, 5, Letterbox{}, 1, 1, 0.0F), std::invalid_argument);
}
