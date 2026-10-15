// scv_logger 토픽 상태 감시 노드 (C++).
//
// 파이썬 scv_logger/ros/monitor_node.py 와 같은 입출력을 갖는다. 메시지는 generic subscription 으로
// 직렬화된 채 받아 도착 시각과 크기를 기록한다. 800 Hz 토픽이 여러 개여도 가볍다.
// 값 검사(value_checks.hpp): 모든 토픽의 header stamp(바이트에서 직접 읽음) + IMU(0·NaN)·GNSS(공분산)·TF(NaN).
// 문제가 있으면 상태 "abnormal", 녹화 중이면 시작·복귀 때 자동 마커. (파이썬 감시 노드에는 없음)
//
// preview 모드 (--session-dir 없음): /scv_logger/health 만 발행.
// session 모드 (--session-dir, --recorder-pid):
//   - health.csv / system.csv 기록, /scv_logger/marker → markers.jsonl (유일한 기록자)
//   - 디스크가 disk_stop_gb 미만으로 3초 연속이면 녹화 자동 정지 (세션/stop_reason 파일에 disk_low)
//   - 녹화 프로세스가 끝나면 `<python> -m scv_logger.core.finalize_cli <세션>` 으로 manifest 마감 후 종료
//   - 카탈로그 auto_markers 가 있으면 파이썬 보조 노드(scv_logger.ros.auto_marker)를 자식으로 띄운다
//     (메시지 내용 비교가 필요한데 대상 토픽이 저주기라 파이썬으로 충분)

#include <signal.h>
#include <sys/statvfs.h>
#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <map>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "value_checks.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

static const char *HEALTH_TOPIC = "/scv_logger/health";
static const char *MARKER_TOPIC = "/scv_logger/marker";
static constexpr int DISK_STOP_TICKS = 3;
static constexpr double ISSUE_HOLD_S = 3.0;      // 문제 문구를 사라진 뒤에도 잠깐 유지 (깜빡임 방지)
static constexpr double MARKER_MIN_GAP_S = 10.0;  // 같은 토픽 값 이상 마커 최소 간격

static double mono_now() {
  return std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
}
static double wall_now() {
  return std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count();
}
static double round_to(double v, int digits) {
  const double f = std::pow(10.0, digits);
  return std::round(v * f) / f;
}

// ---- 측정 ----------------------------------------------------------------
struct Probe {
  std::string topic;
  std::deque<double> arrivals;   // steady clock [s]
  std::deque<size_t> sizes;
  uint64_t count = 0;
  rclcpp::GenericSubscription::SharedPtr sub;
  std::string type, error;
  bool latched = false, heavy = false;
  size_t publishers = 0;
  // 값 검사
  std::unique_ptr<value_checks::StampCheck> stamp;
  std::unique_ptr<value_checks::Check> value;
  value_checks::Result result;
  std::vector<std::string> held;
  double held_until = 0, last_marker = 0, last_got = 0;
  bool marker_open = false;

  bool checked() const { return stamp || value; }
  void check(const rclcpp::SerializedMessage &m) {
    if (!checked()) return;
    const double w = wall_now();
    if (stamp) stamp->on_msg(m, w);
    if (value) value->on_msg(m, w);
  }
  // 보고 주기마다: 이번 주기 판정 → 표시할 문제 목록
  const std::vector<std::string> &evaluate_checks(const value_checks::Context &c) {
    value_checks::Result r;
    bool got = false;
    if (stamp) got = stamp->evaluate(c, r) || got;
    if (value) got = value->evaluate(c, r) || got;
    if (got) {
      result = std::move(r);
      last_got = c.wall;
    } else if (c.wall - last_got > ISSUE_HOLD_S) {
      result = {};                    // 메시지가 끊긴 토픽은 이전 판정을 들고 있지 않는다 (끊김은 주기 판정이 표시)
    }
    if (!result.issues.empty()) {
      held = result.issues;
      held_until = c.wall + ISSUE_HOLD_S;
    } else if (c.wall > held_until) {
      held.clear();
    }
    return held;
  }

  void on_msg(size_t bytes) {
    arrivals.push_back(mono_now());
    if (arrivals.size() > 4000) arrivals.pop_front();
    sizes.push_back(bytes);
    if (sizes.size() > 50) sizes.pop_front();
    ++count;
  }
  std::optional<double> avg_size_kb() const {
    if (sizes.empty()) return std::nullopt;
    double s = 0;
    for (auto v : sizes) s += static_cast<double>(v);
    return s / sizes.size() / 1024.0;
  }
};

