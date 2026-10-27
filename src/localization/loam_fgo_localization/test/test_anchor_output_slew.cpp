#include <cassert>
#include <cmath>
#include <iostream>

#include "loam_fgo_localization/fusion/anchor_output_slew.hpp"

using loam_fgo_localization::normalizeAngle;
using loam_fgo_localization::Se2;
using loam_fgo_localization::slewAnchorAtVehicle;

namespace
{
constexpr double kTolerance = 1e-9;
constexpr double kMaxStep = 0.5 / 50.0;
constexpr double kMaxYawStep = 0.2 / 50.0;

void assertSamePose(const Se2 & a, const Se2 & b)
{
  assert(std::hypot(a.x - b.x, a.y - b.y) < kTolerance);
  assert(std::abs(normalizeAngle(a.yaw - b.yaw)) < kTolerance);
}

void assertCorrectionBound(const Se2 & current, const Se2 & result, const Se2 & odom)
{
  const auto before = current.compose(odom);
  const auto after = result.compose(odom);
  assert(std::hypot(after.x - before.x, after.y - before.y) <= kMaxStep + kTolerance);
  assert(std::abs(normalizeAngle(after.yaw - before.yaw)) <= kMaxYawStep + kTolerance);
}
}  // namespace

int main()
{
  // odom 원점에서 159 m: 기존 yaw 0.004 rad 변경은 차량을 약 0.636 m 움직인다.
  const Se2 current{0.0, 0.0, 0.0};
  const Se2 target{0.0, 0.0, 0.004};
  const Se2 odom{159.0, 0.0, 0.7};
  const auto result = slewAnchorAtVehicle(current, target, odom, kMaxStep, kMaxYawStep);
  const auto before = current.compose(odom);
  const auto after = result.compose(odom);
  const auto old_after = target.compose(odom);
  const double old_step = std::hypot(old_after.x - before.x, old_after.y - before.y);
  const double new_step = std::hypot(after.x - before.x, after.y - before.y);
  assert(old_step > 0.63);
  assert(std::abs(new_step - kMaxStep) < kTolerance);
  assertCorrectionBound(current, result, odom);

  // 같은 물리 상태를 odom 원점 이동/회전으로 표현해도 결과는 같다.
  const Se2 shifted_odom_frame{1000.0, -700.0, 0.8};  // old_odom -> new_odom
  const auto shifted_odom = shifted_odom_frame.inverse().compose(odom);
  const auto shifted_result = slewAnchorAtVehicle(
    current.compose(shifted_odom_frame), target.compose(shifted_odom_frame),
    shifted_odom, kMaxStep, kMaxYawStep);
  assertSamePose(after, shifted_result.compose(shifted_odom));

  // odom 원점에서는 기존 translation/yaw 제한과 같은 결과이다.
  const Se2 at_origin{};
  assertSamePose(
    slewAnchorAtVehicle(current, Se2{1.0, 0.0, 1.0}, at_origin, kMaxStep, kMaxYawStep),
    Se2{kMaxStep, 0.0, kMaxYawStep});

  // 순수 헤딩 보정: 목표 차량 위치가 같으면 XY는 유지한다.
  const Se2 desired_base{before.x, before.y, before.yaw + 0.1};
  const auto yaw_target = desired_base.compose(odom.inverse());
  const auto yaw_result = slewAnchorAtVehicle(
    current, yaw_target, odom, kMaxStep, kMaxYawStep).compose(odom);
  assertSamePose(yaw_result, Se2{before.x, before.y, before.yaw + kMaxYawStep});

  // ±pi 경계는 358도가 아닌 최단 2도 방향으로 보정한다.
  const double pi = std::acos(-1.0);
  const Se2 wrap_current{2.0, 3.0, 179.0 * pi / 180.0};
  const Se2 wrap_target{2.0, 3.0, -179.0 * pi / 180.0};
  const auto wrap_result = slewAnchorAtVehicle(
    wrap_current, wrap_target, at_origin, kMaxStep, kMaxYawStep);
  assert(
    std::abs(normalizeAngle(wrap_result.yaw - wrap_current.yaw) - kMaxYawStep) <
    kTolerance);

  // 보정 제한이 0이면 앵커는 유지된다. XY만 0이어도 yaw 보정은 가능하다.
  assertSamePose(slewAnchorAtVehicle(current, target, odom, 0.0, 0.0), current);
  const auto no_xy = slewAnchorAtVehicle(current, target, odom, 0.0, kMaxYawStep);
  assertSamePose(no_xy.compose(odom), Se2{before.x, before.y, before.yaw + kMaxYawStep});
  const auto no_yaw = slewAnchorAtVehicle(current, target, odom, kMaxStep, 0.0);
  assert(std::abs(normalizeAngle(no_yaw.yaw - current.yaw)) < kTolerance);
  assertCorrectionBound(current, no_yaw, odom);

  // 목표 도달/허용량 이내는 목표에 정확히 수렴하고 반복 갱신해도 유지된다.
  const Se2 near_base{before.x + 0.002, before.y - 0.003, before.yaw + 0.001};
  const auto near_target = near_base.compose(odom.inverse());
  assertSamePose(
    slewAnchorAtVehicle(current, near_target, odom, kMaxStep, kMaxYawStep), near_target);
  assertSamePose(
    slewAnchorAtVehicle(near_target, near_target, odom, kMaxStep, kMaxYawStep), near_target);

  // 차량 자체의 odom 이동은 보정 속도 제한에 가두지 않는다.
  const Se2 moved_odom{159.2, 0.1, 0.75};
  assertSamePose(
    slewAnchorAtVehicle(near_target, near_target, moved_odom, kMaxStep, kMaxYawStep),
    near_target);
  const auto moved_result = slewAnchorAtVehicle(
    current, target, moved_odom, kMaxStep, kMaxYawStep);
  assertCorrectionBound(current, moved_result, moved_odom);

  std::cout << "PASS: vehicle correction bounds, odom-frame invariance, origin, pure yaw, "
            << "angle wrap, zero limits, target reached, moving odom\n"
            << "159 m pivot: old correction=" << old_step
            << " m, new correction=" << new_step << " m\n";
}
