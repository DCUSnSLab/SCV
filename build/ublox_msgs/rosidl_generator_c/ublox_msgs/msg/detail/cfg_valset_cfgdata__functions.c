// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgVALSETCfgdata.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_valset_cfgdata__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ublox_msgs__msg__CfgVALSETCfgdata__init(ublox_msgs__msg__CfgVALSETCfgdata * msg)
{
  if (!msg) {
    return false;
  }
  // key
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    ublox_msgs__msg__CfgVALSETCfgdata__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__CfgVALSETCfgdata__fini(ublox_msgs__msg__CfgVALSETCfgdata * msg)
{
  if (!msg) {
    return;
  }
  // key
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
ublox_msgs__msg__CfgVALSETCfgdata__are_equal(const ublox_msgs__msg__CfgVALSETCfgdata * lhs, const ublox_msgs__msg__CfgVALSETCfgdata * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // key
  if (lhs->key != rhs->key) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgVALSETCfgdata__copy(
  const ublox_msgs__msg__CfgVALSETCfgdata * input,
  ublox_msgs__msg__CfgVALSETCfgdata * output)
{
  if (!input || !output) {
    return false;
  }
  // key
  output->key = input->key;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__CfgVALSETCfgdata *
ublox_msgs__msg__CfgVALSETCfgdata__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgVALSETCfgdata * msg = (ublox_msgs__msg__CfgVALSETCfgdata *)allocator.allocate(sizeof(ublox_msgs__msg__CfgVALSETCfgdata), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgVALSETCfgdata));
  bool success = ublox_msgs__msg__CfgVALSETCfgdata__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgVALSETCfgdata__destroy(ublox_msgs__msg__CfgVALSETCfgdata * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgVALSETCfgdata__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgVALSETCfgdata__Sequence__init(ublox_msgs__msg__CfgVALSETCfgdata__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgVALSETCfgdata * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgVALSETCfgdata *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgVALSETCfgdata), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgVALSETCfgdata__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgVALSETCfgdata__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgVALSETCfgdata__Sequence__fini(ublox_msgs__msg__CfgVALSETCfgdata__Sequence * array)
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
      ublox_msgs__msg__CfgVALSETCfgdata__fini(&array->data[i]);
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

ublox_msgs__msg__CfgVALSETCfgdata__Sequence *
ublox_msgs__msg__CfgVALSETCfgdata__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgVALSETCfgdata__Sequence * array = (ublox_msgs__msg__CfgVALSETCfgdata__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgVALSETCfgdata__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgVALSETCfgdata__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgVALSETCfgdata__Sequence__destroy(ublox_msgs__msg__CfgVALSETCfgdata__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgVALSETCfgdata__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgVALSETCfgdata__Sequence__are_equal(const ublox_msgs__msg__CfgVALSETCfgdata__Sequence * lhs, const ublox_msgs__msg__CfgVALSETCfgdata__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgVALSETCfgdata__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgVALSETCfgdata__Sequence__copy(
  const ublox_msgs__msg__CfgVALSETCfgdata__Sequence * input,
  ublox_msgs__msg__CfgVALSETCfgdata__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgVALSETCfgdata);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgVALSETCfgdata * data =
      (ublox_msgs__msg__CfgVALSETCfgdata *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgVALSETCfgdata__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgVALSETCfgdata__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgVALSETCfgdata__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
