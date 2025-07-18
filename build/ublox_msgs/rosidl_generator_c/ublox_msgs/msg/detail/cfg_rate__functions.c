// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgRATE.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_rate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgRATE__init(ublox_msgs__msg__CfgRATE * msg)
{
  if (!msg) {
    return false;
  }
  // meas_rate
  // nav_rate
  // time_ref
  return true;
}

void
ublox_msgs__msg__CfgRATE__fini(ublox_msgs__msg__CfgRATE * msg)
{
  if (!msg) {
    return;
  }
  // meas_rate
  // nav_rate
  // time_ref
}

bool
ublox_msgs__msg__CfgRATE__are_equal(const ublox_msgs__msg__CfgRATE * lhs, const ublox_msgs__msg__CfgRATE * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // meas_rate
  if (lhs->meas_rate != rhs->meas_rate) {
    return false;
  }
  // nav_rate
  if (lhs->nav_rate != rhs->nav_rate) {
    return false;
  }
  // time_ref
  if (lhs->time_ref != rhs->time_ref) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgRATE__copy(
  const ublox_msgs__msg__CfgRATE * input,
  ublox_msgs__msg__CfgRATE * output)
{
  if (!input || !output) {
    return false;
  }
  // meas_rate
  output->meas_rate = input->meas_rate;
  // nav_rate
  output->nav_rate = input->nav_rate;
  // time_ref
  output->time_ref = input->time_ref;
  return true;
}

ublox_msgs__msg__CfgRATE *
ublox_msgs__msg__CfgRATE__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgRATE * msg = (ublox_msgs__msg__CfgRATE *)allocator.allocate(sizeof(ublox_msgs__msg__CfgRATE), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgRATE));
  bool success = ublox_msgs__msg__CfgRATE__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgRATE__destroy(ublox_msgs__msg__CfgRATE * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgRATE__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgRATE__Sequence__init(ublox_msgs__msg__CfgRATE__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgRATE * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgRATE *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgRATE), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgRATE__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgRATE__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgRATE__Sequence__fini(ublox_msgs__msg__CfgRATE__Sequence * array)
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
      ublox_msgs__msg__CfgRATE__fini(&array->data[i]);
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

ublox_msgs__msg__CfgRATE__Sequence *
ublox_msgs__msg__CfgRATE__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgRATE__Sequence * array = (ublox_msgs__msg__CfgRATE__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgRATE__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgRATE__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgRATE__Sequence__destroy(ublox_msgs__msg__CfgRATE__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgRATE__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgRATE__Sequence__are_equal(const ublox_msgs__msg__CfgRATE__Sequence * lhs, const ublox_msgs__msg__CfgRATE__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgRATE__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgRATE__Sequence__copy(
  const ublox_msgs__msg__CfgRATE__Sequence * input,
  ublox_msgs__msg__CfgRATE__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgRATE);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgRATE * data =
      (ublox_msgs__msg__CfgRATE *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgRATE__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgRATE__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgRATE__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
