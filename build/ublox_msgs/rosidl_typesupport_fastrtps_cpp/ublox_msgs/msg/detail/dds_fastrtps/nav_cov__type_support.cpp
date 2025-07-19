// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/NavCOV.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_cov__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/nav_cov__struct.hpp"

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
  const ublox_msgs::msg::NavCOV & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: i_tow
  cdr << ros_message.i_tow;
  // Member: version
  cdr << ros_message.version;
  // Member: pos_cov_valid
  cdr << ros_message.pos_cov_valid;
  // Member: vel_cov_valid
  cdr << ros_message.vel_cov_valid;
  // Member: reserved_0
  {
    cdr << ros_message.reserved_0;
  }
  // Member: pos_cov_nn
  cdr << ros_message.pos_cov_nn;
  // Member: pos_cov_ne
  cdr << ros_message.pos_cov_ne;
  // Member: pos_cov_nd
  cdr << ros_message.pos_cov_nd;
  // Member: pos_cov_ee
  cdr << ros_message.pos_cov_ee;
  // Member: pos_cov_ed
  cdr << ros_message.pos_cov_ed;
  // Member: pos_cov_dd
  cdr << ros_message.pos_cov_dd;
  // Member: vel_cov_nn
  cdr << ros_message.vel_cov_nn;
  // Member: vel_cov_ne
  cdr << ros_message.vel_cov_ne;
  // Member: vel_cov_nd
  cdr << ros_message.vel_cov_nd;
  // Member: vel_cov_ee
  cdr << ros_message.vel_cov_ee;
  // Member: vel_cov_ed
  cdr << ros_message.vel_cov_ed;
  // Member: vel_cov_dd
  cdr << ros_message.vel_cov_dd;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::NavCOV & ros_message)
{
  // Member: i_tow
  cdr >> ros_message.i_tow;

  // Member: version
  cdr >> ros_message.version;

  // Member: pos_cov_valid
  cdr >> ros_message.pos_cov_valid;

  // Member: vel_cov_valid
  cdr >> ros_message.vel_cov_valid;

  // Member: reserved_0
  {
    cdr >> ros_message.reserved_0;
  }

  // Member: pos_cov_nn
  cdr >> ros_message.pos_cov_nn;

  // Member: pos_cov_ne
  cdr >> ros_message.pos_cov_ne;

  // Member: pos_cov_nd
  cdr >> ros_message.pos_cov_nd;

  // Member: pos_cov_ee
  cdr >> ros_message.pos_cov_ee;

  // Member: pos_cov_ed
  cdr >> ros_message.pos_cov_ed;

  // Member: pos_cov_dd
  cdr >> ros_message.pos_cov_dd;

  // Member: vel_cov_nn
  cdr >> ros_message.vel_cov_nn;

  // Member: vel_cov_ne
  cdr >> ros_message.vel_cov_ne;

  // Member: vel_cov_nd
  cdr >> ros_message.vel_cov_nd;

  // Member: vel_cov_ee
  cdr >> ros_message.vel_cov_ee;

  // Member: vel_cov_ed
  cdr >> ros_message.vel_cov_ed;

  // Member: vel_cov_dd
  cdr >> ros_message.vel_cov_dd;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::NavCOV & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: i_tow
  {
    size_t item_size = sizeof(ros_message.i_tow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: version
  {
    size_t item_size = sizeof(ros_message.version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_cov_valid
  {
    size_t item_size = sizeof(ros_message.pos_cov_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_cov_valid
  {
    size_t item_size = sizeof(ros_message.vel_cov_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved_0
  {
    size_t array_size = 9;
    size_t item_size = sizeof(ros_message.reserved_0[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_cov_nn
  {
    size_t item_size = sizeof(ros_message.pos_cov_nn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_cov_ne
  {
    size_t item_size = sizeof(ros_message.pos_cov_ne);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_cov_nd
  {
    size_t item_size = sizeof(ros_message.pos_cov_nd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_cov_ee
  {
    size_t item_size = sizeof(ros_message.pos_cov_ee);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_cov_ed
  {
    size_t item_size = sizeof(ros_message.pos_cov_ed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos_cov_dd
  {
    size_t item_size = sizeof(ros_message.pos_cov_dd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_cov_nn
  {
    size_t item_size = sizeof(ros_message.vel_cov_nn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_cov_ne
  {
    size_t item_size = sizeof(ros_message.vel_cov_ne);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_cov_nd
  {
    size_t item_size = sizeof(ros_message.vel_cov_nd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_cov_ee
  {
    size_t item_size = sizeof(ros_message.vel_cov_ee);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_cov_ed
  {
    size_t item_size = sizeof(ros_message.vel_cov_ed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_cov_dd
  {
    size_t item_size = sizeof(ros_message.vel_cov_dd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_NavCOV(
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


  // Member: i_tow
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pos_cov_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: vel_cov_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved_0
  {
    size_t array_size = 9;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: pos_cov_nn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pos_cov_ne
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pos_cov_nd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pos_cov_ee
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pos_cov_ed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pos_cov_dd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vel_cov_nn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vel_cov_ne
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vel_cov_nd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vel_cov_ee
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vel_cov_ed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vel_cov_dd
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
    using DataType = ublox_msgs::msg::NavCOV;
    is_plain =
      (
      offsetof(DataType, vel_cov_dd) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _NavCOV__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::NavCOV *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NavCOV__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::NavCOV *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NavCOV__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::NavCOV *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NavCOV__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_NavCOV(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _NavCOV__callbacks = {
  "ublox_msgs::msg",
  "NavCOV",
  _NavCOV__cdr_serialize,
  _NavCOV__cdr_deserialize,
  _NavCOV__get_serialized_size,
  _NavCOV__max_serialized_size
};

static rosidl_message_type_support_t _NavCOV__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NavCOV__callbacks,
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
get_message_type_support_handle<ublox_msgs::msg::NavCOV>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_NavCOV__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, NavCOV)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_NavCOV__handle;
}

#ifdef __cplusplus
}
#endif
