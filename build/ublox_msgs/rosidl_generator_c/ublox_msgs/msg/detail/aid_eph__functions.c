// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/AidEPH.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/aid_eph__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sf1d`
// Member `sf2d`
// Member `sf3d`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ublox_msgs__msg__AidEPH__init(ublox_msgs__msg__AidEPH * msg)
{
  if (!msg) {
    return false;
  }
  // svid
  // how
  // sf1d
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->sf1d, 0)) {
    ublox_msgs__msg__AidEPH__fini(msg);
    return false;
  }
  // sf2d
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->sf2d, 0)) {
    ublox_msgs__msg__AidEPH__fini(msg);
    return false;
  }
  // sf3d
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->sf3d, 0)) {
    ublox_msgs__msg__AidEPH__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__AidEPH__fini(ublox_msgs__msg__AidEPH * msg)
{
  if (!msg) {
    return;
  }
  // svid
  // how
  // sf1d
  rosidl_runtime_c__uint32__Sequence__fini(&msg->sf1d);
  // sf2d
  rosidl_runtime_c__uint32__Sequence__fini(&msg->sf2d);
  // sf3d
  rosidl_runtime_c__uint32__Sequence__fini(&msg->sf3d);
}

bool
ublox_msgs__msg__AidEPH__are_equal(const ublox_msgs__msg__AidEPH * lhs, const ublox_msgs__msg__AidEPH * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // svid
  if (lhs->svid != rhs->svid) {
    return false;
  }
  // how
  if (lhs->how != rhs->how) {
    return false;
  }
  // sf1d
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->sf1d), &(rhs->sf1d)))
  {
    return false;
  }
  // sf2d
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->sf2d), &(rhs->sf2d)))
  {
    return false;
  }
  // sf3d
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->sf3d), &(rhs->sf3d)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__AidEPH__copy(
  const ublox_msgs__msg__AidEPH * input,
  ublox_msgs__msg__AidEPH * output)
{
  if (!input || !output) {
    return false;
  }
  // svid
  output->svid = input->svid;
  // how
  output->how = input->how;
  // sf1d
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->sf1d), &(output->sf1d)))
  {
    return false;
  }
  // sf2d
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->sf2d), &(output->sf2d)))
  {
    return false;
  }
  // sf3d
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->sf3d), &(output->sf3d)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__AidEPH *
ublox_msgs__msg__AidEPH__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__AidEPH * msg = (ublox_msgs__msg__AidEPH *)allocator.allocate(sizeof(ublox_msgs__msg__AidEPH), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__AidEPH));
  bool success = ublox_msgs__msg__AidEPH__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__AidEPH__destroy(ublox_msgs__msg__AidEPH * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__AidEPH__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__AidEPH__Sequence__init(ublox_msgs__msg__AidEPH__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__AidEPH * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__AidEPH *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__AidEPH), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__AidEPH__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__AidEPH__fini(&data[i - 1]);
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
ublox_msgs__msg__AidEPH__Sequence__fini(ublox_msgs__msg__AidEPH__Sequence * array)
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
      ublox_msgs__msg__AidEPH__fini(&array->data[i]);
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

ublox_msgs__msg__AidEPH__Sequence *
ublox_msgs__msg__AidEPH__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__AidEPH__Sequence * array = (ublox_msgs__msg__AidEPH__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__AidEPH__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__AidEPH__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__AidEPH__Sequence__destroy(ublox_msgs__msg__AidEPH__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__AidEPH__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__AidEPH__Sequence__are_equal(const ublox_msgs__msg__AidEPH__Sequence * lhs, const ublox_msgs__msg__AidEPH__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__AidEPH__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__AidEPH__Sequence__copy(
  const ublox_msgs__msg__AidEPH__Sequence * input,
  ublox_msgs__msg__AidEPH__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__AidEPH);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__AidEPH * data =
      (ublox_msgs__msg__AidEPH *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__AidEPH__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__AidEPH__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__AidEPH__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
