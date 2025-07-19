// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgDAT.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_dat__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgDAT__init(ublox_msgs__msg__CfgDAT * msg)
{
  if (!msg) {
    return false;
  }
  // datum_num
  // datum_name
  // maj_a
  // flat
  // d_x
  // d_y
  // d_z
  // rot_x
  // rot_y
  // rot_z
  // scale
  return true;
}

void
ublox_msgs__msg__CfgDAT__fini(ublox_msgs__msg__CfgDAT * msg)
{
  if (!msg) {
    return;
  }
  // datum_num
  // datum_name
  // maj_a
  // flat
  // d_x
  // d_y
  // d_z
  // rot_x
  // rot_y
  // rot_z
  // scale
}

bool
ublox_msgs__msg__CfgDAT__are_equal(const ublox_msgs__msg__CfgDAT * lhs, const ublox_msgs__msg__CfgDAT * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // datum_num
  if (lhs->datum_num != rhs->datum_num) {
    return false;
  }
  // datum_name
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->datum_name[i] != rhs->datum_name[i]) {
      return false;
    }
  }
  // maj_a
  if (lhs->maj_a != rhs->maj_a) {
    return false;
  }
  // flat
  if (lhs->flat != rhs->flat) {
    return false;
  }
  // d_x
  if (lhs->d_x != rhs->d_x) {
    return false;
  }
  // d_y
  if (lhs->d_y != rhs->d_y) {
    return false;
  }
  // d_z
  if (lhs->d_z != rhs->d_z) {
    return false;
  }
  // rot_x
  if (lhs->rot_x != rhs->rot_x) {
    return false;
  }
  // rot_y
  if (lhs->rot_y != rhs->rot_y) {
    return false;
  }
  // rot_z
  if (lhs->rot_z != rhs->rot_z) {
    return false;
  }
  // scale
  if (lhs->scale != rhs->scale) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgDAT__copy(
  const ublox_msgs__msg__CfgDAT * input,
  ublox_msgs__msg__CfgDAT * output)
{
  if (!input || !output) {
    return false;
  }
  // datum_num
  output->datum_num = input->datum_num;
  // datum_name
  for (size_t i = 0; i < 6; ++i) {
    output->datum_name[i] = input->datum_name[i];
  }
  // maj_a
  output->maj_a = input->maj_a;
  // flat
  output->flat = input->flat;
  // d_x
  output->d_x = input->d_x;
  // d_y
  output->d_y = input->d_y;
  // d_z
  output->d_z = input->d_z;
  // rot_x
  output->rot_x = input->rot_x;
  // rot_y
  output->rot_y = input->rot_y;
  // rot_z
  output->rot_z = input->rot_z;
  // scale
  output->scale = input->scale;
  return true;
}

ublox_msgs__msg__CfgDAT *
ublox_msgs__msg__CfgDAT__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgDAT * msg = (ublox_msgs__msg__CfgDAT *)allocator.allocate(sizeof(ublox_msgs__msg__CfgDAT), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgDAT));
  bool success = ublox_msgs__msg__CfgDAT__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgDAT__destroy(ublox_msgs__msg__CfgDAT * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgDAT__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgDAT__Sequence__init(ublox_msgs__msg__CfgDAT__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgDAT * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgDAT *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgDAT), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgDAT__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgDAT__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgDAT__Sequence__fini(ublox_msgs__msg__CfgDAT__Sequence * array)
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
      ublox_msgs__msg__CfgDAT__fini(&array->data[i]);
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

ublox_msgs__msg__CfgDAT__Sequence *
ublox_msgs__msg__CfgDAT__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgDAT__Sequence * array = (ublox_msgs__msg__CfgDAT__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgDAT__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgDAT__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgDAT__Sequence__destroy(ublox_msgs__msg__CfgDAT__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgDAT__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgDAT__Sequence__are_equal(const ublox_msgs__msg__CfgDAT__Sequence * lhs, const ublox_msgs__msg__CfgDAT__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgDAT__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgDAT__Sequence__copy(
  const ublox_msgs__msg__CfgDAT__Sequence * input,
  ublox_msgs__msg__CfgDAT__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgDAT);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgDAT * data =
      (ublox_msgs__msg__CfgDAT *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgDAT__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgDAT__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgDAT__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
