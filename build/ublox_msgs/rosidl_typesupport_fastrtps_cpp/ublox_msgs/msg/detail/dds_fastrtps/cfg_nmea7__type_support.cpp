// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/CfgNMEA7.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_nmea7__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/cfg_nmea7__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ublox_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_serialize(
  const ublox_msgs::msg::CfgNMEA7 & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: filter
  cdr << ros_message.filter;
  // Member: nmea_version
  cdr << ros_message.nmea_version;
  // Member: num_sv
  cdr << ros_message.num_sv;
  // Member: flags
  cdr << ros_message.flags;
  // Member: gnss_to_filter
  cdr << ros_message.gnss_to_filter;
  // Member: sv_numbering
  cdr << ros_message.sv_numbering;
  // Member: main_talker_id
  cdr << ros_message.main_talker_id;
  // Member: gsv_talker_id
  cdr << ros_message.gsv_talker_id;
  // Member: reserved
  cdr << ros_message.reserved;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::CfgNMEA7 & ros_message)
{
  // Member: filter
  cdr >> ros_message.filter;

  // Member: nmea_version
  cdr >> ros_message.nmea_version;

  // Member: num_sv
  cdr >> ros_message.num_sv;

  // Member: flags
  cdr >> ros_message.flags;

  // Member: gnss_to_filter
  cdr >> ros_message.gnss_to_filter;

  // Member: sv_numbering
  cdr >> ros_message.sv_numbering;

  // Member: main_talker_id
  cdr >> ros_message.main_talker_id;

  // Member: gsv_talker_id
  cdr >> ros_message.gsv_talker_id;

  // Member: reserved
  cdr >> ros_message.reserved;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::CfgNMEA7 & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: filter
  {
    size_t item_size = sizeof(ros_message.filter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: nmea_version
  {
    size_t item_size = sizeof(ros_message.nmea_version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: num_sv
  {
    size_t item_size = sizeof(ros_message.num_sv);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: flags
  {
    size_t item_size = sizeof(ros_message.flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gnss_to_filter
  {
    size_t item_size = sizeof(ros_message.gnss_to_filter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sv_numbering
  {
    size_t item_size = sizeof(ros_message.sv_numbering);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: main_talker_id
  {
    size_t item_size = sizeof(ros_message.main_talker_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gsv_talker_id
  {
    size_t item_size = sizeof(ros_message.gsv_talker_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved
  {
    size_t item_size = sizeof(ros_message.reserved);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_CfgNMEA7(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: filter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: nmea_version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: num_sv
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_to_filter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sv_numbering
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: main_talker_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gsv_talker_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs::msg::CfgNMEA7;
    is_plain =
      (
      offsetof(DataType, reserved) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _CfgNMEA7__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgNMEA7 *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CfgNMEA7__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::CfgNMEA7 *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CfgNMEA7__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgNMEA7 *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CfgNMEA7__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CfgNMEA7(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CfgNMEA7__callbacks = {
  "ublox_msgs::msg",
  "CfgNMEA7",
  _CfgNMEA7__cdr_serialize,
  _CfgNMEA7__cdr_deserialize,
  _CfgNMEA7__get_serialized_size,
  _CfgNMEA7__max_serialized_size
};

static rosidl_message_type_support_t _CfgNMEA7__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CfgNMEA7__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ublox_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<ublox_msgs::msg::CfgNMEA7>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgNMEA7__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, CfgNMEA7)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgNMEA7__handle;
}

#ifdef __cplusplus
}
#endif
