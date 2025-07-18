// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgGNSS.idl
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
#include "ublox_msgs/msg/detail/cfg_gnss__struct.h"
#include "ublox_msgs/msg/detail/cfg_gnss__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "ublox_msgs/msg/detail/cfg_gnss_block__functions.h"
// end nested array functions include
bool ublox_msgs__msg__cfg_gnss_block__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * ublox_msgs__msg__cfg_gnss_block__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_gnss__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._cfg_gnss.CfgGNSS", full_classname_dest, 32) == 0);
  }
  ublox_msgs__msg__CfgGNSS * ros_message = _ros_message;
  {  // msg_ver
    PyObject * field = PyObject_GetAttrString(_pymsg, "msg_ver");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->msg_ver = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // num_trk_ch_hw
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_trk_ch_hw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_trk_ch_hw = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // num_trk_ch_use
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_trk_ch_use");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_trk_ch_use = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // num_config_blocks
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_config_blocks");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_config_blocks = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blocks
    PyObject * field = PyObject_GetAttrString(_pymsg, "blocks");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'blocks'");
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
    if (!ublox_msgs__msg__CfgGNSSBlock__Sequence__init(&(ros_message->blocks), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create ublox_msgs__msg__CfgGNSSBlock__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    ublox_msgs__msg__CfgGNSSBlock * dest = ros_message->blocks.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!ublox_msgs__msg__cfg_gnss_block__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
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
PyObject * ublox_msgs__msg__cfg_gnss__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgGNSS */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_gnss");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgGNSS");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgGNSS * ros_message = (ublox_msgs__msg__CfgGNSS *)raw_ros_message;
  {  // msg_ver
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->msg_ver);
    {
      int rc = PyObject_SetAttrString(_pymessage, "msg_ver", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_trk_ch_hw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_trk_ch_hw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_trk_ch_hw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_trk_ch_use
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_trk_ch_use);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_trk_ch_use", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_config_blocks
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num_config_blocks);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_config_blocks", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blocks
    PyObject * field = NULL;
    size_t size = ros_message->blocks.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    ublox_msgs__msg__CfgGNSSBlock * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->blocks.data[i]);
      PyObject * pyitem = ublox_msgs__msg__cfg_gnss_block__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "blocks", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
