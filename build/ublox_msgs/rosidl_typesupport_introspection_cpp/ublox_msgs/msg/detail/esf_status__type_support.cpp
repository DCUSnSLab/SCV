// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/EsfSTATUS.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/esf_status__struct.hpp"
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

void EsfSTATUS_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::EsfSTATUS(_init);
}

void EsfSTATUS_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::EsfSTATUS *>(message_memory);
  typed_message->~EsfSTATUS();
}

size_t size_function__EsfSTATUS__reserved1(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__EsfSTATUS__reserved1(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__EsfSTATUS__reserved1(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 7> *>(untyped_member);
  return &member[index];
}

void fetch_function__EsfSTATUS__reserved1(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__EsfSTATUS__reserved1(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__EsfSTATUS__reserved1(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__EsfSTATUS__reserved1(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__EsfSTATUS__reserved2(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__EsfSTATUS__reserved2(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__EsfSTATUS__reserved2(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__EsfSTATUS__reserved2(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__EsfSTATUS__reserved2(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__EsfSTATUS__reserved2(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__EsfSTATUS__reserved2(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__EsfSTATUS__sens(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<ublox_msgs::msg::EsfSTATUSSens> *>(untyped_member);
  return member->size();
}

const void * get_const_function__EsfSTATUS__sens(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<ublox_msgs::msg::EsfSTATUSSens> *>(untyped_member);
  return &member[index];
}

void * get_function__EsfSTATUS__sens(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<ublox_msgs::msg::EsfSTATUSSens> *>(untyped_member);
  return &member[index];
}

void fetch_function__EsfSTATUS__sens(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const ublox_msgs::msg::EsfSTATUSSens *>(
    get_const_function__EsfSTATUS__sens(untyped_member, index));
  auto & value = *reinterpret_cast<ublox_msgs::msg::EsfSTATUSSens *>(untyped_value);
  value = item;
}

void assign_function__EsfSTATUS__sens(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<ublox_msgs::msg::EsfSTATUSSens *>(
    get_function__EsfSTATUS__sens(untyped_member, index));
  const auto & value = *reinterpret_cast<const ublox_msgs::msg::EsfSTATUSSens *>(untyped_value);
  item = value;
}

void resize_function__EsfSTATUS__sens(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<ublox_msgs::msg::EsfSTATUSSens> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EsfSTATUS_message_member_array[7] = {
  {
    "i_tow",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfSTATUS, i_tow),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfSTATUS, version),  // bytes offset in struct
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
    7,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfSTATUS, reserved1),  // bytes offset in struct
    nullptr,  // default value
    size_function__EsfSTATUS__reserved1,  // size() function pointer
    get_const_function__EsfSTATUS__reserved1,  // get_const(index) function pointer
    get_function__EsfSTATUS__reserved1,  // get(index) function pointer
    fetch_function__EsfSTATUS__reserved1,  // fetch(index, &value) function pointer
    assign_function__EsfSTATUS__reserved1,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "fusion_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfSTATUS, fusion_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
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
    offsetof(ublox_msgs::msg::EsfSTATUS, reserved2),  // bytes offset in struct
    nullptr,  // default value
    size_function__EsfSTATUS__reserved2,  // size() function pointer
    get_const_function__EsfSTATUS__reserved2,  // get_const(index) function pointer
    get_function__EsfSTATUS__reserved2,  // get(index) function pointer
    fetch_function__EsfSTATUS__reserved2,  // fetch(index, &value) function pointer
    assign_function__EsfSTATUS__reserved2,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_sens",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfSTATUS, num_sens),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sens",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<ublox_msgs::msg::EsfSTATUSSens>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfSTATUS, sens),  // bytes offset in struct
    nullptr,  // default value
    size_function__EsfSTATUS__sens,  // size() function pointer
    get_const_function__EsfSTATUS__sens,  // get_const(index) function pointer
    get_function__EsfSTATUS__sens,  // get(index) function pointer
    fetch_function__EsfSTATUS__sens,  // fetch(index, &value) function pointer
    assign_function__EsfSTATUS__sens,  // assign(index, value) function pointer
    resize_function__EsfSTATUS__sens  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EsfSTATUS_message_members = {
  "ublox_msgs::msg",  // message namespace
  "EsfSTATUS",  // message name
  7,  // number of fields
  sizeof(ublox_msgs::msg::EsfSTATUS),
  EsfSTATUS_message_member_array,  // message members
  EsfSTATUS_init_function,  // function to initialize message memory (memory has to be allocated)
  EsfSTATUS_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EsfSTATUS_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EsfSTATUS_message_members,
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
get_message_type_support_handle<ublox_msgs::msg::EsfSTATUS>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::EsfSTATUS_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, EsfSTATUS)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::EsfSTATUS_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
