// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/NavRELPOSNED9.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_relposned9__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/nav_relposned9__struct.hpp"

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
  const ublox_msgs::msg::NavRELPOSNED9 & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: version
  cdr << ros_message.version;
  // Member: reserved1
  cdr << ros_message.reserved1;
  // Member: ref_station_id
  cdr << ros_message.ref_station_id;
  // Member: i_tow
  cdr << ros_message.i_tow;
  // Member: rel_pos_n
  cdr << ros_message.rel_pos_n;
  // Member: rel_pos_e
  cdr << ros_message.rel_pos_e;
  // Member: rel_pos_d
  cdr << ros_message.rel_pos_d;
  // Member: rel_pos_length
  cdr << ros_message.rel_pos_length;
  // Member: rel_pos_heading
  cdr << ros_message.rel_pos_heading;
  // Member: reserved2
  {
    cdr << ros_message.reserved2;
  }
  // Member: rel_pos_hpn
  cdr << ros_message.rel_pos_hpn;
  // Member: rel_pos_hpe
  cdr << ros_message.rel_pos_hpe;
  // Member: rel_pos_hpd
  cdr << ros_message.rel_pos_hpd;
  // Member: rel_pos_hp_length
  cdr << ros_message.rel_pos_hp_length;
  // Member: acc_n
  cdr << ros_message.acc_n;
  // Member: acc_e
  cdr << ros_message.acc_e;
  // Member: acc_d
  cdr << ros_message.acc_d;
  // Member: acc_length
  cdr << ros_message.acc_length;
  // Member: acc_heading
  cdr << ros_message.acc_heading;
  // Member: reserved3
  {
    cdr << ros_message.reserved3;
  }
  // Member: flags
  cdr << ros_message.flags;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::NavRELPOSNED9 & ros_message)
{
  // Member: version
  cdr >> ros_message.version;

  // Member: reserved1
  cdr >> ros_message.reserved1;

  // Member: ref_station_id
  cdr >> ros_message.ref_station_id;

  // Member: i_tow
  cdr >> ros_message.i_tow;

  // Member: rel_pos_n
  cdr >> ros_message.rel_pos_n;

  // Member: rel_pos_e
  cdr >> ros_message.rel_pos_e;

  // Member: rel_pos_d
  cdr >> ros_message.rel_pos_d;

  // Member: rel_pos_length
  cdr >> ros_message.rel_pos_length;

  // Member: rel_pos_heading
  cdr >> ros_message.rel_pos_heading;

  // Member: reserved2
  {
    cdr >> ros_message.reserved2;
  }

  // Member: rel_pos_hpn
  cdr >> ros_message.rel_pos_hpn;

  // Member: rel_pos_hpe
  cdr >> ros_message.rel_pos_hpe;

  // Member: rel_pos_hpd
  cdr >> ros_message.rel_pos_hpd;

  // Member: rel_pos_hp_length
  cdr >> ros_message.rel_pos_hp_length;

  // Member: acc_n
  cdr >> ros_message.acc_n;

  // Member: acc_e
  cdr >> ros_message.acc_e;

  // Member: acc_d
  cdr >> ros_message.acc_d;

  // Member: acc_length
  cdr >> ros_message.acc_length;

  // Member: acc_heading
  cdr >> ros_message.acc_heading;

  // Member: reserved3
  {
    cdr >> ros_message.reserved3;
  }

  // Member: flags
  cdr >> ros_message.flags;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::NavRELPOSNED9 & ros_message,
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
  // Member: ref_station_id
  {
    size_t item_size = sizeof(ros_message.ref_station_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: i_tow
  {
    size_t item_size = sizeof(ros_message.i_tow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_n
  {
    size_t item_size = sizeof(ros_message.rel_pos_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_e
  {
    size_t item_size = sizeof(ros_message.rel_pos_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_d
  {
    size_t item_size = sizeof(ros_message.rel_pos_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_length
  {
    size_t item_size = sizeof(ros_message.rel_pos_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_heading
  {
    size_t item_size = sizeof(ros_message.rel_pos_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved2
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.reserved2[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_hpn
  {
    size_t item_size = sizeof(ros_message.rel_pos_hpn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_hpe
  {
    size_t item_size = sizeof(ros_message.rel_pos_hpe);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_hpd
  {
    size_t item_size = sizeof(ros_message.rel_pos_hpd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rel_pos_hp_length
  {
    size_t item_size = sizeof(ros_message.rel_pos_hp_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acc_n
  {
    size_t item_size = sizeof(ros_message.acc_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acc_e
  {
    size_t item_size = sizeof(ros_message.acc_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acc_d
  {
    size_t item_size = sizeof(ros_message.acc_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acc_length
  {
    size_t item_size = sizeof(ros_message.acc_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acc_heading
  {
    size_t item_size = sizeof(ros_message.acc_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved3
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.reserved3[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: flags
  {
    size_t item_size = sizeof(ros_message.flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_NavRELPOSNED9(
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

  // Member: ref_station_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: i_tow
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rel_pos_n
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rel_pos_e
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rel_pos_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rel_pos_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rel_pos_heading
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: reserved2
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_pos_hpn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_pos_hpe
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_pos_hpd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_pos_hp_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: acc_n
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: acc_e
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: acc_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: acc_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: acc_heading
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: reserved3
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs::msg::NavRELPOSNED9;
    is_plain =
      (
      offsetof(DataType, flags) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _NavRELPOSNED9__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::NavRELPOSNED9 *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NavRELPOSNED9__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::NavRELPOSNED9 *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NavRELPOSNED9__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::NavRELPOSNED9 *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NavRELPOSNED9__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_NavRELPOSNED9(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _NavRELPOSNED9__callbacks = {
  "ublox_msgs::msg",
  "NavRELPOSNED9",
  _NavRELPOSNED9__cdr_serialize,
  _NavRELPOSNED9__cdr_deserialize,
  _NavRELPOSNED9__get_serialized_size,
  _NavRELPOSNED9__max_serialized_size
};

static rosidl_message_type_support_t _NavRELPOSNED9__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NavRELPOSNED9__callbacks,
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
get_message_type_support_handle<ublox_msgs::msg::NavRELPOSNED9>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_NavRELPOSNED9__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, NavRELPOSNED9)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_NavRELPOSNED9__handle;
}

#ifdef __cplusplus
}
#endif
