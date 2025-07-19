# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmRAWX.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmRAWX(type):
    """Metaclass of message 'RxmRAWX'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 2,
        'MESSAGE_ID': 21,
        'REC_STAT_LEAP_SEC': 1,
        'REC_STAT_CLK_RESET': 2,
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
                'ublox_msgs.msg.RxmRAWX')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_rawx
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_rawx
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_rawx
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_rawx
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_rawx

            from ublox_msgs.msg import RxmRAWXMeas
            if RxmRAWXMeas.__class__._TYPE_SUPPORT is None:
                RxmRAWXMeas.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'REC_STAT_LEAP_SEC': cls.__constants['REC_STAT_LEAP_SEC'],
            'REC_STAT_CLK_RESET': cls.__constants['REC_STAT_CLK_RESET'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_RxmRAWX.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_RxmRAWX.__constants['MESSAGE_ID']

    @property
    def REC_STAT_LEAP_SEC(self):
        """Message constant 'REC_STAT_LEAP_SEC'."""
        return Metaclass_RxmRAWX.__constants['REC_STAT_LEAP_SEC']

    @property
    def REC_STAT_CLK_RESET(self):
        """Message constant 'REC_STAT_CLK_RESET'."""
        return Metaclass_RxmRAWX.__constants['REC_STAT_CLK_RESET']


class RxmRAWX(metaclass=Metaclass_RxmRAWX):
    """
    Message class 'RxmRAWX'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      REC_STAT_LEAP_SEC
      REC_STAT_CLK_RESET
    """

    __slots__ = [
        '_rcv_tow',
        '_week',
        '_leap_s',
        '_num_meas',
        '_rec_stat',
        '_version',
        '_reserved1',
        '_meas',
    ]

    _fields_and_field_types = {
        'rcv_tow': 'double',
        'week': 'uint16',
        'leap_s': 'int8',
        'num_meas': 'uint8',
        'rec_stat': 'uint8',
        'version': 'uint8',
        'reserved1': 'uint8[2]',
        'meas': 'sequence<ublox_msgs/RxmRAWXMeas>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'RxmRAWXMeas')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.rcv_tow = kwargs.get('rcv_tow', float())
        self.week = kwargs.get('week', int())
        self.leap_s = kwargs.get('leap_s', int())
        self.num_meas = kwargs.get('num_meas', int())
        self.rec_stat = kwargs.get('rec_stat', int())
        self.version = kwargs.get('version', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (2, )
        self.meas = kwargs.get('meas', [])

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
        if self.rcv_tow != other.rcv_tow:
            return False
        if self.week != other.week:
            return False
        if self.leap_s != other.leap_s:
            return False
        if self.num_meas != other.num_meas:
            return False
        if self.rec_stat != other.rec_stat:
            return False
        if self.version != other.version:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.meas != other.meas:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def rcv_tow(self):
        """Message field 'rcv_tow'."""
        return self._rcv_tow

    @rcv_tow.setter
    def rcv_tow(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rcv_tow' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rcv_tow' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rcv_tow = value

    @builtins.property
    def week(self):
        """Message field 'week'."""
        return self._week

    @week.setter
    def week(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'week' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'week' field must be an unsigned integer in [0, 65535]"
        self._week = value

    @builtins.property
    def leap_s(self):
        """Message field 'leap_s'."""
        return self._leap_s

    @leap_s.setter
    def leap_s(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'leap_s' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'leap_s' field must be an integer in [-128, 127]"
        self._leap_s = value

    @builtins.property
    def num_meas(self):
        """Message field 'num_meas'."""
        return self._num_meas

    @num_meas.setter
    def num_meas(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_meas' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_meas' field must be an unsigned integer in [0, 255]"
        self._num_meas = value

    @builtins.property
    def rec_stat(self):
        """Message field 'rec_stat'."""
        return self._rec_stat

    @rec_stat.setter
    def rec_stat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rec_stat' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rec_stat' field must be an unsigned integer in [0, 255]"
        self._rec_stat = value

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
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved1' numpy.ndarray() must have a size of 2"
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def meas(self):
        """Message field 'meas'."""
        return self._meas

    @meas.setter
    def meas(self, value):
        if __debug__:
            from ublox_msgs.msg import RxmRAWXMeas
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
                 all(isinstance(v, RxmRAWXMeas) for v in value) and
                 True), \
                "The 'meas' field must be a set or sequence and each value of type 'RxmRAWXMeas'"
        self._meas = value
