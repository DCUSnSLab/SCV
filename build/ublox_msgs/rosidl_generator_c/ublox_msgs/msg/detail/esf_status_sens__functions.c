// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/EsfSTATUSSens.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/esf_status_sens__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__EsfSTATUSSens__init(ublox_msgs__msg__EsfSTATUSSens * msg)
{
  if (!msg) {
    return false;
  }
  // sens_status1
  // sens_status2
  // freq
  // faults
  return true;
}

void
ublox_msgs__msg__EsfSTATUSSens__fini(ublox_msgs__msg__EsfSTATUSSens * msg)
{
  if (!msg) {
    return;
  }
  // sens_status1
  // sens_status2
  // freq
  // faults
}

bool
ublox_msgs__msg__EsfSTATUSSens__are_equal(const ublox_msgs__msg__EsfSTATUSSens * lhs, const ublox_msgs__msg__EsfSTATUSSens * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sens_status1
  if (lhs->sens_status1 != rhs->sens_status1) {
    return false;
  }
  // sens_status2
  if (lhs->sens_status2 != rhs->sens_status2) {
    return false;
  }
  // freq
  if (lhs->freq != rhs->freq) {
    return false;
  }
  // faults
  if (lhs->faults != rhs->faults) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__EsfSTATUSSens__copy(
  const ublox_msgs__msg__EsfSTATUSSens * input,
  ublox_msgs__msg__EsfSTATUSSens * output)
{
  if (!input || !output) {
    return false;
  }
  // sens_status1
  output->sens_status1 = input->sens_status1;
  // sens_status2
  output->sens_status2 = input->sens_status2;
  // freq
  output->freq = input->freq;
  // faults
  output->faults = input->faults;
  return true;
}

ublox_msgs__msg__EsfSTATUSSens *
ublox_msgs__msg__EsfSTATUSSens__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfSTATUSSens * msg = (ublox_msgs__msg__EsfSTATUSSens *)allocator.allocate(sizeof(ublox_msgs__msg__EsfSTATUSSens), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__EsfSTATUSSens));
  bool success = ublox_msgs__msg__EsfSTATUSSens__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__EsfSTATUSSens__destroy(ublox_msgs__msg__EsfSTATUSSens * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__EsfSTATUSSens__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__EsfSTATUSSens__Sequence__init(ublox_msgs__msg__EsfSTATUSSens__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfSTATUSSens * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__EsfSTATUSSens *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__EsfSTATUSSens), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__EsfSTATUSSens__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__EsfSTATUSSens__fini(&data[i - 1]);
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
ublox_msgs__msg__EsfSTATUSSens__Sequence__fini(ublox_msgs__msg__EsfSTATUSSens__Sequence * array)
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
      ublox_msgs__msg__EsfSTATUSSens__fini(&array->data[i]);
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

ublox_msgs__msg__EsfSTATUSSens__Sequence *
ublox_msgs__msg__EsfSTATUSSens__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfSTATUSSens__Sequence * array = (ublox_msgs__msg__EsfSTATUSSens__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__EsfSTATUSSens__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__EsfSTATUSSens__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__EsfSTATUSSens__Sequence__destroy(ublox_msgs__msg__EsfSTATUSSens__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__EsfSTATUSSens__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__EsfSTATUSSens__Sequence__are_equal(const ublox_msgs__msg__EsfSTATUSSens__Sequence * lhs, const ublox_msgs__msg__EsfSTATUSSens__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__EsfSTATUSSens__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__EsfSTATUSSens__Sequence__copy(
  const ublox_msgs__msg__EsfSTATUSSens__Sequence * input,
  ublox_msgs__msg__EsfSTATUSSens__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__EsfSTATUSSens);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__EsfSTATUSSens * data =
      (ublox_msgs__msg__EsfSTATUSSens *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__EsfSTATUSSens__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__EsfSTATUSSens__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__EsfSTATUSSens__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
