// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/MgaGAL.idl
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
#include "ublox_msgs/msg/detail/mga_gal__struct.h"
#include "ublox_msgs/msg/detail/mga_gal__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__mga_gal__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._mga_gal.MgaGAL", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__MgaGAL * ros_message = _ros_message;
  {  // type
    PyObject * field = PyObject_GetAttrString(_pymsg, "type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->version = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // svid
    PyObject * field = PyObject_GetAttrString(_pymsg, "svid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->svid = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // iod_nav
    PyObject * field = PyObject_GetAttrString(_pymsg, "iod_nav");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->iod_nav = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // delta_n
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_n");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->delta_n = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // m0
    PyObject * field = PyObject_GetAttrString(_pymsg, "m0");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m0 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // e
    PyObject * field = PyObject_GetAttrString(_pymsg, "e");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->e = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sqrt_a
    PyObject * field = PyObject_GetAttrString(_pymsg, "sqrt_a");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sqrt_a = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // omega0
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega0");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->omega0 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // i0
    PyObject * field = PyObject_GetAttrString(_pymsg, "i0");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i0 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // omega
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->omega = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // omega_dot
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega_dot");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->omega_dot = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // i_dot
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_dot");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_dot = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // cuc
    PyObject * field = PyObject_GetAttrString(_pymsg, "cuc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cuc = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // cus
    PyObject * field = PyObject_GetAttrString(_pymsg, "cus");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cus = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // crc
    PyObject * field = PyObject_GetAttrString(_pymsg, "crc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->crc = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // crs
    PyObject * field = PyObject_GetAttrString(_pymsg, "crs");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->crs = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // cic
    PyObject * field = PyObject_GetAttrString(_pymsg, "cic");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cic = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // cis
    PyObject * field = PyObject_GetAttrString(_pymsg, "cis");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cis = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // toe
    PyObject * field = PyObject_GetAttrString(_pymsg, "toe");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->toe = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // af0
    PyObject * field = PyObject_GetAttrString(_pymsg, "af0");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->af0 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // af1
    PyObject * field = PyObject_GetAttrString(_pymsg, "af1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->af1 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // af2
    PyObject * field = PyObject_GetAttrString(_pymsg, "af2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->af2 = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // sisaindex_e1_e5b
    PyObject * field = PyObject_GetAttrString(_pymsg, "sisaindex_e1_e5b");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sisaindex_e1_e5b = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // toc
    PyObject * field = PyObject_GetAttrString(_pymsg, "toc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->toc = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // bgd_e1_e5b
    PyObject * field = PyObject_GetAttrString(_pymsg, "bgd_e1_e5b");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->bgd_e1_e5b = (int16_t)PyLong_AsLong(field);
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
  {  // health_e1b
    PyObject * field = PyObject_GetAttrString(_pymsg, "health_e1b");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->health_e1b = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // data_validity_e1b
    PyObject * field = PyObject_GetAttrString(_pymsg, "data_validity_e1b");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->data_validity_e1b = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // health_e5b
    PyObject * field = PyObject_GetAttrString(_pymsg, "health_e5b");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->health_e5b = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // data_validity_e5b
    PyObject * field = PyObject_GetAttrString(_pymsg, "data_validity_e5b");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->data_validity_e5b = (uint8_t)PyLong_AsUnsignedLong(field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__mga_gal__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MgaGAL */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._mga_gal");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MgaGAL");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__MgaGAL * ros_message = (ublox_msgs__msg__MgaGAL *)raw_ros_message;
  {  // type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
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
  {  // iod_nav
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->iod_nav);
    {
      int rc = PyObject_SetAttrString(_pymessage, "iod_nav", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_n
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->delta_n);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_n", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m0
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->m0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // e
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->e);
    {
      int rc = PyObject_SetAttrString(_pymessage, "e", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sqrt_a
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sqrt_a);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sqrt_a", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // omega0
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->omega0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // i0
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->i0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "i0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // omega
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->omega);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // omega_dot
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->omega_dot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega_dot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // i_dot
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->i_dot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "i_dot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cuc
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->cuc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cuc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cus
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->cus);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cus", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // crc
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->crc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "crc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // crs
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->crs);
    {
      int rc = PyObject_SetAttrString(_pymessage, "crs", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cic
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->cic);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cis
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->cis);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cis", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toe
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->toe);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toe", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // af0
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->af0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "af0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // af1
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->af1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "af1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // af2
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->af2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "af2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sisaindex_e1_e5b
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sisaindex_e1_e5b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sisaindex_e1_e5b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // toc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->toc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "toc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bgd_e1_e5b
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->bgd_e1_e5b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bgd_e1_e5b", field);
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
  {  // health_e1b
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->health_e1b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "health_e1b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // data_validity_e1b
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->data_validity_e1b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "data_validity_e1b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // health_e5b
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->health_e5b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "health_e5b", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // data_validity_e5b
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->data_validity_e5b);
    {
      int rc = PyObject_SetAttrString(_pymessage, "data_validity_e5b", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
