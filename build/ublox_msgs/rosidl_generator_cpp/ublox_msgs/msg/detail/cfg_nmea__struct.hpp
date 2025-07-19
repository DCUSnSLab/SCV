// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgNMEA.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgNMEA __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgNMEA __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgNMEA_
{
  using Type = CfgNMEA_<ContainerAllocator>;

  explicit CfgNMEA_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter = 0;
      this->nmea_version = 0;
      this->num_sv = 0;
      this->flags = 0;
      this->gnss_to_filter = 0ul;
      this->sv_numbering = 0;
      this->main_talker_id = 0;
      this->gsv_talker_id = 0;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->bds_talker_id.begin(), this->bds_talker_id.end(), 0);
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  explicit CfgNMEA_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bds_talker_id(_alloc),
    reserved1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filter = 0;
      this->nmea_version = 0;
      this->num_sv = 0;
      this->flags = 0;
      this->gnss_to_filter = 0ul;
      this->sv_numbering = 0;
      this->main_talker_id = 0;
      this->gsv_talker_id = 0;
      this->version = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->bds_talker_id.begin(), this->bds_talker_id.end(), 0);
      std::fill<typename std::array<uint8_t, 6>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
    }
  }

  // field types and members
  using _filter_type =
    uint8_t;
  _filter_type filter;
  using _nmea_version_type =
    uint8_t;
  _nmea_version_type nmea_version;
  using _num_sv_type =
    uint8_t;
  _num_sv_type num_sv;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _gnss_to_filter_type =
    uint32_t;
  _gnss_to_filter_type gnss_to_filter;
  using _sv_numbering_type =
    uint8_t;
  _sv_numbering_type sv_numbering;
  using _main_talker_id_type =
    uint8_t;
  _main_talker_id_type main_talker_id;
  using _gsv_talker_id_type =
    uint8_t;
  _gsv_talker_id_type gsv_talker_id;
  using _version_type =
    uint8_t;
  _version_type version;
  using _bds_talker_id_type =
    std::array<uint8_t, 2>;
  _bds_talker_id_type bds_talker_id;
  using _reserved1_type =
    std::array<uint8_t, 6>;
  _reserved1_type reserved1;

  // setters for named parameter idiom
  Type & set__filter(
    const uint8_t & _arg)
  {
    this->filter = _arg;
    return *this;
  }
  Type & set__nmea_version(
    const uint8_t & _arg)
  {
    this->nmea_version = _arg;
    return *this;
  }
  Type & set__num_sv(
    const uint8_t & _arg)
  {
    this->num_sv = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__gnss_to_filter(
    const uint32_t & _arg)
  {
    this->gnss_to_filter = _arg;
    return *this;
  }
  Type & set__sv_numbering(
    const uint8_t & _arg)
  {
    this->sv_numbering = _arg;
    return *this;
  }
  Type & set__main_talker_id(
    const uint8_t & _arg)
  {
    this->main_talker_id = _arg;
    return *this;
  }
  Type & set__gsv_talker_id(
    const uint8_t & _arg)
  {
    this->gsv_talker_id = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__bds_talker_id(
    const std::array<uint8_t, 2> & _arg)
  {
    this->bds_talker_id = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 6> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    23u;
  static constexpr uint8_t FILTER_POS =
    1u;
  static constexpr uint8_t FILTER_MSK_POS =
    2u;
  static constexpr uint8_t FILTER_TIME =
    4u;
  static constexpr uint8_t FILTER_DATE =
    8u;
  static constexpr uint8_t FILTER_GPS_ONLY =
    16u;
  static constexpr uint8_t FILTER_TRACK =
    32u;
  static constexpr uint8_t NMEA_VERSION_4_1 =
    65u;
  static constexpr uint8_t NMEA_VERSION_4_0 =
    64u;
  static constexpr uint8_t NMEA_VERSION_2_3 =
    35u;
  static constexpr uint8_t NMEA_VERSION_2_1 =
    33u;
  static constexpr uint8_t NUM_SV_UNLIMITED =
    0u;
  static constexpr uint8_t FLAGS_COMPAT =
    1u;
  static constexpr uint8_t FLAGS_CONSIDER =
    2u;
  static constexpr uint8_t FLAGS_LIMIT82 =
    4u;
  static constexpr uint8_t FLAGS_HIGH_PREC =
    8u;
  static constexpr uint32_t GNSS_TO_FILTER_GPS =
    1u;
  static constexpr uint32_t GNSS_TO_FILTER_SBAS =
    2u;
  static constexpr uint32_t GNSS_TO_FILTER_QZSS =
    16u;
  static constexpr uint32_t GNSS_TO_FILTER_GLONASS =
    32u;
  static constexpr uint32_t GNSS_TO_FILTER_BEIDOU =
    64u;
  static constexpr uint8_t SV_NUMBERING_STRICT =
    0u;
  static constexpr uint8_t SV_NUMBERING_EXTENDED =
    1u;
  static constexpr uint8_t MAIN_TALKER_ID_NOT_OVERRIDDEN =
    0u;
  static constexpr uint8_t MAIN_TALKER_ID_GP =
    1u;
  static constexpr uint8_t MAIN_TALKER_ID_GL =
    2u;
  static constexpr uint8_t MAIN_TALKER_ID_GN =
    3u;
  static constexpr uint8_t MAIN_TALKER_ID_GA =
    4u;
  static constexpr uint8_t MAIN_TALKER_ID_GB =
    5u;
  static constexpr uint8_t GSV_TALKER_ID_GNSS_SPECIFIC =
    0u;
  static constexpr uint8_t GSV_TALKER_ID_MAIN =
    1u;
  static constexpr uint8_t VERSION =
    1u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgNMEA_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgNMEA_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNMEA_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgNMEA_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgNMEA
    std::shared_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgNMEA
    std::shared_ptr<ublox_msgs::msg::CfgNMEA_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgNMEA_ & other) const
  {
    if (this->filter != other.filter) {
      return false;
    }
    if (this->nmea_version != other.nmea_version) {
      return false;
    }
    if (this->num_sv != other.num_sv) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->gnss_to_filter != other.gnss_to_filter) {
      return false;
    }
    if (this->sv_numbering != other.sv_numbering) {
      return false;
    }
    if (this->main_talker_id != other.main_talker_id) {
      return false;
    }
    if (this->gsv_talker_id != other.gsv_talker_id) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->bds_talker_id != other.bds_talker_id) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgNMEA_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgNMEA_

// alias to use template instance with default allocator
using CfgNMEA =
  ublox_msgs::msg::CfgNMEA_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FILTER_POS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FILTER_MSK_POS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FILTER_TIME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FILTER_DATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FILTER_GPS_ONLY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FILTER_TRACK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::NMEA_VERSION_4_1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::NMEA_VERSION_4_0;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::NMEA_VERSION_2_3;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::NMEA_VERSION_2_1;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::NUM_SV_UNLIMITED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FLAGS_COMPAT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FLAGS_CONSIDER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FLAGS_LIMIT82;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::FLAGS_HIGH_PREC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgNMEA_<ContainerAllocator>::GNSS_TO_FILTER_GPS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgNMEA_<ContainerAllocator>::GNSS_TO_FILTER_SBAS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgNMEA_<ContainerAllocator>::GNSS_TO_FILTER_QZSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgNMEA_<ContainerAllocator>::GNSS_TO_FILTER_GLONASS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgNMEA_<ContainerAllocator>::GNSS_TO_FILTER_BEIDOU;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::SV_NUMBERING_STRICT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::SV_NUMBERING_EXTENDED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::MAIN_TALKER_ID_NOT_OVERRIDDEN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::MAIN_TALKER_ID_GP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::MAIN_TALKER_ID_GL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::MAIN_TALKER_ID_GN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::MAIN_TALKER_ID_GA;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::MAIN_TALKER_ID_GB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::GSV_TALKER_ID_GNSS_SPECIFIC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::GSV_TALKER_ID_MAIN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgNMEA_<ContainerAllocator>::VERSION;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__STRUCT_HPP_
