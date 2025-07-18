// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgPRT.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_prt__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgPRT__init(ublox_msgs__msg__CfgPRT * msg)
{
  if (!msg) {
    return false;
  }
  // port_id
  // reserved0
  // tx_ready
  // mode
  // baud_rate
  // in_proto_mask
  // out_proto_mask
  // flags
  // reserved1
  return true;
}

void
ublox_msgs__msg__CfgPRT__fini(ublox_msgs__msg__CfgPRT * msg)
{
  if (!msg) {
    return;
  }
  // port_id
  // reserved0
  // tx_ready
  // mode
  // baud_rate
  // in_proto_mask
  // out_proto_mask
  // flags
  // reserved1
}

bool
ublox_msgs__msg__CfgPRT__are_equal(const ublox_msgs__msg__CfgPRT * lhs, const ublox_msgs__msg__CfgPRT * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // port_id
  if (lhs->port_id != rhs->port_id) {
    return false;
  }
  // reserved0
  if (lhs->reserved0 != rhs->reserved0) {
    return false;
  }
  // tx_ready
  if (lhs->tx_ready != rhs->tx_ready) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // baud_rate
  if (lhs->baud_rate != rhs->baud_rate) {
    return false;
  }
  // in_proto_mask
  if (lhs->in_proto_mask != rhs->in_proto_mask) {
    return false;
  }
  // out_proto_mask
  if (lhs->out_proto_mask != rhs->out_proto_mask) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgPRT__copy(
  const ublox_msgs__msg__CfgPRT * input,
  ublox_msgs__msg__CfgPRT * output)
{
  if (!input || !output) {
    return false;
  }
  // port_id
  output->port_id = input->port_id;
  // reserved0
  output->reserved0 = input->reserved0;
  // tx_ready
  output->tx_ready = input->tx_ready;
  // mode
  output->mode = input->mode;
  // baud_rate
  output->baud_rate = input->baud_rate;
  // in_proto_mask
  output->in_proto_mask = input->in_proto_mask;
  // out_proto_mask
  output->out_proto_mask = input->out_proto_mask;
  // flags
  output->flags = input->flags;
  // reserved1
  output->reserved1 = input->reserved1;
  return true;
}

ublox_msgs__msg__CfgPRT *
ublox_msgs__msg__CfgPRT__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgPRT * msg = (ublox_msgs__msg__CfgPRT *)allocator.allocate(sizeof(ublox_msgs__msg__CfgPRT), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgPRT));
  bool success = ublox_msgs__msg__CfgPRT__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgPRT__destroy(ublox_msgs__msg__CfgPRT * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgPRT__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgPRT__Sequence__init(ublox_msgs__msg__CfgPRT__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgPRT * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgPRT *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgPRT), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgPRT__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgPRT__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgPRT__Sequence__fini(ublox_msgs__msg__CfgPRT__Sequence * array)
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
      ublox_msgs__msg__CfgPRT__fini(&array->data[i]);
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

ublox_msgs__msg__CfgPRT__Sequence *
ublox_msgs__msg__CfgPRT__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgPRT__Sequence * array = (ublox_msgs__msg__CfgPRT__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgPRT__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgPRT__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgPRT__Sequence__destroy(ublox_msgs__msg__CfgPRT__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgPRT__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgPRT__Sequence__are_equal(const ublox_msgs__msg__CfgPRT__Sequence * lhs, const ublox_msgs__msg__CfgPRT__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgPRT__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgPRT__Sequence__copy(
  const ublox_msgs__msg__CfgPRT__Sequence * input,
  ublox_msgs__msg__CfgPRT__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgPRT);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgPRT * data =
      (ublox_msgs__msg__CfgPRT *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgPRT__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgPRT__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgPRT__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
