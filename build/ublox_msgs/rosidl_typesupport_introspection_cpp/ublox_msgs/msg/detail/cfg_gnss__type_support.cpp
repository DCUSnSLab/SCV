// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/CfgGNSS.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/cfg_gnss__struct.hpp"
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

void CfgGNSS_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::CfgGNSS(_init);
}

void CfgGNSS_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::CfgGNSS *>(message_memory);
  typed_message->~CfgGNSS();
}

size_t size_function__CfgGNSS__blocks(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<ublox_msgs::msg::CfgGNSSBlock> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CfgGNSS__blocks(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<ublox_msgs::msg::CfgGNSSBlock> *>(untyped_member);
  return &member[index];
}

void * get_function__CfgGNSS__blocks(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<ublox_msgs::msg::CfgGNSSBlock> *>(untyped_member);
  return &member[index];
}

void fetch_function__CfgGNSS__blocks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const ublox_msgs::msg::CfgGNSSBlock *>(
    get_const_function__CfgGNSS__blocks(untyped_member, index));
  auto & value = *reinterpret_cast<ublox_msgs::msg::CfgGNSSBlock *>(untyped_value);
  value = item;
}

void assign_function__CfgGNSS__blocks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<ublox_msgs::msg::CfgGNSSBlock *>(
    get_function__CfgGNSS__blocks(untyped_member, index));
  const auto & value = *reinterpret_cast<const ublox_msgs::msg::CfgGNSSBlock *>(untyped_value);
  item = value;
}

void resize_function__CfgGNSS__blocks(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<ublox_msgs::msg::CfgGNSSBlock> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CfgGNSS_message_member_array[5] = {
  {
    "msg_ver",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgGNSS, msg_ver),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_trk_ch_hw",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgGNSS, num_trk_ch_hw),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_trk_ch_use",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgGNSS, num_trk_ch_use),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_config_blocks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgGNSS, num_config_blocks),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "blocks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<ublox_msgs::msg::CfgGNSSBlock>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::CfgGNSS, blocks),  // bytes offset in struct
    nullptr,  // default value
    size_function__CfgGNSS__blocks,  // size() function pointer
    get_const_function__CfgGNSS__blocks,  // get_const(index) function pointer
    get_function__CfgGNSS__blocks,  // get(index) function pointer
    fetch_function__CfgGNSS__blocks,  // fetch(index, &value) function pointer
    assign_function__CfgGNSS__blocks,  // assign(index, value) function pointer
    resize_function__CfgGNSS__blocks  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CfgGNSS_message_members = {
  "ublox_msgs::msg",  // message namespace
  "CfgGNSS",  // message name
  5,  // number of fields
  sizeof(ublox_msgs::msg::CfgGNSS),
  CfgGNSS_message_member_array,  // message members
  CfgGNSS_init_function,  // function to initialize message memory (memory has to be allocated)
  CfgGNSS_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CfgGNSS_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CfgGNSS_message_members,
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
get_message_type_support_handle<ublox_msgs::msg::CfgGNSS>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::CfgGNSS_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, CfgGNSS)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::CfgGNSS_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