struct Watch {
  std::string name, monitor;
  std::optional<double> hz;
  bool required = false, latched = false, heavy = false;
  Probe *probe = nullptr;
};

static double window_for(std::optional<double> expected) {
  return expected ? std::max(3.0, 4.0 / *expected) : 5.0;
}

// 파이썬 probe.evaluate() 와 같은 판정
static json evaluate(std::optional<double> expected, const Probe &p, double now, double tol) {
  double hz = 0.0;
  std::optional<double> age;
  if (!p.arrivals.empty()) {
    age = now - p.arrivals.back();
    const double win = window_for(expected);
    auto it = std::lower_bound(p.arrivals.begin(), p.arrivals.end(), now - win);
    const auto n = std::distance(it, p.arrivals.end());
    if (n >= 2 && p.arrivals.back() > *it) hz = (n - 1) / (p.arrivals.back() - *it);
  }
  std::string status;
  if (!p.error.empty()) {
    status = "type_unavailable";
  } else if (p.latched) {
    status = (p.count > 0 || p.publishers > 0) ? "ok" : "latched_missing";
  } else if (!age) {
    status = p.publishers > 0 ? "waiting" : "no_publisher";
  } else if (*age > (expected ? std::max(2.0, 3.0 / *expected) : 5.0)) {
    status = p.publishers > 0 ? "stale" : "no_publisher";
  } else if (expected && hz < *expected * tol) {
    status = "low";
  } else {
    status = "ok";
  }
  json r;
  r["hz"] = round_to(hz, 2);
  r["age"] = age ? json(round_to(*age, 2)) : json(nullptr);
  r["status"] = status;
  return r;
}

static std::optional<double> disk_free_gb(fs::path p) {
  while (!fs::exists(p) && p != p.parent_path()) p = p.parent_path();
  struct statvfs st {};
  if (statvfs(p.c_str(), &st) != 0) return std::nullopt;
  return static_cast<double>(st.f_bavail) * st.f_frsize / (1024.0 * 1024.0 * 1024.0);
}

static bool pid_alive(int pid) {
  if (pid <= 0 || kill(pid, 0) != 0) return false;
  std::ifstream f("/proc/" + std::to_string(pid) + "/stat");
  std::string s;
  std::getline(f, s);
  auto pos = s.rfind(')');
  return !(pos != std::string::npos && pos + 2 < s.size() && s[pos + 2] == 'Z');
}

static uint64_t dir_bytes(const fs::path &d) {
  uint64_t total = 0;
  std::error_code ec;
  if (!fs::is_directory(d, ec)) return 0;
  for (auto &e : fs::directory_iterator(d, ec)) {
    std::error_code ec2;
    if (e.is_regular_file(ec2)) total += e.file_size(ec2);
  }
  return total;
}

static pid_t spawn(const std::vector<std::string> &args) {
  pid_t pid = fork();
  if (pid == 0) {
    setpgid(0, 0);
    std::vector<char *> argv;
    for (auto &a : args) argv.push_back(const_cast<char *>(a.c_str()));
    argv.push_back(nullptr);
    execvp(argv[0], argv.data());
    _exit(127);
  }
  return pid;
}

// ---- 노드 ----------------------------------------------------------------
struct Options {
  std::string config, session_dir, python = "python3";
  int recorder_pid = 0;
  double rate = 1.0;
  double session_start = 0.0;
  bool value_checks = true;
};

// QoS 이벤트(호환 안 되는 QoS 알림) 핸들러를 붙이지 않는다. Humble의 StaticSingleThreadedExecutor는
// 실행 중에 구독이 추가되면 이 핸들러를 잘못 다뤄 segfault 난다 (카메라처럼 늦게 뜨는 토픽을 구독할 때 재현).
static rclcpp::SubscriptionOptions no_event_options() {
  rclcpp::SubscriptionOptions o;
  o.use_default_callbacks = false;
  return o;
}

