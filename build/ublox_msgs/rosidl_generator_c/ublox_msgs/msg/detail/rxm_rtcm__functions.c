// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/RxmRTCM.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/rxm_rtcm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__RxmRTCM__init(ublox_msgs__msg__RxmRTCM * msg)
{
  if (!msg) {
    return false;
  }
  // version
  // flags
  // reserved0
  // ref_station
  // msg_type
  return true;
}

void
ublox_msgs__msg__RxmRTCM__fini(ublox_msgs__msg__RxmRTCM * msg)
{
  if (!msg) {
    return;
  }
  // version
  // flags
  // reserved0
  // ref_station
  // msg_type
}

bool
ublox_msgs__msg__RxmRTCM__are_equal(const ublox_msgs__msg__RxmRTCM * lhs, const ublox_msgs__msg__RxmRTCM * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // reserved0
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved0[i] != rhs->reserved0[i]) {
      return false;
    }
  }
  // ref_station
  if (lhs->ref_station != rhs->ref_station) {
    return false;
  }
  // msg_type
  if (lhs->msg_type != rhs->msg_type) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__RxmRTCM__copy(
  const ublox_msgs__msg__RxmRTCM * input,
  ublox_msgs__msg__RxmRTCM * output)
{
  if (!input || !output) {
    return false;
  }
  // version
  output->version = input->version;
  // flags
  output->flags = input->flags;
  // reserved0
  for (size_t i = 0; i < 2; ++i) {
    output->reserved0[i] = input->reserved0[i];
  }
  // ref_station
  output->ref_station = input->ref_station;
  // msg_type
  output->msg_type = input->msg_type;
  return true;
}

ublox_msgs__msg__RxmRTCM *
ublox_msgs__msg__RxmRTCM__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRTCM * msg = (ublox_msgs__msg__RxmRTCM *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRTCM), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__RxmRTCM));
  bool success = ublox_msgs__msg__RxmRTCM__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__RxmRTCM__destroy(ublox_msgs__msg__RxmRTCM * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__RxmRTCM__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__RxmRTCM__Sequence__init(ublox_msgs__msg__RxmRTCM__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRTCM * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__RxmRTCM *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__RxmRTCM), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__RxmRTCM__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__RxmRTCM__fini(&data[i - 1]);
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
ublox_msgs__msg__RxmRTCM__Sequence__fini(ublox_msgs__msg__RxmRTCM__Sequence * array)
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
      ublox_msgs__msg__RxmRTCM__fini(&array->data[i]);
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

ublox_msgs__msg__RxmRTCM__Sequence *
ublox_msgs__msg__RxmRTCM__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRTCM__Sequence * array = (ublox_msgs__msg__RxmRTCM__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRTCM__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__RxmRTCM__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__RxmRTCM__Sequence__destroy(ublox_msgs__msg__RxmRTCM__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__RxmRTCM__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__RxmRTCM__Sequence__are_equal(const ublox_msgs__msg__RxmRTCM__Sequence * lhs, const ublox_msgs__msg__RxmRTCM__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__RxmRTCM__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__RxmRTCM__Sequence__copy(
  const ublox_msgs__msg__RxmRTCM__Sequence * input,
  ublox_msgs__msg__RxmRTCM__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__RxmRTCM);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__RxmRTCM * data =
      (ublox_msgs__msg__RxmRTCM *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__RxmRTCM__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__RxmRTCM__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__RxmRTCM__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
