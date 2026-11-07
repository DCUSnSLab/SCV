#ifndef PROGRESS_MONITOR_HPP_
#define PROGRESS_MONITOR_HPP_

#include <optional>

namespace simple_mppi_planner
{

// Stuck: the route position gained less than min_progress over window_sec. It only reports; what
// to do about a stuck vehicle is decided outside the planner.
class ProgressMonitor
{
public:
  ProgressMonitor(double min_progress, double window_sec)
  : min_progress_(min_progress), window_sec_(window_sec)
  {
  }

  void reset() { anchor_.reset(); }

  // Returns whether the vehicle is stuck at time_sec, standing at route length arc.
  bool update(double time_sec, double arc)
  {
    if (!anchor_ || arc - anchor_->arc >= min_progress_) {
      anchor_ = Anchor{time_sec, arc};
    }
    return time_sec - anchor_->time_sec >= window_sec_;
  }

private:
  struct Anchor
  {
    double time_sec;
    double arc;
  };

  double min_progress_;
  double window_sec_;
  std::optional<Anchor> anchor_;
};

}  // namespace simple_mppi_planner

#endif  // PROGRESS_MONITOR_HPP_
