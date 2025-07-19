// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/EsfSTATUSSens.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__EsfSTATUSSens __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__EsfSTATUSSens __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EsfSTATUSSens_
{
  using Type = EsfSTATUSSens_<ContainerAllocator>;

  explicit EsfSTATUSSens_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sens_status1 = 0;
      this->sens_status2 = 0;
      this->freq = 0;
      this->faults = 0;
    }
  }

  explicit EsfSTATUSSens_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sens_status1 = 0;
      this->sens_status2 = 0;
      this->freq = 0;
      this->faults = 0;
    }
  }

  // field types and members
  using _sens_status1_type =
    uint8_t;
  _sens_status1_type sens_status1;
  using _sens_status2_type =
    uint8_t;
  _sens_status2_type sens_status2;
  using _freq_type =
    uint8_t;
  _freq_type freq;
  using _faults_type =
    uint8_t;
  _faults_type faults;

  // setters for named parameter idiom
  Type & set__sens_status1(
    const uint8_t & _arg)
  {
    this->sens_status1 = _arg;
    return *this;
  }
  Type & set__sens_status2(
    const uint8_t & _arg)
  {
    this->sens_status2 = _arg;
    return *this;
  }
  Type & set__freq(
    const uint8_t & _arg)
  {
    this->freq = _arg;
    return *this;
  }
  Type & set__faults(
    const uint8_t & _arg)
  {
    this->faults = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__EsfSTATUSSens
    std::shared_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__EsfSTATUSSens
    std::shared_ptr<ublox_msgs::msg::EsfSTATUSSens_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EsfSTATUSSens_ & other) const
  {
    if (this->sens_status1 != other.sens_status1) {
      return false;
    }
    if (this->sens_status2 != other.sens_status2) {
      return false;
    }
    if (this->freq != other.freq) {
      return false;
    }
    if (this->faults != other.faults) {
      return false;
    }
    return true;
  }
  bool operator!=(const EsfSTATUSSens_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EsfSTATUSSens_

// alias to use template instance with default allocator
using EsfSTATUSSens =
  ublox_msgs::msg::EsfSTATUSSens_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_STATUS_SENS__STRUCT_HPP_
