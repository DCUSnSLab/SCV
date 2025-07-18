// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavSVIN.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_svin__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavSVIN__init(ublox_msgs__msg__NavSVIN * msg)
{
  if (!msg) {
    return false;
  }
  // version
  // reserved0
  // i_tow
  // dur
  // mean_x
  // mean_y
  // mean_z
  // mean_xhp
  // mean_yhp
  // mean_zhp
  // reserved1
  // mean_acc
  // obs
  // valid
  // active
  // reserved3
  return true;
}

void
ublox_msgs__msg__NavSVIN__fini(ublox_msgs__msg__NavSVIN * msg)
{
  if (!msg) {
    return;
  }
  // version
  // reserved0
  // i_tow
  // dur
  // mean_x
  // mean_y
  // mean_z
  // mean_xhp
  // mean_yhp
  // mean_zhp
  // reserved1
  // mean_acc
  // obs
  // valid
  // active
  // reserved3
}

bool
ublox_msgs__msg__NavSVIN__are_equal(const ublox_msgs__msg__NavSVIN * lhs, const ublox_msgs__msg__NavSVIN * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // reserved0
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->reserved0[i] != rhs->reserved0[i]) {
      return false;
    }
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // dur
  if (lhs->dur != rhs->dur) {
    return false;
  }
  // mean_x
  if (lhs->mean_x != rhs->mean_x) {
    return false;
  }
  // mean_y
  if (lhs->mean_y != rhs->mean_y) {
    return false;
  }
  // mean_z
  if (lhs->mean_z != rhs->mean_z) {
    return false;
  }
  // mean_xhp
  if (lhs->mean_xhp != rhs->mean_xhp) {
    return false;
  }
  // mean_yhp
  if (lhs->mean_yhp != rhs->mean_yhp) {
    return false;
  }
  // mean_zhp
  if (lhs->mean_zhp != rhs->mean_zhp) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  // mean_acc
  if (lhs->mean_acc != rhs->mean_acc) {
    return false;
  }
  // obs
  if (lhs->obs != rhs->obs) {
    return false;
  }
  // valid
  if (lhs->valid != rhs->valid) {
    return false;
  }
  // active
  if (lhs->active != rhs->active) {
    return false;
  }
  // reserved3
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved3[i] != rhs->reserved3[i]) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavSVIN__copy(
  const ublox_msgs__msg__NavSVIN * input,
  ublox_msgs__msg__NavSVIN * output)
{
  if (!input || !output) {
    return false;
  }
  // version
  output->version = input->version;
  // reserved0
  for (size_t i = 0; i < 3; ++i) {
    output->reserved0[i] = input->reserved0[i];
  }
  // i_tow
  output->i_tow = input->i_tow;
  // dur
  output->dur = input->dur;
  // mean_x
  output->mean_x = input->mean_x;
  // mean_y
  output->mean_y = input->mean_y;
  // mean_z
  output->mean_z = input->mean_z;
  // mean_xhp
  output->mean_xhp = input->mean_xhp;
  // mean_yhp
  output->mean_yhp = input->mean_yhp;
  // mean_zhp
  output->mean_zhp = input->mean_zhp;
  // reserved1
  output->reserved1 = input->reserved1;
  // mean_acc
  output->mean_acc = input->mean_acc;
  // obs
  output->obs = input->obs;
  // valid
  output->valid = input->valid;
  // active
  output->active = input->active;
  // reserved3
  for (size_t i = 0; i < 2; ++i) {
    output->reserved3[i] = input->reserved3[i];
  }
  return true;
}

ublox_msgs__msg__NavSVIN *
ublox_msgs__msg__NavSVIN__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSVIN * msg = (ublox_msgs__msg__NavSVIN *)allocator.allocate(sizeof(ublox_msgs__msg__NavSVIN), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavSVIN));
  bool success = ublox_msgs__msg__NavSVIN__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavSVIN__destroy(ublox_msgs__msg__NavSVIN * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavSVIN__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavSVIN__Sequence__init(ublox_msgs__msg__NavSVIN__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSVIN * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavSVIN *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavSVIN), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavSVIN__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavSVIN__fini(&data[i - 1]);
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
ublox_msgs__msg__NavSVIN__Sequence__fini(ublox_msgs__msg__NavSVIN__Sequence * array)
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
      ublox_msgs__msg__NavSVIN__fini(&array->data[i]);
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

ublox_msgs__msg__NavSVIN__Sequence *
ublox_msgs__msg__NavSVIN__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavSVIN__Sequence * array = (ublox_msgs__msg__NavSVIN__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavSVIN__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavSVIN__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavSVIN__Sequence__destroy(ublox_msgs__msg__NavSVIN__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavSVIN__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavSVIN__Sequence__are_equal(const ublox_msgs__msg__NavSVIN__Sequence * lhs, const ublox_msgs__msg__NavSVIN__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavSVIN__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavSVIN__Sequence__copy(
  const ublox_msgs__msg__NavSVIN__Sequence * input,
  ublox_msgs__msg__NavSVIN__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavSVIN);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavSVIN * data =
      (ublox_msgs__msg__NavSVIN *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavSVIN__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavSVIN__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavSVIN__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
