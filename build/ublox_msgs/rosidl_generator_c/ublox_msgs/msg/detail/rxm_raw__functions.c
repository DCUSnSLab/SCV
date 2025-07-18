// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/RxmRAW.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/rxm_raw__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sv`
#include "ublox_msgs/msg/detail/rxm_rawsv__functions.h"

bool
ublox_msgs__msg__RxmRAW__init(ublox_msgs__msg__RxmRAW * msg)
{
  if (!msg) {
    return false;
  }
  // rcv_tow
  // week
  // num_sv
  // reserved1
  // sv
  if (!ublox_msgs__msg__RxmRAWSV__Sequence__init(&msg->sv, 0)) {
    ublox_msgs__msg__RxmRAW__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__RxmRAW__fini(ublox_msgs__msg__RxmRAW * msg)
{
  if (!msg) {
    return;
  }
  // rcv_tow
  // week
  // num_sv
  // reserved1
  // sv
  ublox_msgs__msg__RxmRAWSV__Sequence__fini(&msg->sv);
}

bool
ublox_msgs__msg__RxmRAW__are_equal(const ublox_msgs__msg__RxmRAW * lhs, const ublox_msgs__msg__RxmRAW * rhs)
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
  // num_sv
  if (lhs->num_sv != rhs->num_sv) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  // sv
  if (!ublox_msgs__msg__RxmRAWSV__Sequence__are_equal(
      &(lhs->sv), &(rhs->sv)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAW__copy(
  const ublox_msgs__msg__RxmRAW * input,
  ublox_msgs__msg__RxmRAW * output)
{
  if (!input || !output) {
    return false;
  }
  // rcv_tow
  output->rcv_tow = input->rcv_tow;
  // week
  output->week = input->week;
  // num_sv
  output->num_sv = input->num_sv;
  // reserved1
  output->reserved1 = input->reserved1;
  // sv
  if (!ublox_msgs__msg__RxmRAWSV__Sequence__copy(
      &(input->sv), &(output->sv)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__RxmRAW *
ublox_msgs__msg__RxmRAW__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAW * msg = (ublox_msgs__msg__RxmRAW *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAW), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__RxmRAW));
  bool success = ublox_msgs__msg__RxmRAW__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__RxmRAW__destroy(ublox_msgs__msg__RxmRAW * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__RxmRAW__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__RxmRAW__Sequence__init(ublox_msgs__msg__RxmRAW__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAW * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__RxmRAW *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__RxmRAW), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__RxmRAW__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__RxmRAW__fini(&data[i - 1]);
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
ublox_msgs__msg__RxmRAW__Sequence__fini(ublox_msgs__msg__RxmRAW__Sequence * array)
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
      ublox_msgs__msg__RxmRAW__fini(&array->data[i]);
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

ublox_msgs__msg__RxmRAW__Sequence *
ublox_msgs__msg__RxmRAW__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAW__Sequence * array = (ublox_msgs__msg__RxmRAW__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAW__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__RxmRAW__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__RxmRAW__Sequence__destroy(ublox_msgs__msg__RxmRAW__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__RxmRAW__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__RxmRAW__Sequence__are_equal(const ublox_msgs__msg__RxmRAW__Sequence * lhs, const ublox_msgs__msg__RxmRAW__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__RxmRAW__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAW__Sequence__copy(
  const ublox_msgs__msg__RxmRAW__Sequence * input,
  ublox_msgs__msg__RxmRAW__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__RxmRAW);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__RxmRAW * data =
      (ublox_msgs__msg__RxmRAW *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__RxmRAW__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__RxmRAW__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__RxmRAW__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
