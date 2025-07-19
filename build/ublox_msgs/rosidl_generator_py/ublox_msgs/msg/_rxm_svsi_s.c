// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/RxmSVSI.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ublox_msgs/msg/detail/rxm_svsi__struct.h"
#include "ublox_msgs/msg/detail/rxm_svsi__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "ublox_msgs/msg/detail/rxm_svsisv__functions.h"
// end nested array functions include
bool ublox_msgs__msg__rxm_svsisv__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * ublox_msgs__msg__rxm_svsisv__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__rxm_svsi__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ublox_msgs.msg._rxm_svsi.RxmSVSI", full_classname_dest, 32) == 0);
  }
  ublox_msgs__msg__RxmSVSI * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // week
    PyObject * field = PyObject_GetAttrString(_pymsg, "week");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->week = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // num_vis
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_vis");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_vis = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // num_sv
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_sv");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_sv = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sv
    PyObject * field = PyObject_GetAttrString(_pymsg, "sv");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'sv'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!ublox_msgs__msg__RxmSVSISV__Sequence__init(&(ros_message->sv), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create ublox_msgs__msg__RxmSVSISV__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    ublox_msgs__msg__RxmSVSISV * dest = ros_message->sv.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!ublox_msgs__msg__rxm_svsisv__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__rxm_svsi__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RxmSVSI */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._rxm_svsi");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RxmSVSI");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__RxmSVSI * ros_message = (ublox_msgs__msg__RxmSVSI *)raw_ros_message;
  {  // i_tow
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->i_tow);
    {
      int rc = PyObject_SetAttrString(_pymessage, "i_tow", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // week
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->week);
    {
      int rc = PyObject_SetAttrString(_pymessage, "week", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_vis
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_vis);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_vis", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_sv
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_sv);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_sv", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sv
    PyObject * field = NULL;
    size_t size = ros_message->sv.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    ublox_msgs__msg__RxmSVSISV * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->sv.data[i]);
      PyObject * pyitem = ublox_msgs__msg__rxm_svsisv__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "sv", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
