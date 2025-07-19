// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgCFG.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_cfg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgCFG__init(ublox_msgs__msg__CfgCFG * msg)
{
  if (!msg) {
    return false;
  }
  // clear_mask
  // save_mask
  // load_mask
  // device_mask
  return true;
}

void
ublox_msgs__msg__CfgCFG__fini(ublox_msgs__msg__CfgCFG * msg)
{
  if (!msg) {
    return;
  }
  // clear_mask
  // save_mask
  // load_mask
  // device_mask
}

bool
ublox_msgs__msg__CfgCFG__are_equal(const ublox_msgs__msg__CfgCFG * lhs, const ublox_msgs__msg__CfgCFG * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // clear_mask
  if (lhs->clear_mask != rhs->clear_mask) {
    return false;
  }
  // save_mask
  if (lhs->save_mask != rhs->save_mask) {
    return false;
  }
  // load_mask
  if (lhs->load_mask != rhs->load_mask) {
    return false;
  }
  // device_mask
  if (lhs->device_mask != rhs->device_mask) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgCFG__copy(
  const ublox_msgs__msg__CfgCFG * input,
  ublox_msgs__msg__CfgCFG * output)
{
  if (!input || !output) {
    return false;
  }
  // clear_mask
  output->clear_mask = input->clear_mask;
  // save_mask
  output->save_mask = input->save_mask;
  // load_mask
  output->load_mask = input->load_mask;
  // device_mask
  output->device_mask = input->device_mask;
  return true;
}

ublox_msgs__msg__CfgCFG *
ublox_msgs__msg__CfgCFG__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgCFG * msg = (ublox_msgs__msg__CfgCFG *)allocator.allocate(sizeof(ublox_msgs__msg__CfgCFG), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgCFG));
  bool success = ublox_msgs__msg__CfgCFG__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgCFG__destroy(ublox_msgs__msg__CfgCFG * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgCFG__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgCFG__Sequence__init(ublox_msgs__msg__CfgCFG__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgCFG * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgCFG *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgCFG), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgCFG__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgCFG__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgCFG__Sequence__fini(ublox_msgs__msg__CfgCFG__Sequence * array)
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
      ublox_msgs__msg__CfgCFG__fini(&array->data[i]);
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

ublox_msgs__msg__CfgCFG__Sequence *
ublox_msgs__msg__CfgCFG__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgCFG__Sequence * array = (ublox_msgs__msg__CfgCFG__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgCFG__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgCFG__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgCFG__Sequence__destroy(ublox_msgs__msg__CfgCFG__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgCFG__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgCFG__Sequence__are_equal(const ublox_msgs__msg__CfgCFG__Sequence * lhs, const ublox_msgs__msg__CfgCFG__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgCFG__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgCFG__Sequence__copy(
  const ublox_msgs__msg__CfgCFG__Sequence * input,
  ublox_msgs__msg__CfgCFG__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgCFG);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgCFG * data =
      (ublox_msgs__msg__CfgCFG *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgCFG__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgCFG__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgCFG__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
