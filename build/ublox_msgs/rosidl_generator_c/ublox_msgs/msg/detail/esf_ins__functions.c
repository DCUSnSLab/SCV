// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/EsfINS.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/esf_ins__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__EsfINS__init(ublox_msgs__msg__EsfINS * msg)
{
  if (!msg) {
    return false;
  }
  // bitfield0
  // reserved1
  // i_tow
  // x_ang_rate
  // y_ang_rate
  // z_ang_rate
  // x_accel
  // y_accel
  // z_accel
  return true;
}

void
ublox_msgs__msg__EsfINS__fini(ublox_msgs__msg__EsfINS * msg)
{
  if (!msg) {
    return;
  }
  // bitfield0
  // reserved1
  // i_tow
  // x_ang_rate
  // y_ang_rate
  // z_ang_rate
  // x_accel
  // y_accel
  // z_accel
}

bool
ublox_msgs__msg__EsfINS__are_equal(const ublox_msgs__msg__EsfINS * lhs, const ublox_msgs__msg__EsfINS * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // bitfield0
  if (lhs->bitfield0 != rhs->bitfield0) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // x_ang_rate
  if (lhs->x_ang_rate != rhs->x_ang_rate) {
    return false;
  }
  // y_ang_rate
  if (lhs->y_ang_rate != rhs->y_ang_rate) {
    return false;
  }
  // z_ang_rate
  if (lhs->z_ang_rate != rhs->z_ang_rate) {
    return false;
  }
  // x_accel
  if (lhs->x_accel != rhs->x_accel) {
    return false;
  }
  // y_accel
  if (lhs->y_accel != rhs->y_accel) {
    return false;
  }
  // z_accel
  if (lhs->z_accel != rhs->z_accel) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__EsfINS__copy(
  const ublox_msgs__msg__EsfINS * input,
  ublox_msgs__msg__EsfINS * output)
{
  if (!input || !output) {
    return false;
  }
  // bitfield0
  output->bitfield0 = input->bitfield0;
  // reserved1
  for (size_t i = 0; i < 4; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // i_tow
  output->i_tow = input->i_tow;
  // x_ang_rate
  output->x_ang_rate = input->x_ang_rate;
  // y_ang_rate
  output->y_ang_rate = input->y_ang_rate;
  // z_ang_rate
  output->z_ang_rate = input->z_ang_rate;
  // x_accel
  output->x_accel = input->x_accel;
  // y_accel
  output->y_accel = input->y_accel;
  // z_accel
  output->z_accel = input->z_accel;
  return true;
}

ublox_msgs__msg__EsfINS *
ublox_msgs__msg__EsfINS__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfINS * msg = (ublox_msgs__msg__EsfINS *)allocator.allocate(sizeof(ublox_msgs__msg__EsfINS), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__EsfINS));
  bool success = ublox_msgs__msg__EsfINS__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__EsfINS__destroy(ublox_msgs__msg__EsfINS * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__EsfINS__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__EsfINS__Sequence__init(ublox_msgs__msg__EsfINS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfINS * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__EsfINS *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__EsfINS), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__EsfINS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__EsfINS__fini(&data[i - 1]);
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
ublox_msgs__msg__EsfINS__Sequence__fini(ublox_msgs__msg__EsfINS__Sequence * array)
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
      ublox_msgs__msg__EsfINS__fini(&array->data[i]);
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

ublox_msgs__msg__EsfINS__Sequence *
ublox_msgs__msg__EsfINS__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfINS__Sequence * array = (ublox_msgs__msg__EsfINS__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__EsfINS__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__EsfINS__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__EsfINS__Sequence__destroy(ublox_msgs__msg__EsfINS__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__EsfINS__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__EsfINS__Sequence__are_equal(const ublox_msgs__msg__EsfINS__Sequence * lhs, const ublox_msgs__msg__EsfINS__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__EsfINS__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__EsfINS__Sequence__copy(
  const ublox_msgs__msg__EsfINS__Sequence * input,
  ublox_msgs__msg__EsfINS__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__EsfINS);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__EsfINS * data =
      (ublox_msgs__msg__EsfINS *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__EsfINS__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__EsfINS__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__EsfINS__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
