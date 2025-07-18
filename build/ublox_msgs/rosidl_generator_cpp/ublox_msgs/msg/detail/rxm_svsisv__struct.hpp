// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmSVSISV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmSVSISV __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmSVSISV __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmSVSISV_
{
  using Type = RxmSVSISV_<ContainerAllocator>;

  explicit RxmSVSISV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0;
      this->sv_flag = 0;
      this->azim = 0;
      this->elev = 0;
      this->age = 0;
    }
  }

  explicit RxmSVSISV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0;
      this->sv_flag = 0;
      this->azim = 0;
      this->elev = 0;
      this->age = 0;
    }
  }

  // field types and members
  using _svid_type =
    uint8_t;
  _svid_type svid;
  using _sv_flag_type =
    uint8_t;
  _sv_flag_type sv_flag;
  using _azim_type =
    int16_t;
  _azim_type azim;
  using _elev_type =
    int8_t;
  _elev_type elev;
  using _age_type =
    uint8_t;
  _age_type age;

  // setters for named parameter idiom
  Type & set__svid(
    const uint8_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__sv_flag(
    const uint8_t & _arg)
  {
    this->sv_flag = _arg;
    return *this;
  }
  Type & set__azim(
    const int16_t & _arg)
  {
    this->azim = _arg;
    return *this;
  }
  Type & set__elev(
    const int8_t & _arg)
  {
    this->elev = _arg;
    return *this;
  }
  Type & set__age(
    const uint8_t & _arg)
  {
    this->age = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t FLAG_URA_MASK =
    15u;
  static constexpr uint8_t FLAG_HEALTHY =
    16u;
  static constexpr uint8_t FLAG_EPH_VAL =
    32u;
  static constexpr uint8_t FLAG_ALM_VAL =
    64u;
  static constexpr uint8_t FLAG_NOT_AVAIL =
    128u;
  static constexpr uint8_t AGE_ALM_MASK =
    15u;
  static constexpr uint8_t AGE_EPH_MASK =
    240u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmSVSISV_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmSVSISV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmSVSISV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmSVSISV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmSVSISV
    std::shared_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmSVSISV
    std::shared_ptr<ublox_msgs::msg::RxmSVSISV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmSVSISV_ & other) const
  {
    if (this->svid != other.svid) {
      return false;
    }
    if (this->sv_flag != other.sv_flag) {
      return false;
    }
    if (this->azim != other.azim) {
      return false;
    }
    if (this->elev != other.elev) {
      return false;
    }
    if (this->age != other.age) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmSVSISV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmSVSISV_

// alias to use template instance with default allocator
using RxmSVSISV =
  ublox_msgs::msg::RxmSVSISV_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSVSISV_<ContainerAllocator>::FLAG_URA_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSVSISV_<ContainerAllocator>::FLAG_HEALTHY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSVSISV_<ContainerAllocator>::FLAG_EPH_VAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSVSISV_<ContainerAllocator>::FLAG_ALM_VAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSVSISV_<ContainerAllocator>::FLAG_NOT_AVAIL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSVSISV_<ContainerAllocator>::AGE_ALM_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSVSISV_<ContainerAllocator>::AGE_EPH_MASK;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SVSISV__STRUCT_HPP_
