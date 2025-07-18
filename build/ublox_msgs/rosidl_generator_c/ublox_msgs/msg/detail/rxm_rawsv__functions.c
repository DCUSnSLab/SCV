// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/RxmRAWSV.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/rxm_rawsv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__RxmRAWSV__init(ublox_msgs__msg__RxmRAWSV * msg)
{
  if (!msg) {
    return false;
  }
  // cp_mes
  // pr_mes
  // do_mes
  // sv
  // mes_qi
  // cno
  // lli
  return true;
}

void
ublox_msgs__msg__RxmRAWSV__fini(ublox_msgs__msg__RxmRAWSV * msg)
{
  if (!msg) {
    return;
  }
  // cp_mes
  // pr_mes
  // do_mes
  // sv
  // mes_qi
  // cno
  // lli
}

bool
ublox_msgs__msg__RxmRAWSV__are_equal(const ublox_msgs__msg__RxmRAWSV * lhs, const ublox_msgs__msg__RxmRAWSV * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cp_mes
  if (lhs->cp_mes != rhs->cp_mes) {
    return false;
  }
  // pr_mes
  if (lhs->pr_mes != rhs->pr_mes) {
    return false;
  }
  // do_mes
  if (lhs->do_mes != rhs->do_mes) {
    return false;
  }
  // sv
  if (lhs->sv != rhs->sv) {
    return false;
  }
  // mes_qi
  if (lhs->mes_qi != rhs->mes_qi) {
    return false;
  }
  // cno
  if (lhs->cno != rhs->cno) {
    return false;
  }
  // lli
  if (lhs->lli != rhs->lli) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAWSV__copy(
  const ublox_msgs__msg__RxmRAWSV * input,
  ublox_msgs__msg__RxmRAWSV * output)
{
  if (!input || !output) {
    return false;
  }
  // cp_mes
  output->cp_mes = input->cp_mes;
  // pr_mes
  output->pr_mes = input->pr_mes;
  // do_mes
  output->do_mes = input->do_mes;
  // sv
  output->sv = input->sv;
  // mes_qi
  output->mes_qi = input->mes_qi;
  // cno
  output->cno = input->cno;
  // lli
  output->lli = input->lli;
  return true;
}

ublox_msgs__msg__RxmRAWSV *
ublox_msgs__msg__RxmRAWSV__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWSV * msg = (ublox_msgs__msg__RxmRAWSV *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAWSV), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__RxmRAWSV));
  bool success = ublox_msgs__msg__RxmRAWSV__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__RxmRAWSV__destroy(ublox_msgs__msg__RxmRAWSV * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__RxmRAWSV__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__RxmRAWSV__Sequence__init(ublox_msgs__msg__RxmRAWSV__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWSV * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__RxmRAWSV *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__RxmRAWSV), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__RxmRAWSV__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__RxmRAWSV__fini(&data[i - 1]);
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
ublox_msgs__msg__RxmRAWSV__Sequence__fini(ublox_msgs__msg__RxmRAWSV__Sequence * array)
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
      ublox_msgs__msg__RxmRAWSV__fini(&array->data[i]);
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

ublox_msgs__msg__RxmRAWSV__Sequence *
ublox_msgs__msg__RxmRAWSV__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__RxmRAWSV__Sequence * array = (ublox_msgs__msg__RxmRAWSV__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__RxmRAWSV__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__RxmRAWSV__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__RxmRAWSV__Sequence__destroy(ublox_msgs__msg__RxmRAWSV__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__RxmRAWSV__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__RxmRAWSV__Sequence__are_equal(const ublox_msgs__msg__RxmRAWSV__Sequence * lhs, const ublox_msgs__msg__RxmRAWSV__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__RxmRAWSV__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__RxmRAWSV__Sequence__copy(
  const ublox_msgs__msg__RxmRAWSV__Sequence * input,
  ublox_msgs__msg__RxmRAWSV__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__RxmRAWSV);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__RxmRAWSV * data =
      (ublox_msgs__msg__RxmRAWSV *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__RxmRAWSV__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__RxmRAWSV__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__RxmRAWSV__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
