# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavRELPOSNED9.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved2'
# Member 'reserved3'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavRELPOSNED9(type):
    """Metaclass of message 'NavRELPOSNED9'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 60,
        'FLAGS_GNSS_FIX_OK': 1,
        'FLAGS_DIFF_SOLN': 2,
        'FLAGS_REL_POS_VALID': 4,
        'FLAGS_CARR_SOLN_MASK': 24,
        'FLAGS_CARR_SOLN_NONE': 0,
        'FLAGS_CARR_SOLN_FLOAT': 8,
        'FLAGS_CARR_SOLN_FIXED': 16,
        'FLAGS_IS_MOVING': 32,
        'FLAGS_REF_POS_MISS': 64,
        'FLAGS_REF_OBS_MISS': 128,
        'FLAGS_REL_POS_HEAD_VALID': 256,
        'FLAGS_REL_POS_NORM': 512,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ublox_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ublox_msgs.msg.NavRELPOSNED9')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_relposned9
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_relposned9
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_relposned9
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_relposned9
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_relposned9

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FLAGS_GNSS_FIX_OK': cls.__constants['FLAGS_GNSS_FIX_OK'],
            'FLAGS_DIFF_SOLN': cls.__constants['FLAGS_DIFF_SOLN'],
            'FLAGS_REL_POS_VALID': cls.__constants['FLAGS_REL_POS_VALID'],
            'FLAGS_CARR_SOLN_MASK': cls.__constants['FLAGS_CARR_SOLN_MASK'],
            'FLAGS_CARR_SOLN_NONE': cls.__constants['FLAGS_CARR_SOLN_NONE'],
            'FLAGS_CARR_SOLN_FLOAT': cls.__constants['FLAGS_CARR_SOLN_FLOAT'],
            'FLAGS_CARR_SOLN_FIXED': cls.__constants['FLAGS_CARR_SOLN_FIXED'],
            'FLAGS_IS_MOVING': cls.__constants['FLAGS_IS_MOVING'],
            'FLAGS_REF_POS_MISS': cls.__constants['FLAGS_REF_POS_MISS'],
            'FLAGS_REF_OBS_MISS': cls.__constants['FLAGS_REF_OBS_MISS'],
            'FLAGS_REL_POS_HEAD_VALID': cls.__constants['FLAGS_REL_POS_HEAD_VALID'],
            'FLAGS_REL_POS_NORM': cls.__constants['FLAGS_REL_POS_NORM'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavRELPOSNED9.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavRELPOSNED9.__constants['MESSAGE_ID']

    @property
    def FLAGS_GNSS_FIX_OK(self):
        """Message constant 'FLAGS_GNSS_FIX_OK'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_GNSS_FIX_OK']

    @property
    def FLAGS_DIFF_SOLN(self):
        """Message constant 'FLAGS_DIFF_SOLN'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_DIFF_SOLN']

    @property
    def FLAGS_REL_POS_VALID(self):
        """Message constant 'FLAGS_REL_POS_VALID'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_REL_POS_VALID']

    @property
    def FLAGS_CARR_SOLN_MASK(self):
        """Message constant 'FLAGS_CARR_SOLN_MASK'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_CARR_SOLN_MASK']

    @property
    def FLAGS_CARR_SOLN_NONE(self):
        """Message constant 'FLAGS_CARR_SOLN_NONE'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_CARR_SOLN_NONE']

    @property
    def FLAGS_CARR_SOLN_FLOAT(self):
        """Message constant 'FLAGS_CARR_SOLN_FLOAT'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_CARR_SOLN_FLOAT']

    @property
    def FLAGS_CARR_SOLN_FIXED(self):
        """Message constant 'FLAGS_CARR_SOLN_FIXED'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_CARR_SOLN_FIXED']

    @property
    def FLAGS_IS_MOVING(self):
        """Message constant 'FLAGS_IS_MOVING'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_IS_MOVING']

    @property
    def FLAGS_REF_POS_MISS(self):
        """Message constant 'FLAGS_REF_POS_MISS'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_REF_POS_MISS']

    @property
    def FLAGS_REF_OBS_MISS(self):
        """Message constant 'FLAGS_REF_OBS_MISS'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_REF_OBS_MISS']

    @property
    def FLAGS_REL_POS_HEAD_VALID(self):
        """Message constant 'FLAGS_REL_POS_HEAD_VALID'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_REL_POS_HEAD_VALID']

    @property
    def FLAGS_REL_POS_NORM(self):
        """Message constant 'FLAGS_REL_POS_NORM'."""
        return Metaclass_NavRELPOSNED9.__constants['FLAGS_REL_POS_NORM']


