# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/EsfINS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EsfINS(type):
    """Metaclass of message 'EsfINS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 16,
        'MESSAGE_ID': 21,
        'BITFIELD0_VERSION': 255,
        'BITFIELD0_X_ANG_RATE_VALID': 256,
        'BITFIELD0_Y_ANG_RATE_VALID': 512,
        'BITFIELD0_Z_ANG_RATE_VALID': 1024,
        'BITFIELD0_X_ACCEL_VALID': 2048,
        'BITFIELD0_Y_ACCEL_VALID': 4096,
        'BITFIELD0_Z_ACCEL_VALID': 8192,
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
                'ublox_msgs.msg.EsfINS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__esf_ins
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__esf_ins
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__esf_ins
            cls._TYPE_SUPPORT = module.type_support_msg__msg__esf_ins
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__esf_ins

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'BITFIELD0_VERSION': cls.__constants['BITFIELD0_VERSION'],
            'BITFIELD0_X_ANG_RATE_VALID': cls.__constants['BITFIELD0_X_ANG_RATE_VALID'],
            'BITFIELD0_Y_ANG_RATE_VALID': cls.__constants['BITFIELD0_Y_ANG_RATE_VALID'],
            'BITFIELD0_Z_ANG_RATE_VALID': cls.__constants['BITFIELD0_Z_ANG_RATE_VALID'],
            'BITFIELD0_X_ACCEL_VALID': cls.__constants['BITFIELD0_X_ACCEL_VALID'],
            'BITFIELD0_Y_ACCEL_VALID': cls.__constants['BITFIELD0_Y_ACCEL_VALID'],
            'BITFIELD0_Z_ACCEL_VALID': cls.__constants['BITFIELD0_Z_ACCEL_VALID'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_EsfINS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_EsfINS.__constants['MESSAGE_ID']

    @property
    def BITFIELD0_VERSION(self):
        """Message constant 'BITFIELD0_VERSION'."""
        return Metaclass_EsfINS.__constants['BITFIELD0_VERSION']

    @property
    def BITFIELD0_X_ANG_RATE_VALID(self):
        """Message constant 'BITFIELD0_X_ANG_RATE_VALID'."""
        return Metaclass_EsfINS.__constants['BITFIELD0_X_ANG_RATE_VALID']

    @property
    def BITFIELD0_Y_ANG_RATE_VALID(self):
        """Message constant 'BITFIELD0_Y_ANG_RATE_VALID'."""
        return Metaclass_EsfINS.__constants['BITFIELD0_Y_ANG_RATE_VALID']

    @property
    def BITFIELD0_Z_ANG_RATE_VALID(self):
        """Message constant 'BITFIELD0_Z_ANG_RATE_VALID'."""
        return Metaclass_EsfINS.__constants['BITFIELD0_Z_ANG_RATE_VALID']

    @property
    def BITFIELD0_X_ACCEL_VALID(self):
        """Message constant 'BITFIELD0_X_ACCEL_VALID'."""
        return Metaclass_EsfINS.__constants['BITFIELD0_X_ACCEL_VALID']

    @property
    def BITFIELD0_Y_ACCEL_VALID(self):
        """Message constant 'BITFIELD0_Y_ACCEL_VALID'."""
        return Metaclass_EsfINS.__constants['BITFIELD0_Y_ACCEL_VALID']

    @property
    def BITFIELD0_Z_ACCEL_VALID(self):
        """Message constant 'BITFIELD0_Z_ACCEL_VALID'."""
        return Metaclass_EsfINS.__constants['BITFIELD0_Z_ACCEL_VALID']


class EsfINS(metaclass=Metaclass_EsfINS):
    """
    Message class 'EsfINS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      BITFIELD0_VERSION
      BITFIELD0_X_ANG_RATE_VALID
      BITFIELD0_Y_ANG_RATE_VALID
      BITFIELD0_Z_ANG_RATE_VALID
      BITFIELD0_X_ACCEL_VALID
      BITFIELD0_Y_ACCEL_VALID
      BITFIELD0_Z_ACCEL_VALID
    """

    __slots__ = [
        '_bitfield0',
        '_reserved1',
        '_i_tow',
        '_x_ang_rate',
        '_y_ang_rate',
        '_z_ang_rate',
        '_x_accel',
        '_y_accel',
        '_z_accel',
    ]

    _fields_and_field_types = {
        'bitfield0': 'uint32',
        'reserved1': 'uint8[4]',
        'i_tow': 'uint32',
        'x_ang_rate': 'int32',
        'y_ang_rate': 'int32',
        'z_ang_rate': 'int32',
        'x_accel': 'int32',
        'y_accel': 'int32',
        'z_accel': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.bitfield0 = kwargs.get('bitfield0', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (4, )
        self.i_tow = kwargs.get('i_tow', int())
        self.x_ang_rate = kwargs.get('x_ang_rate', int())
        self.y_ang_rate = kwargs.get('y_ang_rate', int())
        self.z_ang_rate = kwargs.get('z_ang_rate', int())
        self.x_accel = kwargs.get('x_accel', int())
        self.y_accel = kwargs.get('y_accel', int())
        self.z_accel = kwargs.get('z_accel', int())

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
        if self.bitfield0 != other.bitfield0:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.i_tow != other.i_tow:
            return False
        if self.x_ang_rate != other.x_ang_rate:
            return False
        if self.y_ang_rate != other.y_ang_rate:
            return False
        if self.z_ang_rate != other.z_ang_rate:
            return False
        if self.x_accel != other.x_accel:
            return False
        if self.y_accel != other.y_accel:
            return False
        if self.z_accel != other.z_accel:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def bitfield0(self):
        """Message field 'bitfield0'."""
        return self._bitfield0

    @bitfield0.setter
    def bitfield0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'bitfield0' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'bitfield0' field must be an unsigned integer in [0, 4294967295]"
        self._bitfield0 = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'reserved1' numpy.ndarray() must have a size of 4"
            self._reserved1 = value
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
                "The 'reserved1' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)

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
    def x_ang_rate(self):
        """Message field 'x_ang_rate'."""
        return self._x_ang_rate

    @x_ang_rate.setter
    def x_ang_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x_ang_rate' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'x_ang_rate' field must be an integer in [-2147483648, 2147483647]"
        self._x_ang_rate = value

    @builtins.property
    def y_ang_rate(self):
        """Message field 'y_ang_rate'."""
        return self._y_ang_rate

    @y_ang_rate.setter
    def y_ang_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y_ang_rate' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'y_ang_rate' field must be an integer in [-2147483648, 2147483647]"
        self._y_ang_rate = value

    @builtins.property
    def z_ang_rate(self):
        """Message field 'z_ang_rate'."""
        return self._z_ang_rate

    @z_ang_rate.setter
    def z_ang_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'z_ang_rate' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'z_ang_rate' field must be an integer in [-2147483648, 2147483647]"
        self._z_ang_rate = value

    @builtins.property
    def x_accel(self):
        """Message field 'x_accel'."""
        return self._x_accel

    @x_accel.setter
    def x_accel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x_accel' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'x_accel' field must be an integer in [-2147483648, 2147483647]"
        self._x_accel = value

    @builtins.property
    def y_accel(self):
        """Message field 'y_accel'."""
        return self._y_accel

    @y_accel.setter
    def y_accel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y_accel' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'y_accel' field must be an integer in [-2147483648, 2147483647]"
        self._y_accel = value

    @builtins.property
    def z_accel(self):
        """Message field 'z_accel'."""
        return self._z_accel

    @z_accel.setter
    def z_accel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'z_accel' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'z_accel' field must be an integer in [-2147483648, 2147483647]"
        self._z_accel = value
