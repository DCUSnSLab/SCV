#ifndef FAULT_HPP_
#define FAULT_HPP_

#include <cstdint>
#include <deque>
#include <functional>
#include <optional>
#include <string>
#include <utility>

namespace sensor_dummy
{

enum class FaultMode { None, Dropout, Latency, Nan, Freeze };

FaultMode parse_fault_mode(const std::string & name);

struct FaultSpec
{
  FaultMode mode;
  double latency_s;
};

template <class Msg>
void copy_stamp(Msg & to, const Msg & from)
{
  if constexpr (requires { to.header.stamp; }) {
    to.header.stamp = from.header.stamp;
  }
}

// Sits between a sensor model and its publisher. poison(Msg &) is found by ADL. A frozen message
// keeps its payload and takes the live stamp, as a stuck sensor behind a healthy driver would.
template <class Msg>
class FaultFilter
{
public:
  using Sink = std::function<void(const Msg &)>;

  FaultFilter(const FaultSpec & spec, Sink sink) : spec_(spec), sink_(std::move(sink)) {}

  void push(Msg & msg, std::int64_t now_ns)
  {
    if (spec_.mode != FaultMode::Freeze) {
      frozen_.reset();
    }
    switch (spec_.mode) {
      case FaultMode::None:
        sink_(msg);
        break;
      case FaultMode::Dropout:
        break;
      case FaultMode::Latency:
        delayed_.emplace_back(now_ns + static_cast<std::int64_t>(spec_.latency_s * 1e9), msg);
        break;
      case FaultMode::Nan:
        poison(msg);
        sink_(msg);
        break;
      case FaultMode::Freeze:
        if (!frozen_) {
          frozen_ = msg;
        }
        copy_stamp(*frozen_, msg);
        sink_(*frozen_);
        break;
    }
  }

  void flush(std::int64_t now_ns)
  {
    while (!delayed_.empty() && delayed_.front().first <= now_ns) {
      sink_(delayed_.front().second);
      delayed_.pop_front();
    }
  }

private:
  const FaultSpec & spec_;
  Sink sink_;
  std::deque<std::pair<std::int64_t, Msg>> delayed_;
  std::optional<Msg> frozen_;
};

}  // namespace sensor_dummy

#endif  // FAULT_HPP_
