// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
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
#include "ublox_msgs/msg/detail/nav_posecef__struct.h"
#include "ublox_msgs/msg/detail/nav_posecef__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_posecef__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
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
    assert(strncmp("ublox_msgs.msg._nav_posecef.NavPOSECEF", full_classname_dest, 38) == 0);
  }
  ublox_msgs__msg__NavPOSECEF * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ecef_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_z = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // p_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->p_acc = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_posecef__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavPOSECEF */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_posecef");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavPOSECEF");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavPOSECEF * ros_message = (ublox_msgs__msg__NavPOSECEF *)raw_ros_message;
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
  {  // ecef_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_z
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_acc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->p_acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
