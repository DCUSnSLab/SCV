// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgGNSS.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_gnss__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `blocks`
#include "ublox_msgs/msg/detail/cfg_gnss_block__functions.h"

bool
ublox_msgs__msg__CfgGNSS__init(ublox_msgs__msg__CfgGNSS * msg)
{
  if (!msg) {
    return false;
  }
  // msg_ver
  // num_trk_ch_hw
  // num_trk_ch_use
  // num_config_blocks
  // blocks
  if (!ublox_msgs__msg__CfgGNSSBlock__Sequence__init(&msg->blocks, 0)) {
    ublox_msgs__msg__CfgGNSS__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__CfgGNSS__fini(ublox_msgs__msg__CfgGNSS * msg)
{
  if (!msg) {
    return;
  }
  // msg_ver
  // num_trk_ch_hw
  // num_trk_ch_use
  // num_config_blocks
  // blocks
  ublox_msgs__msg__CfgGNSSBlock__Sequence__fini(&msg->blocks);
}

bool
ublox_msgs__msg__CfgGNSS__are_equal(const ublox_msgs__msg__CfgGNSS * lhs, const ublox_msgs__msg__CfgGNSS * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg_ver
  if (lhs->msg_ver != rhs->msg_ver) {
    return false;
  }
  // num_trk_ch_hw
  if (lhs->num_trk_ch_hw != rhs->num_trk_ch_hw) {
    return false;
  }
  // num_trk_ch_use
  if (lhs->num_trk_ch_use != rhs->num_trk_ch_use) {
    return false;
  }
  // num_config_blocks
  if (lhs->num_config_blocks != rhs->num_config_blocks) {
    return false;
  }
  // blocks
  if (!ublox_msgs__msg__CfgGNSSBlock__Sequence__are_equal(
      &(lhs->blocks), &(rhs->blocks)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgGNSS__copy(
  const ublox_msgs__msg__CfgGNSS * input,
  ublox_msgs__msg__CfgGNSS * output)
{
  if (!input || !output) {
    return false;
  }
  // msg_ver
  output->msg_ver = input->msg_ver;
  // num_trk_ch_hw
  output->num_trk_ch_hw = input->num_trk_ch_hw;
  // num_trk_ch_use
  output->num_trk_ch_use = input->num_trk_ch_use;
  // num_config_blocks
  output->num_config_blocks = input->num_config_blocks;
  // blocks
  if (!ublox_msgs__msg__CfgGNSSBlock__Sequence__copy(
      &(input->blocks), &(output->blocks)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__CfgGNSS *
ublox_msgs__msg__CfgGNSS__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgGNSS * msg = (ublox_msgs__msg__CfgGNSS *)allocator.allocate(sizeof(ublox_msgs__msg__CfgGNSS), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgGNSS));
  bool success = ublox_msgs__msg__CfgGNSS__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgGNSS__destroy(ublox_msgs__msg__CfgGNSS * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgGNSS__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgGNSS__Sequence__init(ublox_msgs__msg__CfgGNSS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgGNSS * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgGNSS *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgGNSS), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgGNSS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgGNSS__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgGNSS__Sequence__fini(ublox_msgs__msg__CfgGNSS__Sequence * array)
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
      ublox_msgs__msg__CfgGNSS__fini(&array->data[i]);
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

ublox_msgs__msg__CfgGNSS__Sequence *
ublox_msgs__msg__CfgGNSS__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgGNSS__Sequence * array = (ublox_msgs__msg__CfgGNSS__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgGNSS__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgGNSS__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgGNSS__Sequence__destroy(ublox_msgs__msg__CfgGNSS__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgGNSS__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgGNSS__Sequence__are_equal(const ublox_msgs__msg__CfgGNSS__Sequence * lhs, const ublox_msgs__msg__CfgGNSS__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgGNSS__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgGNSS__Sequence__copy(
  const ublox_msgs__msg__CfgGNSS__Sequence * input,
  ublox_msgs__msg__CfgGNSS__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgGNSS);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgGNSS * data =
      (ublox_msgs__msg__CfgGNSS *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgGNSS__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgGNSS__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgGNSS__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