class MonitorNode : public rclcpp::Node {
 public:
  explicit MonitorNode(const Options &o, json cfg)
      : Node("scv_logger_monitor_" + std::to_string(getpid())), opt_(o), cfg_(std::move(cfg)) {
    tolerance_ = cfg_.value("hz_tolerance", 0.8);
    output_dir_ = cfg_.value("output_dir", std::string("."));
    disk_warn_ = cfg_.value("disk_warn_gb", 30.0);
    disk_stop_ = cfg_.value("disk_stop_gb", 10.0);
    profile_ = cfg_.value("profile", std::string());
    session_ = !opt_.session_dir.empty();
    thresholds_ = value_checks::Thresholds::from_json(cfg_.value("value_checks", json::object()));

    for (auto &t : cfg_.value("topics", json::array())) {
      Watch w;
      w.name = t.at("name").get<std::string>();
      w.monitor = t.value("monitor", std::string());
      if (w.monitor.empty()) w.monitor = w.name;
      if (t.contains("hz") && t["hz"].is_number()) w.hz = t["hz"].get<double>();
      w.required = t.value("required", false);
      w.latched = t.value("latched", false);
      w.heavy = t.value("heavy", false);
      auto &pp = probes_[w.monitor];
      if (!pp) {
        pp = std::make_unique<Probe>();
        pp->topic = w.monitor;
      }
      pp->latched = pp->latched || w.latched;
      pp->heavy = pp->heavy || (w.heavy && w.monitor == w.name);
      w.probe = pp.get();
      watches_.push_back(w);
    }

    health_pub_ = create_publisher<std_msgs::msg::String>(HEALTH_TOPIC, 10);
    marker_pub_ = create_publisher<std_msgs::msg::String>(MARKER_TOPIC, 10);

    if (session_) {
      fs::path s(opt_.session_dir);
      started_ = opt_.session_start > 0 ? opt_.session_start : wall_now();
      session_id_ = s.filename().string();
      marker_sub_ = create_subscription<std_msgs::msg::String>(
          MARKER_TOPIC, rclcpp::QoS(50).reliable(),
          [this](std_msgs::msg::String::ConstSharedPtr m) { on_marker(*m); }, no_event_options());
      open_csv(health_csv_, s / "health.csv", "time,topic,hz,age_s,status,issues");
      open_csv(system_csv_, s / "system.csv", "time,disk_free_gb,bag_bytes,write_mbps,recorder_alive");
      if (!cfg_.value("auto_markers", json::array()).empty()) {
        auto_pid_ = spawn({opt_.python, "-m", "scv_logger.ros.auto_marker", "--config", opt_.config});
      }
    }

    resolve();
    resolve_timer_ = create_wall_timer(std::chrono::seconds(1), [this] { resolve(); });
    report_timer_ = create_wall_timer(std::chrono::duration<double>(1.0 / std::max(opt_.rate, 0.1)),
                                      [this] { report(); });
  }

  ~MonitorNode() override { stop_children(); }

  bool done() const { return done_; }

  void stop_children() {
    if (auto_pid_ > 0) {
      kill(-auto_pid_, SIGINT);
      for (int i = 0; i < 30 && waitpid(auto_pid_, nullptr, WNOHANG) == 0; ++i) usleep(100000);
      kill(-auto_pid_, SIGKILL);
      waitpid(auto_pid_, nullptr, WNOHANG);
      auto_pid_ = 0;
    }
  }

 private:
  void open_csv(std::ofstream &f, const fs::path &p, const char *header) {
    const bool fresh = !fs::exists(p);
    f.open(p, std::ios::app);
    if (fresh) f << header << "\n";
  }

