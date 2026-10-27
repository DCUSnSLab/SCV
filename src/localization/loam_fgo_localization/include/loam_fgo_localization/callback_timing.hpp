#ifndef SCV_LOCALIZATION__CALLBACK_TIMING_HPP_
#define SCV_LOCALIZATION__CALLBACK_TIMING_HPP_

#include <chrono>
#include <cstdio>
#include <string>

namespace loam_fgo_localization
{

// 콜백 처리시간 집계 -> 주기(기본 2s)마다 한 줄 요약 로그용.
//   사용:  timing_.add(ms);
//         if (timing_.due()) RCLCPP_INFO(get_logger(), "cb %s", timing_.flush("imu").c_str());
class CallbackTiming
{
public:
  explicit CallbackTiming(double period_sec = 2.0)
  : period_(period_sec) {}

  void add(double ms)
  {
    ++n_;
    sum_ += ms;
    if (ms > max_) {max_ = ms;}
  }

  bool due()
  {
    const auto now = std::chrono::steady_clock::now();
    if (start_.time_since_epoch().count() == 0) {
      start_ = now;
      return false;
    }
    return n_ > 0 &&
           std::chrono::duration<double>(now - start_).count() >= period_;
  }

  std::string flush(const char * name)
  {
    char buf[96];
    std::snprintf(
      buf, sizeof(buf), "%s %.2f avg / %.2f max ms (n=%zu)",
      name, n_ > 0 ? sum_ / static_cast<double>(n_) : 0.0, max_, n_);
    start_ = std::chrono::steady_clock::now();
    n_ = 0;
    sum_ = 0.0;
    max_ = 0.0;
    return std::string(buf);
  }

private:
  double period_;
  std::chrono::steady_clock::time_point start_{};
  std::size_t n_{0};
  double sum_{0.0};
  double max_{0.0};
};

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__CALLBACK_TIMING_HPP_
