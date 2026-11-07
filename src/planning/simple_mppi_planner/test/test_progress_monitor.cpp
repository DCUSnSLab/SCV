#include "progress_monitor.hpp"

#include <gtest/gtest.h>

namespace simple_mppi_planner
{
namespace
{

TEST(ProgressMonitor, IsNotStuckBeforeTheWindowHasPassed)
{
  ProgressMonitor monitor(0.3, 5.0);
  EXPECT_FALSE(monitor.update(0.0, 2.0));
  EXPECT_FALSE(monitor.update(4.9, 2.0));
}

TEST(ProgressMonitor, IsStuckAfterAWindowWithoutProgress)
{
  ProgressMonitor monitor(0.3, 5.0);
  monitor.update(0.0, 2.0);
  EXPECT_TRUE(monitor.update(5.0, 2.2));
}

TEST(ProgressMonitor, ProgressRestartsTheWindowAndEndsTheStuckState)
{
  ProgressMonitor monitor(0.3, 5.0);
  monitor.update(0.0, 2.0);
  ASSERT_TRUE(monitor.update(6.0, 2.0));
  EXPECT_FALSE(monitor.update(6.1, 2.4));
  EXPECT_FALSE(monitor.update(11.0, 2.4));
  EXPECT_TRUE(monitor.update(11.1, 2.4));
}

TEST(ProgressMonitor, SlowCreepBelowTheThresholdStillAddsUp)
{
  ProgressMonitor monitor(0.3, 5.0);
  monitor.update(0.0, 0.0);
  for (int i = 1; i <= 100; ++i) {
    EXPECT_FALSE(monitor.update(i * 0.1, i * 0.1));
  }
}

TEST(ProgressMonitor, ResetForgetsTheWindow)
{
  ProgressMonitor monitor(0.3, 5.0);
  monitor.update(0.0, 2.0);
  monitor.reset();
  EXPECT_FALSE(monitor.update(10.0, 2.0));
}

}  // namespace
}  // namespace simple_mppi_planner
