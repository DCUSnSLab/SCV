// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/RxmRAW.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/rxm_raw__struct.hpp"
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

void RxmRAW_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::RxmRAW(_init);
}

void RxmRAW_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::RxmRAW *>(message_memory);
  typed_message->~RxmRAW();
}

size_t size_function__RxmRAW__sv(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<ublox_msgs::msg::RxmRAWSV> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RxmRAW__sv(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<ublox_msgs::msg::RxmRAWSV> *>(untyped_member);
  return &member[index];
}

void * get_function__RxmRAW__sv(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<ublox_msgs::msg::RxmRAWSV> *>(untyped_member);
  return &member[index];
}

void fetch_function__RxmRAW__sv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const ublox_msgs::msg::RxmRAWSV *>(
    get_const_function__RxmRAW__sv(untyped_member, index));
  auto & value = *reinterpret_cast<ublox_msgs::msg::RxmRAWSV *>(untyped_value);
  value = item;
}

void assign_function__RxmRAW__sv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<ublox_msgs::msg::RxmRAWSV *>(
    get_function__RxmRAW__sv(untyped_member, index));
  const auto & value = *reinterpret_cast<const ublox_msgs::msg::RxmRAWSV *>(untyped_value);
  item = value;
}

void resize_function__RxmRAW__sv(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<ublox_msgs::msg::RxmRAWSV> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RxmRAW_message_member_array[5] = {
  {
    "rcv_tow",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmRAW, rcv_tow),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "week",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmRAW, week),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_sv",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmRAW, num_sv),  // bytes offset in struct
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
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmRAW, reserved1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sv",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<ublox_msgs::msg::RxmRAWSV>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmRAW, sv),  // bytes offset in struct
    nullptr,  // default value
    size_function__RxmRAW__sv,  // size() function pointer
    get_const_function__RxmRAW__sv,  // get_const(index) function pointer
    get_function__RxmRAW__sv,  // get(index) function pointer
    fetch_function__RxmRAW__sv,  // fetch(index, &value) function pointer
    assign_function__RxmRAW__sv,  // assign(index, value) function pointer
    resize_function__RxmRAW__sv  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RxmRAW_message_members = {
  "ublox_msgs::msg",  // message namespace
  "RxmRAW",  // message name
  5,  // number of fields
  sizeof(ublox_msgs::msg::RxmRAW),
  RxmRAW_message_member_array,  // message members
  RxmRAW_init_function,  // function to initialize message memory (memory has to be allocated)
  RxmRAW_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RxmRAW_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RxmRAW_message_members,
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
get_message_type_support_handle<ublox_msgs::msg::RxmRAW>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::RxmRAW_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, RxmRAW)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::RxmRAW_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
