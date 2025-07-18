// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavSBAS.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_sbas__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sv`
#include "ublox_msgs/msg/detail/nav_sbassv__functions.h"

bool
ublox_msgs__msg__NavSBAS__init(ublox_msgs__msg__NavSBAS * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // geo
  // mode
  // sys
  // service
  // cnt
  // reserved0
  // sv
  if (!ublox_msgs__msg__NavSBASSV__Sequence__init(&msg->sv, 0)) {
    ublox_msgs__msg__NavSBAS__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__NavSBAS__fini(ublox_msgs__msg__NavSBAS * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // geo
  // mode
  // sys
  // service
  // cnt
  // reserved0
  // sv
  ublox_msgs__msg__NavSBASSV__Sequence__fini(&msg->sv);
}

bool
ublox_msgs__msg__NavSBAS__are_equal(const ublox_msgs__msg__NavSBAS * lhs, const ublox_msgs__msg__NavSBAS * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // geo
  if (lhs->geo != rhs->geo) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // sys
  if (lhs->sys != rhs->sys) {
    return false;
  }
  // service
  if (lhs->service != rhs->service) {
    return false;
  }
  // cnt
  if (lhs->cnt != rhs->cnt) {
    return false;
  }
  // reserved0
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->reserved0[i] != rhs->reserved0[i]) {
      return false;
    }
  }
  // sv
  if (!ublox_msgs__msg__NavSBASSV__Sequence__are_equal(
      &(lhs->sv), &(rhs->sv)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavSBAS__copy(
  const ublox_msgs__msg__NavSBAS * input,
  ublox_msgs__msg__NavSBAS * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // geo
  output->geo = input->geo;
  // mode
  output->mode = input->mode;
  // sys
  output->sys = input->sys;
  // service
  output->service = input->service;
  // cnt
  output->cnt = input->cnt;
  // reserved0
  for (size_t i = 0; i < 3; ++i) {
    output->reserved0[i] = input->reserved0[i];
  }
  // sv
  if (!ublox_msgs__msg__NavSBASSV__Sequence__copy(
      &(input->sv), &(output->sv)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__NavSBAS *
ublox_msgs__msg__NavSBAS__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSBAS * msg = (ublox_msgs__msg__NavSBAS *)allocator.allocate(sizeof(ublox_msgs__msg__NavSBAS), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavSBAS));
  bool success = ublox_msgs__msg__NavSBAS__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavSBAS__destroy(ublox_msgs__msg__NavSBAS * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavSBAS__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavSBAS__Sequence__init(ublox_msgs__msg__NavSBAS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSBAS * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavSBAS *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavSBAS), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavSBAS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavSBAS__fini(&data[i - 1]);
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
ublox_msgs__msg__NavSBAS__Sequence__fini(ublox_msgs__msg__NavSBAS__Sequence * array)
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
      ublox_msgs__msg__NavSBAS__fini(&array->data[i]);
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

ublox_msgs__msg__NavSBAS__Sequence *
ublox_msgs__msg__NavSBAS__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSBAS__Sequence * array = (ublox_msgs__msg__NavSBAS__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavSBAS__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavSBAS__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavSBAS__Sequence__destroy(ublox_msgs__msg__NavSBAS__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavSBAS__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavSBAS__Sequence__are_equal(const ublox_msgs__msg__NavSBAS__Sequence * lhs, const ublox_msgs__msg__NavSBAS__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavSBAS__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavSBAS__Sequence__copy(
  const ublox_msgs__msg__NavSBAS__Sequence * input,
  ublox_msgs__msg__NavSBAS__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavSBAS);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavSBAS * data =
      (ublox_msgs__msg__NavSBAS *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavSBAS__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavSBAS__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavSBAS__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
