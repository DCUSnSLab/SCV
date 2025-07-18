// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/CfgNAV5.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_nav5__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/cfg_nav5__struct.hpp"

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
  const ublox_msgs::msg::CfgNAV5 & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mask
  cdr << ros_message.mask;
  // Member: dyn_model
  cdr << ros_message.dyn_model;
  // Member: fix_mode
  cdr << ros_message.fix_mode;
  // Member: fixed_alt
  cdr << ros_message.fixed_alt;
  // Member: fixed_alt_var
  cdr << ros_message.fixed_alt_var;
  // Member: min_elev
  cdr << ros_message.min_elev;
  // Member: dr_limit
  cdr << ros_message.dr_limit;
  // Member: p_dop
  cdr << ros_message.p_dop;
  // Member: t_dop
  cdr << ros_message.t_dop;
  // Member: p_acc
  cdr << ros_message.p_acc;
  // Member: t_acc
  cdr << ros_message.t_acc;
  // Member: static_hold_thresh
  cdr << ros_message.static_hold_thresh;
  // Member: dgnss_time_out
  cdr << ros_message.dgnss_time_out;
  // Member: cno_thresh_num_svs
  cdr << ros_message.cno_thresh_num_svs;
  // Member: cno_thresh
  cdr << ros_message.cno_thresh;
  // Member: reserved1
  {
    cdr << ros_message.reserved1;
  }
  // Member: static_hold_max_dist
  cdr << ros_message.static_hold_max_dist;
  // Member: utc_standard
  cdr << ros_message.utc_standard;
  // Member: reserved2
  {
    cdr << ros_message.reserved2;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::CfgNAV5 & ros_message)
{
  // Member: mask
  cdr >> ros_message.mask;

  // Member: dyn_model
  cdr >> ros_message.dyn_model;

  // Member: fix_mode
  cdr >> ros_message.fix_mode;

  // Member: fixed_alt
  cdr >> ros_message.fixed_alt;

  // Member: fixed_alt_var
  cdr >> ros_message.fixed_alt_var;

  // Member: min_elev
  cdr >> ros_message.min_elev;

  // Member: dr_limit
  cdr >> ros_message.dr_limit;

  // Member: p_dop
  cdr >> ros_message.p_dop;

  // Member: t_dop
  cdr >> ros_message.t_dop;

  // Member: p_acc
  cdr >> ros_message.p_acc;

  // Member: t_acc
  cdr >> ros_message.t_acc;

  // Member: static_hold_thresh
  cdr >> ros_message.static_hold_thresh;

  // Member: dgnss_time_out
  cdr >> ros_message.dgnss_time_out;

  // Member: cno_thresh_num_svs
  cdr >> ros_message.cno_thresh_num_svs;

  // Member: cno_thresh
  cdr >> ros_message.cno_thresh;

  // Member: reserved1
  {
    cdr >> ros_message.reserved1;
  }

  // Member: static_hold_max_dist
  cdr >> ros_message.static_hold_max_dist;

  // Member: utc_standard
  cdr >> ros_message.utc_standard;

  // Member: reserved2
  {
    cdr >> ros_message.reserved2;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::CfgNAV5 & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mask
  {
    size_t item_size = sizeof(ros_message.mask);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dyn_model
  {
    size_t item_size = sizeof(ros_message.dyn_model);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fix_mode
  {
    size_t item_size = sizeof(ros_message.fix_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fixed_alt
  {
    size_t item_size = sizeof(ros_message.fixed_alt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fixed_alt_var
  {
    size_t item_size = sizeof(ros_message.fixed_alt_var);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: min_elev
  {
    size_t item_size = sizeof(ros_message.min_elev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dr_limit
  {
    size_t item_size = sizeof(ros_message.dr_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_dop
  {
    size_t item_size = sizeof(ros_message.p_dop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: t_dop
  {
    size_t item_size = sizeof(ros_message.t_dop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_acc
  {
    size_t item_size = sizeof(ros_message.p_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: t_acc
  {
    size_t item_size = sizeof(ros_message.t_acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: static_hold_thresh
  {
    size_t item_size = sizeof(ros_message.static_hold_thresh);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dgnss_time_out
  {
    size_t item_size = sizeof(ros_message.dgnss_time_out);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cno_thresh_num_svs
  {
    size_t item_size = sizeof(ros_message.cno_thresh_num_svs);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cno_thresh
  {
    size_t item_size = sizeof(ros_message.cno_thresh);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved1
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.reserved1[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: static_hold_max_dist
  {
    size_t item_size = sizeof(ros_message.static_hold_max_dist);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_standard
  {
    size_t item_size = sizeof(ros_message.utc_standard);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved2
  {
    size_t array_size = 5;
    size_t item_size = sizeof(ros_message.reserved2[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_CfgNAV5(
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


  // Member: mask
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: dyn_model
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: fix_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: fixed_alt
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: fixed_alt_var
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: min_elev
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: dr_limit
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: p_dop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: t_dop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: p_acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: t_acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: static_hold_thresh
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: dgnss_time_out
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cno_thresh_num_svs
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cno_thresh
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved1
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: static_hold_max_dist
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: utc_standard
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved2
  {
    size_t array_size = 5;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs::msg::CfgNAV5;
    is_plain =
      (
      offsetof(DataType, reserved2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _CfgNAV5__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgNAV5 *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CfgNAV5__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::CfgNAV5 *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CfgNAV5__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::CfgNAV5 *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CfgNAV5__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CfgNAV5(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CfgNAV5__callbacks = {
  "ublox_msgs::msg",
  "CfgNAV5",
  _CfgNAV5__cdr_serialize,
  _CfgNAV5__cdr_deserialize,
  _CfgNAV5__get_serialized_size,
  _CfgNAV5__max_serialized_size
};

static rosidl_message_type_support_t _CfgNAV5__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CfgNAV5__callbacks,
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
get_message_type_support_handle<ublox_msgs::msg::CfgNAV5>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgNAV5__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, CfgNAV5)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_CfgNAV5__handle;
}

#ifdef __cplusplus
}
#endif