  // 아직 구독하지 못한 토픽을 그래프에서 찾아 연결 (발행자가 늦게 떠도 됨)
  void resolve() {
    bool pending = false;
    // /clock 이 있으면 (bag 재생) stamp-수신 시각 비교 생략. 재생이 끝난 직후 몇 초도 옛 stamp가 남아 있어 같이 생략
    if (count_publishers("/clock") > 0) sim_until_ = wall_now() + 5.0;
    sim_time_ = wall_now() < sim_until_;
    for (auto &[name, p] : probes_) {
      p->publishers = count_publishers(name);
      if (!p->sub && p->error.empty()) pending = true;
    }
    if (!pending) return;
    auto types = get_topic_names_and_types();
    for (auto &[name, p] : probes_) {
      if (p->sub || !p->error.empty() || p->publishers == 0) continue;
      auto it = types.find(name);
      if (it == types.end() || it->second.empty()) continue;
      p->type = it->second.front();
      if (!p->latched) {
        for (auto &info : get_publishers_info_by_topic(name)) {
          if (info.qos_profile().durability() == rclcpp::DurabilityPolicy::TransientLocal) p->latched = true;
        }
      }
      rclcpp::QoS qos(10);
      if (p->latched) {
        // TF 정적은 한 발행자가 메시지를 여러 개 남길 수 있어 (bag 재생, 여러 launch) 넉넉히 받는다
        const size_t depth = p->type == "tf2_msgs/msg/TFMessage" ? 100 : 1;
        qos = rclcpp::QoS(depth).reliable().transient_local();
      } else if (p->heavy) {
        qos = rclcpp::QoS(5).reliable();       // 큰 메시지 — best-effort면 조각 손실로 낮게 잰다
      } else {
        qos = rclcpp::QoS(10).best_effort();
      }
      Probe *raw = p.get();
      make_checks(*p);
      try {
        p->sub = create_generic_subscription(
            name, p->type, qos,
            [raw](std::shared_ptr<rclcpp::SerializedMessage> m) {
              raw->on_msg(m->size());
              raw->check(*m);
            },
            no_event_options());
      } catch (const std::exception &e) {
        p->error = "type_unavailable: " + p->type;
        RCLCPP_WARN(get_logger(), "%s 구독 실패 (%s): %s", name.c_str(), p->type.c_str(), e.what());
      }
    }
  }

  // 타입별 값 검사 붙이기. stamp 검사는 header가 있는 토픽이면 자동으로 동작 (없으면 첫 메시지에서 꺼짐)
  void make_checks(Probe &p) {
    namespace vc = value_checks;
    if (!opt_.value_checks) return;
    if (p.type == "tf2_msgs/msg/TFMessage") {
      p.value = std::make_unique<vc::TfCheck>();
      return;
    }
    if (!p.latched) {
      p.stamp = std::make_unique<vc::StampCheck>();
      p.stamp->set_thresholds(thresholds_);
    }
    if (p.type == "sensor_msgs/msg/Imu") p.value = std::make_unique<vc::ImuCheck>();
    else if (p.type == "sensor_msgs/msg/NavSatFix") p.value = std::make_unique<vc::GnssCheck>(thresholds_);
  }

  static std::string join(const std::vector<std::string> &v, const char *sep) {
    std::string s;
    for (auto &x : v) s += (s.empty() ? "" : sep) + x;
    return s;
  }

  // 녹화 중 값 이상 시작·복귀 마커
  void value_markers(Probe &p, bool abnormal, double wall) {
    if (!session_) return;
    if (abnormal && !p.marker_open && wall - p.last_marker >= MARKER_MIN_GAP_S) {
      publish_marker("value_issue", "값 이상: " + p.topic + " — " + join(p.held, ", "));
      p.marker_open = true;
      p.last_marker = wall;
    } else if (!abnormal && p.marker_open) {
      publish_marker("value_ok", "값 정상 복귀: " + p.topic);
      p.marker_open = false;
    }
  }

  void publish_marker(const std::string &kind, const std::string &text) {
    json m = {{"ts", wall_now()}, {"kind", kind}, {"text", text}, {"source", "auto"}};
    std_msgs::msg::String s;
    s.data = m.dump();
    marker_pub_->publish(s);
  }

  void on_marker(const std_msgs::msg::String &msg) {
    json m;
    try {
      m = json::parse(msg.data);
      if (!m.is_object()) throw std::runtime_error("not object");
    } catch (...) {
      m = {{"ts", wall_now()}, {"kind", "note"}, {"text", msg.data}};
    }
    if (!m.contains("ts") || !m["ts"].is_number()) m["ts"] = wall_now();
    m["t_rel"] = round_to(m["ts"].get<double>() - started_, 2);
    std::ofstream f(fs::path(opt_.session_dir) / "markers.jsonl", std::ios::app);
    f << m.dump() << "\n";
  }

