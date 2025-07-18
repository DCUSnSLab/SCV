# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSVINFO.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSVINFO(type):
    """Metaclass of message 'NavSVINFO'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 48,
        'CHIPGEN_ANTARIS': 0,
        'CHIPGEN_UBLOX5': 1,
        'CHIPGEN_UBLOX6': 2,
        'CHIPGEN_UBLOX7': 3,
        'CHIPGEN_UBLOX8': 4,
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
                'ublox_msgs.msg.NavSVINFO')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_svinfo
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_svinfo
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_svinfo
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_svinfo
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_svinfo

            from ublox_msgs.msg import NavSVINFOSV
            if NavSVINFOSV.__class__._TYPE_SUPPORT is None:
                NavSVINFOSV.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'CHIPGEN_ANTARIS': cls.__constants['CHIPGEN_ANTARIS'],
            'CHIPGEN_UBLOX5': cls.__constants['CHIPGEN_UBLOX5'],
            'CHIPGEN_UBLOX6': cls.__constants['CHIPGEN_UBLOX6'],
            'CHIPGEN_UBLOX7': cls.__constants['CHIPGEN_UBLOX7'],
            'CHIPGEN_UBLOX8': cls.__constants['CHIPGEN_UBLOX8'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavSVINFO.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavSVINFO.__constants['MESSAGE_ID']

    @property
    def CHIPGEN_ANTARIS(self):
        """Message constant 'CHIPGEN_ANTARIS'."""
        return Metaclass_NavSVINFO.__constants['CHIPGEN_ANTARIS']

    @property
    def CHIPGEN_UBLOX5(self):
        """Message constant 'CHIPGEN_UBLOX5'."""
        return Metaclass_NavSVINFO.__constants['CHIPGEN_UBLOX5']

    @property
    def CHIPGEN_UBLOX6(self):
        """Message constant 'CHIPGEN_UBLOX6'."""
        return Metaclass_NavSVINFO.__constants['CHIPGEN_UBLOX6']

    @property
    def CHIPGEN_UBLOX7(self):
        """Message constant 'CHIPGEN_UBLOX7'."""
        return Metaclass_NavSVINFO.__constants['CHIPGEN_UBLOX7']

    @property
    def CHIPGEN_UBLOX8(self):
        """Message constant 'CHIPGEN_UBLOX8'."""
        return Metaclass_NavSVINFO.__constants['CHIPGEN_UBLOX8']


class NavSVINFO(metaclass=Metaclass_NavSVINFO):
    """
    Message class 'NavSVINFO'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      CHIPGEN_ANTARIS
      CHIPGEN_UBLOX5
      CHIPGEN_UBLOX6
      CHIPGEN_UBLOX7
      CHIPGEN_UBLOX8
    """

    __slots__ = [
        '_i_tow',
        '_num_ch',
        '_global_flags',
        '_reserved2',
        '_sv',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'num_ch': 'uint8',
        'global_flags': 'uint8',
        'reserved2': 'uint16',
        'sv': 'sequence<ublox_msgs/NavSVINFOSV>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'NavSVINFOSV')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.num_ch = kwargs.get('num_ch', int())
        self.global_flags = kwargs.get('global_flags', int())
        self.reserved2 = kwargs.get('reserved2', int())
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
        if self.num_ch != other.num_ch:
            return False
        if self.global_flags != other.global_flags:
            return False
        if self.reserved2 != other.reserved2:
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
    def num_ch(self):
        """Message field 'num_ch'."""
        return self._num_ch

    @num_ch.setter
    def num_ch(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_ch' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_ch' field must be an unsigned integer in [0, 255]"
        self._num_ch = value

    @builtins.property
    def global_flags(self):
        """Message field 'global_flags'."""
        return self._global_flags

    @global_flags.setter
    def global_flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'global_flags' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'global_flags' field must be an unsigned integer in [0, 255]"
        self._global_flags = value

    @builtins.property
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved2' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'reserved2' field must be an unsigned integer in [0, 65535]"
        self._reserved2 = value

    @builtins.property
    def sv(self):
        """Message field 'sv'."""
        return self._sv

    @sv.setter
    def sv(self, value):
        if __debug__:
            from ublox_msgs.msg import NavSVINFOSV
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
                 all(isinstance(v, NavSVINFOSV) for v in value) and
                 True), \
                "The 'sv' field must be a set or sequence and each value of type 'NavSVINFOSV'"
        self._sv = value
