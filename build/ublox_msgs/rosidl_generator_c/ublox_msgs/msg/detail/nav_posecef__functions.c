// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_posecef__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavPOSECEF__init(ublox_msgs__msg__NavPOSECEF * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // ecef_x
  // ecef_y
  // ecef_z
  // p_acc
  return true;
}

void
ublox_msgs__msg__NavPOSECEF__fini(ublox_msgs__msg__NavPOSECEF * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // ecef_x
  // ecef_y
  // ecef_z
  // p_acc
}

bool
ublox_msgs__msg__NavPOSECEF__are_equal(const ublox_msgs__msg__NavPOSECEF * lhs, const ublox_msgs__msg__NavPOSECEF * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // ecef_x
  if (lhs->ecef_x != rhs->ecef_x) {
    return false;
  }
  // ecef_y
  if (lhs->ecef_y != rhs->ecef_y) {
    return false;
  }
  // ecef_z
  if (lhs->ecef_z != rhs->ecef_z) {
    return false;
  }
  // p_acc
  if (lhs->p_acc != rhs->p_acc) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavPOSECEF__copy(
  const ublox_msgs__msg__NavPOSECEF * input,
  ublox_msgs__msg__NavPOSECEF * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // ecef_x
  output->ecef_x = input->ecef_x;
  // ecef_y
  output->ecef_y = input->ecef_y;
  // ecef_z
  output->ecef_z = input->ecef_z;
  // p_acc
  output->p_acc = input->p_acc;
  return true;
}

ublox_msgs__msg__NavPOSECEF *
ublox_msgs__msg__NavPOSECEF__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavPOSECEF * msg = (ublox_msgs__msg__NavPOSECEF *)allocator.allocate(sizeof(ublox_msgs__msg__NavPOSECEF), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavPOSECEF));
  bool success = ublox_msgs__msg__NavPOSECEF__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavPOSECEF__destroy(ublox_msgs__msg__NavPOSECEF * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavPOSECEF__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavPOSECEF__Sequence__init(ublox_msgs__msg__NavPOSECEF__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavPOSECEF * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavPOSECEF *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavPOSECEF), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavPOSECEF__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavPOSECEF__fini(&data[i - 1]);
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
ublox_msgs__msg__NavPOSECEF__Sequence__fini(ublox_msgs__msg__NavPOSECEF__Sequence * array)
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
      ublox_msgs__msg__NavPOSECEF__fini(&array->data[i]);
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

ublox_msgs__msg__NavPOSECEF__Sequence *
ublox_msgs__msg__NavPOSECEF__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavPOSECEF__Sequence * array = (ublox_msgs__msg__NavPOSECEF__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavPOSECEF__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavPOSECEF__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavPOSECEF__Sequence__destroy(ublox_msgs__msg__NavPOSECEF__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavPOSECEF__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavPOSECEF__Sequence__are_equal(const ublox_msgs__msg__NavPOSECEF__Sequence * lhs, const ublox_msgs__msg__NavPOSECEF__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavPOSECEF__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavPOSECEF__Sequence__copy(
  const ublox_msgs__msg__NavPOSECEF__Sequence * input,
  ublox_msgs__msg__NavPOSECEF__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavPOSECEF);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavPOSECEF * data =
      (ublox_msgs__msg__NavPOSECEF *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavPOSECEF__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavPOSECEF__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavPOSECEF__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