class NavRELPOSNED9(metaclass=Metaclass_NavRELPOSNED9):
    """
    Message class 'NavRELPOSNED9'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FLAGS_GNSS_FIX_OK
      FLAGS_DIFF_SOLN
      FLAGS_REL_POS_VALID
      FLAGS_CARR_SOLN_MASK
      FLAGS_CARR_SOLN_NONE
      FLAGS_CARR_SOLN_FLOAT
      FLAGS_CARR_SOLN_FIXED
      FLAGS_IS_MOVING
      FLAGS_REF_POS_MISS
      FLAGS_REF_OBS_MISS
      FLAGS_REL_POS_HEAD_VALID
      FLAGS_REL_POS_NORM
    """

    __slots__ = [
        '_version',
        '_reserved1',
        '_ref_station_id',
        '_i_tow',
        '_rel_pos_n',
        '_rel_pos_e',
        '_rel_pos_d',
        '_rel_pos_length',
        '_rel_pos_heading',
        '_reserved2',
        '_rel_pos_hpn',
        '_rel_pos_hpe',
        '_rel_pos_hpd',
        '_rel_pos_hp_length',
        '_acc_n',
        '_acc_e',
        '_acc_d',
        '_acc_length',
        '_acc_heading',
        '_reserved3',
        '_flags',
    ]

    _fields_and_field_types = {
        'version': 'uint8',
        'reserved1': 'uint8',
        'ref_station_id': 'uint16',
        'i_tow': 'uint32',
        'rel_pos_n': 'int32',
        'rel_pos_e': 'int32',
        'rel_pos_d': 'int32',
        'rel_pos_length': 'int32',
        'rel_pos_heading': 'int32',
        'reserved2': 'uint8[4]',
        'rel_pos_hpn': 'int8',
        'rel_pos_hpe': 'int8',
        'rel_pos_hpd': 'int8',
        'rel_pos_hp_length': 'int8',
        'acc_n': 'uint32',
        'acc_e': 'uint32',
        'acc_d': 'uint32',
        'acc_length': 'uint32',
        'acc_heading': 'uint32',
        'reserved3': 'uint8[4]',
        'flags': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.version = kwargs.get('version', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.ref_station_id = kwargs.get('ref_station_id', int())
        self.i_tow = kwargs.get('i_tow', int())
        self.rel_pos_n = kwargs.get('rel_pos_n', int())
        self.rel_pos_e = kwargs.get('rel_pos_e', int())
        self.rel_pos_d = kwargs.get('rel_pos_d', int())
        self.rel_pos_length = kwargs.get('rel_pos_length', int())
        self.rel_pos_heading = kwargs.get('rel_pos_heading', int())
        if 'reserved2' not in kwargs:
            self.reserved2 = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.reserved2 = numpy.array(kwargs.get('reserved2'), dtype=numpy.uint8)
            assert self.reserved2.shape == (4, )
        self.rel_pos_hpn = kwargs.get('rel_pos_hpn', int())
        self.rel_pos_hpe = kwargs.get('rel_pos_hpe', int())
        self.rel_pos_hpd = kwargs.get('rel_pos_hpd', int())
        self.rel_pos_hp_length = kwargs.get('rel_pos_hp_length', int())
        self.acc_n = kwargs.get('acc_n', int())
        self.acc_e = kwargs.get('acc_e', int())
        self.acc_d = kwargs.get('acc_d', int())
        self.acc_length = kwargs.get('acc_length', int())
        self.acc_heading = kwargs.get('acc_heading', int())
        if 'reserved3' not in kwargs:
            self.reserved3 = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.reserved3 = numpy.array(kwargs.get('reserved3'), dtype=numpy.uint8)
            assert self.reserved3.shape == (4, )
        self.flags = kwargs.get('flags', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.version != other.version:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.ref_station_id != other.ref_station_id:
            return False
        if self.i_tow != other.i_tow:
            return False
        if self.rel_pos_n != other.rel_pos_n:
            return False
        if self.rel_pos_e != other.rel_pos_e:
            return False
        if self.rel_pos_d != other.rel_pos_d:
            return False
        if self.rel_pos_length != other.rel_pos_length:
            return False
        if self.rel_pos_heading != other.rel_pos_heading:
            return False
        if all(self.reserved2 != other.reserved2):
            return False
        if self.rel_pos_hpn != other.rel_pos_hpn:
            return False
        if self.rel_pos_hpe != other.rel_pos_hpe:
            return False
        if self.rel_pos_hpd != other.rel_pos_hpd:
            return False
        if self.rel_pos_hp_length != other.rel_pos_hp_length:
            return False
        if self.acc_n != other.acc_n:
            return False
        if self.acc_e != other.acc_e:
            return False
        if self.acc_d != other.acc_d:
            return False
        if self.acc_length != other.acc_length:
            return False
        if self.acc_heading != other.acc_heading:
            return False
        if all(self.reserved3 != other.reserved3):
            return False
        if self.flags != other.flags:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'version' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'version' field must be an unsigned integer in [0, 255]"
        self._version = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved1' field must be an unsigned integer in [0, 255]"
        self._reserved1 = value

    @builtins.property
    def ref_station_id(self):
        """Message field 'ref_station_id'."""
        return self._ref_station_id

    @ref_station_id.setter
    def ref_station_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ref_station_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ref_station_id' field must be an unsigned integer in [0, 65535]"
        self._ref_station_id = value

    @builtins.property
    def i_tow(self):
        """Message field 'i_tow'."""
        return self._i_tow

    @i_tow.setter
    def i_tow(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'i_tow' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'i_tow' field must be an unsigned integer in [0, 4294967295]"
        self._i_tow = value

    @builtins.property
    def rel_pos_n(self):
        """Message field 'rel_pos_n'."""
        return self._rel_pos_n

    @rel_pos_n.setter
    def rel_pos_n(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_n' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rel_pos_n' field must be an integer in [-2147483648, 2147483647]"
        self._rel_pos_n = value

    @builtins.property
    def rel_pos_e(self):
        """Message field 'rel_pos_e'."""
        return self._rel_pos_e

    @rel_pos_e.setter
    def rel_pos_e(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_e' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rel_pos_e' field must be an integer in [-2147483648, 2147483647]"
        self._rel_pos_e = value

    @builtins.property
    def rel_pos_d(self):
        """Message field 'rel_pos_d'."""
        return self._rel_pos_d

    @rel_pos_d.setter
    def rel_pos_d(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_d' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rel_pos_d' field must be an integer in [-2147483648, 2147483647]"
        self._rel_pos_d = value

    @builtins.property
    def rel_pos_length(self):
        """Message field 'rel_pos_length'."""
        return self._rel_pos_length

    @rel_pos_length.setter
    def rel_pos_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_length' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rel_pos_length' field must be an integer in [-2147483648, 2147483647]"
        self._rel_pos_length = value

    @builtins.property
    def rel_pos_heading(self):
        """Message field 'rel_pos_heading'."""
        return self._rel_pos_heading

    @rel_pos_heading.setter
    def rel_pos_heading(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_heading' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rel_pos_heading' field must be an integer in [-2147483648, 2147483647]"
        self._rel_pos_heading = value

    @builtins.property
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved2' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'reserved2' numpy.ndarray() must have a size of 4"
            self._reserved2 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved2' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved2 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def rel_pos_hpn(self):
        """Message field 'rel_pos_hpn'."""
        return self._rel_pos_hpn

    @rel_pos_hpn.setter
    def rel_pos_hpn(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_hpn' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'rel_pos_hpn' field must be an integer in [-128, 127]"
        self._rel_pos_hpn = value

    @builtins.property
    def rel_pos_hpe(self):
        """Message field 'rel_pos_hpe'."""
        return self._rel_pos_hpe

    @rel_pos_hpe.setter
    def rel_pos_hpe(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_hpe' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'rel_pos_hpe' field must be an integer in [-128, 127]"
        self._rel_pos_hpe = value

    @builtins.property
    def rel_pos_hpd(self):
        """Message field 'rel_pos_hpd'."""
        return self._rel_pos_hpd

    @rel_pos_hpd.setter
    def rel_pos_hpd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_hpd' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'rel_pos_hpd' field must be an integer in [-128, 127]"
        self._rel_pos_hpd = value

    @builtins.property
    def rel_pos_hp_length(self):
        """Message field 'rel_pos_hp_length'."""
        return self._rel_pos_hp_length

    @rel_pos_hp_length.setter
    def rel_pos_hp_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rel_pos_hp_length' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'rel_pos_hp_length' field must be an integer in [-128, 127]"
        self._rel_pos_hp_length = value

    @builtins.property
    def acc_n(self):
        """Message field 'acc_n'."""
        return self._acc_n

    @acc_n.setter
    def acc_n(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_n' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_n' field must be an unsigned integer in [0, 4294967295]"
        self._acc_n = value

    @builtins.property
    def acc_e(self):
        """Message field 'acc_e'."""
        return self._acc_e

    @acc_e.setter
    def acc_e(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_e' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_e' field must be an unsigned integer in [0, 4294967295]"
        self._acc_e = value

    @builtins.property
    def acc_d(self):
        """Message field 'acc_d'."""
        return self._acc_d

    @acc_d.setter
    def acc_d(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_d' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_d' field must be an unsigned integer in [0, 4294967295]"
        self._acc_d = value

    @builtins.property
    def acc_length(self):
        """Message field 'acc_length'."""
        return self._acc_length

    @acc_length.setter
    def acc_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_length' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_length' field must be an unsigned integer in [0, 4294967295]"
        self._acc_length = value

    @builtins.property
    def acc_heading(self):
        """Message field 'acc_heading'."""
        return self._acc_heading

    @acc_heading.setter
    def acc_heading(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_heading' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_heading' field must be an unsigned integer in [0, 4294967295]"
        self._acc_heading = value

    @builtins.property
    def reserved3(self):
        """Message field 'reserved3'."""
        return self._reserved3

    @reserved3.setter
    def reserved3(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved3' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'reserved3' numpy.ndarray() must have a size of 4"
            self._reserved3 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved3' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved3 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def flags(self):
        """Message field 'flags'."""
        return self._flags

    @flags.setter
    def flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flags' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'flags' field must be an unsigned integer in [0, 4294967295]"
        self._flags = value
