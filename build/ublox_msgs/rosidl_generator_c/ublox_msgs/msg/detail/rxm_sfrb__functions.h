// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ublox_msgs:msg/RxmSFRB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__FUNCTIONS_H_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ublox_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ublox_msgs/msg/detail/rxm_sfrb__struct.h"

/// Initialize msg/RxmSFRB message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ublox_msgs__msg__RxmSFRB
 * )) before or use
 * ublox_msgs__msg__RxmSFRB__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__RxmSFRB__init(ublox_msgs__msg__RxmSFRB * msg);

/// Finalize msg/RxmSFRB message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__RxmSFRB__fini(ublox_msgs__msg__RxmSFRB * msg);

/// Create msg/RxmSFRB message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ublox_msgs__msg__RxmSFRB__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__RxmSFRB *
ublox_msgs__msg__RxmSFRB__create();

/// Destroy msg/RxmSFRB message.
/**
 * It calls
 * ublox_msgs__msg__RxmSFRB__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__RxmSFRB__destroy(ublox_msgs__msg__RxmSFRB * msg);

/// Check for msg/RxmSFRB message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__RxmSFRB__are_equal(const ublox_msgs__msg__RxmSFRB * lhs, const ublox_msgs__msg__RxmSFRB * rhs);

/// Copy a msg/RxmSFRB message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__RxmSFRB__copy(
  const ublox_msgs__msg__RxmSFRB * input,
  ublox_msgs__msg__RxmSFRB * output);

/// Initialize array of msg/RxmSFRB messages.
/**
 * It allocates the memory for the number of elements and calls
 * ublox_msgs__msg__RxmSFRB__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__RxmSFRB__Sequence__init(ublox_msgs__msg__RxmSFRB__Sequence * array, size_t size);

/// Finalize array of msg/RxmSFRB messages.
/**
 * It calls
 * ublox_msgs__msg__RxmSFRB__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__RxmSFRB__Sequence__fini(ublox_msgs__msg__RxmSFRB__Sequence * array);

/// Create array of msg/RxmSFRB messages.
/**
 * It allocates the memory for the array and calls
 * ublox_msgs__msg__RxmSFRB__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__RxmSFRB__Sequence *
ublox_msgs__msg__RxmSFRB__Sequence__create(size_t size);

/// Destroy array of msg/RxmSFRB messages.
/**
 * It calls
 * ublox_msgs__msg__RxmSFRB__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__RxmSFRB__Sequence__destroy(ublox_msgs__msg__RxmSFRB__Sequence * array);

/// Check for msg/RxmSFRB message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__RxmSFRB__Sequence__are_equal(const ublox_msgs__msg__RxmSFRB__Sequence * lhs, const ublox_msgs__msg__RxmSFRB__Sequence * rhs);

/// Copy an array of msg/RxmSFRB messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__RxmSFRB__Sequence__copy(
  const ublox_msgs__msg__RxmSFRB__Sequence * input,
  ublox_msgs__msg__RxmSFRB__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__FUNCTIONS_H_
