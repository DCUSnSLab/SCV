// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
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
#include "ublox_msgs/msg/detail/cfg_navx5__struct.h"
#include "ublox_msgs/msg/detail/cfg_navx5__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_navx5__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
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
    assert(strncmp("ublox_msgs.msg._cfg_navx5.CfgNAVX5", full_classname_dest, 34) == 0);
  }
  ublox_msgs__msg__CfgNAVX5 * ros_message = _ros_message;
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->version = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mask1
    PyObject * field = PyObject_GetAttrString(_pymsg, "mask1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mask1 = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mask2
    PyObject * field = PyObject_GetAttrString(_pymsg, "mask2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mask2 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved1
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved1");
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
      Py_ssize_t size = 2;
      uint8_t * dest = ros_message->reserved1;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // min_svs
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_svs");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min_svs = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // max_svs
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_svs");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_svs = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // min_cno
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_cno");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min_cno = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // ini_fix3d
    PyObject * field = PyObject_GetAttrString(_pymsg, "ini_fix3d");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ini_fix3d = (uint8_t)PyLong_AsUnsignedLong(field);
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
      Py_ssize_t size = 2;
      uint8_t * dest = ros_message->reserved3;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // ack_aiding
    PyObject * field = PyObject_GetAttrString(_pymsg, "ack_aiding");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ack_aiding = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // wkn_rollover
    PyObject * field = PyObject_GetAttrString(_pymsg, "wkn_rollover");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->wkn_rollover = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sig_atten_comp_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "sig_atten_comp_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sig_atten_comp_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved4
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved4");
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
      Py_ssize_t size = 5;
      uint8_t * dest = ros_message->reserved4;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // use_ppp
    PyObject * field = PyObject_GetAttrString(_pymsg, "use_ppp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->use_ppp = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // aop_cfg
    PyObject * field = PyObject_GetAttrString(_pymsg, "aop_cfg");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->aop_cfg = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved5
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved5");
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
      Py_ssize_t size = 2;
      uint8_t * dest = ros_message->reserved5;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // aop_orb_max_err
    PyObject * field = PyObject_GetAttrString(_pymsg, "aop_orb_max_err");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->aop_orb_max_err = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved6
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved6");
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
      Py_ssize_t size = 7;
      uint8_t * dest = ros_message->reserved6;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // use_adr
    PyObject * field = PyObject_GetAttrString(_pymsg, "use_adr");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->use_adr = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__cfg_navx5__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgNAVX5 */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_navx5");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgNAVX5");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgNAVX5 * ros_message = (ublox_msgs__msg__CfgNAVX5 *)raw_ros_message;
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
  {  // mask1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mask1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mask1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mask2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mask2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mask2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved1
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved1");
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
    uint8_t * src = &(ros_message->reserved1[0]);
    memcpy(dst, src, 2 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // min_svs
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->min_svs);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_svs", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_svs
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->max_svs);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_svs", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_cno
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->min_cno);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_cno", field);
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
  {  // ini_fix3d
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ini_fix3d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ini_fix3d", field);
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
    memcpy(dst, src, 2 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // ack_aiding
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ack_aiding);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ack_aiding", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wkn_rollover
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->wkn_rollover);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wkn_rollover", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sig_atten_comp_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sig_atten_comp_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sig_atten_comp_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved4
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved4");
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
    uint8_t * src = &(ros_message->reserved4[0]);
    memcpy(dst, src, 5 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // use_ppp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->use_ppp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "use_ppp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aop_cfg
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->aop_cfg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aop_cfg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved5
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved5");
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
    uint8_t * src = &(ros_message->reserved5[0]);
    memcpy(dst, src, 2 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // aop_orb_max_err
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->aop_orb_max_err);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aop_orb_max_err", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved6
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved6");
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
    uint8_t * src = &(ros_message->reserved6[0]);
    memcpy(dst, src, 7 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // use_adr
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->use_adr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "use_adr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
