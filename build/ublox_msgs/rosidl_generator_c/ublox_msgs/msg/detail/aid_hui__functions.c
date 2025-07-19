// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/AidHUI.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/aid_hui__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__AidHUI__init(ublox_msgs__msg__AidHUI * msg)
{
  if (!msg) {
    return false;
  }
  // health
  // utc_a0
  // utc_a1
  // utc_tow
  // utc_wnt
  // utc_ls
  // utc_wnf
  // utc_dn
  // utc_lsf
  // utc_spare
  // klob_a0
  // klob_a1
  // klob_a2
  // klob_a3
  // klob_b0
  // klob_b1
  // klob_b2
  // klob_b3
  // flags
  return true;
}

void
ublox_msgs__msg__AidHUI__fini(ublox_msgs__msg__AidHUI * msg)
{
  if (!msg) {
    return;
  }
  // health
  // utc_a0
  // utc_a1
  // utc_tow
  // utc_wnt
  // utc_ls
  // utc_wnf
  // utc_dn
  // utc_lsf
  // utc_spare
  // klob_a0
  // klob_a1
  // klob_a2
  // klob_a3
  // klob_b0
  // klob_b1
  // klob_b2
  // klob_b3
  // flags
}

bool
ublox_msgs__msg__AidHUI__are_equal(const ublox_msgs__msg__AidHUI * lhs, const ublox_msgs__msg__AidHUI * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // health
  if (lhs->health != rhs->health) {
    return false;
  }
  // utc_a0
  if (lhs->utc_a0 != rhs->utc_a0) {
    return false;
  }
  // utc_a1
  if (lhs->utc_a1 != rhs->utc_a1) {
    return false;
  }
  // utc_tow
  if (lhs->utc_tow != rhs->utc_tow) {
    return false;
  }
  // utc_wnt
  if (lhs->utc_wnt != rhs->utc_wnt) {
    return false;
  }
  // utc_ls
  if (lhs->utc_ls != rhs->utc_ls) {
    return false;
  }
  // utc_wnf
  if (lhs->utc_wnf != rhs->utc_wnf) {
    return false;
  }
  // utc_dn
  if (lhs->utc_dn != rhs->utc_dn) {
    return false;
  }
  // utc_lsf
  if (lhs->utc_lsf != rhs->utc_lsf) {
    return false;
  }
  // utc_spare
  if (lhs->utc_spare != rhs->utc_spare) {
    return false;
  }
  // klob_a0
  if (lhs->klob_a0 != rhs->klob_a0) {
    return false;
  }
  // klob_a1
  if (lhs->klob_a1 != rhs->klob_a1) {
    return false;
  }
  // klob_a2
  if (lhs->klob_a2 != rhs->klob_a2) {
    return false;
  }
  // klob_a3
  if (lhs->klob_a3 != rhs->klob_a3) {
    return false;
  }
  // klob_b0
  if (lhs->klob_b0 != rhs->klob_b0) {
    return false;
  }
  // klob_b1
  if (lhs->klob_b1 != rhs->klob_b1) {
    return false;
  }
  // klob_b2
  if (lhs->klob_b2 != rhs->klob_b2) {
    return false;
  }
  // klob_b3
  if (lhs->klob_b3 != rhs->klob_b3) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__AidHUI__copy(
  const ublox_msgs__msg__AidHUI * input,
  ublox_msgs__msg__AidHUI * output)
{
  if (!input || !output) {
    return false;
  }
  // health
  output->health = input->health;
  // utc_a0
  output->utc_a0 = input->utc_a0;
  // utc_a1
  output->utc_a1 = input->utc_a1;
  // utc_tow
  output->utc_tow = input->utc_tow;
  // utc_wnt
  output->utc_wnt = input->utc_wnt;
  // utc_ls
  output->utc_ls = input->utc_ls;
  // utc_wnf
  output->utc_wnf = input->utc_wnf;
  // utc_dn
  output->utc_dn = input->utc_dn;
  // utc_lsf
  output->utc_lsf = input->utc_lsf;
  // utc_spare
  output->utc_spare = input->utc_spare;
  // klob_a0
  output->klob_a0 = input->klob_a0;
  // klob_a1
  output->klob_a1 = input->klob_a1;
  // klob_a2
  output->klob_a2 = input->klob_a2;
  // klob_a3
  output->klob_a3 = input->klob_a3;
  // klob_b0
  output->klob_b0 = input->klob_b0;
  // klob_b1
  output->klob_b1 = input->klob_b1;
  // klob_b2
  output->klob_b2 = input->klob_b2;
  // klob_b3
  output->klob_b3 = input->klob_b3;
  // flags
  output->flags = input->flags;
  return true;
}

ublox_msgs__msg__AidHUI *
ublox_msgs__msg__AidHUI__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__AidHUI * msg = (ublox_msgs__msg__AidHUI *)allocator.allocate(sizeof(ublox_msgs__msg__AidHUI), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__AidHUI));
  bool success = ublox_msgs__msg__AidHUI__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__AidHUI__destroy(ublox_msgs__msg__AidHUI * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__AidHUI__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__AidHUI__Sequence__init(ublox_msgs__msg__AidHUI__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__AidHUI * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__AidHUI *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__AidHUI), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__AidHUI__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__AidHUI__fini(&data[i - 1]);
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
ublox_msgs__msg__AidHUI__Sequence__fini(ublox_msgs__msg__AidHUI__Sequence * array)
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
      ublox_msgs__msg__AidHUI__fini(&array->data[i]);
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

ublox_msgs__msg__AidHUI__Sequence *
ublox_msgs__msg__AidHUI__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__AidHUI__Sequence * array = (ublox_msgs__msg__AidHUI__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__AidHUI__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__AidHUI__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__AidHUI__Sequence__destroy(ublox_msgs__msg__AidHUI__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__AidHUI__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__AidHUI__Sequence__are_equal(const ublox_msgs__msg__AidHUI__Sequence * lhs, const ublox_msgs__msg__AidHUI__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__AidHUI__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__AidHUI__Sequence__copy(
  const ublox_msgs__msg__AidHUI__Sequence * input,
  ublox_msgs__msg__AidHUI__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__AidHUI);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__AidHUI * data =
      (ublox_msgs__msg__AidHUI *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__AidHUI__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__AidHUI__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__AidHUI__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
