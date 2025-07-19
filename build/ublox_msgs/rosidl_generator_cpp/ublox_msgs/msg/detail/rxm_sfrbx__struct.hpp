// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/RxmSFRBX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__RxmSFRBX __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__RxmSFRBX __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RxmSFRBX_
{
  using Type = RxmSFRBX_<ContainerAllocator>;

  explicit RxmSFRBX_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gnss_id = 0;
      this->sv_id = 0;
      this->reserved0 = 0;
      this->freq_id = 0;
      this->num_words = 0;
      this->chn = 0;
      this->version = 0;
      this->reserved1 = 0;
    }
  }

  explicit RxmSFRBX_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gnss_id = 0;
      this->sv_id = 0;
      this->reserved0 = 0;
      this->freq_id = 0;
      this->num_words = 0;
      this->chn = 0;
      this->version = 0;
      this->reserved1 = 0;
    }
  }

  // field types and members
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
  using _num_words_type =
    uint8_t;
  _num_words_type num_words;
  using _chn_type =
    uint8_t;
  _chn_type chn;
  using _version_type =
    uint8_t;
  _version_type version;
  using _reserved1_type =
    uint8_t;
  _reserved1_type reserved1;
  using _dwrd_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _dwrd_type dwrd;

  // setters for named parameter idiom
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
  Type & set__num_words(
    const uint8_t & _arg)
  {
    this->num_words = _arg;
    return *this;
  }
  Type & set__chn(
    const uint8_t & _arg)
  {
    this->chn = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__reserved1(
    const uint8_t & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__dwrd(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->dwrd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    2u;
  static constexpr uint8_t MESSAGE_ID =
    19u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::RxmSFRBX_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::RxmSFRBX_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmSFRBX_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::RxmSFRBX_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__RxmSFRBX
    std::shared_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__RxmSFRBX
    std::shared_ptr<ublox_msgs::msg::RxmSFRBX_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RxmSFRBX_ & other) const
  {
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
    if (this->num_words != other.num_words) {
      return false;
    }
    if (this->chn != other.chn) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->dwrd != other.dwrd) {
      return false;
    }
    return true;
  }
  bool operator!=(const RxmSFRBX_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RxmSFRBX_

// alias to use template instance with default allocator
using RxmSFRBX =
  ublox_msgs::msg::RxmSFRBX_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSFRBX_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RxmSFRBX_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__STRUCT_HPP_
