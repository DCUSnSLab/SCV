// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/MonVER.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ublox_msgs/msg/detail/mon_ver__struct.hpp"
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

void MonVER_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ublox_msgs::msg::MonVER(_init);
}

void MonVER_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ublox_msgs::msg::MonVER *>(message_memory);
  typed_message->~MonVER();
}

size_t size_function__MonVER__sw_version(const void * untyped_member)
{
  (void)untyped_member;
  return 30;
}

const void * get_const_function__MonVER__sw_version(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 30> *>(untyped_member);
  return &member[index];
}

void * get_function__MonVER__sw_version(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 30> *>(untyped_member);
  return &member[index];
}

void fetch_function__MonVER__sw_version(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__MonVER__sw_version(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__MonVER__sw_version(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__MonVER__sw_version(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__MonVER__hw_version(const void * untyped_member)
{
  (void)untyped_member;
  return 10;
}

const void * get_const_function__MonVER__hw_version(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 10> *>(untyped_member);
  return &member[index];
}

void * get_function__MonVER__hw_version(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 10> *>(untyped_member);
  return &member[index];
}

void fetch_function__MonVER__hw_version(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__MonVER__hw_version(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__MonVER__hw_version(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__MonVER__hw_version(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

size_t size_function__MonVER__extension(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<ublox_msgs::msg::MonVERExtension> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MonVER__extension(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<ublox_msgs::msg::MonVERExtension> *>(untyped_member);
  return &member[index];
}

void * get_function__MonVER__extension(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<ublox_msgs::msg::MonVERExtension> *>(untyped_member);
  return &member[index];
}

void fetch_function__MonVER__extension(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const ublox_msgs::msg::MonVERExtension *>(
    get_const_function__MonVER__extension(untyped_member, index));
  auto & value = *reinterpret_cast<ublox_msgs::msg::MonVERExtension *>(untyped_value);
  value = item;
}

void assign_function__MonVER__extension(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<ublox_msgs::msg::MonVERExtension *>(
    get_function__MonVER__extension(untyped_member, index));
  const auto & value = *reinterpret_cast<const ublox_msgs::msg::MonVERExtension *>(untyped_value);
  item = value;
}

void resize_function__MonVER__extension(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<ublox_msgs::msg::MonVERExtension> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MonVER_message_member_array[3] = {
  {
    "sw_version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    30,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::MonVER, sw_version),  // bytes offset in struct
    nullptr,  // default value
    size_function__MonVER__sw_version,  // size() function pointer
    get_const_function__MonVER__sw_version,  // get_const(index) function pointer
    get_function__MonVER__sw_version,  // get(index) function pointer
    fetch_function__MonVER__sw_version,  // fetch(index, &value) function pointer
    assign_function__MonVER__sw_version,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hw_version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    10,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::MonVER, hw_version),  // bytes offset in struct
    nullptr,  // default value
    size_function__MonVER__hw_version,  // size() function pointer
    get_const_function__MonVER__hw_version,  // get_const(index) function pointer
    get_function__MonVER__hw_version,  // get(index) function pointer
    fetch_function__MonVER__hw_version,  // fetch(index, &value) function pointer
    assign_function__MonVER__hw_version,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "extension",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<ublox_msgs::msg::MonVERExtension>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs::msg::MonVER, extension),  // bytes offset in struct
    nullptr,  // default value
    size_function__MonVER__extension,  // size() function pointer
    get_const_function__MonVER__extension,  // get_const(index) function pointer
    get_function__MonVER__extension,  // get(index) function pointer
    fetch_function__MonVER__extension,  // fetch(index, &value) function pointer
    assign_function__MonVER__extension,  // assign(index, value) function pointer
    resize_function__MonVER__extension  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MonVER_message_members = {
  "ublox_msgs::msg",  // message namespace
  "MonVER",  // message name
  3,  // number of fields
  sizeof(ublox_msgs::msg::MonVER),
  MonVER_message_member_array,  // message members
  MonVER_init_function,  // function to initialize message memory (memory has to be allocated)
  MonVER_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MonVER_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MonVER_message_members,
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
get_message_type_support_handle<ublox_msgs::msg::MonVER>()
{
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::MonVER_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ublox_msgs, msg, MonVER)() {
  return &::ublox_msgs::msg::rosidl_typesupport_introspection_cpp::MonVER_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
