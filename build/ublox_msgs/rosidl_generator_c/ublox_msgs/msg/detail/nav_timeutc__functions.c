// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavTIMEUTC.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_timeutc__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavTIMEUTC__init(ublox_msgs__msg__NavTIMEUTC * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // t_acc
  // nano
  // year
  // month
  // day
  // hour
  // min
  // sec
  // valid
  return true;
}

void
ublox_msgs__msg__NavTIMEUTC__fini(ublox_msgs__msg__NavTIMEUTC * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // t_acc
  // nano
  // year
  // month
  // day
  // hour
  // min
  // sec
  // valid
}

bool
ublox_msgs__msg__NavTIMEUTC__are_equal(const ublox_msgs__msg__NavTIMEUTC * lhs, const ublox_msgs__msg__NavTIMEUTC * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // t_acc
  if (lhs->t_acc != rhs->t_acc) {
    return false;
  }
  // nano
  if (lhs->nano != rhs->nano) {
    return false;
  }
  // year
  if (lhs->year != rhs->year) {
    return false;
  }
  // month
  if (lhs->month != rhs->month) {
    return false;
  }
  // day
  if (lhs->day != rhs->day) {
    return false;
  }
  // hour
  if (lhs->hour != rhs->hour) {
    return false;
  }
  // min
  if (lhs->min != rhs->min) {
    return false;
  }
  // sec
  if (lhs->sec != rhs->sec) {
    return false;
  }
  // valid
  if (lhs->valid != rhs->valid) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavTIMEUTC__copy(
  const ublox_msgs__msg__NavTIMEUTC * input,
  ublox_msgs__msg__NavTIMEUTC * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // t_acc
  output->t_acc = input->t_acc;
  // nano
  output->nano = input->nano;
  // year
  output->year = input->year;
  // month
  output->month = input->month;
  // day
  output->day = input->day;
  // hour
  output->hour = input->hour;
  // min
  output->min = input->min;
  // sec
  output->sec = input->sec;
  // valid
  output->valid = input->valid;
  return true;
}

ublox_msgs__msg__NavTIMEUTC *
ublox_msgs__msg__NavTIMEUTC__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavTIMEUTC * msg = (ublox_msgs__msg__NavTIMEUTC *)allocator.allocate(sizeof(ublox_msgs__msg__NavTIMEUTC), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavTIMEUTC));
  bool success = ublox_msgs__msg__NavTIMEUTC__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavTIMEUTC__destroy(ublox_msgs__msg__NavTIMEUTC * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavTIMEUTC__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavTIMEUTC__Sequence__init(ublox_msgs__msg__NavTIMEUTC__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavTIMEUTC * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavTIMEUTC *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavTIMEUTC), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavTIMEUTC__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavTIMEUTC__fini(&data[i - 1]);
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
ublox_msgs__msg__NavTIMEUTC__Sequence__fini(ublox_msgs__msg__NavTIMEUTC__Sequence * array)
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
      ublox_msgs__msg__NavTIMEUTC__fini(&array->data[i]);
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

ublox_msgs__msg__NavTIMEUTC__Sequence *
ublox_msgs__msg__NavTIMEUTC__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavTIMEUTC__Sequence * array = (ublox_msgs__msg__NavTIMEUTC__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavTIMEUTC__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavTIMEUTC__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavTIMEUTC__Sequence__destroy(ublox_msgs__msg__NavTIMEUTC__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavTIMEUTC__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavTIMEUTC__Sequence__are_equal(const ublox_msgs__msg__NavTIMEUTC__Sequence * lhs, const ublox_msgs__msg__NavTIMEUTC__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavTIMEUTC__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavTIMEUTC__Sequence__copy(
  const ublox_msgs__msg__NavTIMEUTC__Sequence * input,
  ublox_msgs__msg__NavTIMEUTC__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavTIMEUTC);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavTIMEUTC * data =
      (ublox_msgs__msg__NavTIMEUTC *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavTIMEUTC__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavTIMEUTC__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavTIMEUTC__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
