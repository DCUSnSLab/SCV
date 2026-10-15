// 값 검사 — "들어오긴 하는데 값이 이상한" 경우.
//
// 1단계 StampCheck: 모든 토픽. 직렬화된 바이트 앞부분에서 header stamp만 읽는다 (역직렬화 없음, 메시지당 수십 ns).
//   header가 맨 앞에 있는 메시지인지는 처음 몇 개의 바이트 모양(frame_id 문자열)으로 판단한다.
//   - stamp가 0 / 역행 / 같은 값 반복 / 수신 시각과 차이(지연·시계 어긋남)
// 2단계: 타입별로 역직렬화해 값 확인 — 모두 메시지가 작다.
//   IMU: 전부 0 / NaN·Inf,  GNSS: 위치 공분산(정확도),  TF: NaN·Inf·쿼터니언 크기
//
// 판정은 보고 주기(1초)마다 그 사이에 받은 메시지로 한다. 문제 문구가 하나라도 있으면 상태가 "abnormal".

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <deque>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>
#include <rclcpp/serialization.hpp>
#include <rclcpp/serialized_message.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <tf2_msgs/msg/tf_message.hpp>

namespace value_checks {

struct Thresholds {
  double stamp_delay_max_s = 0.5;     // 수신 시각 - stamp 평균이 이보다 크면 지연
  double stamp_future_max_s = 0.2;    // stamp가 수신 시각보다 이만큼 앞서면 시계 어긋남
  double gnss_max_std_m = 10.0;       // 위치 공분산의 수평 표준편차가 이보다 크면 정확도 낮음

  static Thresholds from_json(const nlohmann::json &j) {
    Thresholds t;
    if (!j.is_object()) return t;
    t.stamp_delay_max_s = j.value("stamp_delay_max_s", t.stamp_delay_max_s);
    t.stamp_future_max_s = j.value("stamp_future_max_s", t.stamp_future_max_s);
    t.gnss_max_std_m = j.value("gnss_max_std_m", t.gnss_max_std_m);
    return t;
  }
};

struct Context {
  double wall = 0.0;
  bool sim_time = false;        // /clock 발행자가 있으면 (bag 재생 등) stamp-수신 시각 비교를 하지 않는다
  size_t publishers = 0;
};

struct Result {
  std::vector<std::string> issues;
  std::vector<std::string> values;   // 참고 표시 (문제 아님)
};

static std::string fmt(double v, int prec) {
  std::ostringstream os;
  os.setf(std::ios::fixed);
  os.precision(prec);
  os << v;
  return os.str();
}

static bool finite3(double a, double b, double c) { return std::isfinite(a) && std::isfinite(b) && std::isfinite(c); }

class Check {
 public:
  virtual ~Check() = default;
  virtual void on_msg(const rclcpp::SerializedMessage &m, double wall) = 0;
  // 이번 주기에 받은 메시지로 판정. 받은 게 없으면 false (직전 결과 유지)
  virtual bool evaluate(const Context &c, Result &r) = 0;
};

// ---- 1단계: header stamp ------------------------------------------------
class StampCheck : public Check {
 public:
  void on_msg(const rclcpp::SerializedMessage &m, double wall) override {
    const auto &raw = m.get_rcl_serialized_message();
    int32_t sec = 0;
    uint32_t nsec = 0;
    const bool shaped = parse(raw.buffer, raw.buffer_length, sec, nsec);
    if (!decided_) {
      shaped ? ++shaped_ : ++unshaped_;
      if (unshaped_ > 0) { decided_ = true; header_ = false; }
      else if (shaped_ >= 5) { decided_ = true; header_ = true; }
      if (!decided_ || !header_) return;
    }
    if (!header_ || !shaped) return;
    ++n_;
    const int64_t stamp = static_cast<int64_t>(sec) * 1000000000LL + nsec;
    if (stamp == 0) { ++zero_; prev_ = 0; return; }
    if (prev_ > 0) {
      if (stamp < prev_) ++back_;
      if (stamp == prev_) { ++same_run_; same_max_ = std::max(same_max_, same_run_); }
      else same_run_ = 0;
    }
    prev_ = stamp;
    const double d = wall - stamp * 1e-9;
    dsum_ += d;
    dmax_ = std::max(dmax_, d);
    ++dn_;
  }

