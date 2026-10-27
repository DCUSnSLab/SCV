#ifndef SCV_LOCALIZATION__ANCHOR_OUTPUT_SLEW_HPP_
#define SCV_LOCALIZATION__ANCHOR_OUTPUT_SLEW_HPP_

#include <algorithm>
#include <cmath>

#include "loam_fgo_localization/fusion/anchor_core.hpp"

namespace loam_fgo_localization
{

// 초기 앵커 스냅 이후 사용. 한 주기의 허용 보정량 [m, rad]은 0 이상이다.
inline Se2 slewAnchorAtVehicle(
  const Se2 & current, const Se2 & target, const Se2 & odom_base,
  double max_step, double max_yaw_step)
{
  // 두 앵커를 같은 현재 odom 자세에 적용하여 보정만 제한한다.
  // 이전 발행 차량 자세와 비교하면 정상 주행 이동까지 제한하게 된다.
  Se2 current_base = current.compose(odom_base);
  const Se2 target_base = target.compose(odom_base);
  const double dx = target_base.x - current_base.x;
  const double dy = target_base.y - current_base.y;
  const double dist = std::hypot(dx, dy);
  if (dist > max_step) {
    current_base.x += dx / dist * max_step;
    current_base.y += dy / dist * max_step;
  } else {
    current_base.x = target_base.x;
    current_base.y = target_base.y;
  }
  const double dyaw = normalizeAngle(target_base.yaw - current_base.yaw);
  current_base.yaw = normalizeAngle(
    current_base.yaw + std::clamp(dyaw, -max_yaw_step, max_yaw_step));
  // 차량 위치에서 제한한 결과를 map->odom으로 환산한다.
  // 따라서 map->odom translation 자체의 변화량은 max_step보다 클 수 있다.
  return current_base.compose(odom_base.inverse());
}

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__ANCHOR_OUTPUT_SLEW_HPP_
