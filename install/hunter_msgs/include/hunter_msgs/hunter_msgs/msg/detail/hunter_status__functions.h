// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hunter_msgs:msg/HunterStatus.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__FUNCTIONS_H_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hunter_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "hunter_msgs/msg/detail/hunter_status__struct.h"

/// Initialize msg/HunterStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hunter_msgs__msg__HunterStatus
 * )) before or use
 * hunter_msgs__msg__HunterStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterStatus__init(hunter_msgs__msg__HunterStatus * msg);

/// Finalize msg/HunterStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterStatus__fini(hunter_msgs__msg__HunterStatus * msg);

/// Create msg/HunterStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hunter_msgs__msg__HunterStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
hunter_msgs__msg__HunterStatus *
hunter_msgs__msg__HunterStatus__create();

/// Destroy msg/HunterStatus message.
/**
 * It calls
 * hunter_msgs__msg__HunterStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterStatus__destroy(hunter_msgs__msg__HunterStatus * msg);

/// Check for msg/HunterStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterStatus__are_equal(const hunter_msgs__msg__HunterStatus * lhs, const hunter_msgs__msg__HunterStatus * rhs);

/// Copy a msg/HunterStatus message.
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
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterStatus__copy(
  const hunter_msgs__msg__HunterStatus * input,
  hunter_msgs__msg__HunterStatus * output);

/// Initialize array of msg/HunterStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * hunter_msgs__msg__HunterStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterStatus__Sequence__init(hunter_msgs__msg__HunterStatus__Sequence * array, size_t size);

/// Finalize array of msg/HunterStatus messages.
/**
 * It calls
 * hunter_msgs__msg__HunterStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterStatus__Sequence__fini(hunter_msgs__msg__HunterStatus__Sequence * array);

/// Create array of msg/HunterStatus messages.
/**
 * It allocates the memory for the array and calls
 * hunter_msgs__msg__HunterStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
hunter_msgs__msg__HunterStatus__Sequence *
hunter_msgs__msg__HunterStatus__Sequence__create(size_t size);

/// Destroy array of msg/HunterStatus messages.
/**
 * It calls
 * hunter_msgs__msg__HunterStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterStatus__Sequence__destroy(hunter_msgs__msg__HunterStatus__Sequence * array);

/// Check for msg/HunterStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterStatus__Sequence__are_equal(const hunter_msgs__msg__HunterStatus__Sequence * lhs, const hunter_msgs__msg__HunterStatus__Sequence * rhs);

/// Copy an array of msg/HunterStatus messages.
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
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterStatus__Sequence__copy(
  const hunter_msgs__msg__HunterStatus__Sequence * input,
  hunter_msgs__msg__HunterStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_STATUS__FUNCTIONS_H_
