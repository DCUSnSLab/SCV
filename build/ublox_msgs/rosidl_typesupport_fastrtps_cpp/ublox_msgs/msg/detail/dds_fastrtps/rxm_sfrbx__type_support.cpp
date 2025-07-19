// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ublox_msgs:msg/RxmSFRBX.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/rxm_sfrbx__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ublox_msgs/msg/detail/rxm_sfrbx__struct.hpp"

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
  const ublox_msgs::msg::RxmSFRBX & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gnss_id
  cdr << ros_message.gnss_id;
  // Member: sv_id
  cdr << ros_message.sv_id;
  // Member: reserved0
  cdr << ros_message.reserved0;
  // Member: freq_id
  cdr << ros_message.freq_id;
  // Member: num_words
  cdr << ros_message.num_words;
  // Member: chn
  cdr << ros_message.chn;
  // Member: version
  cdr << ros_message.version;
  // Member: reserved1
  cdr << ros_message.reserved1;
  // Member: dwrd
  {
    cdr << ros_message.dwrd;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ublox_msgs::msg::RxmSFRBX & ros_message)
{
  // Member: gnss_id
  cdr >> ros_message.gnss_id;

  // Member: sv_id
  cdr >> ros_message.sv_id;

  // Member: reserved0
  cdr >> ros_message.reserved0;

  // Member: freq_id
  cdr >> ros_message.freq_id;

  // Member: num_words
  cdr >> ros_message.num_words;

  // Member: chn
  cdr >> ros_message.chn;

  // Member: version
  cdr >> ros_message.version;

  // Member: reserved1
  cdr >> ros_message.reserved1;

  // Member: dwrd
  {
    cdr >> ros_message.dwrd;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
get_serialized_size(
  const ublox_msgs::msg::RxmSFRBX & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gnss_id
  {
    size_t item_size = sizeof(ros_message.gnss_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sv_id
  {
    size_t item_size = sizeof(ros_message.sv_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reserved0
  {
    size_t item_size = sizeof(ros_message.reserved0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: freq_id
  {
    size_t item_size = sizeof(ros_message.freq_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: num_words
  {
    size_t item_size = sizeof(ros_message.num_words);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: chn
  {
    size_t item_size = sizeof(ros_message.chn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
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
  // Member: dwrd
  {
    size_t array_size = ros_message.dwrd.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.dwrd[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ublox_msgs
max_serialized_size_RxmSFRBX(
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


  // Member: gnss_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: sv_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reserved0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: freq_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: num_words
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: chn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

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

  // Member: dwrd
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs::msg::RxmSFRBX;
    is_plain =
      (
      offsetof(DataType, dwrd) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RxmSFRBX__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::RxmSFRBX *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RxmSFRBX__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ublox_msgs::msg::RxmSFRBX *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RxmSFRBX__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ublox_msgs::msg::RxmSFRBX *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RxmSFRBX__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RxmSFRBX(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RxmSFRBX__callbacks = {
  "ublox_msgs::msg",
  "RxmSFRBX",
  _RxmSFRBX__cdr_serialize,
  _RxmSFRBX__cdr_deserialize,
  _RxmSFRBX__get_serialized_size,
  _RxmSFRBX__max_serialized_size
};

static rosidl_message_type_support_t _RxmSFRBX__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RxmSFRBX__callbacks,
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
get_message_type_support_handle<ublox_msgs::msg::RxmSFRBX>()
{
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_RxmSFRBX__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ublox_msgs, msg, RxmSFRBX)() {
  return &ublox_msgs::msg::typesupport_fastrtps_cpp::_RxmSFRBX__handle;
}

#ifdef __cplusplus
}
#endif
