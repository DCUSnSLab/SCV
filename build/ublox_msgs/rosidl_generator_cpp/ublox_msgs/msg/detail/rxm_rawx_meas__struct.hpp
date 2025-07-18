// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmRAWXMeas.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmRAWXMeas __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmRAWXMeas __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmRAWXMeas_
{
  using Type = RxmRAWXMeas_<ContainerAllocator>;

  explicit RxmRAWXMeas_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pr_mes = 0.0;
      this->cp_mes = 0.0;
      this->do_mes = 0.0f;
      this->gnss_id = 0;
      this->sv_id = 0;
      this->reserved0 = 0;
      this->freq_id = 0;
      this->locktime = 0;
      this->cno = 0;
      this->pr_stdev = 0;
      this->cp_stdev = 0;
      this->do_stdev = 0;
      this->trk_stat = 0;
      this->reserved1 = 0;
    }
  }

  explicit RxmRAWXMeas_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pr_mes = 0.0;
      this->cp_mes = 0.0;
      this->do_mes = 0.0f;
      this->gnss_id = 0;
      this->sv_id = 0;
      this->reserved0 = 0;
      this->freq_id = 0;
      this->locktime = 0;
      this->cno = 0;
      this->pr_stdev = 0;
      this->cp_stdev = 0;
      this->do_stdev = 0;
      this->trk_stat = 0;
      this->reserved1 = 0;
    }
  }

  // field types and members
  using _pr_mes_type =
    double;
  _pr_mes_type pr_mes;
  using _cp_mes_type =
    double;
  _cp_mes_type cp_mes;
  using _do_mes_type =
    float;
  _do_mes_type do_mes;
  using _gnss_id_type =
    uint8_t;
  _gnss_id_type gnss_id;
  using _sv_id_type =
    uint8_t;
  _sv_id_type sv_id;
  using _reserved0_type =
    uint8_t;
  _reserved0_type reserved0;
  using _freq_id_type =
    uint8_t;
  _freq_id_type freq_id;
  using _locktime_type =
    uint16_t;
  _locktime_type locktime;
  using _cno_type =
    int8_t;
  _cno_type cno;
  using _pr_stdev_type =
    uint8_t;
  _pr_stdev_type pr_stdev;
  using _cp_stdev_type =
    uint8_t;
  _cp_stdev_type cp_stdev;
  using _do_stdev_type =
    uint8_t;
  _do_stdev_type do_stdev;
  using _trk_stat_type =
    uint8_t;
  _trk_stat_type trk_stat;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;

  // setters for named parameter idiom
  Type & set__pr_mes(
    const double & _arg)
  {
    this->pr_mes = _arg;
    return *this;
  }
  Type & set__cp_mes(
    const double & _arg)
  {
    this->cp_mes = _arg;
    return *this;
  }
  Type & set__do_mes(
    const float & _arg)
  {
    this->do_mes = _arg;
    return *this;
  }
  Type & set__gnss_id(
    const uint8_t & _arg)
  {
    this->gnss_id = _arg;
    return *this;
  }
  Type & set__sv_id(
    const uint8_t & _arg)
  {
    this->sv_id = _arg;
    return *this;
  }
  Type & set__reserved0(
    const uint8_t & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__freq_id(
    const uint8_t & _arg)
  {
    this->freq_id = _arg;
    return *this;
  }
  Type & set__locktime(
    const uint16_t & _arg)
  {
    this->locktime = _arg;
    return *this;
  }
  Type & set__cno(
    const int8_t & _arg)
  {
    this->cno = _arg;
    return *this;
  }
  Type & set__pr_stdev(
    const uint8_t & _arg)
  {
    this->pr_stdev = _arg;
    return *this;
  }
  Type & set__cp_stdev(
    const uint8_t & _arg)
  {
    this->cp_stdev = _arg;
    return *this;
  }
  Type & set__do_stdev(
    const uint8_t & _arg)
  {
    this->do_stdev = _arg;
    return *this;
  }
  Type & set__trk_stat(
    const uint8_t & _arg)
  {
    this->trk_stat = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TRK_STAT_PR_VALID =
    1u;
  static constexpr uint8_t TRK_STAT_CP_VALID =
    2u;
  static constexpr uint8_t TRK_STAT_HALF_CYC =
    4u;
  static constexpr uint8_t TRK_STAT_SUB_HALF_CYC =
    8u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmRAWXMeas
    std::shared_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmRAWXMeas
    std::shared_ptr<ublox_msgs::msg::RxmRAWXMeas_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmRAWXMeas_ & other) const
  {
    if (this->pr_mes != other.pr_mes) {
      return false;
    }
    if (this->cp_mes != other.cp_mes) {
      return false;
    }
    if (this->do_mes != other.do_mes) {
      return false;
    }
    if (this->gnss_id != other.gnss_id) {
      return false;
    }
    if (this->sv_id != other.sv_id) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->freq_id != other.freq_id) {
      return false;
    }
    if (this->locktime != other.locktime) {
      return false;
    }
    if (this->cno != other.cno) {
      return false;
    }
    if (this->pr_stdev != other.pr_stdev) {
      return false;
    }
    if (this->cp_stdev != other.cp_stdev) {
      return false;
    }
    if (this->do_stdev != other.do_stdev) {
      return false;
    }
    if (this->trk_stat != other.trk_stat) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmRAWXMeas_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmRAWXMeas_

// alias to use template instance with default allocator
using RxmRAWXMeas =
  ublox_msgs::msg::RxmRAWXMeas_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWXMeas_<ContainerAllocator>::TRK_STAT_PR_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWXMeas_<ContainerAllocator>::TRK_STAT_CP_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWXMeas_<ContainerAllocator>::TRK_STAT_HALF_CYC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmRAWXMeas_<ContainerAllocator>::TRK_STAT_SUB_HALF_CYC;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__STRUCT_HPP_
