#include "fault.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <limits>
#include <vector>

namespace sensor_dummy
{
namespace
{
struct Sample
{
  struct
  {
    std::int64_t stamp;
  } header;
  double value;
};

void poison(Sample & sample)
{
  sample.value = std::numeric_limits<double>::quiet_NaN();
}

class FaultFilterTest : public ::testing::Test
{
protected:
  void push(double value, std::int64_t now)
  {
    Sample sample{{now}, value};
    filter.push(sample, now);
  }

  FaultSpec spec{FaultMode::None, 0.0};
  std::vector<Sample> received;
  FaultFilter<Sample> filter{spec, [this](const Sample & s) { received.push_back(s); }};
};

TEST_F(FaultFilterTest, PassesThroughWithoutFault)
{
  push(1.0, 10);
  ASSERT_EQ(received.size(), 1u);
  EXPECT_DOUBLE_EQ(received[0].value, 1.0);
}

TEST_F(FaultFilterTest, DropoutPublishesNothing)
{
  spec.mode = FaultMode::Dropout;
  push(1.0, 10);
  EXPECT_TRUE(received.empty());
}

TEST_F(FaultFilterTest, NanPoisonsPayload)
{
  spec.mode = FaultMode::Nan;
  push(1.0, 10);
  ASSERT_EQ(received.size(), 1u);
  EXPECT_TRUE(std::isnan(received[0].value));
}

TEST_F(FaultFilterTest, FreezeKeepsPayloadAndTakesLiveStamp)
{
  spec.mode = FaultMode::Freeze;
  push(1.0, 10);
  push(2.0, 20);
  ASSERT_EQ(received.size(), 2u);
  EXPECT_DOUBLE_EQ(received[1].value, 1.0);
  EXPECT_EQ(received[1].header.stamp, 20);
}

TEST_F(FaultFilterTest, LatencyHoldsUntilDueAndKeepsOriginalStamp)
{
  spec.mode = FaultMode::Latency;
  spec.latency_s = 1e-6;
  push(1.0, 100);
  filter.flush(1099);
  EXPECT_TRUE(received.empty());
  filter.flush(1100);
  ASSERT_EQ(received.size(), 1u);
  EXPECT_EQ(received[0].header.stamp, 100);
}

TEST(FaultModeTest, RejectsUnknownName)
{
  EXPECT_EQ(parse_fault_mode("freeze"), FaultMode::Freeze);
  EXPECT_THROW(parse_fault_mode("bogus"), std::invalid_argument);
}

}  // namespace
}  // namespace sensor_dummy
