# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/MonGNSS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MonGNSS(type):
    """Metaclass of message 'MonGNSS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 10,
        'MESSAGE_ID': 40,
        'BIT_MASK_GPS': 1,
        'BIT_MASK_GLONASS': 2,
        'BIT_MASK_BEIDOU': 4,
        'BIT_MASK_GALILEO': 8,
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
                'ublox_msgs.msg.MonGNSS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mon_gnss
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mon_gnss
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mon_gnss
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mon_gnss
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mon_gnss

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'BIT_MASK_GPS': cls.__constants['BIT_MASK_GPS'],
            'BIT_MASK_GLONASS': cls.__constants['BIT_MASK_GLONASS'],
            'BIT_MASK_BEIDOU': cls.__constants['BIT_MASK_BEIDOU'],
            'BIT_MASK_GALILEO': cls.__constants['BIT_MASK_GALILEO'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_MonGNSS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_MonGNSS.__constants['MESSAGE_ID']

    @property
    def BIT_MASK_GPS(self):
        """Message constant 'BIT_MASK_GPS'."""
        return Metaclass_MonGNSS.__constants['BIT_MASK_GPS']

    @property
    def BIT_MASK_GLONASS(self):
        """Message constant 'BIT_MASK_GLONASS'."""
        return Metaclass_MonGNSS.__constants['BIT_MASK_GLONASS']

    @property
    def BIT_MASK_BEIDOU(self):
        """Message constant 'BIT_MASK_BEIDOU'."""
        return Metaclass_MonGNSS.__constants['BIT_MASK_BEIDOU']

    @property
    def BIT_MASK_GALILEO(self):
        """Message constant 'BIT_MASK_GALILEO'."""
        return Metaclass_MonGNSS.__constants['BIT_MASK_GALILEO']


class MonGNSS(metaclass=Metaclass_MonGNSS):
    """
    Message class 'MonGNSS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      BIT_MASK_GPS
      BIT_MASK_GLONASS
      BIT_MASK_BEIDOU
      BIT_MASK_GALILEO
    """

    __slots__ = [
        '_version',
        '_supported',
        '_default_gnss',
        '_enabled',
        '_simultaneous',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'version': 'uint8',
        'supported': 'uint8',
        'default_gnss': 'uint8',
        'enabled': 'uint8',
        'simultaneous': 'uint8',
        'reserved1': 'uint8[3]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.version = kwargs.get('version', int())
        self.supported = kwargs.get('supported', int())
        self.default_gnss = kwargs.get('default_gnss', int())
        self.enabled = kwargs.get('enabled', int())
        self.simultaneous = kwargs.get('simultaneous', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(3, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (3, )

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
        if self.supported != other.supported:
            return False
        if self.default_gnss != other.default_gnss:
            return False
        if self.enabled != other.enabled:
            return False
        if self.simultaneous != other.simultaneous:
            return False
        if all(self.reserved1 != other.reserved1):
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
    def supported(self):
        """Message field 'supported'."""
        return self._supported

    @supported.setter
    def supported(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'supported' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'supported' field must be an unsigned integer in [0, 255]"
        self._supported = value

    @builtins.property
    def default_gnss(self):
        """Message field 'default_gnss'."""
        return self._default_gnss

    @default_gnss.setter
    def default_gnss(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'default_gnss' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'default_gnss' field must be an unsigned integer in [0, 255]"
        self._default_gnss = value

    @builtins.property
    def enabled(self):
        """Message field 'enabled'."""
        return self._enabled

    @enabled.setter
    def enabled(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enabled' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enabled' field must be an unsigned integer in [0, 255]"
        self._enabled = value

    @builtins.property
    def simultaneous(self):
        """Message field 'simultaneous'."""
        return self._simultaneous

    @simultaneous.setter
    def simultaneous(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'simultaneous' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'simultaneous' field must be an unsigned integer in [0, 255]"
        self._simultaneous = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 3, \
                "The 'reserved1' numpy.ndarray() must have a size of 3"
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
                 len(value) == 3 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 3 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)
