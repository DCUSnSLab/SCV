// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavDGPSSV.idl
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
#include "ublox_msgs/msg/detail/nav_dgpssv__struct.h"
#include "ublox_msgs/msg/detail/nav_dgpssv__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_dgpssv__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("ublox_msgs.msg._nav_dgpssv.NavDGPSSV", full_classname_dest, 36) == 0);
  }
  ublox_msgs__msg__NavDGPSSV * ros_message = _ros_message;
  {  // svid
    PyObject * field = PyObject_GetAttrString(_pymsg, "svid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->svid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // age_c
    PyObject * field = PyObject_GetAttrString(_pymsg, "age_c");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->age_c = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // prc
    PyObject * field = PyObject_GetAttrString(_pymsg, "prc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->prc = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // prrc
    PyObject * field = PyObject_GetAttrString(_pymsg, "prrc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->prrc = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_dgpssv__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavDGPSSV */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_dgpssv");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavDGPSSV");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavDGPSSV * ros_message = (ublox_msgs__msg__NavDGPSSV *)raw_ros_message;
  {  // svid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->svid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "svid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flags
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // age_c
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->age_c);
    {
      int rc = PyObject_SetAttrString(_pymessage, "age_c", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // prc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->prc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "prc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // prrc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->prrc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "prrc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
