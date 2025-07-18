// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/TimTM2.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/tim_tm2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__TimTM2__init(ublox_msgs__msg__TimTM2 * msg)
{
  if (!msg) {
    return false;
  }
  // ch
  // flags
  // rising_edge_count
  // wn_r
  // wn_f
  // tow_ms_r
  // tow_sub_ms_r
  // tow_ms_f
  // tow_sub_ms_f
  // acc_est
  return true;
}

void
ublox_msgs__msg__TimTM2__fini(ublox_msgs__msg__TimTM2 * msg)
{
  if (!msg) {
    return;
  }
  // ch
  // flags
  // rising_edge_count
  // wn_r
  // wn_f
  // tow_ms_r
  // tow_sub_ms_r
  // tow_ms_f
  // tow_sub_ms_f
  // acc_est
}

bool
ublox_msgs__msg__TimTM2__are_equal(const ublox_msgs__msg__TimTM2 * lhs, const ublox_msgs__msg__TimTM2 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ch
  if (lhs->ch != rhs->ch) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // rising_edge_count
  if (lhs->rising_edge_count != rhs->rising_edge_count) {
    return false;
  }
  // wn_r
  if (lhs->wn_r != rhs->wn_r) {
    return false;
  }
  // wn_f
  if (lhs->wn_f != rhs->wn_f) {
    return false;
  }
  // tow_ms_r
  if (lhs->tow_ms_r != rhs->tow_ms_r) {
    return false;
  }
  // tow_sub_ms_r
  if (lhs->tow_sub_ms_r != rhs->tow_sub_ms_r) {
    return false;
  }
  // tow_ms_f
  if (lhs->tow_ms_f != rhs->tow_ms_f) {
    return false;
  }
  // tow_sub_ms_f
  if (lhs->tow_sub_ms_f != rhs->tow_sub_ms_f) {
    return false;
  }
  // acc_est
  if (lhs->acc_est != rhs->acc_est) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__TimTM2__copy(
  const ublox_msgs__msg__TimTM2 * input,
  ublox_msgs__msg__TimTM2 * output)
{
  if (!input || !output) {
    return false;
  }
  // ch
  output->ch = input->ch;
  // flags
  output->flags = input->flags;
  // rising_edge_count
  output->rising_edge_count = input->rising_edge_count;
  // wn_r
  output->wn_r = input->wn_r;
  // wn_f
  output->wn_f = input->wn_f;
  // tow_ms_r
  output->tow_ms_r = input->tow_ms_r;
  // tow_sub_ms_r
  output->tow_sub_ms_r = input->tow_sub_ms_r;
  // tow_ms_f
  output->tow_ms_f = input->tow_ms_f;
  // tow_sub_ms_f
  output->tow_sub_ms_f = input->tow_sub_ms_f;
  // acc_est
  output->acc_est = input->acc_est;
  return true;
}

ublox_msgs__msg__TimTM2 *
ublox_msgs__msg__TimTM2__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__TimTM2 * msg = (ublox_msgs__msg__TimTM2 *)allocator.allocate(sizeof(ublox_msgs__msg__TimTM2), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__TimTM2));
  bool success = ublox_msgs__msg__TimTM2__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__TimTM2__destroy(ublox_msgs__msg__TimTM2 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__TimTM2__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__TimTM2__Sequence__init(ublox_msgs__msg__TimTM2__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__TimTM2 * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__TimTM2 *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__TimTM2), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__TimTM2__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__TimTM2__fini(&data[i - 1]);
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
ublox_msgs__msg__TimTM2__Sequence__fini(ublox_msgs__msg__TimTM2__Sequence * array)
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
      ublox_msgs__msg__TimTM2__fini(&array->data[i]);
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

ublox_msgs__msg__TimTM2__Sequence *
ublox_msgs__msg__TimTM2__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__TimTM2__Sequence * array = (ublox_msgs__msg__TimTM2__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__TimTM2__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__TimTM2__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__TimTM2__Sequence__destroy(ublox_msgs__msg__TimTM2__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__TimTM2__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__TimTM2__Sequence__are_equal(const ublox_msgs__msg__TimTM2__Sequence * lhs, const ublox_msgs__msg__TimTM2__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__TimTM2__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__TimTM2__Sequence__copy(
  const ublox_msgs__msg__TimTM2__Sequence * input,
  ublox_msgs__msg__TimTM2__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__TimTM2);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__TimTM2 * data =
      (ublox_msgs__msg__TimTM2 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__TimTM2__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__TimTM2__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__TimTM2__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
