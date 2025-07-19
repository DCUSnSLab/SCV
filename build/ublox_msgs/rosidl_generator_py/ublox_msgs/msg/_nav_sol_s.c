// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavSOL.idl
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
#include "ublox_msgs/msg/detail/nav_sol__struct.h"
#include "ublox_msgs/msg/detail/nav_sol__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_sol__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[31];
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
    assert(strncmp("ublox_msgs.msg._nav_sol.NavSOL", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__NavSOL * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // f_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->f_tow = (int32_t)PyLong_AsLong(field);
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
  {  // gps_fix
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_fix");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gps_fix = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // ecef_vx
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_vx");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_vx = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_vy
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_vy");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_vy = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_vz
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_vz");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_vz = (int32_t)PyLong_AsLong(field);
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
  {  // p_dop
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_dop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->p_dop = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved1
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reserved1 = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // reserved2
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reserved2 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_sol__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavSOL */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_sol");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavSOL");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavSOL * ros_message = (ublox_msgs__msg__NavSOL *)raw_ros_message;
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
  {  // f_tow
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->f_tow);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_tow", field);
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
  {  // gps_fix
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gps_fix);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_fix", field);
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
  {  // ecef_vx
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_vx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_vx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_vy
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_vy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_vy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_vz
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_vz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_vz", field);
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
  {  // p_dop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->p_dop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_dop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->reserved1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reserved1", field);
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
  {  // reserved2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->reserved2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reserved2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
