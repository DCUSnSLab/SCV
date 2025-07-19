// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'blocks'
#include "ublox_msgs/msg/detail/cfg_gnss_block__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgGNSS __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgGNSS __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgGNSS_
{
  using Type = CfgGNSS_<ContainerAllocator>;

  explicit CfgGNSS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_ver = 0;
      this->num_trk_ch_hw = 0;
      this->num_trk_ch_use = 0;
      this->num_config_blocks = 0;
    }
  }

  explicit CfgGNSS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_ver = 0;
      this->num_trk_ch_hw = 0;
      this->num_trk_ch_use = 0;
      this->num_config_blocks = 0;
    }
  }

  // field types and members
  using _msg_ver_type =
    uint8_t;
  _msg_ver_type msg_ver;
  using _num_trk_ch_hw_type =
    uint8_t;
  _num_trk_ch_hw_type num_trk_ch_hw;
  using _num_trk_ch_use_type =
    uint8_t;
  _num_trk_ch_use_type num_trk_ch_use;
  using _num_config_blocks_type =
    uint8_t;
  _num_config_blocks_type num_config_blocks;
  using _blocks_type =
    std::vector<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>>>;
  _blocks_type blocks;

  // setters for named parameter idiom
  Type & set__msg_ver(
    const uint8_t & _arg)
  {
    this->msg_ver = _arg;
    return *this;
  }
  Type & set__num_trk_ch_hw(
    const uint8_t & _arg)
  {
    this->num_trk_ch_hw = _arg;
    return *this;
  }
  Type & set__num_trk_ch_use(
    const uint8_t & _arg)
  {
    this->num_trk_ch_use = _arg;
    return *this;
  }
  Type & set__num_config_blocks(
    const uint8_t & _arg)
  {
    this->num_config_blocks = _arg;
    return *this;
  }
  Type & set__blocks(
    const std::vector<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ublox_msgs::msg::CfgGNSSBlock_<ContainerAllocator>>> & _arg)
  {
    this->blocks = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    6u;
  static constexpr uint8_t MESSAGE_ID =
    62u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgGNSS_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgGNSS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgGNSS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgGNSS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgGNSS
    std::shared_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgGNSS
    std::shared_ptr<ublox_msgs::msg::CfgGNSS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgGNSS_ & other) const
  {
    if (this->msg_ver != other.msg_ver) {
      return false;
    }
    if (this->num_trk_ch_hw != other.num_trk_ch_hw) {
      return false;
    }
    if (this->num_trk_ch_use != other.num_trk_ch_use) {
      return false;
    }
    if (this->num_config_blocks != other.num_config_blocks) {
      return false;
    }
    if (this->blocks != other.blocks) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgGNSS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgGNSS_

// alias to use template instance with default allocator
using CfgGNSS =
  ublox_msgs::msg::CfgGNSS_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSS_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CfgGNSS_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__STRUCT_HPP_
