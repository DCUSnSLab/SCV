// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavSBAS.idl
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
#include "ublox_msgs/msg/detail/nav_sbas__struct.h"
#include "ublox_msgs/msg/detail/nav_sbas__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "ublox_msgs/msg/detail/nav_sbassv__functions.h"
// end nested array functions include
bool ublox_msgs__msg__nav_sbassv__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * ublox_msgs__msg__nav_sbassv__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_sbas__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._nav_sbas.NavSBAS", full_classname_dest, 32) == 0);
  }
  ublox_msgs__msg__NavSBAS * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // geo
    PyObject * field = PyObject_GetAttrString(_pymsg, "geo");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->geo = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sys
    PyObject * field = PyObject_GetAttrString(_pymsg, "sys");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sys = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // service
    PyObject * field = PyObject_GetAttrString(_pymsg, "service");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->service = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cnt
    PyObject * field = PyObject_GetAttrString(_pymsg, "cnt");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cnt = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved0
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved0");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_UINT8);
      Py_ssize_t size = 3;
      uint8_t * dest = ros_message->reserved0;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
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
    if (!ublox_msgs__msg__NavSBASSV__Sequence__init(&(ros_message->sv), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create ublox_msgs__msg__NavSBASSV__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    ublox_msgs__msg__NavSBASSV * dest = ros_message->sv.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!ublox_msgs__msg__nav_sbassv__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
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
PyObject * ublox_msgs__msg__nav_sbas__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavSBAS */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_sbas");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavSBAS");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavSBAS * ros_message = (ublox_msgs__msg__NavSBAS *)raw_ros_message;
  {  // i_tow
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->i_tow);
    {
      int rc = PyObject_SetAttrString(_pymessage, "i_tow", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // geo
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->geo);
    {
      int rc = PyObject_SetAttrString(_pymessage, "geo", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sys
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->sys);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sys", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // service
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->service);
    {
      int rc = PyObject_SetAttrString(_pymessage, "service", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cnt
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cnt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cnt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved0
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved0");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_UINT8);
    assert(sizeof(npy_uint8) == sizeof(uint8_t));
    npy_uint8 * dst = (npy_uint8 *)PyArray_GETPTR1(seq_field, 0);
    uint8_t * src = &(ros_message->reserved0[0]);
    memcpy(dst, src, 3 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // sv
    PyObject * field = NULL;
    size_t size = ros_message->sv.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    ublox_msgs__msg__NavSBASSV * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->sv.data[i]);
      PyObject * pyitem = ublox_msgs__msg__nav_sbassv__convert_to_py(item);
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
