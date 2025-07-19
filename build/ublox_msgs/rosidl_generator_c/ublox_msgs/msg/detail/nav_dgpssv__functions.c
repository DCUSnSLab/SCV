// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavDGPSSV.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_dgpssv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavDGPSSV__init(ublox_msgs__msg__NavDGPSSV * msg)
{
  if (!msg) {
    return false;
  }
  // svid
  // flags
  // age_c
  // prc
  // prrc
  return true;
}

void
ublox_msgs__msg__NavDGPSSV__fini(ublox_msgs__msg__NavDGPSSV * msg)
{
  if (!msg) {
    return;
  }
  // svid
  // flags
  // age_c
  // prc
  // prrc
}

bool
ublox_msgs__msg__NavDGPSSV__are_equal(const ublox_msgs__msg__NavDGPSSV * lhs, const ublox_msgs__msg__NavDGPSSV * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // svid
  if (lhs->svid != rhs->svid) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // age_c
  if (lhs->age_c != rhs->age_c) {
    return false;
  }
  // prc
  if (lhs->prc != rhs->prc) {
    return false;
  }
  // prrc
  if (lhs->prrc != rhs->prrc) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavDGPSSV__copy(
  const ublox_msgs__msg__NavDGPSSV * input,
  ublox_msgs__msg__NavDGPSSV * output)
{
  if (!input || !output) {
    return false;
  }
  // svid
  output->svid = input->svid;
  // flags
  output->flags = input->flags;
  // age_c
  output->age_c = input->age_c;
  // prc
  output->prc = input->prc;
  // prrc
  output->prrc = input->prrc;
  return true;
}

ublox_msgs__msg__NavDGPSSV *
ublox_msgs__msg__NavDGPSSV__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavDGPSSV * msg = (ublox_msgs__msg__NavDGPSSV *)allocator.allocate(sizeof(ublox_msgs__msg__NavDGPSSV), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavDGPSSV));
  bool success = ublox_msgs__msg__NavDGPSSV__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavDGPSSV__destroy(ublox_msgs__msg__NavDGPSSV * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavDGPSSV__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavDGPSSV__Sequence__init(ublox_msgs__msg__NavDGPSSV__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavDGPSSV * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavDGPSSV *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavDGPSSV), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavDGPSSV__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavDGPSSV__fini(&data[i - 1]);
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
ublox_msgs__msg__NavDGPSSV__Sequence__fini(ublox_msgs__msg__NavDGPSSV__Sequence * array)
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
      ublox_msgs__msg__NavDGPSSV__fini(&array->data[i]);
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

ublox_msgs__msg__NavDGPSSV__Sequence *
ublox_msgs__msg__NavDGPSSV__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavDGPSSV__Sequence * array = (ublox_msgs__msg__NavDGPSSV__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavDGPSSV__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavDGPSSV__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavDGPSSV__Sequence__destroy(ublox_msgs__msg__NavDGPSSV__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavDGPSSV__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavDGPSSV__Sequence__are_equal(const ublox_msgs__msg__NavDGPSSV__Sequence * lhs, const ublox_msgs__msg__NavDGPSSV__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavDGPSSV__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavDGPSSV__Sequence__copy(
  const ublox_msgs__msg__NavDGPSSV__Sequence * input,
  ublox_msgs__msg__NavDGPSSV__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavDGPSSV);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavDGPSSV * data =
      (ublox_msgs__msg__NavDGPSSV *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavDGPSSV__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavDGPSSV__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavDGPSSV__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
