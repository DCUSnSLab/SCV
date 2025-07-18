// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmEPH.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_EPH__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_EPH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmEPH __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmEPH __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmEPH_
{
  using Type = RxmEPH_<ContainerAllocator>;

  explicit RxmEPH_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0ul;
      this->how = 0ul;
    }
  }

  explicit RxmEPH_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->svid = 0ul;
      this->how = 0ul;
    }
  }

  // field types and members
  using _svid_type =
    uint32_t;
  _svid_type svid;
  using _how_type =
    uint32_t;
  _how_type how;
  using _sf1d_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _sf1d_type sf1d;
  using _sf2d_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _sf2d_type sf2d;
  using _sf3d_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _sf3d_type sf3d;

  // setters for named parameter idiom
  Type & set__svid(
    const uint32_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__how(
    const uint32_t & _arg)
  {
    this->how = _arg;
    return *this;
  }
  Type & set__sf1d(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->sf1d = _arg;
    return *this;
  }
  Type & set__sf2d(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->sf2d = _arg;
    return *this;
  }
  Type & set__sf3d(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->sf3d = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    2u;
  static constexpr uint8_t MESSAGE_ID =
    49u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmEPH_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmEPH_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmEPH_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmEPH_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmEPH
    std::shared_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmEPH
    std::shared_ptr<ublox_msgs::msg::RxmEPH_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmEPH_ & other) const
  {
    if (this->svid != other.svid) {
      return false;
    }
    if (this->how != other.how) {
      return false;
    }
    if (this->sf1d != other.sf1d) {
      return false;
    }
    if (this->sf2d != other.sf2d) {
      return false;
    }
    if (this->sf3d != other.sf3d) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmEPH_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmEPH_

// alias to use template instance with default allocator
using RxmEPH =
  ublox_msgs::msg::RxmEPH_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmEPH_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmEPH_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_EPH__STRUCT_HPP_
