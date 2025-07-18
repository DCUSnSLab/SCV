# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSBAS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved0'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSBAS(type):
    """Metaclass of message 'NavSBAS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 50,
        'MODE_DISABLED': 0,
        'MODE_ENABLED_INTEGRITY': 1,
        'MODE_ENABLED_TESTMODE': 3,
        'SYS_UNKNOWN': -1,
        'SYS_WAAS': 0,
        'SYS_EGNOS': 1,
        'SYS_MSAS': 2,
        'SYS_GAGAN': 3,
        'SYS_GPS': 16,
        'SERVICE_RANGING': 1,
        'SERVICE_CORRECTIONS': 2,
        'SERVICE_INTEGRITY': 4,
        'SERVICE_TESTMODE': 8,
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
                'ublox_msgs.msg.NavSBAS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_sbas
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_sbas
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_sbas
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_sbas
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_sbas

            from ublox_msgs.msg import NavSBASSV
            if NavSBASSV.__class__._TYPE_SUPPORT is None:
                NavSBASSV.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'MODE_DISABLED': cls.__constants['MODE_DISABLED'],
            'MODE_ENABLED_INTEGRITY': cls.__constants['MODE_ENABLED_INTEGRITY'],
            'MODE_ENABLED_TESTMODE': cls.__constants['MODE_ENABLED_TESTMODE'],
            'SYS_UNKNOWN': cls.__constants['SYS_UNKNOWN'],
            'SYS_WAAS': cls.__constants['SYS_WAAS'],
            'SYS_EGNOS': cls.__constants['SYS_EGNOS'],
            'SYS_MSAS': cls.__constants['SYS_MSAS'],
            'SYS_GAGAN': cls.__constants['SYS_GAGAN'],
            'SYS_GPS': cls.__constants['SYS_GPS'],
            'SERVICE_RANGING': cls.__constants['SERVICE_RANGING'],
            'SERVICE_CORRECTIONS': cls.__constants['SERVICE_CORRECTIONS'],
            'SERVICE_INTEGRITY': cls.__constants['SERVICE_INTEGRITY'],
            'SERVICE_TESTMODE': cls.__constants['SERVICE_TESTMODE'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavSBAS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavSBAS.__constants['MESSAGE_ID']

    @property
    def MODE_DISABLED(self):
        """Message constant 'MODE_DISABLED'."""
        return Metaclass_NavSBAS.__constants['MODE_DISABLED']

    @property
    def MODE_ENABLED_INTEGRITY(self):
        """Message constant 'MODE_ENABLED_INTEGRITY'."""
        return Metaclass_NavSBAS.__constants['MODE_ENABLED_INTEGRITY']

    @property
    def MODE_ENABLED_TESTMODE(self):
        """Message constant 'MODE_ENABLED_TESTMODE'."""
        return Metaclass_NavSBAS.__constants['MODE_ENABLED_TESTMODE']

    @property
    def SYS_UNKNOWN(self):
        """Message constant 'SYS_UNKNOWN'."""
        return Metaclass_NavSBAS.__constants['SYS_UNKNOWN']

    @property
    def SYS_WAAS(self):
        """Message constant 'SYS_WAAS'."""
        return Metaclass_NavSBAS.__constants['SYS_WAAS']

    @property
    def SYS_EGNOS(self):
        """Message constant 'SYS_EGNOS'."""
        return Metaclass_NavSBAS.__constants['SYS_EGNOS']

    @property
    def SYS_MSAS(self):
        """Message constant 'SYS_MSAS'."""
        return Metaclass_NavSBAS.__constants['SYS_MSAS']

    @property
    def SYS_GAGAN(self):
        """Message constant 'SYS_GAGAN'."""
        return Metaclass_NavSBAS.__constants['SYS_GAGAN']

    @property
    def SYS_GPS(self):
        """Message constant 'SYS_GPS'."""
        return Metaclass_NavSBAS.__constants['SYS_GPS']

    @property
    def SERVICE_RANGING(self):
        """Message constant 'SERVICE_RANGING'."""
        return Metaclass_NavSBAS.__constants['SERVICE_RANGING']

    @property
    def SERVICE_CORRECTIONS(self):
        """Message constant 'SERVICE_CORRECTIONS'."""
        return Metaclass_NavSBAS.__constants['SERVICE_CORRECTIONS']

    @property
    def SERVICE_INTEGRITY(self):
        """Message constant 'SERVICE_INTEGRITY'."""
        return Metaclass_NavSBAS.__constants['SERVICE_INTEGRITY']

    @property
    def SERVICE_TESTMODE(self):
        """Message constant 'SERVICE_TESTMODE'."""
        return Metaclass_NavSBAS.__constants['SERVICE_TESTMODE']


class NavSBAS(metaclass=Metaclass_NavSBAS):
    """
    Message class 'NavSBAS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      MODE_DISABLED
      MODE_ENABLED_INTEGRITY
      MODE_ENABLED_TESTMODE
      SYS_UNKNOWN
      SYS_WAAS
      SYS_EGNOS
      SYS_MSAS
      SYS_GAGAN
      SYS_GPS
      SERVICE_RANGING
      SERVICE_CORRECTIONS
      SERVICE_INTEGRITY
      SERVICE_TESTMODE
    """

    __slots__ = [
        '_i_tow',
        '_geo',
        '_mode',
        '_sys',
        '_service',
        '_cnt',
        '_reserved0',
        '_sv',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'geo': 'uint8',
        'mode': 'uint8',
        'sys': 'int8',
        'service': 'uint8',
        'cnt': 'uint8',
        'reserved0': 'uint8[3]',
        'sv': 'sequence<ublox_msgs/NavSBASSV>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'NavSBASSV')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.geo = kwargs.get('geo', int())
        self.mode = kwargs.get('mode', int())
        self.sys = kwargs.get('sys', int())
        self.service = kwargs.get('service', int())
        self.cnt = kwargs.get('cnt', int())
        if 'reserved0' not in kwargs:
            self.reserved0 = numpy.zeros(3, dtype=numpy.uint8)
        else:
            self.reserved0 = numpy.array(kwargs.get('reserved0'), dtype=numpy.uint8)
            assert self.reserved0.shape == (3, )
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
        if self.geo != other.geo:
            return False
        if self.mode != other.mode:
            return False
        if self.sys != other.sys:
            return False
        if self.service != other.service:
            return False
        if self.cnt != other.cnt:
            return False
        if all(self.reserved0 != other.reserved0):
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
    def geo(self):
        """Message field 'geo'."""
        return self._geo

    @geo.setter
    def geo(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'geo' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'geo' field must be an unsigned integer in [0, 255]"
        self._geo = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode' field must be an unsigned integer in [0, 255]"
        self._mode = value

    @builtins.property
    def sys(self):
        """Message field 'sys'."""
        return self._sys

    @sys.setter
    def sys(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sys' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'sys' field must be an integer in [-128, 127]"
        self._sys = value

    @builtins.property
    def service(self):
        """Message field 'service'."""
        return self._service

    @service.setter
    def service(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'service' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'service' field must be an unsigned integer in [0, 255]"
        self._service = value

    @builtins.property
    def cnt(self):
        """Message field 'cnt'."""
        return self._cnt

    @cnt.setter
    def cnt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cnt' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cnt' field must be an unsigned integer in [0, 255]"
        self._cnt = value

    @builtins.property
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved0' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 3, \
                "The 'reserved0' numpy.ndarray() must have a size of 3"
            self._reserved0 = value
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
                "The 'reserved0' field must be a set or sequence with length 3 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved0 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def sv(self):
        """Message field 'sv'."""
        return self._sv

    @sv.setter
    def sv(self, value):
        if __debug__:
            from ublox_msgs.msg import NavSBASSV
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
                 all(isinstance(v, NavSBASSV) for v in value) and
                 True), \
                "The 'sv' field must be a set or sequence and each value of type 'NavSBASSV'"
        self._sv = value
