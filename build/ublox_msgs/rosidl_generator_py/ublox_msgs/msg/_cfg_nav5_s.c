// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgNAV5.idl
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
#include "ublox_msgs/msg/detail/cfg_nav5__struct.h"
#include "ublox_msgs/msg/detail/cfg_nav5__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_nav5__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._cfg_nav5.CfgNAV5", full_classname_dest, 32) == 0);
  }
  ublox_msgs__msg__CfgNAV5 * ros_message = _ros_message;
  {  // mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mask = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dyn_model
    PyObject * field = PyObject_GetAttrString(_pymsg, "dyn_model");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dyn_model = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fix_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "fix_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fix_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fixed_alt
    PyObject * field = PyObject_GetAttrString(_pymsg, "fixed_alt");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fixed_alt = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // fixed_alt_var
    PyObject * field = PyObject_GetAttrString(_pymsg, "fixed_alt_var");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fixed_alt_var = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // min_elev
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_elev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min_elev = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // dr_limit
    PyObject * field = PyObject_GetAttrString(_pymsg, "dr_limit");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dr_limit = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // p_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->p_acc = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // t_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "t_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->t_acc = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // static_hold_thresh
    PyObject * field = PyObject_GetAttrString(_pymsg, "static_hold_thresh");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->static_hold_thresh = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dgnss_time_out
    PyObject * field = PyObject_GetAttrString(_pymsg, "dgnss_time_out");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dgnss_time_out = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cno_thresh_num_svs
    PyObject * field = PyObject_GetAttrString(_pymsg, "cno_thresh_num_svs");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cno_thresh_num_svs = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cno_thresh
    PyObject * field = PyObject_GetAttrString(_pymsg, "cno_thresh");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cno_thresh = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // static_hold_max_dist
    PyObject * field = PyObject_GetAttrString(_pymsg, "static_hold_max_dist");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->static_hold_max_dist = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_standard
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_standard");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_standard = (uint8_t)PyLong_AsUnsignedLong(field);
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
      Py_ssize_t size = 5;
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
PyObject * ublox_msgs__msg__cfg_nav5__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgNAV5 */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_nav5");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgNAV5");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgNAV5 * ros_message = (ublox_msgs__msg__CfgNAV5 *)raw_ros_message;
  {  // mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dyn_model
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dyn_model);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dyn_model", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fix_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fix_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fix_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fixed_alt
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->fixed_alt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fixed_alt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fixed_alt_var
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fixed_alt_var);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fixed_alt_var", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_elev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->min_elev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_elev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dr_limit
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dr_limit);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dr_limit", field);
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
  {  // t_acc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->t_acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "t_acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // static_hold_thresh
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->static_hold_thresh);
    {
      int rc = PyObject_SetAttrString(_pymessage, "static_hold_thresh", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dgnss_time_out
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dgnss_time_out);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dgnss_time_out", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cno_thresh_num_svs
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cno_thresh_num_svs);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cno_thresh_num_svs", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cno_thresh
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cno_thresh);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cno_thresh", field);
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
  {  // static_hold_max_dist
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->static_hold_max_dist);
    {
      int rc = PyObject_SetAttrString(_pymessage, "static_hold_max_dist", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_standard
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_standard);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_standard", field);
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
    memcpy(dst, src, 5 * sizeof(uint8_t));
    Py_DECREF(field);
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
