// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgNMEA7.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_nmea7__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgNMEA7__init(ublox_msgs__msg__CfgNMEA7 * msg)
{
  if (!msg) {
    return false;
  }
  // filter
  // nmea_version
  // num_sv
  // flags
  // gnss_to_filter
  // sv_numbering
  // main_talker_id
  // gsv_talker_id
  // reserved
  return true;
}

void
ublox_msgs__msg__CfgNMEA7__fini(ublox_msgs__msg__CfgNMEA7 * msg)
{
  if (!msg) {
    return;
  }
  // filter
  // nmea_version
  // num_sv
  // flags
  // gnss_to_filter
  // sv_numbering
  // main_talker_id
  // gsv_talker_id
  // reserved
}

bool
ublox_msgs__msg__CfgNMEA7__are_equal(const ublox_msgs__msg__CfgNMEA7 * lhs, const ublox_msgs__msg__CfgNMEA7 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // filter
  if (lhs->filter != rhs->filter) {
    return false;
  }
  // nmea_version
  if (lhs->nmea_version != rhs->nmea_version) {
    return false;
  }
  // num_sv
  if (lhs->num_sv != rhs->num_sv) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // gnss_to_filter
  if (lhs->gnss_to_filter != rhs->gnss_to_filter) {
    return false;
  }
  // sv_numbering
  if (lhs->sv_numbering != rhs->sv_numbering) {
    return false;
  }
  // main_talker_id
  if (lhs->main_talker_id != rhs->main_talker_id) {
    return false;
  }
  // gsv_talker_id
  if (lhs->gsv_talker_id != rhs->gsv_talker_id) {
    return false;
  }
  // reserved
  if (lhs->reserved != rhs->reserved) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgNMEA7__copy(
  const ublox_msgs__msg__CfgNMEA7 * input,
  ublox_msgs__msg__CfgNMEA7 * output)
{
  if (!input || !output) {
    return false;
  }
  // filter
  output->filter = input->filter;
  // nmea_version
  output->nmea_version = input->nmea_version;
  // num_sv
  output->num_sv = input->num_sv;
  // flags
  output->flags = input->flags;
  // gnss_to_filter
  output->gnss_to_filter = input->gnss_to_filter;
  // sv_numbering
  output->sv_numbering = input->sv_numbering;
  // main_talker_id
  output->main_talker_id = input->main_talker_id;
  // gsv_talker_id
  output->gsv_talker_id = input->gsv_talker_id;
  // reserved
  output->reserved = input->reserved;
  return true;
}

ublox_msgs__msg__CfgNMEA7 *
ublox_msgs__msg__CfgNMEA7__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNMEA7 * msg = (ublox_msgs__msg__CfgNMEA7 *)allocator.allocate(sizeof(ublox_msgs__msg__CfgNMEA7), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgNMEA7));
  bool success = ublox_msgs__msg__CfgNMEA7__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgNMEA7__destroy(ublox_msgs__msg__CfgNMEA7 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgNMEA7__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgNMEA7__Sequence__init(ublox_msgs__msg__CfgNMEA7__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNMEA7 * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgNMEA7 *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgNMEA7), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgNMEA7__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgNMEA7__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ublox_msgs__msg__CfgNMEA7__Sequence__fini(ublox_msgs__msg__CfgNMEA7__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ublox_msgs__msg__CfgNMEA7__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ublox_msgs__msg__CfgNMEA7__Sequence *
ublox_msgs__msg__CfgNMEA7__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNMEA7__Sequence * array = (ublox_msgs__msg__CfgNMEA7__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgNMEA7__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgNMEA7__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgNMEA7__Sequence__destroy(ublox_msgs__msg__CfgNMEA7__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgNMEA7__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgNMEA7__Sequence__are_equal(const ublox_msgs__msg__CfgNMEA7__Sequence * lhs, const ublox_msgs__msg__CfgNMEA7__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgNMEA7__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgNMEA7__Sequence__copy(
  const ublox_msgs__msg__CfgNMEA7__Sequence * input,
  ublox_msgs__msg__CfgNMEA7__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgNMEA7);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgNMEA7 * data =
      (ublox_msgs__msg__CfgNMEA7 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgNMEA7__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgNMEA7__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgNMEA7__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
