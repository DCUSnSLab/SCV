// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmRAWSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmRAWSV __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmRAWSV __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmRAWSV_
{
  using Type = RxmRAWSV_<ContainerAllocator>;

  explicit RxmRAWSV_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cp_mes = 0.0;
      this->pr_mes = 0.0;
      this->do_mes = 0.0f;
      this->sv = 0;
      this->mes_qi = 0;
      this->cno = 0;
      this->lli = 0;
    }
  }

  explicit RxmRAWSV_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cp_mes = 0.0;
      this->pr_mes = 0.0;
      this->do_mes = 0.0f;
      this->sv = 0;
      this->mes_qi = 0;
      this->cno = 0;
      this->lli = 0;
    }
  }

  // field types and members
  using _cp_mes_type =
    double;
  _cp_mes_type cp_mes;
  using _pr_mes_type =
    double;
  _pr_mes_type pr_mes;
  using _do_mes_type =
    float;
  _do_mes_type do_mes;
  using _sv_type =
    uint8_t;
  _sv_type sv;
  using _mes_qi_type =
    int8_t;
  _mes_qi_type mes_qi;
  using _cno_type =
    int8_t;
  _cno_type cno;
  using _lli_type =
    uint8_t;
  _lli_type lli;

  // setters for named parameter idiom
  Type & set__cp_mes(
    const double & _arg)
  {
    this->cp_mes = _arg;
    return *this;
  }
  Type & set__pr_mes(
    const double & _arg)
  {
    this->pr_mes = _arg;
    return *this;
  }
  Type & set__do_mes(
    const float & _arg)
  {
    this->do_mes = _arg;
    return *this;
  }
  Type & set__sv(
    const uint8_t & _arg)
  {
    this->sv = _arg;
    return *this;
  }
  Type & set__mes_qi(
    const int8_t & _arg)
  {
    this->mes_qi = _arg;
    return *this;
  }
  Type & set__cno(
    const int8_t & _arg)
  {
    this->cno = _arg;
    return *this;
  }
  Type & set__lli(
    const uint8_t & _arg)
  {
    this->lli = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmRAWSV_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmRAWSV_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmRAWSV
    std::shared_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmRAWSV
    std::shared_ptr<ublox_msgs::msg::RxmRAWSV_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmRAWSV_ & other) const
  {
    if (this->cp_mes != other.cp_mes) {
      return false;
    }
    if (this->pr_mes != other.pr_mes) {
      return false;
    }
    if (this->do_mes != other.do_mes) {
      return false;
    }
    if (this->sv != other.sv) {
      return false;
    }
    if (this->mes_qi != other.mes_qi) {
      return false;
    }
    if (this->cno != other.cno) {
      return false;
    }
    if (this->lli != other.lli) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmRAWSV_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmRAWSV_

// alias to use template instance with default allocator
using RxmRAWSV =
  ublox_msgs::msg::RxmRAWSV_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__STRUCT_HPP_
