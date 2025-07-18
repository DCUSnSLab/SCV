// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/CfgUSB.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/cfg_usb__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ublox_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CfgUSB_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::CfgUSB(_init);
}

void CfgUSB_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::CfgUSB *>(message_memory);
  typed_message->~CfgUSB();
}

size_t size_function__CfgUSB__reserved1(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__CfgUSB__reserved1(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgUSB__reserved1(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgUSB__reserved1(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__CfgUSB__reserved1(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__CfgUSB__reserved1(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__CfgUSB__reserved1(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__CfgUSB__reserved2(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__CfgUSB__reserved2(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgUSB__reserved2(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgUSB__reserved2(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__CfgUSB__reserved2(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__CfgUSB__reserved2(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__CfgUSB__reserved2(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__CfgUSB__vendor_string(const void * untyped_member)
{
  (void)untyped_member;
  return 32;
}

const void * get_const_function__CfgUSB__vendor_string(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 32> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgUSB__vendor_string(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 32> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgUSB__vendor_string(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__CfgUSB__vendor_string(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__CfgUSB__vendor_string(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__CfgUSB__vendor_string(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

size_t size_function__CfgUSB__product_string(const void * untyped_member)
{
  (void)untyped_member;
  return 32;
}

const void * get_const_function__CfgUSB__product_string(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 32> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgUSB__product_string(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 32> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgUSB__product_string(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__CfgUSB__product_string(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__CfgUSB__product_string(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__CfgUSB__product_string(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

size_t size_function__CfgUSB__serial_number(const void * untyped_member)
{
  (void)untyped_member;
  return 32;
}

const void * get_const_function__CfgUSB__serial_number(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 32> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgUSB__serial_number(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 32> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgUSB__serial_number(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__CfgUSB__serial_number(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__CfgUSB__serial_number(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__CfgUSB__serial_number(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CfgUSB_message_member_array[9] = {
  {
    "vendor_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, vendor_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "product_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, product_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "reserved1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, reserved1),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgUSB__reserved1,  // size() function pointer
    get_const_function__CfgUSB__reserved1,  // get_const(index) function pointer
    get_function__CfgUSB__reserved1,  // get(index) function pointer
    fetch_function__CfgUSB__reserved1,  // fetch(index, &value) function pointer
    assign_function__CfgUSB__reserved1,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "reserved2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, reserved2),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgUSB__reserved2,  // size() function pointer
    get_const_function__CfgUSB__reserved2,  // get_const(index) function pointer
    get_function__CfgUSB__reserved2,  // get(index) function pointer
    fetch_function__CfgUSB__reserved2,  // fetch(index, &value) function pointer
    assign_function__CfgUSB__reserved2,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "power_consumption",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, power_consumption),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "flags",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, flags),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "vendor_string",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    32,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, vendor_string),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgUSB__vendor_string,  // size() function pointer
    get_const_function__CfgUSB__vendor_string,  // get_const(index) function pointer
    get_function__CfgUSB__vendor_string,  // get(index) function pointer
    fetch_function__CfgUSB__vendor_string,  // fetch(index, &value) function pointer
    assign_function__CfgUSB__vendor_string,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "product_string",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    32,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, product_string),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgUSB__product_string,  // size() function pointer
    get_const_function__CfgUSB__product_string,  // get_const(index) function pointer
    get_function__CfgUSB__product_string,  // get(index) function pointer
    fetch_function__CfgUSB__product_string,  // fetch(index, &value) function pointer
    assign_function__CfgUSB__product_string,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "serial_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    32,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgUSB, serial_number),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgUSB__serial_number,  // size() function pointer
    get_const_function__CfgUSB__serial_number,  // get_const(index) function pointer
    get_function__CfgUSB__serial_number,  // get(index) function pointer
    fetch_function__CfgUSB__serial_number,  // fetch(index, &value) function pointer
    assign_function__CfgUSB__serial_number,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CfgUSB_message_members = {
  "ublox_msgs::msg",  // message namespace
  "CfgUSB",  // message name
  9,  // number of fields
  sizeof(ublox_msgs::msg::CfgUSB),
  CfgUSB_message_member_array,  // message members
  CfgUSB_init_function,  // function to initialize message memory (memory has to be allocated)
  CfgUSB_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CfgUSB_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CfgUSB_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ublox_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ublox_msgs::msg::CfgUSB>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::CfgUSB_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, CfgUSB)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::CfgUSB_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
