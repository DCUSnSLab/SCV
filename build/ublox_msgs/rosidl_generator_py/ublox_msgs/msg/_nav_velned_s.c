// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavVELNED.idl
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
#include "ublox_msgs/msg/detail/nav_velned__struct.h"
#include "ublox_msgs/msg/detail/nav_velned__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_velned__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._nav_velned.NavVELNED", full_classname_dest, 36) == 0);
  }
  ublox_msgs__msg__NavVELNED * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vel_n
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_n");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vel_n = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // vel_e
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_e");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vel_e = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // vel_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_d");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vel_d = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->speed = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // g_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "g_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->g_speed = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->heading = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // s_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "s_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->s_acc = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // c_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "c_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->c_acc = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_velned__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavVELNED */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_velned");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavVELNED");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavVELNED * ros_message = (ublox_msgs__msg__NavVELNED *)raw_ros_message;
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
  {  // vel_n
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->vel_n);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_n", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_e
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->vel_e);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_e", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_d
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->vel_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // g_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->g_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "g_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // s_acc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->s_acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "s_acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // c_acc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->c_acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "c_acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
