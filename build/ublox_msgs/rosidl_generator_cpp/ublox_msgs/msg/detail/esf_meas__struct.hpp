// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/EsfMEAS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_MEAS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_MEAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__EsfMEAS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__EsfMEAS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EsfMEAS_
{
  using Type = EsfMEAS_<ContainerAllocator>;

  explicit EsfMEAS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_tag = 0ul;
      this->flags = 0;
      this->id = 0;
    }
  }

  explicit EsfMEAS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_tag = 0ul;
      this->flags = 0;
      this->id = 0;
    }
  }

  // field types and members
  using _time_tag_type =
    uint32_t;
  _time_tag_type time_tag;
  using _flags_type =
    uint16_t;
  _flags_type flags;
  using _id_type =
    uint16_t;
  _id_type id;
  using _data_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _data_type data;
  using _calib_t_tag_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _calib_t_tag_type calib_t_tag;

  // setters for named parameter idiom
  Type & set__time_tag(
    const uint32_t & _arg)
  {
    this->time_tag = _arg;
    return *this;
  }
  Type & set__flags(
    const uint16_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__id(
    const uint16_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }
  Type & set__calib_t_tag(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->calib_t_tag = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    16u;
  static constexpr uint8_t MESSAGE_ID =
    2u;
  static constexpr uint16_t FLAGS_TIME_MARK_SENT_MASK =
    3u;
  static constexpr uint16_t TIME_MARK_NONE =
    0u;
  static constexpr uint16_t TIME_MARK_EXT0 =
    1u;
  static constexpr uint16_t TIME_MARK_EXT =
    2u;
  static constexpr uint16_t FLAGS_TIME_MARK_EDGE =
    4u;
  static constexpr uint16_t FLAGS_CALIB_T_TAG_VALID =
    8u;
  static constexpr uint32_t DATA_FIELD_MASK =
    16777215u;
  static constexpr uint32_t DATA_TYPE_MASK =
    1056964608u;
  static constexpr uint32_t DATA_TYPE_SHIFT =
    24u;
  static constexpr uint32_t DATA_TYPE_NONE =
    0u;
  static constexpr uint32_t DATA_TYPE_Z_AXIS_GYRO =
    5u;
  static constexpr uint32_t DATA_TYPE_WHEEL_TICKS_FRONT_LEFT =
    6u;
  static constexpr uint32_t DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT =
    7u;
  static constexpr uint32_t DATA_TYPE_WHEEL_TICKS_REAR_LEFT =
    8u;
  static constexpr uint32_t DATA_TYPE_WHEEL_TICKS_REAR_RIGHT =
    9u;
  static constexpr uint32_t DATA_TYPE_SINGLE_TICK =
    10u;
  static constexpr uint32_t DATA_TYPE_SPEED =
    11u;
  static constexpr uint32_t DATA_TYPE_GYRO_TEMPERATURE =
    12u;
  static constexpr uint32_t DATA_TYPE_GYRO_ANG_RATE_Y =
    13u;
  static constexpr uint32_t DATA_TYPE_GYRO_ANG_RATE_X =
    14u;
  static constexpr uint32_t DATA_TYPE_ACCELEROMETER_X =
    16u;
  static constexpr uint32_t DATA_TYPE_ACCELEROMETER_Y =
    17u;
  static constexpr uint32_t DATA_TYPE_ACCELEROMETER_Z =
    18u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::EsfMEAS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::EsfMEAS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfMEAS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfMEAS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__EsfMEAS
    std::shared_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__EsfMEAS
    std::shared_ptr<ublox_msgs::msg::EsfMEAS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EsfMEAS_ & other) const
  {
    if (this->time_tag != other.time_tag) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    if (this->calib_t_tag != other.calib_t_tag) {
      return false;
    }
    return true;
  }
  bool operator!=(const EsfMEAS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EsfMEAS_

// alias to use template instance with default allocator
using EsfMEAS =
  ublox_msgs::msg::EsfMEAS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfMEAS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EsfMEAS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EsfMEAS_<ContainerAllocator>::FLAGS_TIME_MARK_SENT_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EsfMEAS_<ContainerAllocator>::TIME_MARK_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EsfMEAS_<ContainerAllocator>::TIME_MARK_EXT0;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EsfMEAS_<ContainerAllocator>::TIME_MARK_EXT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EsfMEAS_<ContainerAllocator>::FLAGS_TIME_MARK_EDGE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EsfMEAS_<ContainerAllocator>::FLAGS_CALIB_T_TAG_VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_FIELD_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_MASK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_SHIFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_Z_AXIS_GYRO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_WHEEL_TICKS_FRONT_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_WHEEL_TICKS_REAR_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_WHEEL_TICKS_REAR_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_SINGLE_TICK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_SPEED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_GYRO_TEMPERATURE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_GYRO_ANG_RATE_Y;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_GYRO_ANG_RATE_X;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_ACCELEROMETER_X;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_ACCELEROMETER_Y;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t EsfMEAS_<ContainerAllocator>::DATA_TYPE_ACCELEROMETER_Z;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_MEAS__STRUCT_HPP_
