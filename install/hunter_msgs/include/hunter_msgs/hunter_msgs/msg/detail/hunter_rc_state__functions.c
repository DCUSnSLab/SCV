// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hunter_msgs:msg/HunterRCState.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_rc_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hunter_msgs__msg__HunterRCState__init(hunter_msgs__msg__HunterRCState * msg)
{
  if (!msg) {
    return false;
  }
  // swa
  // swb
  // swc
  // swd
  // stick_right_v
  // stick_right_h
  // stick_left_v
  // stick_left_h
  // var_a
  return true;
}

void
hunter_msgs__msg__HunterRCState__fini(hunter_msgs__msg__HunterRCState * msg)
{
  if (!msg) {
    return;
  }
  // swa
  // swb
  // swc
  // swd
  // stick_right_v
  // stick_right_h
  // stick_left_v
  // stick_left_h
  // var_a
}

bool
hunter_msgs__msg__HunterRCState__are_equal(const hunter_msgs__msg__HunterRCState * lhs, const hunter_msgs__msg__HunterRCState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // swa
  if (lhs->swa != rhs->swa) {
    return false;
  }
  // swb
  if (lhs->swb != rhs->swb) {
    return false;
  }
  // swc
  if (lhs->swc != rhs->swc) {
    return false;
  }
  // swd
  if (lhs->swd != rhs->swd) {
    return false;
  }
  // stick_right_v
  if (lhs->stick_right_v != rhs->stick_right_v) {
    return false;
  }
  // stick_right_h
  if (lhs->stick_right_h != rhs->stick_right_h) {
    return false;
  }
  // stick_left_v
  if (lhs->stick_left_v != rhs->stick_left_v) {
    return false;
  }
  // stick_left_h
  if (lhs->stick_left_h != rhs->stick_left_h) {
    return false;
  }
  // var_a
  if (lhs->var_a != rhs->var_a) {
    return false;
  }
  return true;
}

bool
hunter_msgs__msg__HunterRCState__copy(
  const hunter_msgs__msg__HunterRCState * input,
  hunter_msgs__msg__HunterRCState * output)
{
  if (!input || !output) {
    return false;
  }
  // swa
  output->swa = input->swa;
  // swb
  output->swb = input->swb;
  // swc
  output->swc = input->swc;
  // swd
  output->swd = input->swd;
  // stick_right_v
  output->stick_right_v = input->stick_right_v;
  // stick_right_h
  output->stick_right_h = input->stick_right_h;
  // stick_left_v
  output->stick_left_v = input->stick_left_v;
  // stick_left_h
  output->stick_left_h = input->stick_left_h;
  // var_a
  output->var_a = input->var_a;
  return true;
}

hunter_msgs__msg__HunterRCState *
hunter_msgs__msg__HunterRCState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterRCState * msg = (hunter_msgs__msg__HunterRCState *)allocator.allocate(sizeof(hunter_msgs__msg__HunterRCState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hunter_msgs__msg__HunterRCState));
  bool success = hunter_msgs__msg__HunterRCState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hunter_msgs__msg__HunterRCState__destroy(hunter_msgs__msg__HunterRCState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hunter_msgs__msg__HunterRCState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hunter_msgs__msg__HunterRCState__Sequence__init(hunter_msgs__msg__HunterRCState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterRCState * data = NULL;

  if (size) {
    data = (hunter_msgs__msg__HunterRCState *)allocator.zero_allocate(size, sizeof(hunter_msgs__msg__HunterRCState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hunter_msgs__msg__HunterRCState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hunter_msgs__msg__HunterRCState__fini(&data[i - 1]);
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
hunter_msgs__msg__HunterRCState__Sequence__fini(hunter_msgs__msg__HunterRCState__Sequence * array)
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
      hunter_msgs__msg__HunterRCState__fini(&array->data[i]);
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

hunter_msgs__msg__HunterRCState__Sequence *
hunter_msgs__msg__HunterRCState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterRCState__Sequence * array = (hunter_msgs__msg__HunterRCState__Sequence *)allocator.allocate(sizeof(hunter_msgs__msg__HunterRCState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hunter_msgs__msg__HunterRCState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hunter_msgs__msg__HunterRCState__Sequence__destroy(hunter_msgs__msg__HunterRCState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hunter_msgs__msg__HunterRCState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hunter_msgs__msg__HunterRCState__Sequence__are_equal(const hunter_msgs__msg__HunterRCState__Sequence * lhs, const hunter_msgs__msg__HunterRCState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hunter_msgs__msg__HunterRCState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hunter_msgs__msg__HunterRCState__Sequence__copy(
  const hunter_msgs__msg__HunterRCState__Sequence * input,
  hunter_msgs__msg__HunterRCState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hunter_msgs__msg__HunterRCState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hunter_msgs__msg__HunterRCState * data =
      (hunter_msgs__msg__HunterRCState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hunter_msgs__msg__HunterRCState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hunter_msgs__msg__HunterRCState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hunter_msgs__msg__HunterRCState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
