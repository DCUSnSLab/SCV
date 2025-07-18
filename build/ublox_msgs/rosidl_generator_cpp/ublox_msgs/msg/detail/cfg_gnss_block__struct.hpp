// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgGNSSBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgGNSSBlock __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgGNSSBlock __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgGNSSBlock_
{
  using Type = CfgGNSSBlock_<ContainerAllocator>;

  explicit CfgGNSSBlock_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gnss_id = 0;
      this->res_trk_ch = 0;
      this->max_trk_ch = 0;
      this->reserved1 = 0;
      this->flags = 0ul;
    }
  }

  explicit CfgGNSSBlock_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gnss_id = 0;
      this->res_trk_ch = 0;
      this->max_trk_ch = 0;
      this->reserved1 = 0;
      this->flags = 0ul;
    }
  }

  // field types and members
  using _gnss_id_type =
    uint8_t;
  _gnss_id_type gnss_id;
  using _res_trk_ch_type =
    uint8_t;
  _res_trk_ch_type res_trk_ch;
  using _max_trk_ch_type =
    uint8_t;
  _max_trk_ch_type max_trk_ch;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _flags_type =
    uint32_t;
  _flags_type flags;

  // setters for named parameter idiom
  Type & set__gnss_id(
    const uint8_t & _arg)
  {
    this->gnss_id = _arg;
    return *this;
  }
  Type & set__res_trk_ch(
    const uint8_t & _arg)
  {
    this->res_trk_ch = _arg;
    return *this;
  }
  Type & set__max_trk_ch(
    const uint8_t & _arg)
  {
    this->max_trk_ch = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__flags(
    const uint32_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t GNSS_ID_GPS =
    0u;
  static constexpr uint8_t GNSS_ID_SBAS =
    1u;
  static constexpr uint8_t GNSS_ID_GALILEO =
    2u;
  static constexpr uint8_t GNSS_ID_BEIDOU =
    3u;
  static constexpr uint8_t GNSS_ID_IMES =
    4u;
  static constexpr uint8_t GNSS_ID_QZSS =
    5u;
  static constexpr uint8_t GNSS_ID_GLONASS =
    6u;
  static constexpr uint8_t RES_TRK_CH_GPS =
    8u;
  static constexpr uint8_t RES_TRK_CH_QZSS =
    0u;
  static constexpr uint8_t RES_TRK_CH_SBAS =
    0u;
  static constexpr uint8_t RES_TRK_CH_GLONASS =
    8u;
  static constexpr uint8_t MAX_TRK_CH_MAJOR_MIN =
    4u;
  static constexpr uint8_t MAX_TRK_CH_GPS =
    16u;
  static constexpr uint8_t MAX_TRK_CH_GLONASS =
    14u;
  static constexpr uint8_t MAX_TRK_CH_QZSS =
    3u;
  static constexpr uint8_t MAX_TRK_CH_SBAS =
    3u;
  static constexpr uint32_t FLAGS_ENABLE =
    1u;
  static constexpr uint32_t FLAGS_SIG_CFG_MASK =
    16711680u;
  static constexpr uint32_t SIG_CFG_GPS_L1CA =
    65536u;
  static constexpr uint32_t SIG_CFG_SBAS_L1CA =
    65536u;
  static constexpr uint32_t SIG_CFG_GALILEO_E1OS =
    65536u;
  static constexpr uint32_t SIG_CFG_BEIDOU_B1I =
    65536u;
  static constexpr uint32_t SIG_CFG_IMES_L1 =
    65536u;
  static constexpr uint32_t SIG_CFG_QZSS_L1CA =
    65536u;
  static constexpr uint32_t SIG_CFG_QZSS_L1SAIF =
    262144u;
  static constexpr uint32_t SIG_CFG_GLONASS_L1OF =
    65536u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgGNSSBlock
    std::shared_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgGNSSBlock
    std::shared_ptr<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgGNSSBlock_ & other) const
  {
    if (this->gnss_id != other.gnss_id) {
      return false;
    }
    if (this->res_trk_ch != other.res_trk_ch) {
      return false;
    }
    if (this->max_trk_ch != other.max_trk_ch) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgGNSSBlock_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgGNSSBlock_

// alias to use template instance with default allocator
using CfgGNSSBlock =
  ublox_msgs::msg::CfgGNSSBlock_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::GNSS_ID_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::GNSS_ID_SBAS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::GNSS_ID_GALILEO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::GNSS_ID_BEIDOU;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::GNSS_ID_IMES;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::GNSS_ID_QZSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::GNSS_ID_GLONASS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::RES_TRK_CH_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::RES_TRK_CH_QZSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::RES_TRK_CH_SBAS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::RES_TRK_CH_GLONASS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::MAX_TRK_CH_MAJOR_MIN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::MAX_TRK_CH_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::MAX_TRK_CH_GLONASS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::MAX_TRK_CH_QZSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSSBlock_<ContainerAllocator>::MAX_TRK_CH_SBAS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::FLAGS_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::FLAGS_SIG_CFG_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_GPS_L1CA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_SBAS_L1CA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_GALILEO_E1OS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_BEIDOU_B1I;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_IMES_L1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_QZSS_L1CA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_QZSS_L1SAIF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgGNSSBlock_<ContainerAllocator>::SIG_CFG_GLONASS_L1OF;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__STRUCT_HPP_
