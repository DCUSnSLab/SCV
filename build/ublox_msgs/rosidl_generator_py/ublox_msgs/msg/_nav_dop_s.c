// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavDOP.idl
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
#include "ublox_msgs/msg/detail/nav_dop__struct.h"
#include "ublox_msgs/msg/detail/nav_dop__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_dop__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._nav_dop.NavDOP", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__NavDOP * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // g_dop
    PyObject * field = PyObject_GetAttrString(_pymsg, "g_dop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->g_dop = (uint16_t)PyLong_AsUnsignedLong(field);
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
  {  // t_dop
    PyObject * field = PyObject_GetAttrString(_pymsg, "t_dop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->t_dop = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // v_dop
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_dop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->v_dop = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // h_dop
    PyObject * field = PyObject_GetAttrString(_pymsg, "h_dop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->h_dop = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // n_dop
    PyObject * field = PyObject_GetAttrString(_pymsg, "n_dop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->n_dop = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // e_dop
    PyObject * field = PyObject_GetAttrString(_pymsg, "e_dop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->e_dop = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_dop__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavDOP */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_dop");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavDOP");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavDOP * ros_message = (ublox_msgs__msg__NavDOP *)raw_ros_message;
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
  {  // g_dop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->g_dop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "g_dop", field);
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
  {  // t_dop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->t_dop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "t_dop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_dop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->v_dop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_dop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // h_dop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->h_dop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "h_dop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // n_dop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->n_dop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "n_dop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // e_dop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->e_dop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "e_dop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
