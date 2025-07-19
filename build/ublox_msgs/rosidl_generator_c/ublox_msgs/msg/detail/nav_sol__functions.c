// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavSOL.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_sol__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavSOL__init(ublox_msgs__msg__NavSOL * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // f_tow
  // week
  // gps_fix
  // flags
  // ecef_x
  // ecef_y
  // ecef_z
  // p_acc
  // ecef_vx
  // ecef_vy
  // ecef_vz
  // s_acc
  // p_dop
  // reserved1
  // num_sv
  // reserved2
  return true;
}

void
ublox_msgs__msg__NavSOL__fini(ublox_msgs__msg__NavSOL * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // f_tow
  // week
  // gps_fix
  // flags
  // ecef_x
  // ecef_y
  // ecef_z
  // p_acc
  // ecef_vx
  // ecef_vy
  // ecef_vz
  // s_acc
  // p_dop
  // reserved1
  // num_sv
  // reserved2
}

bool
ublox_msgs__msg__NavSOL__are_equal(const ublox_msgs__msg__NavSOL * lhs, const ublox_msgs__msg__NavSOL * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // f_tow
  if (lhs->f_tow != rhs->f_tow) {
    return false;
  }
  // week
  if (lhs->week != rhs->week) {
    return false;
  }
  // gps_fix
  if (lhs->gps_fix != rhs->gps_fix) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
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
  // ecef_vx
  if (lhs->ecef_vx != rhs->ecef_vx) {
    return false;
  }
  // ecef_vy
  if (lhs->ecef_vy != rhs->ecef_vy) {
    return false;
  }
  // ecef_vz
  if (lhs->ecef_vz != rhs->ecef_vz) {
    return false;
  }
  // s_acc
  if (lhs->s_acc != rhs->s_acc) {
    return false;
  }
  // p_dop
  if (lhs->p_dop != rhs->p_dop) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  // num_sv
  if (lhs->num_sv != rhs->num_sv) {
    return false;
  }
  // reserved2
  if (lhs->reserved2 != rhs->reserved2) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavSOL__copy(
  const ublox_msgs__msg__NavSOL * input,
  ublox_msgs__msg__NavSOL * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // f_tow
  output->f_tow = input->f_tow;
  // week
  output->week = input->week;
  // gps_fix
  output->gps_fix = input->gps_fix;
  // flags
  output->flags = input->flags;
  // ecef_x
  output->ecef_x = input->ecef_x;
  // ecef_y
  output->ecef_y = input->ecef_y;
  // ecef_z
  output->ecef_z = input->ecef_z;
  // p_acc
  output->p_acc = input->p_acc;
  // ecef_vx
  output->ecef_vx = input->ecef_vx;
  // ecef_vy
  output->ecef_vy = input->ecef_vy;
  // ecef_vz
  output->ecef_vz = input->ecef_vz;
  // s_acc
  output->s_acc = input->s_acc;
  // p_dop
  output->p_dop = input->p_dop;
  // reserved1
  output->reserved1 = input->reserved1;
  // num_sv
  output->num_sv = input->num_sv;
  // reserved2
  output->reserved2 = input->reserved2;
  return true;
}

ublox_msgs__msg__NavSOL *
ublox_msgs__msg__NavSOL__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSOL * msg = (ublox_msgs__msg__NavSOL *)allocator.allocate(sizeof(ublox_msgs__msg__NavSOL), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavSOL));
  bool success = ublox_msgs__msg__NavSOL__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavSOL__destroy(ublox_msgs__msg__NavSOL * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavSOL__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavSOL__Sequence__init(ublox_msgs__msg__NavSOL__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSOL * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavSOL *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavSOL), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavSOL__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavSOL__fini(&data[i - 1]);
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
ublox_msgs__msg__NavSOL__Sequence__fini(ublox_msgs__msg__NavSOL__Sequence * array)
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
      ublox_msgs__msg__NavSOL__fini(&array->data[i]);
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

ublox_msgs__msg__NavSOL__Sequence *
ublox_msgs__msg__NavSOL__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSOL__Sequence * array = (ublox_msgs__msg__NavSOL__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavSOL__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavSOL__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavSOL__Sequence__destroy(ublox_msgs__msg__NavSOL__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavSOL__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavSOL__Sequence__are_equal(const ublox_msgs__msg__NavSOL__Sequence * lhs, const ublox_msgs__msg__NavSOL__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavSOL__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavSOL__Sequence__copy(
  const ublox_msgs__msg__NavSOL__Sequence * input,
  ublox_msgs__msg__NavSOL__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavSOL);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavSOL * data =
      (ublox_msgs__msg__NavSOL *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavSOL__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavSOL__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavSOL__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
