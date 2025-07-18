// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavRELPOSNED9.idl
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
#include "ublox_msgs/msg/detail/nav_relposned9__struct.h"
#include "ublox_msgs/msg/detail/nav_relposned9__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_relposned9__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
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
    assert(strncmp("ublox_msgs.msg._nav_relposned9.NavRELPOSNED9", full_classname_dest, 44) == 0);
  }
  ublox_msgs__msg__NavRELPOSNED9 * ros_message = _ros_message;
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
  {  // ref_station_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "ref_station_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ref_station_id = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_n
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_n");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_n = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_e
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_e");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_e = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_d");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_d = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_length = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_heading");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_heading = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // reserved2
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved2");
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
      Py_ssize_t size = 4;
      uint8_t * dest = ros_message->reserved2;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // rel_pos_hpn
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_hpn");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_hpn = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_hpe
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_hpe");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_hpe = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_hpd
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_hpd");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_hpd = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rel_pos_hp_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "rel_pos_hp_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rel_pos_hp_length = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // acc_n
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_n");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_n = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // acc_e
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_e");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_e = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // acc_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_d");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_d = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // acc_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_length = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // acc_heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc_heading");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->acc_heading = PyLong_AsUnsignedLong(field);
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
      Py_ssize_t size = 4;
      uint8_t * dest = ros_message->reserved3;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_relposned9__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavRELPOSNED9 */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_relposned9");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavRELPOSNED9");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavRELPOSNED9 * ros_message = (ublox_msgs__msg__NavRELPOSNED9 *)raw_ros_message;
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
  {  // ref_station_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ref_station_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ref_station_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
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
  {  // rel_pos_n
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_n);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_n", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_pos_e
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_e);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_e", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_pos_d
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_pos_length
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_pos_heading
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_heading", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved2
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved2");
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
    uint8_t * src = &(ros_message->reserved2[0]);
    memcpy(dst, src, 4 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // rel_pos_hpn
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_hpn);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_hpn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_pos_hpe
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_hpe);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_hpe", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_pos_hpd
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_hpd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_hpd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rel_pos_hp_length
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rel_pos_hp_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rel_pos_hp_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_n
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->acc_n);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_n", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_e
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->acc_e);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_e", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_d
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->acc_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_length
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->acc_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc_heading
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->acc_heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc_heading", field);
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
    memcpy(dst, src, 4 * sizeof(uint8_t));
    Py_DECREF(field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
