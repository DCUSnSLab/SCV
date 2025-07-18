// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavPOSLLH.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_posllh__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavPOSLLH__init(ublox_msgs__msg__NavPOSLLH * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // lon
  // lat
  // height
  // h_msl
  // h_acc
  // v_acc
  return true;
}

void
ublox_msgs__msg__NavPOSLLH__fini(ublox_msgs__msg__NavPOSLLH * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // lon
  // lat
  // height
  // h_msl
  // h_acc
  // v_acc
}

bool
ublox_msgs__msg__NavPOSLLH__are_equal(const ublox_msgs__msg__NavPOSLLH * lhs, const ublox_msgs__msg__NavPOSLLH * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // lon
  if (lhs->lon != rhs->lon) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // h_msl
  if (lhs->h_msl != rhs->h_msl) {
    return false;
  }
  // h_acc
  if (lhs->h_acc != rhs->h_acc) {
    return false;
  }
  // v_acc
  if (lhs->v_acc != rhs->v_acc) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavPOSLLH__copy(
  const ublox_msgs__msg__NavPOSLLH * input,
  ublox_msgs__msg__NavPOSLLH * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // lon
  output->lon = input->lon;
  // lat
  output->lat = input->lat;
  // height
  output->height = input->height;
  // h_msl
  output->h_msl = input->h_msl;
  // h_acc
  output->h_acc = input->h_acc;
  // v_acc
  output->v_acc = input->v_acc;
  return true;
}

ublox_msgs__msg__NavPOSLLH *
ublox_msgs__msg__NavPOSLLH__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavPOSLLH * msg = (ublox_msgs__msg__NavPOSLLH *)allocator.allocate(sizeof(ublox_msgs__msg__NavPOSLLH), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavPOSLLH));
  bool success = ublox_msgs__msg__NavPOSLLH__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavPOSLLH__destroy(ublox_msgs__msg__NavPOSLLH * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavPOSLLH__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavPOSLLH__Sequence__init(ublox_msgs__msg__NavPOSLLH__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavPOSLLH * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavPOSLLH *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavPOSLLH), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavPOSLLH__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavPOSLLH__fini(&data[i - 1]);
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
ublox_msgs__msg__NavPOSLLH__Sequence__fini(ublox_msgs__msg__NavPOSLLH__Sequence * array)
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
      ublox_msgs__msg__NavPOSLLH__fini(&array->data[i]);
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

ublox_msgs__msg__NavPOSLLH__Sequence *
ublox_msgs__msg__NavPOSLLH__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavPOSLLH__Sequence * array = (ublox_msgs__msg__NavPOSLLH__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavPOSLLH__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavPOSLLH__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavPOSLLH__Sequence__destroy(ublox_msgs__msg__NavPOSLLH__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavPOSLLH__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavPOSLLH__Sequence__are_equal(const ublox_msgs__msg__NavPOSLLH__Sequence * lhs, const ublox_msgs__msg__NavPOSLLH__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavPOSLLH__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavPOSLLH__Sequence__copy(
  const ublox_msgs__msg__NavPOSLLH__Sequence * input,
  ublox_msgs__msg__NavPOSLLH__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavPOSLLH);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavPOSLLH * data =
      (ublox_msgs__msg__NavPOSLLH *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavPOSLLH__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavPOSLLH__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavPOSLLH__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
