// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/CfgINFBlock.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/cfg_inf_block__struct.hpp"
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

void CfgINFBlock_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::CfgINFBlock(_init);
}

void CfgINFBlock_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::CfgINFBlock *>(message_memory);
  typed_message->~CfgINFBlock();
}

size_t size_function__CfgINFBlock__reserved1(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__CfgINFBlock__reserved1(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgINFBlock__reserved1(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgINFBlock__reserved1(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__CfgINFBlock__reserved1(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__CfgINFBlock__reserved1(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__CfgINFBlock__reserved1(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__CfgINFBlock__inf_msg_mask(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__CfgINFBlock__inf_msg_mask(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgINFBlock__inf_msg_mask(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgINFBlock__inf_msg_mask(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__CfgINFBlock__inf_msg_mask(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__CfgINFBlock__inf_msg_mask(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__CfgINFBlock__inf_msg_mask(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CfgINFBlock_message_member_array[3] = {
  {
    "protocol_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgINFBlock, protocol_id),  // bytes offset in struct
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
    3,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgINFBlock, reserved1),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgINFBlock__reserved1,  // size() function pointer
    get_const_function__CfgINFBlock__reserved1,  // get_const(index) function pointer
    get_function__CfgINFBlock__reserved1,  // get(index) function pointer
    fetch_function__CfgINFBlock__reserved1,  // fetch(index, &value) function pointer
    assign_function__CfgINFBlock__reserved1,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "inf_msg_mask",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgINFBlock, inf_msg_mask),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgINFBlock__inf_msg_mask,  // size() function pointer
    get_const_function__CfgINFBlock__inf_msg_mask,  // get_const(index) function pointer
    get_function__CfgINFBlock__inf_msg_mask,  // get(index) function pointer
    fetch_function__CfgINFBlock__inf_msg_mask,  // fetch(index, &value) function pointer
    assign_function__CfgINFBlock__inf_msg_mask,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CfgINFBlock_message_members = {
  "ublox_msgs::msg",  // message namespace
  "CfgINFBlock",  // message name
  3,  // number of fields
  sizeof(ublox_msgs::msg::CfgINFBlock),
  CfgINFBlock_message_member_array,  // message members
  CfgINFBlock_init_function,  // function to initialize message memory (memory has to be allocated)
  CfgINFBlock_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CfgINFBlock_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CfgINFBlock_message_members,
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
get_message_type_support_handle<ublox_msgs::msg::CfgINFBlock>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::CfgINFBlock_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, CfgINFBlock)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::CfgINFBlock_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