  bool evaluate(const Context &c, Result &r) override {
    if (n_ == 0) return false;
    if (zero_ == n_) {
      r.values.push_back("stamp 0 (시각 없음)");
    } else {
      if (dn_ > 0 && !c.sim_time) {
        const double mean = dsum_ / dn_;
        if (mean > th_.stamp_delay_max_s) {
          r.issues.push_back("stamp 지연 평균 " + fmt(mean * 1000, 0) + " ms (최대 " + fmt(dmax_ * 1000, 0) + ")");
        } else if (mean < -th_.stamp_future_max_s) {
          r.issues.push_back("stamp가 수신보다 " + fmt(-mean, 2) + " s 앞섬 (시계 어긋남)");
        }
        r.values.push_back("지연 " + fmt(mean * 1000, 0) + " ms");
      }
      if (c.publishers == 1) {   // 발행자가 여럿이면 순서가 섞이는 게 정상
        if (back_ > 0) r.issues.push_back("stamp 역행 " + std::to_string(back_) + "회");
        if (same_max_ >= 2) r.issues.push_back("같은 stamp 반복 (" + std::to_string(same_max_ + 1) + "회 연속)");
      }
    }
    n_ = zero_ = back_ = dn_ = same_max_ = 0;
    dsum_ = 0;
    dmax_ = -1e18;
    return true;
  }

  bool has_header() const { return decided_ && header_; }
  void set_thresholds(const Thresholds &t) { th_ = t; }

  // CDR little-endian: [캡슐 4B][sec i32][nsec u32][frame_id 길이 u32][frame_id ... \0]
  static bool parse(const uint8_t *b, size_t len, int32_t &sec, uint32_t &nsec) {
    if (len < 17 || b[0] != 0x00 || b[1] != 0x01) return false;
    uint32_t slen = 0;
    std::memcpy(&sec, b + 4, 4);
    std::memcpy(&nsec, b + 8, 4);
    std::memcpy(&slen, b + 12, 4);
    if (nsec >= 1000000000U || slen < 1 || slen > 256 || 16 + slen > len || b[16 + slen - 1] != 0) return false;
    for (uint32_t i = 0; i + 1 < slen; ++i) {
      if (b[16 + i] < 0x20 || b[16 + i] > 0x7e) return false;
    }
    return true;
  }

 private:
  Thresholds th_;
  bool decided_ = false, header_ = false;
  int shaped_ = 0, unshaped_ = 0;
  int64_t prev_ = -1;
  uint64_t n_ = 0, zero_ = 0, back_ = 0, dn_ = 0, same_run_ = 0, same_max_ = 0;
  double dsum_ = 0, dmax_ = -1e18;
};

// ---- IMU: 값이 전부 0 이거나 NaN·Inf 인지만 ----------------------------------
class ImuCheck : public Check {
 public:
  void on_msg(const rclcpp::SerializedMessage &m, double) override {
    try {
      ser_.deserialize_message(&m, &msg_);
    } catch (...) {
      ++bad_decode_;
      return;
    }
    ++n_;
    const auto &a = msg_.linear_acceleration;
    const auto &g = msg_.angular_velocity;
    const auto &q = msg_.orientation;
    if (!finite3(a.x, a.y, a.z) || !finite3(g.x, g.y, g.z) || !finite3(q.x, q.y, q.z) || !std::isfinite(q.w)) {
      ++nonfinite_;
      return;
    }
    if (a.x == 0 && a.y == 0 && a.z == 0 && g.x == 0 && g.y == 0 && g.z == 0) { ++zero_; return; }
    ++valid_;
    acc_sum_ += std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
  }

  bool evaluate(const Context &, Result &r) override {
    if (n_ == 0 && bad_decode_ == 0) return false;
    if (bad_decode_ > 0) r.issues.push_back("역직렬화 실패 " + std::to_string(bad_decode_) + "회");
    if (nonfinite_ > 0) r.issues.push_back("NaN/Inf 값 " + std::to_string(nonfinite_) + "개");
    if (n_ > 0 && zero_ == n_) r.issues.push_back("가속도·각속도 모두 0");
    else if (zero_ > 0) r.issues.push_back("값이 전부 0인 메시지 " + std::to_string(zero_) + "개");
    if (valid_ > 0) r.values.push_back("|a| " + fmt(acc_sum_ / valid_, 2) + " m/s²");
    n_ = valid_ = nonfinite_ = zero_ = bad_decode_ = 0;
    acc_sum_ = 0;
    return true;
  }

