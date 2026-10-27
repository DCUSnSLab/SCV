#ifndef SCV_LOCALIZATION__GPS_FRONTEND_HPP_
#define SCV_LOCALIZATION__GPS_FRONTEND_HPP_

#include <cmath>
#include <string>

namespace loam_fgo_localization
{

// GPS fix 분류 (FGO 팩터의 노이즈 모델 선택 기준).
//   RTK_FIXED : 모호정수 고정 — cm급. bias 앵커(강한 prior) 트리거.
//   FLOAT     : float/DGPS — 보고 σ가 과신 가능, m급 바이어스 가정.
//   NONE      : fix 없음/비유한값 — 사용 불가.
enum class GpsFixClass
{
  RtkFixed,
  Float,
  None
};

inline const char * gpsFixClassName(GpsFixClass c)
{
  switch (c) {
    case GpsFixClass::RtkFixed: return "RTK_FIXED";
    case GpsFixClass::Float: return "FLOAT";
    case GpsFixClass::None: return "NONE";
  }
  return "NONE";
}

struct GpsClassifierParams
{
  // NavSatStatus.status 가 이 값 이상이고(u-blox: 2=GBAS/RTK) σ가 아래 문턱 미만이면 RTK_FIXED.
  int rtk_status_min{2};
  double rtk_sigma_max{0.05};       // m (record_20260721: RTK 구간 σ p50=0.037)
  // fix-type별 σ floor: 보고 공분산 과신 차단. 실제 팩터 노이즈 = max(보고 σ, floor).
  double rtk_sigma_floor{0.05};     // m
  double float_sigma_floor{1.5};    // m (float 바이어스 잔여 + multipath)
  double unknown_sigma{5.0};        // m (공분산 UNKNOWN일 때)
};

// status/σ -> 분류. sigma 는 보고된 수평 σ (비유한/UNKNOWN 처리 후).
inline GpsFixClass classifyGpsFix(
  int status, double sigma, bool sigma_known, const GpsClassifierParams & p)
{
  if (status < 0 || !std::isfinite(sigma)) {
    return GpsFixClass::None;
  }
  if (sigma_known && status >= p.rtk_status_min && sigma < p.rtk_sigma_max) {
    return GpsFixClass::RtkFixed;
  }
  return GpsFixClass::Float;
}

// 분류에 따른 팩터용 σ (floor 적용).
inline double flooredSigma(GpsFixClass c, double sigma, bool sigma_known,
  const GpsClassifierParams & p)
{
  switch (c) {
    case GpsFixClass::RtkFixed:
      return std::max(sigma, p.rtk_sigma_floor);
    case GpsFixClass::Float:
      return std::max(sigma_known ? sigma : p.unknown_sigma, p.float_sigma_floor);
    case GpsFixClass::None:
      break;
  }
  return p.unknown_sigma;
}

}  // namespace loam_fgo_localization

#endif  // SCV_LOCALIZATION__GPS_FRONTEND_HPP_
