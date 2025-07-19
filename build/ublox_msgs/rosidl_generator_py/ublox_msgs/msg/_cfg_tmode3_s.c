// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
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
#include "ublox_msgs/msg/detail/cfg_tmode3__struct.h"
#include "ublox_msgs/msg/detail/cfg_tmode3__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_tmode3__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._cfg_tmode3.CfgTMODE3", full_classname_dest, 36) == 0);
  }
  ublox_msgs__msg__CfgTMODE3 * ros_message = _ros_message;
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->version = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ecef_x_or_lat
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_x_or_lat");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_x_or_lat = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_y_or_lon
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_y_or_lon");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_y_or_lon = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_z_or_alt
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_z_or_alt");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_z_or_alt = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_x_or_lat_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_x_or_lat_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_x_or_lat_hp = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_y_or_lon_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_y_or_lon_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_y_or_lon_hp = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ecef_z_or_alt_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ecef_z_or_alt_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ecef_z_or_alt_hp = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // reserved2
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reserved2 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fixed_pos_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "fixed_pos_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fixed_pos_acc = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // svin_min_dur
    PyObject * field = PyObject_GetAttrString(_pymsg, "svin_min_dur");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->svin_min_dur = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // svin_acc_limit
    PyObject * field = PyObject_GetAttrString(_pymsg, "svin_acc_limit");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->svin_acc_limit = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved3
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved3");
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
      Py_ssize_t size = 8;
      uint8_t * dest = ros_message->reserved3;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__cfg_tmode3__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgTMODE3 */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_tmode3");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgTMODE3");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgTMODE3 * ros_message = (ublox_msgs__msg__CfgTMODE3 *)raw_ros_message;
  {  // version
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->version);
    {
      int rc = PyObject_SetAttrString(_pymessage, "version", field);
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
  {  // ecef_x_or_lat
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_x_or_lat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_x_or_lat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_y_or_lon
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_y_or_lon);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_y_or_lon", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_z_or_alt
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_z_or_alt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_z_or_alt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_x_or_lat_hp
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_x_or_lat_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_x_or_lat_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_y_or_lon_hp
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_y_or_lon_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_y_or_lon_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ecef_z_or_alt_hp
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ecef_z_or_alt_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ecef_z_or_alt_hp", field);
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
  {  // fixed_pos_acc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fixed_pos_acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fixed_pos_acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // svin_min_dur
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->svin_min_dur);
    {
      int rc = PyObject_SetAttrString(_pymessage, "svin_min_dur", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // svin_acc_limit
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->svin_acc_limit);
    {
      int rc = PyObject_SetAttrString(_pymessage, "svin_acc_limit", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved3
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved3");
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
    uint8_t * src = &(ros_message->reserved3[0]);
    memcpy(dst, src, 8 * sizeof(uint8_t));
    Py_DECREF(field);
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
