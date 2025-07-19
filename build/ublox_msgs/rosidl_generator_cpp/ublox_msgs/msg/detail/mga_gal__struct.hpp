// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ublox_msgs:msg/MgaGAL.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__MGA_GAL__STRUCT_HPP_
#define UBLOX_MSGS__MSG__DETAIL__MGA_GAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ublox_msgs__msg__MgaGAL __attribute__((deprecated))
#else
# define DEPRECATED__ublox_msgs__msg__MgaGAL __declspec(deprecated)
#endif

namespace ublox_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MgaGAL_
{
  using Type = MgaGAL_<ContainerAllocator>;

  explicit MgaGAL_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->version = 0;
      this->svid = 0;
      this->reserved0 = 0;
      this->iod_nav = 0;
      this->delta_n = 0;
      this->m0 = 0l;
      this->e = 0ul;
      this->sqrt_a = 0ul;
      this->omega0 = 0l;
      this->i0 = 0l;
      this->omega = 0l;
      this->omega_dot = 0l;
      this->i_dot = 0;
      this->cuc = 0;
      this->cus = 0;
      this->crc = 0;
      this->crs = 0;
      this->cic = 0;
      this->cis = 0;
      this->toe = 0;
      this->af0 = 0l;
      this->af1 = 0l;
      this->af2 = 0;
      this->sisaindex_e1_e5b = 0;
      this->toc = 0;
      this->bgd_e1_e5b = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->health_e1b = 0;
      this->data_validity_e1b = 0;
      this->health_e5b = 0;
      this->data_validity_e5b = 0;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
    }
  }

  explicit MgaGAL_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reserved1(_alloc),
    reserved2(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->version = 0;
      this->svid = 0;
      this->reserved0 = 0;
      this->iod_nav = 0;
      this->delta_n = 0;
      this->m0 = 0l;
      this->e = 0ul;
      this->sqrt_a = 0ul;
      this->omega0 = 0l;
      this->i0 = 0l;
      this->omega = 0l;
      this->omega_dot = 0l;
      this->i_dot = 0;
      this->cuc = 0;
      this->cus = 0;
      this->crc = 0;
      this->crs = 0;
      this->cic = 0;
      this->cis = 0;
      this->toe = 0;
      this->af0 = 0l;
      this->af1 = 0l;
      this->af2 = 0;
      this->sisaindex_e1_e5b = 0;
      this->toc = 0;
      this->bgd_e1_e5b = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->reserved1.begin(), this->reserved1.end(), 0);
      this->health_e1b = 0;
      this->data_validity_e1b = 0;
      this->health_e5b = 0;
      this->data_validity_e5b = 0;
      std::fill<typename std::array<uint8_t, 4>::iterator, uint8_t>(this->reserved2.begin(), this->reserved2.end(), 0);
    }
  }

  // field types and members
  using _type_type =
    uint8_t;
  _type_type type;
  using _version_type =
    uint8_t;
  _version_type version;
  using _svid_type =
    uint8_t;
  _svid_type svid;
  using _reserved0_type =
    uint8_t;
  _reserved0_type reserved0;
  using _iod_nav_type =
    uint16_t;
  _iod_nav_type iod_nav;
  using _delta_n_type =
    int16_t;
  _delta_n_type delta_n;
  using _m0_type =
    int32_t;
  _m0_type m0;
  using _e_type =
    uint32_t;
  _e_type e;
  using _sqrt_a_type =
    uint32_t;
  _sqrt_a_type sqrt_a;
  using _omega0_type =
    int32_t;
  _omega0_type omega0;
  using _i0_type =
    int32_t;
  _i0_type i0;
  using _omega_type =
    int32_t;
  _omega_type omega;
  using _omega_dot_type =
    int32_t;
  _omega_dot_type omega_dot;
  using _i_dot_type =
    int16_t;
  _i_dot_type i_dot;
  using _cuc_type =
    int16_t;
  _cuc_type cuc;
  using _cus_type =
    int16_t;
  _cus_type cus;
  using _crc_type =
    int16_t;
  _crc_type crc;
  using _crs_type =
    int16_t;
  _crs_type crs;
  using _cic_type =
    int16_t;
  _cic_type cic;
  using _cis_type =
    int16_t;
  _cis_type cis;
  using _toe_type =
    uint16_t;
  _toe_type toe;
  using _af0_type =
    int32_t;
  _af0_type af0;
  using _af1_type =
    int32_t;
  _af1_type af1;
  using _af2_type =
    int8_t;
  _af2_type af2;
  using _sisaindex_e1_e5b_type =
    uint8_t;
  _sisaindex_e1_e5b_type sisaindex_e1_e5b;
  using _toc_type =
    uint16_t;
  _toc_type toc;
  using _bgd_e1_e5b_type =
    int16_t;
  _bgd_e1_e5b_type bgd_e1_e5b;
  using _reserved1_type =
    std::array<uint8_t, 2>;
  _reserved1_type reserved1;
  using _health_e1b_type =
    uint8_t;
  _health_e1b_type health_e1b;
  using _data_validity_e1b_type =
    uint8_t;
  _data_validity_e1b_type data_validity_e1b;
  using _health_e5b_type =
    uint8_t;
  _health_e5b_type health_e5b;
  using _data_validity_e5b_type =
    uint8_t;
  _data_validity_e5b_type data_validity_e5b;
  using _reserved2_type =
    std::array<uint8_t, 4>;
  _reserved2_type reserved2;

  // setters for named parameter idiom
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__svid(
    const uint8_t & _arg)
  {
    this->svid = _arg;
    return *this;
  }
  Type & set__reserved0(
    const uint8_t & _arg)
  {
    this->reserved0 = _arg;
    return *this;
  }
  Type & set__iod_nav(
    const uint16_t & _arg)
  {
    this->iod_nav = _arg;
    return *this;
  }
  Type & set__delta_n(
    const int16_t & _arg)
  {
    this->delta_n = _arg;
    return *this;
  }
  Type & set__m0(
    const int32_t & _arg)
  {
    this->m0 = _arg;
    return *this;
  }
  Type & set__e(
    const uint32_t & _arg)
  {
    this->e = _arg;
    return *this;
  }
  Type & set__sqrt_a(
    const uint32_t & _arg)
  {
    this->sqrt_a = _arg;
    return *this;
  }
  Type & set__omega0(
    const int32_t & _arg)
  {
    this->omega0 = _arg;
    return *this;
  }
  Type & set__i0(
    const int32_t & _arg)
  {
    this->i0 = _arg;
    return *this;
  }
  Type & set__omega(
    const int32_t & _arg)
  {
    this->omega = _arg;
    return *this;
  }
  Type & set__omega_dot(
    const int32_t & _arg)
  {
    this->omega_dot = _arg;
    return *this;
  }
  Type & set__i_dot(
    const int16_t & _arg)
  {
    this->i_dot = _arg;
    return *this;
  }
  Type & set__cuc(
    const int16_t & _arg)
  {
    this->cuc = _arg;
    return *this;
  }
  Type & set__cus(
    const int16_t & _arg)
  {
    this->cus = _arg;
    return *this;
  }
  Type & set__crc(
    const int16_t & _arg)
  {
    this->crc = _arg;
    return *this;
  }
  Type & set__crs(
    const int16_t & _arg)
  {
    this->crs = _arg;
    return *this;
  }
  Type & set__cic(
    const int16_t & _arg)
  {
    this->cic = _arg;
    return *this;
  }
  Type & set__cis(
    const int16_t & _arg)
  {
    this->cis = _arg;
    return *this;
  }
  Type & set__toe(
    const uint16_t & _arg)
  {
    this->toe = _arg;
    return *this;
  }
  Type & set__af0(
    const int32_t & _arg)
  {
    this->af0 = _arg;
    return *this;
  }
  Type & set__af1(
    const int32_t & _arg)
  {
    this->af1 = _arg;
    return *this;
  }
  Type & set__af2(
    const int8_t & _arg)
  {
    this->af2 = _arg;
    return *this;
  }
  Type & set__sisaindex_e1_e5b(
    const uint8_t & _arg)
  {
    this->sisaindex_e1_e5b = _arg;
    return *this;
  }
  Type & set__toc(
    const uint16_t & _arg)
  {
    this->toc = _arg;
    return *this;
  }
  Type & set__bgd_e1_e5b(
    const int16_t & _arg)
  {
    this->bgd_e1_e5b = _arg;
    return *this;
  }
  Type & set__reserved1(
    const std::array<uint8_t, 2> & _arg)
  {
    this->reserved1 = _arg;
    return *this;
  }
  Type & set__health_e1b(
    const uint8_t & _arg)
  {
    this->health_e1b = _arg;
    return *this;
  }
  Type & set__data_validity_e1b(
    const uint8_t & _arg)
  {
    this->data_validity_e1b = _arg;
    return *this;
  }
  Type & set__health_e5b(
    const uint8_t & _arg)
  {
    this->health_e5b = _arg;
    return *this;
  }
  Type & set__data_validity_e5b(
    const uint8_t & _arg)
  {
    this->data_validity_e5b = _arg;
    return *this;
  }
  Type & set__reserved2(
    const std::array<uint8_t, 4> & _arg)
  {
    this->reserved2 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_ID =
    19u;
  static constexpr uint8_t MESSAGE_ID =
    2u;

  // pointer types
  using RawPtr =
    ublox_msgs::msg::MgaGAL_<ContainerAllocator> *;
  using ConstRawPtr =
    const ublox_msgs::msg::MgaGAL_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MgaGAL_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ublox_msgs::msg::MgaGAL_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ublox_msgs__msg__MgaGAL
    std::shared_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ublox_msgs__msg__MgaGAL
    std::shared_ptr<ublox_msgs::msg::MgaGAL_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MgaGAL_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->svid != other.svid) {
      return false;
    }
    if (this->reserved0 != other.reserved0) {
      return false;
    }
    if (this->iod_nav != other.iod_nav) {
      return false;
    }
    if (this->delta_n != other.delta_n) {
      return false;
    }
    if (this->m0 != other.m0) {
      return false;
    }
    if (this->e != other.e) {
      return false;
    }
    if (this->sqrt_a != other.sqrt_a) {
      return false;
    }
    if (this->omega0 != other.omega0) {
      return false;
    }
    if (this->i0 != other.i0) {
      return false;
    }
    if (this->omega != other.omega) {
      return false;
    }
    if (this->omega_dot != other.omega_dot) {
      return false;
    }
    if (this->i_dot != other.i_dot) {
      return false;
    }
    if (this->cuc != other.cuc) {
      return false;
    }
    if (this->cus != other.cus) {
      return false;
    }
    if (this->crc != other.crc) {
      return false;
    }
    if (this->crs != other.crs) {
      return false;
    }
    if (this->cic != other.cic) {
      return false;
    }
    if (this->cis != other.cis) {
      return false;
    }
    if (this->toe != other.toe) {
      return false;
    }
    if (this->af0 != other.af0) {
      return false;
    }
    if (this->af1 != other.af1) {
      return false;
    }
    if (this->af2 != other.af2) {
      return false;
    }
    if (this->sisaindex_e1_e5b != other.sisaindex_e1_e5b) {
      return false;
    }
    if (this->toc != other.toc) {
      return false;
    }
    if (this->bgd_e1_e5b != other.bgd_e1_e5b) {
      return false;
    }
    if (this->reserved1 != other.reserved1) {
      return false;
    }
    if (this->health_e1b != other.health_e1b) {
      return false;
    }
    if (this->data_validity_e1b != other.data_validity_e1b) {
      return false;
    }
    if (this->health_e5b != other.health_e5b) {
      return false;
    }
    if (this->data_validity_e5b != other.data_validity_e5b) {
      return false;
    }
    if (this->reserved2 != other.reserved2) {
      return false;
    }
    return true;
  }
  bool operator!=(const MgaGAL_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MgaGAL_

// alias to use template instance with default allocator
using MgaGAL =
  ublox_msgs::msg::MgaGAL_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MgaGAL_<ContainerAllocator>::CLASS_ID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MgaGAL_<ContainerAllocator>::MESSAGE_ID;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__MGA_GAL__STRUCT_HPP_
