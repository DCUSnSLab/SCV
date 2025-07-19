// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgPRT.idl
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
#include "ublox_msgs/msg/detail/cfg_prt__struct.h"
#include "ublox_msgs/msg/detail/cfg_prt__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_prt__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._cfg_prt.CfgPRT", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__CfgPRT * ros_message = _ros_message;
  {  // port_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "port_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->port_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved0
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved0");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reserved0 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // tx_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "tx_ready");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tx_ready = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // baud_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "baud_rate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->baud_rate = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // in_proto_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "in_proto_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->in_proto_mask = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // out_proto_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "out_proto_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->out_proto_mask = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved1
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reserved1 = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__cfg_prt__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgPRT */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_prt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgPRT");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgPRT * ros_message = (ublox_msgs__msg__CfgPRT *)raw_ros_message;
  {  // port_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->port_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "port_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved0
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->reserved0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reserved0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tx_ready
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->tx_ready);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tx_ready", field);
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
  {  // baud_rate
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->baud_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "baud_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // in_proto_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->in_proto_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "in_proto_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // out_proto_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->out_proto_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "out_proto_mask", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
