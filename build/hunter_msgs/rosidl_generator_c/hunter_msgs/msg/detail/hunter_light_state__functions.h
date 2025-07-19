// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hunter_msgs:msg/HunterLightState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__FUNCTIONS_H_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hunter_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "hunter_msgs/msg/detail/hunter_light_state__struct.h"

/// Initialize msg/HunterLightState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hunter_msgs__msg__HunterLightState
 * )) before or use
 * hunter_msgs__msg__HunterLightState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterLightState__init(hunter_msgs__msg__HunterLightState * msg);

/// Finalize msg/HunterLightState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterLightState__fini(hunter_msgs__msg__HunterLightState * msg);

/// Create msg/HunterLightState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hunter_msgs__msg__HunterLightState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
hunter_msgs__msg__HunterLightState *
hunter_msgs__msg__HunterLightState__create();

/// Destroy msg/HunterLightState message.
/**
 * It calls
 * hunter_msgs__msg__HunterLightState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterLightState__destroy(hunter_msgs__msg__HunterLightState * msg);

/// Check for msg/HunterLightState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterLightState__are_equal(const hunter_msgs__msg__HunterLightState * lhs, const hunter_msgs__msg__HunterLightState * rhs);

/// Copy a msg/HunterLightState message.
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
hunter_msgs__msg__HunterLightState__copy(
  const hunter_msgs__msg__HunterLightState * input,
  hunter_msgs__msg__HunterLightState * output);

/// Initialize array of msg/HunterLightState messages.
/**
 * It allocates the memory for the number of elements and calls
 * hunter_msgs__msg__HunterLightState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterLightState__Sequence__init(hunter_msgs__msg__HunterLightState__Sequence * array, size_t size);

/// Finalize array of msg/HunterLightState messages.
/**
 * It calls
 * hunter_msgs__msg__HunterLightState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterLightState__Sequence__fini(hunter_msgs__msg__HunterLightState__Sequence * array);

/// Create array of msg/HunterLightState messages.
/**
 * It allocates the memory for the array and calls
 * hunter_msgs__msg__HunterLightState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
hunter_msgs__msg__HunterLightState__Sequence *
hunter_msgs__msg__HunterLightState__Sequence__create(size_t size);

/// Destroy array of msg/HunterLightState messages.
/**
 * It calls
 * hunter_msgs__msg__HunterLightState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
void
hunter_msgs__msg__HunterLightState__Sequence__destroy(hunter_msgs__msg__HunterLightState__Sequence * array);

/// Check for msg/HunterLightState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hunter_msgs
bool
hunter_msgs__msg__HunterLightState__Sequence__are_equal(const hunter_msgs__msg__HunterLightState__Sequence * lhs, const hunter_msgs__msg__HunterLightState__Sequence * rhs);

/// Copy an array of msg/HunterLightState messages.
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
hunter_msgs__msg__HunterLightState__Sequence__copy(
  const hunter_msgs__msg__HunterLightState__Sequence * input,
  hunter_msgs__msg__HunterLightState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_LIGHT_STATE__FUNCTIONS_H_
