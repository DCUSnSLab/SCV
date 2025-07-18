// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ublox_msgs:msg/EsfINS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_INS__FUNCTIONS_H_
#define UBLOX_MSGS__MSG__DETAIL__ESF_INS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ublox_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ublox_msgs/msg/detail/esf_ins__struct.h"

/// Initialize msg/EsfINS message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ublox_msgs__msg__EsfINS
 * )) before or use
 * ublox_msgs__msg__EsfINS__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__EsfINS__init(ublox_msgs__msg__EsfINS * msg);

/// Finalize msg/EsfINS message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__EsfINS__fini(ublox_msgs__msg__EsfINS * msg);

/// Create msg/EsfINS message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ublox_msgs__msg__EsfINS__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__EsfINS *
ublox_msgs__msg__EsfINS__create();

/// Destroy msg/EsfINS message.
/**
 * It calls
 * ublox_msgs__msg__EsfINS__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__EsfINS__destroy(ublox_msgs__msg__EsfINS * msg);

/// Check for msg/EsfINS message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__EsfINS__are_equal(const ublox_msgs__msg__EsfINS * lhs, const ublox_msgs__msg__EsfINS * rhs);

/// Copy a msg/EsfINS message.
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
ublox_msgs__msg__EsfINS__copy(
  const ublox_msgs__msg__EsfINS * input,
  ublox_msgs__msg__EsfINS * output);

/// Initialize array of msg/EsfINS messages.
/**
 * It allocates the memory for the number of elements and calls
 * ublox_msgs__msg__EsfINS__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__EsfINS__Sequence__init(ublox_msgs__msg__EsfINS__Sequence * array, size_t size);

/// Finalize array of msg/EsfINS messages.
/**
 * It calls
 * ublox_msgs__msg__EsfINS__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__EsfINS__Sequence__fini(ublox_msgs__msg__EsfINS__Sequence * array);

/// Create array of msg/EsfINS messages.
/**
 * It allocates the memory for the array and calls
 * ublox_msgs__msg__EsfINS__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__EsfINS__Sequence *
ublox_msgs__msg__EsfINS__Sequence__create(size_t size);

/// Destroy array of msg/EsfINS messages.
/**
 * It calls
 * ublox_msgs__msg__EsfINS__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__EsfINS__Sequence__destroy(ublox_msgs__msg__EsfINS__Sequence * array);

/// Check for msg/EsfINS message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__EsfINS__Sequence__are_equal(const ublox_msgs__msg__EsfINS__Sequence * lhs, const ublox_msgs__msg__EsfINS__Sequence * rhs);

/// Copy an array of msg/EsfINS messages.
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
ublox_msgs__msg__EsfINS__Sequence__copy(
  const ublox_msgs__msg__EsfINS__Sequence * input,
  ublox_msgs__msg__EsfINS__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_INS__FUNCTIONS_H_
