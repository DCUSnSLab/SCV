// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_tmode3__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/cfg_tmode3__struct.hpp"

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
  const ublox_msgs::msg::CfgTMODE3 & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: version
  cdr << ros_message.version;
  // Member: reserved1
  cdr << ros_message.reserved1;
  // Member: flags
  cdr << ros_message.flags;
  // Member: ecef_x_or_lat
  cdr << ros_message.ecef_x_or_lat;
  // Member: ecef_y_or_lon
  cdr << ros_message.ecef_y_or_lon;
  // Member: ecef_z_or_alt
  cdr << ros_message.ecef_z_or_alt;
  // Member: ecef_x_or_lat_hp
  cdr << ros_message.ecef_x_or_lat_hp;
  // Member: ecef_y_or_lon_hp
  cdr << ros_message.ecef_y_or_lon_hp;
  // Member: ecef_z_or_alt_hp
  cdr << ros_message.ecef_z_or_alt_hp;
  // Member: reserved2
  cdr << ros_message.reserved2;
  // Member: fixed_pos_acc
  cdr << ros_message.fixed_pos_acc;
  // Member: svin_min_dur
  cdr << ros_message.svin_min_dur;
  // Member: svin_acc_limit
  cdr << ros_message.svin_acc_limit;
  // Member: reserved3
  {
    cdr << ros_message.reserved3;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::CfgTMODE3 & ros_message)
{
  // Member: version
  cdr >> ros_message.version;

  // Member: reserved1
  cdr >> ros_message.reserved1;

  // Member: flags
  cdr >> ros_message.flags;

  // Member: ecef_x_or_lat
  cdr >> ros_message.ecef_x_or_lat;

  // Member: ecef_y_or_lon
  cdr >> ros_message.ecef_y_or_lon;

  // Member: ecef_z_or_alt
  cdr >> ros_message.ecef_z_or_alt;

  // Member: ecef_x_or_lat_hp
  cdr >> ros_message.ecef_x_or_lat_hp;

  // Member: ecef_y_or_lon_hp
  cdr >> ros_message.ecef_y_or_lon_hp;

  // Member: ecef_z_or_alt_hp
  cdr >> ros_message.ecef_z_or_alt_hp;

  // Member: reserved2
  cdr >> ros_message.reserved2;

  // Member: fixed_pos_acc
  cdr >> ros_message.fixed_pos_acc;

  // Member: svin_min_dur
  cdr >> ros_message.svin_min_dur;

  // Member: svin_acc_limit
  cdr >> ros_message.svin_acc_limit;

  // Member: reserved3
  {
    cdr >> ros_message.reserved3;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::CfgTMODE3 & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: version
  {
    size_t item_size = sizeof(ros_message.version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved1
  {
    size_t item_size = sizeof(ros_message.reserved1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: flags
  {
    size_t item_size = sizeof(ros_message.flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ecef_x_or_lat
  {
    size_t item_size = sizeof(ros_message.ecef_x_or_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ecef_y_or_lon
  {
    size_t item_size = sizeof(ros_message.ecef_y_or_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ecef_z_or_alt
  {
    size_t item_size = sizeof(ros_message.ecef_z_or_alt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ecef_x_or_lat_hp
  {
    size_t item_size = sizeof(ros_message.ecef_x_or_lat_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ecef_y_or_lon_hp
  {
    size_t item_size = sizeof(ros_message.ecef_y_or_lon_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ecef_z_or_alt_hp
  {
    size_t item_size = sizeof(ros_message.ecef_z_or_alt_hp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved2
  {
    size_t item_size = sizeof(ros_message.reserved2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fixed_pos_acc
  {
    size_t item_size = sizeof(ros_message.fixed_pos_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: svin_min_dur
  {
    size_t item_size = sizeof(ros_message.svin_min_dur);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: svin_acc_limit
  {
    size_t item_size = sizeof(ros_message.svin_acc_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved3
  {
    size_t array_size = 8;
    size_t item_size = sizeof(ros_message.reserved3[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_CfgTMODE3(
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


  // Member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: ecef_x_or_lat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ecef_y_or_lon
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ecef_z_or_alt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ecef_x_or_lat_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ecef_y_or_lon_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ecef_z_or_alt_hp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: fixed_pos_acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: svin_min_dur
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: svin_acc_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: reserved3
  {
    size_t array_size = 8;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs::msg::CfgTMODE3;
    is_plain =
      (
      offsetof(DataType, reserved3) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _CfgTMODE3__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgTMODE3 *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CfgTMODE3__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::CfgTMODE3 *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CfgTMODE3__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgTMODE3 *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CfgTMODE3__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CfgTMODE3(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CfgTMODE3__callbacks = {
  "ublox_msgs::msg",
  "CfgTMODE3",
  _CfgTMODE3__cdr_serialize,
  _CfgTMODE3__cdr_deserialize,
  _CfgTMODE3__get_serialized_size,
  _CfgTMODE3__max_serialized_size
};

static rosidl_message_type_support_t _CfgTMODE3__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CfgTMODE3__callbacks,
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
get_message_type_support_handle<ublox_msgs::msg::CfgTMODE3>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgTMODE3__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, CfgTMODE3)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgTMODE3__handle;
}

#ifdef __cplusplus
}
#endif
