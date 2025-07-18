// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/RxmRAWXMeas.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/rxm_rawx_meas__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__RxmRAWXMeas__init(ublox_msgs__msg__RxmRAWXMeas * msg)
{
  if (!msg) {
    return false;
  }
  // pr_mes
  // cp_mes
  // do_mes
  // gnss_id
  // sv_id
  // reserved0
  // freq_id
  // locktime
  // cno
  // pr_stdev
  // cp_stdev
  // do_stdev
  // trk_stat
  // reserved1
  return true;
}

void
ublox_msgs__msg__RxmRAWXMeas__fini(ublox_msgs__msg__RxmRAWXMeas * msg)
{
  if (!msg) {
    return;
  }
  // pr_mes
  // cp_mes
  // do_mes
  // gnss_id
  // sv_id
  // reserved0
  // freq_id
  // locktime
  // cno
  // pr_stdev
  // cp_stdev
  // do_stdev
  // trk_stat
  // reserved1
}

bool
ublox_msgs__msg__RxmRAWXMeas__are_equal(const ublox_msgs__msg__RxmRAWXMeas * lhs, const ublox_msgs__msg__RxmRAWXMeas * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pr_mes
  if (lhs->pr_mes != rhs->pr_mes) {
    return false;
  }
  // cp_mes
  if (lhs->cp_mes != rhs->cp_mes) {
    return false;
  }
  // do_mes
  if (lhs->do_mes != rhs->do_mes) {
    return false;
  }
  // gnss_id
  if (lhs->gnss_id != rhs->gnss_id) {
    return false;
  }
  // sv_id
  if (lhs->sv_id != rhs->sv_id) {
    return false;
  }
  // reserved0
  if (lhs->reserved0 != rhs->reserved0) {
    return false;
  }
  // freq_id
  if (lhs->freq_id != rhs->freq_id) {
    return false;
  }
  // locktime
  if (lhs->locktime != rhs->locktime) {
    return false;
  }
  // cno
  if (lhs->cno != rhs->cno) {
    return false;
  }
  // pr_stdev
  if (lhs->pr_stdev != rhs->pr_stdev) {
    return false;
  }
  // cp_stdev
  if (lhs->cp_stdev != rhs->cp_stdev) {
    return false;
  }
  // do_stdev
  if (lhs->do_stdev != rhs->do_stdev) {
    return false;
  }
  // trk_stat
  if (lhs->trk_stat != rhs->trk_stat) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAWXMeas__copy(
  const ublox_msgs__msg__RxmRAWXMeas * input,
  ublox_msgs__msg__RxmRAWXMeas * output)
{
  if (!input || !output) {
    return false;
  }
  // pr_mes
  output->pr_mes = input->pr_mes;
  // cp_mes
  output->cp_mes = input->cp_mes;
  // do_mes
  output->do_mes = input->do_mes;
  // gnss_id
  output->gnss_id = input->gnss_id;
  // sv_id
  output->sv_id = input->sv_id;
  // reserved0
  output->reserved0 = input->reserved0;
  // freq_id
  output->freq_id = input->freq_id;
  // locktime
  output->locktime = input->locktime;
  // cno
  output->cno = input->cno;
  // pr_stdev
  output->pr_stdev = input->pr_stdev;
  // cp_stdev
  output->cp_stdev = input->cp_stdev;
  // do_stdev
  output->do_stdev = input->do_stdev;
  // trk_stat
  output->trk_stat = input->trk_stat;
  // reserved1
  output->reserved1 = input->reserved1;
  return true;
}

ublox_msgs__msg__RxmRAWXMeas *
ublox_msgs__msg__RxmRAWXMeas__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWXMeas * msg = (ublox_msgs__msg__RxmRAWXMeas *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAWXMeas), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__RxmRAWXMeas));
  bool success = ublox_msgs__msg__RxmRAWXMeas__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__RxmRAWXMeas__destroy(ublox_msgs__msg__RxmRAWXMeas * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__RxmRAWXMeas__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__RxmRAWXMeas__Sequence__init(ublox_msgs__msg__RxmRAWXMeas__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWXMeas * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__RxmRAWXMeas *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__RxmRAWXMeas), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__RxmRAWXMeas__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__RxmRAWXMeas__fini(&data[i - 1]);
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
ublox_msgs__msg__RxmRAWXMeas__Sequence__fini(ublox_msgs__msg__RxmRAWXMeas__Sequence * array)
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
      ublox_msgs__msg__RxmRAWXMeas__fini(&array->data[i]);
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

ublox_msgs__msg__RxmRAWXMeas__Sequence *
ublox_msgs__msg__RxmRAWXMeas__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWXMeas__Sequence * array = (ublox_msgs__msg__RxmRAWXMeas__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAWXMeas__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__RxmRAWXMeas__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__RxmRAWXMeas__Sequence__destroy(ublox_msgs__msg__RxmRAWXMeas__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__RxmRAWXMeas__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__RxmRAWXMeas__Sequence__are_equal(const ublox_msgs__msg__RxmRAWXMeas__Sequence * lhs, const ublox_msgs__msg__RxmRAWXMeas__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__RxmRAWXMeas__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAWXMeas__Sequence__copy(
  const ublox_msgs__msg__RxmRAWXMeas__Sequence * input,
  ublox_msgs__msg__RxmRAWXMeas__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__RxmRAWXMeas);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__RxmRAWXMeas * data =
      (ublox_msgs__msg__RxmRAWXMeas *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__RxmRAWXMeas__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__RxmRAWXMeas__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__RxmRAWXMeas__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