 private:
  rclcpp::Serialization<sensor_msgs::msg::Imu> ser_;
  sensor_msgs::msg::Imu msg_;
  uint64_t n_ = 0, valid_ = 0, nonfinite_ = 0, zero_ = 0, bad_decode_ = 0;
  double acc_sum_ = 0;
};

// ---- GNSS (NavSatFix): 위치 공분산만 -----------------------------------------
class GnssCheck : public Check {
 public:
  explicit GnssCheck(const Thresholds &t) : th_(t) {}

  void on_msg(const rclcpp::SerializedMessage &m, double) override {
    try {
      ser_.deserialize_message(&m, &msg_);
    } catch (...) {
      ++bad_decode_;
      return;
    }
    ++n_;
    status_ = msg_.status.status;
    cov_type_ = msg_.position_covariance_type;
    const double cx = msg_.position_covariance[0], cy = msg_.position_covariance[4];
    if (!std::isfinite(cx) || !std::isfinite(cy) || cx < 0 || cy < 0) { ++bad_cov_; return; }
    std_m_ = std::sqrt(std::max(cx, cy));    // 수평 표준편차 (큰 쪽)
  }

  bool evaluate(const Context &, Result &r) override {
    if (n_ == 0 && bad_decode_ == 0) return false;
    if (bad_decode_ > 0) r.issues.push_back("역직렬화 실패 " + std::to_string(bad_decode_) + "회");
    if (bad_cov_ > 0) r.issues.push_back("공분산 비정상 (NaN·음수) " + std::to_string(bad_cov_) + "개");
    else if (cov_type_ > 0 && std_m_ > th_.gnss_max_std_m) r.issues.push_back("정확도 낮음 ±" + fmt(std_m_, 1) + " m");
    static const char *labels[] = {"FIX", "SBAS", "RTK/GBAS"};
    r.values.push_back(status_ < 0 ? "NO_FIX" : status_ <= 2 ? labels[status_] : "status " + std::to_string(status_));
    r.values.push_back(cov_type_ > 0 ? "±" + fmt(std_m_, 2) + " m" : "공분산 미제공");
    n_ = bad_cov_ = bad_decode_ = 0;
    return true;
  }

 private:
  Thresholds th_;
  rclcpp::Serialization<sensor_msgs::msg::NavSatFix> ser_;
  sensor_msgs::msg::NavSatFix msg_;
  int status_ = -1, cov_type_ = 0;
  double std_m_ = 0;
  uint64_t n_ = 0, bad_cov_ = 0, bad_decode_ = 0;
};

// ---- TF: 변환 값이 비정상(NaN·Inf·쿼터니언 크기)인지만 ----------------------------
class TfCheck : public Check {
 public:
  void on_msg(const rclcpp::SerializedMessage &m, double) override {
    try {
      ser_.deserialize_message(&m, &msg_);
    } catch (...) {
      ++bad_decode_;
      return;
    }
    ++n_;
    for (const auto &t : msg_.transforms) {
      const auto &p = t.transform.translation;
      const auto &q = t.transform.rotation;
      const double qn = std::sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
      if (!finite3(p.x, p.y, p.z) || !std::isfinite(qn) || std::fabs(qn - 1.0) > 0.01)
        bad_.insert(t.header.frame_id + "→" + t.child_frame_id);
      frames_.insert(t.child_frame_id);
    }
  }

  bool evaluate(const Context &, Result &r) override {
    if (n_ == 0 && bad_decode_ == 0) return false;
    if (bad_decode_ > 0) r.issues.push_back("역직렬화 실패 " + std::to_string(bad_decode_) + "회");
    if (!bad_.empty()) {
      std::string s;
      size_t i = 0;
      for (auto &b : bad_) {
        if (i++ == 3) { s += " 외 " + std::to_string(bad_.size() - 3) + "개"; break; }
        s += (i > 1 ? ", " : "") + b;
      }
      r.issues.push_back("변환 값 비정상 (NaN·쿼터니언): " + s);
    }
    r.values.push_back("프레임 " + std::to_string(frames_.size()) + "개");
    n_ = bad_decode_ = 0;
    bad_.clear();
    return true;
  }

 private:
  rclcpp::Serialization<tf2_msgs::msg::TFMessage> ser_;
  tf2_msgs::msg::TFMessage msg_;
  std::set<std::string> bad_, frames_;
  uint64_t n_ = 0, bad_decode_ = 0;
};

}  // namespace value_checks
