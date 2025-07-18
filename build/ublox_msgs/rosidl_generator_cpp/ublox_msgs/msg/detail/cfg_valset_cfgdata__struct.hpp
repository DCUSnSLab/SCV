// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/CfgVALSETCfgdata.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__CfgVALSETCfgdata __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__CfgVALSETCfgdata __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CfgVALSETCfgdata_
{
  using Type = CfgVALSETCfgdata_<ContainerAllocator>;

  explicit CfgVALSETCfgdata_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = 0ul;
    }
  }

  explicit CfgVALSETCfgdata_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = 0ul;
    }
  }

  // field types and members
  using _key_type =
    uint32_t;
  _key_type key;
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__key(
    const uint32_t & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t GPS_ENABLE =
    271646751u;
  static constexpr uint32_t GPS_L1CA_ENABLE =
    271646721u;
  static constexpr uint32_t GPS_L2C_ENABLE =
    271646723u;
  static constexpr uint32_t SBAS_ENABLE =
    271646752u;
  static constexpr uint32_t SBAS_L1CA_ENABLE =
    271646725u;
  static constexpr uint32_t GAL_ENABLE =
    271646753u;
  static constexpr uint32_t GAL_E1_ENABLE =
    271646727u;
  static constexpr uint32_t GAL_E5B_ENABLE =
    271646730u;
  static constexpr uint32_t BDS_ENABLE =
    271646754u;
  static constexpr uint32_t BDS_B1_ENABLE =
    271646733u;
  static constexpr uint32_t BDS_B2_ENABLE =
    271646734u;
  static constexpr uint32_t QZSS_ENABLE =
    271646756u;
  static constexpr uint32_t QZSS_L1CA_ENABLE =
    271646738u;
  static constexpr uint32_t QZSS_L1S_ENABLE =
    271646740u;
  static constexpr uint32_t QZSS_L2C_ENABLE =
    271646741u;
  static constexpr uint32_t GLO_ENABLE =
    271646757u;
  static constexpr uint32_t GLO_L1_ENABLE =
    271646744u;
  static constexpr uint32_t GLO_L2_ENABLE =
    271646746u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__CfgVALSETCfgdata
    std::shared_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__CfgVALSETCfgdata
    std::shared_ptr<ublox_msgs::msg::CfgVALSETCfgdata_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CfgVALSETCfgdata_ & other) const
  {
    if (this->key != other.key) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const CfgVALSETCfgdata_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CfgVALSETCfgdata_

// alias to use template instance with default allocator
using CfgVALSETCfgdata =
  ublox_msgs::msg::CfgVALSETCfgdata_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GPS_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GPS_L1CA_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GPS_L2C_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::SBAS_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::SBAS_L1CA_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GAL_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GAL_E1_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GAL_E5B_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::BDS_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::BDS_B1_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::BDS_B2_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::QZSS_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::QZSS_L1CA_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::QZSS_L1S_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::QZSS_L2C_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GLO_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GLO_L1_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t CfgVALSETCfgdata_<ContainerAllocator>::GLO_L2_ENABLE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__STRUCT_HPP_
