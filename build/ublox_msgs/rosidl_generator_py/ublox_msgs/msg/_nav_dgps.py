# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavDGPS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavDGPS(type):
    """Metaclass of message 'NavDGPS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 49,
        'DGPS_CORRECTION_NONE': 0,
        'DGPS_CORRECTION_PR_PRR': 1,
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
                'ublox_msgs.msg.NavDGPS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_dgps
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_dgps
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_dgps
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_dgps
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_dgps

            from ublox_msgs.msg import NavDGPSSV
            if NavDGPSSV.__class__._TYPE_SUPPORT is None:
                NavDGPSSV.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'DGPS_CORRECTION_NONE': cls.__constants['DGPS_CORRECTION_NONE'],
            'DGPS_CORRECTION_PR_PRR': cls.__constants['DGPS_CORRECTION_PR_PRR'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavDGPS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavDGPS.__constants['MESSAGE_ID']

    @property
    def DGPS_CORRECTION_NONE(self):
        """Message constant 'DGPS_CORRECTION_NONE'."""
        return Metaclass_NavDGPS.__constants['DGPS_CORRECTION_NONE']

    @property
    def DGPS_CORRECTION_PR_PRR(self):
        """Message constant 'DGPS_CORRECTION_PR_PRR'."""
        return Metaclass_NavDGPS.__constants['DGPS_CORRECTION_PR_PRR']


class NavDGPS(metaclass=Metaclass_NavDGPS):
    """
    Message class 'NavDGPS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      DGPS_CORRECTION_NONE
      DGPS_CORRECTION_PR_PRR
    """

    __slots__ = [
        '_i_tow',
        '_age',
        '_base_id',
        '_base_health',
        '_num_ch',
        '_status',
        '_reserved1',
        '_sv',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'age': 'int32',
        'base_id': 'int16',
        'base_health': 'int16',
        'num_ch': 'int8',
        'status': 'uint8',
        'reserved1': 'uint16',
        'sv': 'sequence<ublox_msgs/NavDGPSSV>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'NavDGPSSV')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.age = kwargs.get('age', int())
        self.base_id = kwargs.get('base_id', int())
        self.base_health = kwargs.get('base_health', int())
        self.num_ch = kwargs.get('num_ch', int())
        self.status = kwargs.get('status', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.sv = kwargs.get('sv', [])

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
        if self.i_tow != other.i_tow:
            return False
        if self.age != other.age:
            return False
        if self.base_id != other.base_id:
            return False
        if self.base_health != other.base_health:
            return False
        if self.num_ch != other.num_ch:
            return False
        if self.status != other.status:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.sv != other.sv:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def age(self):
        """Message field 'age'."""
        return self._age

    @age.setter
    def age(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'age' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'age' field must be an integer in [-2147483648, 2147483647]"
        self._age = value

    @builtins.property
    def base_id(self):
        """Message field 'base_id'."""
        return self._base_id

    @base_id.setter
    def base_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'base_id' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'base_id' field must be an integer in [-32768, 32767]"
        self._base_id = value

    @builtins.property
    def base_health(self):
        """Message field 'base_health'."""
        return self._base_health

    @base_health.setter
    def base_health(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'base_health' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'base_health' field must be an integer in [-32768, 32767]"
        self._base_health = value

    @builtins.property
    def num_ch(self):
        """Message field 'num_ch'."""
        return self._num_ch

    @num_ch.setter
    def num_ch(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_ch' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'num_ch' field must be an integer in [-128, 127]"
        self._num_ch = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'status' field must be an unsigned integer in [0, 255]"
        self._status = value

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
            assert value >= 0 and value < 65536, \
                "The 'reserved1' field must be an unsigned integer in [0, 65535]"
        self._reserved1 = value

    @builtins.property
    def sv(self):
        """Message field 'sv'."""
        return self._sv

    @sv.setter
    def sv(self, value):
        if __debug__:
            from ublox_msgs.msg import NavDGPSSV
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
                 all(isinstance(v, NavDGPSSV) for v in value) and
                 True), \
                "The 'sv' field must be a set or sequence and each value of type 'NavDGPSSV'"
        self._sv = value
