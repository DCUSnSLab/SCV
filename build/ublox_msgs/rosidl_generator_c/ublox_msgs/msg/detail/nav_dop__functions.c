// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavDOP.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_dop__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavDOP__init(ublox_msgs__msg__NavDOP * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // g_dop
  // p_dop
  // t_dop
  // v_dop
  // h_dop
  // n_dop
  // e_dop
  return true;
}

void
ublox_msgs__msg__NavDOP__fini(ublox_msgs__msg__NavDOP * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // g_dop
  // p_dop
  // t_dop
  // v_dop
  // h_dop
  // n_dop
  // e_dop
}

bool
ublox_msgs__msg__NavDOP__are_equal(const ublox_msgs__msg__NavDOP * lhs, const ublox_msgs__msg__NavDOP * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // g_dop
  if (lhs->g_dop != rhs->g_dop) {
    return false;
  }
  // p_dop
  if (lhs->p_dop != rhs->p_dop) {
    return false;
  }
  // t_dop
  if (lhs->t_dop != rhs->t_dop) {
    return false;
  }
  // v_dop
  if (lhs->v_dop != rhs->v_dop) {
    return false;
  }
  // h_dop
  if (lhs->h_dop != rhs->h_dop) {
    return false;
  }
  // n_dop
  if (lhs->n_dop != rhs->n_dop) {
    return false;
  }
  // e_dop
  if (lhs->e_dop != rhs->e_dop) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavDOP__copy(
  const ublox_msgs__msg__NavDOP * input,
  ublox_msgs__msg__NavDOP * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // g_dop
  output->g_dop = input->g_dop;
  // p_dop
  output->p_dop = input->p_dop;
  // t_dop
  output->t_dop = input->t_dop;
  // v_dop
  output->v_dop = input->v_dop;
  // h_dop
  output->h_dop = input->h_dop;
  // n_dop
  output->n_dop = input->n_dop;
  // e_dop
  output->e_dop = input->e_dop;
  return true;
}

ublox_msgs__msg__NavDOP *
ublox_msgs__msg__NavDOP__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavDOP * msg = (ublox_msgs__msg__NavDOP *)allocator.allocate(sizeof(ublox_msgs__msg__NavDOP), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavDOP));
  bool success = ublox_msgs__msg__NavDOP__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavDOP__destroy(ublox_msgs__msg__NavDOP * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavDOP__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavDOP__Sequence__init(ublox_msgs__msg__NavDOP__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavDOP * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavDOP *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavDOP), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavDOP__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavDOP__fini(&data[i - 1]);
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
ublox_msgs__msg__NavDOP__Sequence__fini(ublox_msgs__msg__NavDOP__Sequence * array)
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
      ublox_msgs__msg__NavDOP__fini(&array->data[i]);
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

ublox_msgs__msg__NavDOP__Sequence *
ublox_msgs__msg__NavDOP__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavDOP__Sequence * array = (ublox_msgs__msg__NavDOP__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavDOP__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavDOP__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavDOP__Sequence__destroy(ublox_msgs__msg__NavDOP__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavDOP__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavDOP__Sequence__are_equal(const ublox_msgs__msg__NavDOP__Sequence * lhs, const ublox_msgs__msg__NavDOP__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavDOP__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavDOP__Sequence__copy(
  const ublox_msgs__msg__NavDOP__Sequence * input,
  ublox_msgs__msg__NavDOP__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavDOP);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavDOP * data =
      (ublox_msgs__msg__NavDOP *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavDOP__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavDOP__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavDOP__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
