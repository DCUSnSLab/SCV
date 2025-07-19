// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavSBASSV.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_sbassv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavSBASSV__init(ublox_msgs__msg__NavSBASSV * msg)
{
  if (!msg) {
    return false;
  }
  // svid
  // flags
  // udre
  // sv_sys
  // sv_service
  // reserved1
  // prc
  // reserved2
  // ic
  return true;
}

void
ublox_msgs__msg__NavSBASSV__fini(ublox_msgs__msg__NavSBASSV * msg)
{
  if (!msg) {
    return;
  }
  // svid
  // flags
  // udre
  // sv_sys
  // sv_service
  // reserved1
  // prc
  // reserved2
  // ic
}

bool
ublox_msgs__msg__NavSBASSV__are_equal(const ublox_msgs__msg__NavSBASSV * lhs, const ublox_msgs__msg__NavSBASSV * rhs)
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
  // udre
  if (lhs->udre != rhs->udre) {
    return false;
  }
  // sv_sys
  if (lhs->sv_sys != rhs->sv_sys) {
    return false;
  }
  // sv_service
  if (lhs->sv_service != rhs->sv_service) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  // prc
  if (lhs->prc != rhs->prc) {
    return false;
  }
  // reserved2
  if (lhs->reserved2 != rhs->reserved2) {
    return false;
  }
  // ic
  if (lhs->ic != rhs->ic) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavSBASSV__copy(
  const ublox_msgs__msg__NavSBASSV * input,
  ublox_msgs__msg__NavSBASSV * output)
{
  if (!input || !output) {
    return false;
  }
  // svid
  output->svid = input->svid;
  // flags
  output->flags = input->flags;
  // udre
  output->udre = input->udre;
  // sv_sys
  output->sv_sys = input->sv_sys;
  // sv_service
  output->sv_service = input->sv_service;
  // reserved1
  output->reserved1 = input->reserved1;
  // prc
  output->prc = input->prc;
  // reserved2
  output->reserved2 = input->reserved2;
  // ic
  output->ic = input->ic;
  return true;
}

ublox_msgs__msg__NavSBASSV *
ublox_msgs__msg__NavSBASSV__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSBASSV * msg = (ublox_msgs__msg__NavSBASSV *)allocator.allocate(sizeof(ublox_msgs__msg__NavSBASSV), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavSBASSV));
  bool success = ublox_msgs__msg__NavSBASSV__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavSBASSV__destroy(ublox_msgs__msg__NavSBASSV * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavSBASSV__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavSBASSV__Sequence__init(ublox_msgs__msg__NavSBASSV__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSBASSV * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavSBASSV *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavSBASSV), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavSBASSV__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavSBASSV__fini(&data[i - 1]);
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
ublox_msgs__msg__NavSBASSV__Sequence__fini(ublox_msgs__msg__NavSBASSV__Sequence * array)
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
      ublox_msgs__msg__NavSBASSV__fini(&array->data[i]);
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

ublox_msgs__msg__NavSBASSV__Sequence *
ublox_msgs__msg__NavSBASSV__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSBASSV__Sequence * array = (ublox_msgs__msg__NavSBASSV__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavSBASSV__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavSBASSV__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavSBASSV__Sequence__destroy(ublox_msgs__msg__NavSBASSV__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavSBASSV__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavSBASSV__Sequence__are_equal(const ublox_msgs__msg__NavSBASSV__Sequence * lhs, const ublox_msgs__msg__NavSBASSV__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavSBASSV__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavSBASSV__Sequence__copy(
  const ublox_msgs__msg__NavSBASSV__Sequence * input,
  ublox_msgs__msg__NavSBASSV__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavSBASSV);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavSBASSV * data =
      (ublox_msgs__msg__NavSBASSV *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavSBASSV__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavSBASSV__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavSBASSV__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
