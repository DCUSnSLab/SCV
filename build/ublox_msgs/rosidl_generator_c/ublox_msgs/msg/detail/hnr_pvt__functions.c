// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/HnrPVT.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/hnr_pvt__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__HnrPVT__init(ublox_msgs__msg__HnrPVT * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // year
  // month
  // day
  // hour
  // min
  // sec
  // valid
  // nano
  // gps_fix
  // flags
  // reserved0
  // lon
  // lat
  // height
  // h_msl
  // g_speed
  // speed
  // head_mot
  // head_veh
  // h_acc
  // v_acc
  // s_acc
  // head_acc
  // reserved1
  return true;
}

void
ublox_msgs__msg__HnrPVT__fini(ublox_msgs__msg__HnrPVT * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // year
  // month
  // day
  // hour
  // min
  // sec
  // valid
  // nano
  // gps_fix
  // flags
  // reserved0
  // lon
  // lat
  // height
  // h_msl
  // g_speed
  // speed
  // head_mot
  // head_veh
  // h_acc
  // v_acc
  // s_acc
  // head_acc
  // reserved1
}

bool
ublox_msgs__msg__HnrPVT__are_equal(const ublox_msgs__msg__HnrPVT * lhs, const ublox_msgs__msg__HnrPVT * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
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
  // nano
  if (lhs->nano != rhs->nano) {
    return false;
  }
  // gps_fix
  if (lhs->gps_fix != rhs->gps_fix) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // reserved0
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved0[i] != rhs->reserved0[i]) {
      return false;
    }
  }
  // lon
  if (lhs->lon != rhs->lon) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // h_msl
  if (lhs->h_msl != rhs->h_msl) {
    return false;
  }
  // g_speed
  if (lhs->g_speed != rhs->g_speed) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // head_mot
  if (lhs->head_mot != rhs->head_mot) {
    return false;
  }
  // head_veh
  if (lhs->head_veh != rhs->head_veh) {
    return false;
  }
  // h_acc
  if (lhs->h_acc != rhs->h_acc) {
    return false;
  }
  // v_acc
  if (lhs->v_acc != rhs->v_acc) {
    return false;
  }
  // s_acc
  if (lhs->s_acc != rhs->s_acc) {
    return false;
  }
  // head_acc
  if (lhs->head_acc != rhs->head_acc) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__HnrPVT__copy(
  const ublox_msgs__msg__HnrPVT * input,
  ublox_msgs__msg__HnrPVT * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
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
  // nano
  output->nano = input->nano;
  // gps_fix
  output->gps_fix = input->gps_fix;
  // flags
  output->flags = input->flags;
  // reserved0
  for (size_t i = 0; i < 2; ++i) {
    output->reserved0[i] = input->reserved0[i];
  }
  // lon
  output->lon = input->lon;
  // lat
  output->lat = input->lat;
  // height
  output->height = input->height;
  // h_msl
  output->h_msl = input->h_msl;
  // g_speed
  output->g_speed = input->g_speed;
  // speed
  output->speed = input->speed;
  // head_mot
  output->head_mot = input->head_mot;
  // head_veh
  output->head_veh = input->head_veh;
  // h_acc
  output->h_acc = input->h_acc;
  // v_acc
  output->v_acc = input->v_acc;
  // s_acc
  output->s_acc = input->s_acc;
  // head_acc
  output->head_acc = input->head_acc;
  // reserved1
  for (size_t i = 0; i < 4; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  return true;
}

ublox_msgs__msg__HnrPVT *
ublox_msgs__msg__HnrPVT__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__HnrPVT * msg = (ublox_msgs__msg__HnrPVT *)allocator.allocate(sizeof(ublox_msgs__msg__HnrPVT), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__HnrPVT));
  bool success = ublox_msgs__msg__HnrPVT__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__HnrPVT__destroy(ublox_msgs__msg__HnrPVT * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__HnrPVT__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__HnrPVT__Sequence__init(ublox_msgs__msg__HnrPVT__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__HnrPVT * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__HnrPVT *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__HnrPVT), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__HnrPVT__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__HnrPVT__fini(&data[i - 1]);
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
ublox_msgs__msg__HnrPVT__Sequence__fini(ublox_msgs__msg__HnrPVT__Sequence * array)
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
      ublox_msgs__msg__HnrPVT__fini(&array->data[i]);
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

ublox_msgs__msg__HnrPVT__Sequence *
ublox_msgs__msg__HnrPVT__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__HnrPVT__Sequence * array = (ublox_msgs__msg__HnrPVT__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__HnrPVT__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__HnrPVT__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__HnrPVT__Sequence__destroy(ublox_msgs__msg__HnrPVT__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__HnrPVT__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__HnrPVT__Sequence__are_equal(const ublox_msgs__msg__HnrPVT__Sequence * lhs, const ublox_msgs__msg__HnrPVT__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__HnrPVT__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__HnrPVT__Sequence__copy(
  const ublox_msgs__msg__HnrPVT__Sequence * input,
  ublox_msgs__msg__HnrPVT__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__HnrPVT);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__HnrPVT * data =
      (ublox_msgs__msg__HnrPVT *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__HnrPVT__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__HnrPVT__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__HnrPVT__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
