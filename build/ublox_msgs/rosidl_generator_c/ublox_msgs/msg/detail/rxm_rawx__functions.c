// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/RxmRAWX.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/rxm_rawx__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `meas`
#include "ublox_msgs/msg/detail/rxm_rawx_meas__functions.h"

bool
ublox_msgs__msg__RxmRAWX__init(ublox_msgs__msg__RxmRAWX * msg)
{
  if (!msg) {
    return false;
  }
  // rcv_tow
  // week
  // leap_s
  // num_meas
  // rec_stat
  // version
  // reserved1
  // meas
  if (!ublox_msgs__msg__RxmRAWXMeas__Sequence__init(&msg->meas, 0)) {
    ublox_msgs__msg__RxmRAWX__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__RxmRAWX__fini(ublox_msgs__msg__RxmRAWX * msg)
{
  if (!msg) {
    return;
  }
  // rcv_tow
  // week
  // leap_s
  // num_meas
  // rec_stat
  // version
  // reserved1
  // meas
  ublox_msgs__msg__RxmRAWXMeas__Sequence__fini(&msg->meas);
}

bool
ublox_msgs__msg__RxmRAWX__are_equal(const ublox_msgs__msg__RxmRAWX * lhs, const ublox_msgs__msg__RxmRAWX * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rcv_tow
  if (lhs->rcv_tow != rhs->rcv_tow) {
    return false;
  }
  // week
  if (lhs->week != rhs->week) {
    return false;
  }
  // leap_s
  if (lhs->leap_s != rhs->leap_s) {
    return false;
  }
  // num_meas
  if (lhs->num_meas != rhs->num_meas) {
    return false;
  }
  // rec_stat
  if (lhs->rec_stat != rhs->rec_stat) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // meas
  if (!ublox_msgs__msg__RxmRAWXMeas__Sequence__are_equal(
      &(lhs->meas), &(rhs->meas)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAWX__copy(
  const ublox_msgs__msg__RxmRAWX * input,
  ublox_msgs__msg__RxmRAWX * output)
{
  if (!input || !output) {
    return false;
  }
  // rcv_tow
  output->rcv_tow = input->rcv_tow;
  // week
  output->week = input->week;
  // leap_s
  output->leap_s = input->leap_s;
  // num_meas
  output->num_meas = input->num_meas;
  // rec_stat
  output->rec_stat = input->rec_stat;
  // version
  output->version = input->version;
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // meas
  if (!ublox_msgs__msg__RxmRAWXMeas__Sequence__copy(
      &(input->meas), &(output->meas)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__RxmRAWX *
ublox_msgs__msg__RxmRAWX__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWX * msg = (ublox_msgs__msg__RxmRAWX *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAWX), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__RxmRAWX));
  bool success = ublox_msgs__msg__RxmRAWX__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__RxmRAWX__destroy(ublox_msgs__msg__RxmRAWX * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__RxmRAWX__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__RxmRAWX__Sequence__init(ublox_msgs__msg__RxmRAWX__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWX * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__RxmRAWX *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__RxmRAWX), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__RxmRAWX__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__RxmRAWX__fini(&data[i - 1]);
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
ublox_msgs__msg__RxmRAWX__Sequence__fini(ublox_msgs__msg__RxmRAWX__Sequence * array)
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
      ublox_msgs__msg__RxmRAWX__fini(&array->data[i]);
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

ublox_msgs__msg__RxmRAWX__Sequence *
ublox_msgs__msg__RxmRAWX__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWX__Sequence * array = (ublox_msgs__msg__RxmRAWX__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAWX__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__RxmRAWX__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__RxmRAWX__Sequence__destroy(ublox_msgs__msg__RxmRAWX__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__RxmRAWX__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__RxmRAWX__Sequence__are_equal(const ublox_msgs__msg__RxmRAWX__Sequence * lhs, const ublox_msgs__msg__RxmRAWX__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__RxmRAWX__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAWX__Sequence__copy(
  const ublox_msgs__msg__RxmRAWX__Sequence * input,
  ublox_msgs__msg__RxmRAWX__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__RxmRAWX);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__RxmRAWX * data =
      (ublox_msgs__msg__RxmRAWX *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__RxmRAWX__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__RxmRAWX__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__RxmRAWX__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
