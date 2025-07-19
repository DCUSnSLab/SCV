// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hunter_msgs:msg/HunterActuatorState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__STRUCT_HPP_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hunter_msgs__msg__HunterActuatorState __attribute__((deprecated))
#else
# define DEPRECATED__hunter_msgs__msg__HunterActuatorState __declspec(deprecated)
#endif

namespace hunter_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HunterActuatorState_
{
  using Type = HunterActuatorState_<ContainerAllocator>;

  explicit HunterActuatorState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->rpm = 0;
      this->current = 0.0;
      this->pulse_count = 0l;
      this->driver_voltage = 0.0f;
      this->driver_temperature = 0.0f;
      this->motor_temperature = 0;
      this->driver_state = 0;
    }
  }

  explicit HunterActuatorState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->rpm = 0;
      this->current = 0.0;
      this->pulse_count = 0l;
      this->driver_voltage = 0.0f;
      this->driver_temperature = 0.0f;
      this->motor_temperature = 0;
      this->driver_state = 0;
    }
  }

  // field types and members
  using _motor_id_type =
    uint8_t;
  _motor_id_type motor_id;
  using _rpm_type =
    int16_t;
  _rpm_type rpm;
  using _current_type =
    double;
  _current_type current;
  using _pulse_count_type =
    int32_t;
  _pulse_count_type pulse_count;
  using _driver_voltage_type =
    float;
  _driver_voltage_type driver_voltage;
  using _driver_temperature_type =
    float;
  _driver_temperature_type driver_temperature;
  using _motor_temperature_type =
    int8_t;
  _motor_temperature_type motor_temperature;
  using _driver_state_type =
    uint8_t;
  _driver_state_type driver_state;

  // setters for named parameter idiom
  Type & set__motor_id(
    const uint8_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__rpm(
    const int16_t & _arg)
  {
    this->rpm = _arg;
    return *this;
  }
  Type & set__current(
    const double & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__pulse_count(
    const int32_t & _arg)
  {
    this->pulse_count = _arg;
    return *this;
  }
  Type & set__driver_voltage(
    const float & _arg)
  {
    this->driver_voltage = _arg;
    return *this;
  }
  Type & set__driver_temperature(
    const float & _arg)
  {
    this->driver_temperature = _arg;
    return *this;
  }
  Type & set__motor_temperature(
    const int8_t & _arg)
  {
    this->motor_temperature = _arg;
    return *this;
  }
  Type & set__driver_state(
    const uint8_t & _arg)
  {
    this->driver_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hunter_msgs::msg::HunterActuatorState_<ContainerAllocator> *;
  using ConstRawPtr =
    const hunter_msgs::msg::HunterActuatorState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hunter_msgs::msg::HunterActuatorState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hunter_msgs::msg::HunterActuatorState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hunter_msgs__msg__HunterActuatorState
    std::shared_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hunter_msgs__msg__HunterActuatorState
    std::shared_ptr<hunter_msgs::msg::HunterActuatorState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HunterActuatorState_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->rpm != other.rpm) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->pulse_count != other.pulse_count) {
      return false;
    }
    if (this->driver_voltage != other.driver_voltage) {
      return false;
    }
    if (this->driver_temperature != other.driver_temperature) {
      return false;
    }
    if (this->motor_temperature != other.motor_temperature) {
      return false;
    }
    if (this->driver_state != other.driver_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const HunterActuatorState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HunterActuatorState_

// alias to use template instance with default allocator
using HunterActuatorState =
  hunter_msgs::msg::HunterActuatorState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hunter_msgs

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__STRUCT_HPP_
