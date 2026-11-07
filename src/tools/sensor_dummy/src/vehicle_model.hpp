#ifndef VEHICLE_MODEL_HPP_
#define VEHICLE_MODEL_HPP_

#include <deque>
#include <string>

namespace sensor_dummy
{

enum class MotionModel { Ackermann, Diff };

MotionModel parse_motion_model(const std::string & name);

struct VehicleParams
{
  MotionModel model;
  double track;
  double wheelbase;
  double rear_axle_x;  // rear axle along base_link x
  double max_steer_angle;
  double max_linear_speed;
  double cmd_delay_s;
  double speed_tau_s;
  double steer_tau_s;
  double speed_dead_band_mps;  // a smaller speed command does not move the vehicle
  double steer_dead_band_rad;  // ackermann: a smaller steering command leaves the wheels centered
  double steer_bias_rad;       // ackermann: added to the steering target, as a misaligned rack does
};

struct Pose2d
{
  double x;
  double y;
  double yaw;
};

// hunter_messenger.hpp AngelVelocity2Angel: a Twist to the inner wheel angle, before the clamp
// that the Hunter firmware applies.
double twist_to_inner_steer(
  double linear, double angular, double wheelbase, double track, double max_steer_angle);
// hunter_messenger.hpp ConvertInnerAngleToCentral.
double inner_to_central_steer(double inner, double wheelbase, double track);
double apply_dead_band(double value, double band);

class VehicleModel
{
public:
  VehicleModel(const VehicleParams & params, const Pose2d & base_pose);

  void command(double t, double linear, double angular);
  void step(double t, double dt);

  Pose2d base_pose() const;
  double speed() const { return speed_; }
  double steering() const { return steering_; }
  double yaw_rate() const { return yaw_rate_; }
  double acceleration() const { return acceleration_; }

private:
  struct Command
  {
    double apply_t;
    double linear;
    double angular;
  };

  void apply_due_commands(double t);
  void update_ackermann(double dt);
  void update_diff(double dt);
  double reference_offset() const;

  VehicleParams params_;
  std::deque<Command> pending_;
  double target_linear_{0.0};
  double target_angular_{0.0};
  Pose2d reference_;  // rear axle for ackermann, base_link for diff
  double speed_{0.0};
  double steering_{0.0};
  double angular_{0.0};
  double yaw_rate_{0.0};
  double acceleration_{0.0};
};

}  // namespace sensor_dummy

#endif  // VEHICLE_MODEL_HPP_