  void report() {
    const double now = mono_now();
    const double wall = wall_now();
    json topics = json::object();
    int ok = 0, bad = 0;
    std::map<const Probe *, const std::vector<std::string> *> issues;
    for (auto &[name, p] : probes_) {
      if (!p->checked()) continue;
      value_checks::Context c{wall, sim_time_, p->publishers};
      issues[p.get()] = &p->evaluate_checks(c);
    }
    std::map<Probe *, bool> abnormal_probe;
    for (auto &w : watches_) {
      json st = evaluate(w.hz, *w.probe, now, tolerance_);
      if (auto it = issues.find(w.probe); it != issues.end()) {
        // 끊김·발행자 없음 등 주기 문제일 땐 값 판정은 의미가 없어 문제 문구를 붙이지 않는다
        const bool live = st["status"] == "ok";
        st["check"] = {{"issues", live ? *it->second : std::vector<std::string>{}},
                       {"values", w.probe->result.values}};
        const bool abnormal = st["status"] == "ok" && !it->second->empty();
        if (abnormal) st["status"] = "abnormal";
        abnormal_probe[w.probe] = abnormal_probe[w.probe] || abnormal;
      }
      std::optional<double> size;
      if (w.monitor == w.name) size = w.probe->avg_size_kb();
      st["expected"] = w.hz ? json(*w.hz) : json(nullptr);
      st["required"] = w.required;
      st["publishers"] = w.probe->publishers;
      st["size_kb"] = size ? json(round_to(*size, 2)) : json(nullptr);
      st["via"] = w.monitor != w.name ? json(w.monitor) : json(nullptr);
      st["direct_heavy"] = w.heavy && w.monitor == w.name;
      (st["status"] == "ok" ? ok : bad)++;
      topics[w.name] = st;
    }
    for (auto &[p, abnormal] : abnormal_probe) value_markers(*p, abnormal, wall);
    const auto free = disk_free_gb(output_dir_);
    json warnings = json::array();
    if (free && *free < disk_warn_) {
      std::ostringstream os;
      os << "디스크 여유 " << std::fixed << std::setprecision(0) << *free << " GB (경고 " << disk_warn_ << " GB)";
      warnings.push_back(os.str());
    }
    json h = {
        {"ts", wall}, {"pid", getpid()}, {"profile", profile_},
        {"mode", session_ ? "session" : "preview"},
        {"disk", {{"path", output_dir_}, {"free_gb", free ? json(round_to(*free, 1)) : json(nullptr)},
                  {"warn_gb", disk_warn_}, {"stop_gb", disk_stop_}}},
        {"topics", topics}, {"warnings", warnings}, {"summary", {{"ok", ok}, {"bad", bad}}},
        {"monitor_impl", "cpp"},
    };

    if (session_) {
      const bool alive = pid_alive(opt_.recorder_pid);
      const uint64_t bytes = dir_bytes(fs::path(opt_.session_dir) / "bag");
      bytes_hist_.emplace_back(now, bytes);
      if (bytes_hist_.size() > 12) bytes_hist_.pop_front();
      const auto [t0, b0] = bytes_hist_.front();
      const double mbps = now > t0 ? (static_cast<double>(bytes) - b0) / (now - t0) / (1024.0 * 1024.0) : 0.0;
      json remaining = nullptr;
      if (free && mbps > 0.01) remaining = std::round(std::max(0.0, (*free - disk_stop_) * 1024.0 / mbps / 60.0));
      h["session"] = session_id_;
      h["recorder"] = {{"pid", opt_.recorder_pid}, {"alive", alive}};
      h["bag"] = {{"bytes", bytes}, {"mbps", round_to(mbps, 2)}, {"remaining_min", remaining}};
      h["elapsed_sec"] = round_to(wall - started_, 1);
      write_csv(wall, topics, free, bytes, mbps, alive);
      check_disk(free, alive);
      if (!alive) {
        finalize();
        h["final_status"] = "finalized";
        done_ = true;
      }
    }
    std_msgs::msg::String s;
    s.data = h.dump();
    health_pub_->publish(s);
  }

  void write_csv(double wall, const json &topics, std::optional<double> free, uint64_t bytes, double mbps,
                 bool alive) {
    char ts[32];
    std::snprintf(ts, sizeof(ts), "%.3f", wall);
    for (auto &[name, t] : topics.items()) {
      health_csv_ << ts << ',' << name << ',' << t["hz"].get<double>() << ','
                  << (t["age"].is_null() ? std::string() : std::to_string(t["age"].get<double>())) << ','
                  << t["status"].get<std::string>() << ',';
      if (t.contains("check")) {
        std::string s = join(t["check"]["issues"].get<std::vector<std::string>>(), " | ");
        std::replace(s.begin(), s.end(), ',', ';');
        std::replace(s.begin(), s.end(), '"', '\'');
        health_csv_ << s;
      }
      health_csv_ << '\n';
    }
    health_csv_.flush();
    system_csv_ << ts << ',' << (free ? std::to_string(round_to(*free, 2)) : std::string()) << ',' << bytes << ','
                << round_to(mbps, 3) << ',' << (alive ? 1 : 0) << '\n';
    system_csv_.flush();
  }

