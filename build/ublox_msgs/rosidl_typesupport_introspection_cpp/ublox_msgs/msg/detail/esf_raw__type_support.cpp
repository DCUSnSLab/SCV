// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/EsfRAW.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/esf_raw__struct.hpp"
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

void EsfRAW_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::EsfRAW(_init);
}

void EsfRAW_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::EsfRAW *>(message_memory);
  typed_message->~EsfRAW();
}

size_t size_function__EsfRAW__reserved0(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__EsfRAW__reserved0(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__EsfRAW__reserved0(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__EsfRAW__reserved0(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__EsfRAW__reserved0(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__EsfRAW__reserved0(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__EsfRAW__reserved0(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__EsfRAW__blocks(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<ublox_msgs::msg::EsfRAWBlock> *>(untyped_member);
  return member->size();
}

const void * get_const_function__EsfRAW__blocks(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<ublox_msgs::msg::EsfRAWBlock> *>(untyped_member);
  return &member[index];
}

void * get_function__EsfRAW__blocks(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<ublox_msgs::msg::EsfRAWBlock> *>(untyped_member);
  return &member[index];
}

void fetch_function__EsfRAW__blocks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const ublox_msgs::msg::EsfRAWBlock *>(
    get_const_function__EsfRAW__blocks(untyped_member, index));
  auto & value = *reinterpret_cast<ublox_msgs::msg::EsfRAWBlock *>(untyped_value);
  value = item;
}

void assign_function__EsfRAW__blocks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<ublox_msgs::msg::EsfRAWBlock *>(
    get_function__EsfRAW__blocks(untyped_member, index));
  const auto & value = *reinterpret_cast<const ublox_msgs::msg::EsfRAWBlock *>(untyped_value);
  item = value;
}

void resize_function__EsfRAW__blocks(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<ublox_msgs::msg::EsfRAWBlock> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EsfRAW_message_member_array[2] = {
  {
    "reserved0",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfRAW, reserved0),  // bytes offset in struct
    nullptr,  // default value
    size_function__EsfRAW__reserved0,  // size() function pointer
    get_const_function__EsfRAW__reserved0,  // get_const(index) function pointer
    get_function__EsfRAW__reserved0,  // get(index) function pointer
    fetch_function__EsfRAW__reserved0,  // fetch(index, &value) function pointer
    assign_function__EsfRAW__reserved0,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "blocks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<ublox_msgs::msg::EsfRAWBlock>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::EsfRAW, blocks),  // bytes offset in struct
    nullptr,  // default value
    size_function__EsfRAW__blocks,  // size() function pointer
    get_const_function__EsfRAW__blocks,  // get_const(index) function pointer
    get_function__EsfRAW__blocks,  // get(index) function pointer
    fetch_function__EsfRAW__blocks,  // fetch(index, &value) function pointer
    assign_function__EsfRAW__blocks,  // assign(index, value) function pointer
    resize_function__EsfRAW__blocks  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EsfRAW_message_members = {
  "ublox_msgs::msg",  // message namespace
  "EsfRAW",  // message name
  2,  // number of fields
  sizeof(ublox_msgs::msg::EsfRAW),
  EsfRAW_message_member_array,  // message members
  EsfRAW_init_function,  // function to initialize message memory (memory has to be allocated)
  EsfRAW_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EsfRAW_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EsfRAW_message_members,
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
get_message_type_support_handle<ublox_msgs::msg::EsfRAW>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::EsfRAW_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, EsfRAW)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::EsfRAW_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
