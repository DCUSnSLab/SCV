// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgUSB.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_usb__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgUSB__init(ublox_msgs__msg__CfgUSB * msg)
{
  if (!msg) {
    return false;
  }
  // vendor_id
  // product_id
  // reserved1
  // reserved2
  // power_consumption
  // flags
  // vendor_string
  // product_string
  // serial_number
  return true;
}

void
ublox_msgs__msg__CfgUSB__fini(ublox_msgs__msg__CfgUSB * msg)
{
  if (!msg) {
    return;
  }
  // vendor_id
  // product_id
  // reserved1
  // reserved2
  // power_consumption
  // flags
  // vendor_string
  // product_string
  // serial_number
}

bool
ublox_msgs__msg__CfgUSB__are_equal(const ublox_msgs__msg__CfgUSB * lhs, const ublox_msgs__msg__CfgUSB * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vendor_id
  if (lhs->vendor_id != rhs->vendor_id) {
    return false;
  }
  // product_id
  if (lhs->product_id != rhs->product_id) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // reserved2
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved2[i] != rhs->reserved2[i]) {
      return false;
    }
  }
  // power_consumption
  if (lhs->power_consumption != rhs->power_consumption) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // vendor_string
  for (size_t i = 0; i < 32; ++i) {
    if (lhs->vendor_string[i] != rhs->vendor_string[i]) {
      return false;
    }
  }
  // product_string
  for (size_t i = 0; i < 32; ++i) {
    if (lhs->product_string[i] != rhs->product_string[i]) {
      return false;
    }
  }
  // serial_number
  for (size_t i = 0; i < 32; ++i) {
    if (lhs->serial_number[i] != rhs->serial_number[i]) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgUSB__copy(
  const ublox_msgs__msg__CfgUSB * input,
  ublox_msgs__msg__CfgUSB * output)
{
  if (!input || !output) {
    return false;
  }
  // vendor_id
  output->vendor_id = input->vendor_id;
  // product_id
  output->product_id = input->product_id;
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // reserved2
  for (size_t i = 0; i < 2; ++i) {
    output->reserved2[i] = input->reserved2[i];
  }
  // power_consumption
  output->power_consumption = input->power_consumption;
  // flags
  output->flags = input->flags;
  // vendor_string
  for (size_t i = 0; i < 32; ++i) {
    output->vendor_string[i] = input->vendor_string[i];
  }
  // product_string
  for (size_t i = 0; i < 32; ++i) {
    output->product_string[i] = input->product_string[i];
  }
  // serial_number
  for (size_t i = 0; i < 32; ++i) {
    output->serial_number[i] = input->serial_number[i];
  }
  return true;
}

ublox_msgs__msg__CfgUSB *
ublox_msgs__msg__CfgUSB__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgUSB * msg = (ublox_msgs__msg__CfgUSB *)allocator.allocate(sizeof(ublox_msgs__msg__CfgUSB), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgUSB));
  bool success = ublox_msgs__msg__CfgUSB__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgUSB__destroy(ublox_msgs__msg__CfgUSB * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgUSB__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgUSB__Sequence__init(ublox_msgs__msg__CfgUSB__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgUSB * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgUSB *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgUSB), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgUSB__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgUSB__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgUSB__Sequence__fini(ublox_msgs__msg__CfgUSB__Sequence * array)
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
      ublox_msgs__msg__CfgUSB__fini(&array->data[i]);
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

ublox_msgs__msg__CfgUSB__Sequence *
ublox_msgs__msg__CfgUSB__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgUSB__Sequence * array = (ublox_msgs__msg__CfgUSB__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgUSB__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgUSB__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgUSB__Sequence__destroy(ublox_msgs__msg__CfgUSB__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgUSB__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgUSB__Sequence__are_equal(const ublox_msgs__msg__CfgUSB__Sequence * lhs, const ublox_msgs__msg__CfgUSB__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgUSB__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgUSB__Sequence__copy(
  const ublox_msgs__msg__CfgUSB__Sequence * input,
  ublox_msgs__msg__CfgUSB__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgUSB);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgUSB * data =
      (ublox_msgs__msg__CfgUSB *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgUSB__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgUSB__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgUSB__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