  void check_disk(std::optional<double> free, bool alive) {
    if (!free || !alive || disk_stop_sent_) return;
    disk_low_ticks_ = *free < disk_stop_ ? disk_low_ticks_ + 1 : 0;
    if (disk_low_ticks_ < DISK_STOP_TICKS) return;
    disk_stop_sent_ = true;
    RCLCPP_ERROR(get_logger(), "디스크 여유 %.1f GB < %.1f GB — 녹화 자동 정지", *free, disk_stop_);
    std::ofstream(fs::path(opt_.session_dir) / "stop_reason") << "disk_low\n";
    std::ostringstream os;
    os << "디스크 여유 " << std::fixed << std::setprecision(1) << *free << " GB — 녹화 자동 정지";
    publish_marker("disk_stop", os.str());
    const pid_t pg = getpgid(opt_.recorder_pid);
    kill(pg > 0 ? -pg : opt_.recorder_pid, SIGINT);
  }

  void finalize() {
    stop_children();
    pid_t pid = spawn({opt_.python, "-m", "scv_logger.core.finalize_cli", opt_.session_dir});
    if (pid > 0) {
      for (int i = 0; i < 300 && waitpid(pid, nullptr, WNOHANG) == 0; ++i) usleep(100000);
    }
  }

  Options opt_;
  json cfg_;
  double tolerance_ = 0.8, disk_warn_ = 30.0, disk_stop_ = 10.0, started_ = 0.0;
  std::string output_dir_, profile_, session_id_;
  bool session_ = false, done_ = false, disk_stop_sent_ = false;
  int disk_low_ticks_ = 0;
  bool sim_time_ = false;
  double sim_until_ = 0;
  value_checks::Thresholds thresholds_;
  pid_t auto_pid_ = 0;
  std::map<std::string, std::unique_ptr<Probe>> probes_;
  std::vector<Watch> watches_;
  std::deque<std::pair<double, uint64_t>> bytes_hist_;
  std::ofstream health_csv_, system_csv_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr health_pub_, marker_pub_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr marker_sub_;
  rclcpp::TimerBase::SharedPtr resolve_timer_, report_timer_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  const auto args = rclcpp::remove_ros_arguments(argc, argv);
  Options o;
  for (size_t i = 1; i < args.size(); ++i) {
    if (args[i] == "--no-value-checks") { o.value_checks = false; continue; }
    if (i + 1 >= args.size()) break;
    const std::string k = args[i], v = args[i + 1];
    if (k == "--config") { o.config = v; ++i; }
    else if (k == "--session-dir") { o.session_dir = v; ++i; }
    else if (k == "--recorder-pid") { o.recorder_pid = std::stoi(v); ++i; }
    else if (k == "--rate") { o.rate = std::stod(v); ++i; }
    else if (k == "--session-start") { o.session_start = std::stod(v); ++i; }
    else if (k == "--python") { o.python = v; ++i; }
  }
  if (o.config.empty()) {
    std::fprintf(stderr, "사용법: scv_logger_monitor --config <json> [--session-dir D --recorder-pid P "
                         "--session-start EPOCH --python PY] [--rate HZ] [--no-value-checks]\n");
    return 2;
  }
  json cfg;
  try {
    std::ifstream f(o.config);
    cfg = json::parse(f);
  } catch (const std::exception &e) {
    std::fprintf(stderr, "설정 읽기 실패 %s: %s\n", o.config.c_str(), e.what());
    return 2;
  }
  auto node = std::make_shared<MonitorNode>(o, cfg);
  // StaticSingleThreadedExecutor: 매 메시지마다 대기 집합을 다시 만들지 않는다 (구독이 늘면 자동 갱신).
  // 초당 수천 개(800 Hz 토픽 여러 개)를 받을 때 spin_once 루프보다 executor 비용이 훨씬 작다.
  rclcpp::executors::StaticSingleThreadedExecutor exec;
  exec.add_node(node);
  auto stopper = node->create_wall_timer(std::chrono::milliseconds(200), [&exec, &node] {
    if (node->done()) exec.cancel();
  });
  exec.spin();
  node->stop_children();
  rclcpp::shutdown();
  return 0;
}
