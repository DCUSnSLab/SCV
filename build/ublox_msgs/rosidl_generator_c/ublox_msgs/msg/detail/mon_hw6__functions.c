// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/MonHW6.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/mon_hw6__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__MonHW6__init(ublox_msgs__msg__MonHW6 * msg)
{
  if (!msg) {
    return false;
  }
  // pin_sel
  // pin_bank
  // pin_dir
  // pin_val
  // noise_per_ms
  // agc_cnt
  // a_status
  // a_power
  // flags
  // reserved0
  // used_mask
  // vp
  // jam_ind
  // reserved1
  // pin_irq
  // pull_h
  // pull_l
  return true;
}

void
ublox_msgs__msg__MonHW6__fini(ublox_msgs__msg__MonHW6 * msg)
{
  if (!msg) {
    return;
  }
  // pin_sel
  // pin_bank
  // pin_dir
  // pin_val
  // noise_per_ms
  // agc_cnt
  // a_status
  // a_power
  // flags
  // reserved0
  // used_mask
  // vp
  // jam_ind
  // reserved1
  // pin_irq
  // pull_h
  // pull_l
}

bool
ublox_msgs__msg__MonHW6__are_equal(const ublox_msgs__msg__MonHW6 * lhs, const ublox_msgs__msg__MonHW6 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pin_sel
  if (lhs->pin_sel != rhs->pin_sel) {
    return false;
  }
  // pin_bank
  if (lhs->pin_bank != rhs->pin_bank) {
    return false;
  }
  // pin_dir
  if (lhs->pin_dir != rhs->pin_dir) {
    return false;
  }
  // pin_val
  if (lhs->pin_val != rhs->pin_val) {
    return false;
  }
  // noise_per_ms
  if (lhs->noise_per_ms != rhs->noise_per_ms) {
    return false;
  }
  // agc_cnt
  if (lhs->agc_cnt != rhs->agc_cnt) {
    return false;
  }
  // a_status
  if (lhs->a_status != rhs->a_status) {
    return false;
  }
  // a_power
  if (lhs->a_power != rhs->a_power) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // reserved0
  if (lhs->reserved0 != rhs->reserved0) {
    return false;
  }
  // used_mask
  if (lhs->used_mask != rhs->used_mask) {
    return false;
  }
  // vp
  for (size_t i = 0; i < 25; ++i) {
    if (lhs->vp[i] != rhs->vp[i]) {
      return false;
    }
  }
  // jam_ind
  if (lhs->jam_ind != rhs->jam_ind) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // pin_irq
  if (lhs->pin_irq != rhs->pin_irq) {
    return false;
  }
  // pull_h
  if (lhs->pull_h != rhs->pull_h) {
    return false;
  }
  // pull_l
  if (lhs->pull_l != rhs->pull_l) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__MonHW6__copy(
  const ublox_msgs__msg__MonHW6 * input,
  ublox_msgs__msg__MonHW6 * output)
{
  if (!input || !output) {
    return false;
  }
  // pin_sel
  output->pin_sel = input->pin_sel;
  // pin_bank
  output->pin_bank = input->pin_bank;
  // pin_dir
  output->pin_dir = input->pin_dir;
  // pin_val
  output->pin_val = input->pin_val;
  // noise_per_ms
  output->noise_per_ms = input->noise_per_ms;
  // agc_cnt
  output->agc_cnt = input->agc_cnt;
  // a_status
  output->a_status = input->a_status;
  // a_power
  output->a_power = input->a_power;
  // flags
  output->flags = input->flags;
  // reserved0
  output->reserved0 = input->reserved0;
  // used_mask
  output->used_mask = input->used_mask;
  // vp
  for (size_t i = 0; i < 25; ++i) {
    output->vp[i] = input->vp[i];
  }
  // jam_ind
  output->jam_ind = input->jam_ind;
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // pin_irq
  output->pin_irq = input->pin_irq;
  // pull_h
  output->pull_h = input->pull_h;
  // pull_l
  output->pull_l = input->pull_l;
  return true;
}

ublox_msgs__msg__MonHW6 *
ublox_msgs__msg__MonHW6__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MonHW6 * msg = (ublox_msgs__msg__MonHW6 *)allocator.allocate(sizeof(ublox_msgs__msg__MonHW6), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__MonHW6));
  bool success = ublox_msgs__msg__MonHW6__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__MonHW6__destroy(ublox_msgs__msg__MonHW6 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__MonHW6__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__MonHW6__Sequence__init(ublox_msgs__msg__MonHW6__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MonHW6 * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__MonHW6 *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__MonHW6), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__MonHW6__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__MonHW6__fini(&data[i - 1]);
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
ublox_msgs__msg__MonHW6__Sequence__fini(ublox_msgs__msg__MonHW6__Sequence * array)
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
      ublox_msgs__msg__MonHW6__fini(&array->data[i]);
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

ublox_msgs__msg__MonHW6__Sequence *
ublox_msgs__msg__MonHW6__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MonHW6__Sequence * array = (ublox_msgs__msg__MonHW6__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__MonHW6__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__MonHW6__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__MonHW6__Sequence__destroy(ublox_msgs__msg__MonHW6__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__MonHW6__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__MonHW6__Sequence__are_equal(const ublox_msgs__msg__MonHW6__Sequence * lhs, const ublox_msgs__msg__MonHW6__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__MonHW6__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__MonHW6__Sequence__copy(
  const ublox_msgs__msg__MonHW6__Sequence * input,
  ublox_msgs__msg__MonHW6__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__MonHW6);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__MonHW6 * data =
      (ublox_msgs__msg__MonHW6 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__MonHW6__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__MonHW6__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__MonHW6__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
