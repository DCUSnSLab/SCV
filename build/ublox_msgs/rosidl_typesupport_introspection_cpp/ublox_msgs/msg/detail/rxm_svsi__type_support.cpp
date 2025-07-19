// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/RxmSVSI.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/rxm_svsi__struct.hpp"
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

void RxmSVSI_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::RxmSVSI(_init);
}

void RxmSVSI_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::RxmSVSI *>(message_memory);
  typed_message->~RxmSVSI();
}

size_t size_function__RxmSVSI__sv(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<ublox_msgs::msg::RxmSVSISV> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RxmSVSI__sv(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<ublox_msgs::msg::RxmSVSISV> *>(untyped_member);
  return &member[index];
}

void * get_function__RxmSVSI__sv(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<ublox_msgs::msg::RxmSVSISV> *>(untyped_member);
  return &member[index];
}

void fetch_function__RxmSVSI__sv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const ublox_msgs::msg::RxmSVSISV *>(
    get_const_function__RxmSVSI__sv(untyped_member, index));
  auto & value = *reinterpret_cast<ublox_msgs::msg::RxmSVSISV *>(untyped_value);
  value = item;
}

void assign_function__RxmSVSI__sv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<ublox_msgs::msg::RxmSVSISV *>(
    get_function__RxmSVSI__sv(untyped_member, index));
  const auto & value = *reinterpret_cast<const ublox_msgs::msg::RxmSVSISV *>(untyped_value);
  item = value;
}

void resize_function__RxmSVSI__sv(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<ublox_msgs::msg::RxmSVSISV> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RxmSVSI_message_member_array[5] = {
  {
    "i_tow",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmSVSI, i_tow),  // bytes offset in struct
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
    offsetof(ublox_msgs::msg::RxmSVSI, week),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_vis",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmSVSI, num_vis),  // bytes offset in struct
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
    offsetof(ublox_msgs::msg::RxmSVSI, num_sv),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<ublox_msgs::msg::RxmSVSISV>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::RxmSVSI, sv),  // bytes offset in struct
    nullptr,  // default value
    size_function__RxmSVSI__sv,  // size() function pointer
    get_const_function__RxmSVSI__sv,  // get_const(index) function pointer
    get_function__RxmSVSI__sv,  // get(index) function pointer
    fetch_function__RxmSVSI__sv,  // fetch(index, &value) function pointer
    assign_function__RxmSVSI__sv,  // assign(index, value) function pointer
    resize_function__RxmSVSI__sv  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RxmSVSI_message_members = {
  "ublox_msgs::msg",  // message namespace
  "RxmSVSI",  // message name
  5,  // number of fields
  sizeof(ublox_msgs::msg::RxmSVSI),
  RxmSVSI_message_member_array,  // message members
  RxmSVSI_init_function,  // function to initialize message memory (memory has to be allocated)
  RxmSVSI_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RxmSVSI_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RxmSVSI_message_members,
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
get_message_type_support_handle<ublox_msgs::msg::RxmSVSI>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::RxmSVSI_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, RxmSVSI)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::RxmSVSI_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
