// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavRELPOSNED.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_relposned__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavRELPOSNED__init(ublox_msgs__msg__NavRELPOSNED * msg)
{
  if (!msg) {
    return false;
  }
  // version
  // reserved0
  // ref_station_id
  // i_tow
  // rel_pos_n
  // rel_pos_e
  // rel_pos_d
  // rel_pos_hpn
  // rel_pos_hpe
  // rel_pos_hpd
  // reserved1
  // acc_n
  // acc_e
  // acc_d
  // flags
  return true;
}

void
ublox_msgs__msg__NavRELPOSNED__fini(ublox_msgs__msg__NavRELPOSNED * msg)
{
  if (!msg) {
    return;
  }
  // version
  // reserved0
  // ref_station_id
  // i_tow
  // rel_pos_n
  // rel_pos_e
  // rel_pos_d
  // rel_pos_hpn
  // rel_pos_hpe
  // rel_pos_hpd
  // reserved1
  // acc_n
  // acc_e
  // acc_d
  // flags
}

bool
ublox_msgs__msg__NavRELPOSNED__are_equal(const ublox_msgs__msg__NavRELPOSNED * lhs, const ublox_msgs__msg__NavRELPOSNED * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // reserved0
  if (lhs->reserved0 != rhs->reserved0) {
    return false;
  }
  // ref_station_id
  if (lhs->ref_station_id != rhs->ref_station_id) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // rel_pos_n
  if (lhs->rel_pos_n != rhs->rel_pos_n) {
    return false;
  }
  // rel_pos_e
  if (lhs->rel_pos_e != rhs->rel_pos_e) {
    return false;
  }
  // rel_pos_d
  if (lhs->rel_pos_d != rhs->rel_pos_d) {
    return false;
  }
  // rel_pos_hpn
  if (lhs->rel_pos_hpn != rhs->rel_pos_hpn) {
    return false;
  }
  // rel_pos_hpe
  if (lhs->rel_pos_hpe != rhs->rel_pos_hpe) {
    return false;
  }
  // rel_pos_hpd
  if (lhs->rel_pos_hpd != rhs->rel_pos_hpd) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  // acc_n
  if (lhs->acc_n != rhs->acc_n) {
    return false;
  }
  // acc_e
  if (lhs->acc_e != rhs->acc_e) {
    return false;
  }
  // acc_d
  if (lhs->acc_d != rhs->acc_d) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavRELPOSNED__copy(
  const ublox_msgs__msg__NavRELPOSNED * input,
  ublox_msgs__msg__NavRELPOSNED * output)
{
  if (!input || !output) {
    return false;
  }
  // version
  output->version = input->version;
  // reserved0
  output->reserved0 = input->reserved0;
  // ref_station_id
  output->ref_station_id = input->ref_station_id;
  // i_tow
  output->i_tow = input->i_tow;
  // rel_pos_n
  output->rel_pos_n = input->rel_pos_n;
  // rel_pos_e
  output->rel_pos_e = input->rel_pos_e;
  // rel_pos_d
  output->rel_pos_d = input->rel_pos_d;
  // rel_pos_hpn
  output->rel_pos_hpn = input->rel_pos_hpn;
  // rel_pos_hpe
  output->rel_pos_hpe = input->rel_pos_hpe;
  // rel_pos_hpd
  output->rel_pos_hpd = input->rel_pos_hpd;
  // reserved1
  output->reserved1 = input->reserved1;
  // acc_n
  output->acc_n = input->acc_n;
  // acc_e
  output->acc_e = input->acc_e;
  // acc_d
  output->acc_d = input->acc_d;
  // flags
  output->flags = input->flags;
  return true;
}

ublox_msgs__msg__NavRELPOSNED *
ublox_msgs__msg__NavRELPOSNED__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavRELPOSNED * msg = (ublox_msgs__msg__NavRELPOSNED *)allocator.allocate(sizeof(ublox_msgs__msg__NavRELPOSNED), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavRELPOSNED));
  bool success = ublox_msgs__msg__NavRELPOSNED__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavRELPOSNED__destroy(ublox_msgs__msg__NavRELPOSNED * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavRELPOSNED__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavRELPOSNED__Sequence__init(ublox_msgs__msg__NavRELPOSNED__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavRELPOSNED * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavRELPOSNED *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavRELPOSNED), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavRELPOSNED__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavRELPOSNED__fini(&data[i - 1]);
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
ublox_msgs__msg__NavRELPOSNED__Sequence__fini(ublox_msgs__msg__NavRELPOSNED__Sequence * array)
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
      ublox_msgs__msg__NavRELPOSNED__fini(&array->data[i]);
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

ublox_msgs__msg__NavRELPOSNED__Sequence *
ublox_msgs__msg__NavRELPOSNED__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavRELPOSNED__Sequence * array = (ublox_msgs__msg__NavRELPOSNED__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavRELPOSNED__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavRELPOSNED__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavRELPOSNED__Sequence__destroy(ublox_msgs__msg__NavRELPOSNED__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavRELPOSNED__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavRELPOSNED__Sequence__are_equal(const ublox_msgs__msg__NavRELPOSNED__Sequence * lhs, const ublox_msgs__msg__NavRELPOSNED__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavRELPOSNED__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavRELPOSNED__Sequence__copy(
  const ublox_msgs__msg__NavRELPOSNED__Sequence * input,
  ublox_msgs__msg__NavRELPOSNED__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavRELPOSNED);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavRELPOSNED * data =
      (ublox_msgs__msg__NavRELPOSNED *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavRELPOSNED__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavRELPOSNED__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavRELPOSNED__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
