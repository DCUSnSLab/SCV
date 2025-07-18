# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/AidHUI.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AidHUI(type):
    """Metaclass of message 'AidHUI'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 11,
        'MESSAGE_ID': 2,
        'FLAGS_HEALTH': 1,
        'FLAGS_UTC': 2,
        'FLAGS_KLOB': 4,
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
                'ublox_msgs.msg.AidHUI')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__aid_hui
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__aid_hui
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__aid_hui
            cls._TYPE_SUPPORT = module.type_support_msg__msg__aid_hui
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__aid_hui

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FLAGS_HEALTH': cls.__constants['FLAGS_HEALTH'],
            'FLAGS_UTC': cls.__constants['FLAGS_UTC'],
            'FLAGS_KLOB': cls.__constants['FLAGS_KLOB'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_AidHUI.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_AidHUI.__constants['MESSAGE_ID']

    @property
    def FLAGS_HEALTH(self):
        """Message constant 'FLAGS_HEALTH'."""
        return Metaclass_AidHUI.__constants['FLAGS_HEALTH']

    @property
    def FLAGS_UTC(self):
        """Message constant 'FLAGS_UTC'."""
        return Metaclass_AidHUI.__constants['FLAGS_UTC']

    @property
    def FLAGS_KLOB(self):
        """Message constant 'FLAGS_KLOB'."""
        return Metaclass_AidHUI.__constants['FLAGS_KLOB']


class AidHUI(metaclass=Metaclass_AidHUI):
    """
    Message class 'AidHUI'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FLAGS_HEALTH
      FLAGS_UTC
      FLAGS_KLOB
    """

    __slots__ = [
        '_health',
        '_utc_a0',
        '_utc_a1',
        '_utc_tow',
        '_utc_wnt',
        '_utc_ls',
        '_utc_wnf',
        '_utc_dn',
        '_utc_lsf',
        '_utc_spare',
        '_klob_a0',
        '_klob_a1',
        '_klob_a2',
        '_klob_a3',
        '_klob_b0',
        '_klob_b1',
        '_klob_b2',
        '_klob_b3',
        '_flags',
    ]

    _fields_and_field_types = {
        'health': 'uint32',
        'utc_a0': 'double',
        'utc_a1': 'double',
        'utc_tow': 'int32',
        'utc_wnt': 'int16',
        'utc_ls': 'int16',
        'utc_wnf': 'int16',
        'utc_dn': 'int16',
        'utc_lsf': 'int16',
        'utc_spare': 'int16',
        'klob_a0': 'float',
        'klob_a1': 'float',
        'klob_a2': 'float',
        'klob_a3': 'float',
        'klob_b0': 'float',
        'klob_b1': 'float',
        'klob_b2': 'float',
        'klob_b3': 'float',
        'flags': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.health = kwargs.get('health', int())
        self.utc_a0 = kwargs.get('utc_a0', float())
        self.utc_a1 = kwargs.get('utc_a1', float())
        self.utc_tow = kwargs.get('utc_tow', int())
        self.utc_wnt = kwargs.get('utc_wnt', int())
        self.utc_ls = kwargs.get('utc_ls', int())
        self.utc_wnf = kwargs.get('utc_wnf', int())
        self.utc_dn = kwargs.get('utc_dn', int())
        self.utc_lsf = kwargs.get('utc_lsf', int())
        self.utc_spare = kwargs.get('utc_spare', int())
        self.klob_a0 = kwargs.get('klob_a0', float())
        self.klob_a1 = kwargs.get('klob_a1', float())
        self.klob_a2 = kwargs.get('klob_a2', float())
        self.klob_a3 = kwargs.get('klob_a3', float())
        self.klob_b0 = kwargs.get('klob_b0', float())
        self.klob_b1 = kwargs.get('klob_b1', float())
        self.klob_b2 = kwargs.get('klob_b2', float())
        self.klob_b3 = kwargs.get('klob_b3', float())
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
        if self.health != other.health:
            return False
        if self.utc_a0 != other.utc_a0:
            return False
        if self.utc_a1 != other.utc_a1:
            return False
        if self.utc_tow != other.utc_tow:
            return False
        if self.utc_wnt != other.utc_wnt:
            return False
        if self.utc_ls != other.utc_ls:
            return False
        if self.utc_wnf != other.utc_wnf:
            return False
        if self.utc_dn != other.utc_dn:
            return False
        if self.utc_lsf != other.utc_lsf:
            return False
        if self.utc_spare != other.utc_spare:
            return False
        if self.klob_a0 != other.klob_a0:
            return False
        if self.klob_a1 != other.klob_a1:
            return False
        if self.klob_a2 != other.klob_a2:
            return False
        if self.klob_a3 != other.klob_a3:
            return False
        if self.klob_b0 != other.klob_b0:
            return False
        if self.klob_b1 != other.klob_b1:
            return False
        if self.klob_b2 != other.klob_b2:
            return False
        if self.klob_b3 != other.klob_b3:
            return False
        if self.flags != other.flags:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def health(self):
        """Message field 'health'."""
        return self._health

    @health.setter
    def health(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'health' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'health' field must be an unsigned integer in [0, 4294967295]"
        self._health = value

    @builtins.property
    def utc_a0(self):
        """Message field 'utc_a0'."""
        return self._utc_a0

    @utc_a0.setter
    def utc_a0(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'utc_a0' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'utc_a0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._utc_a0 = value

    @builtins.property
    def utc_a1(self):
        """Message field 'utc_a1'."""
        return self._utc_a1

    @utc_a1.setter
    def utc_a1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'utc_a1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'utc_a1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._utc_a1 = value

    @builtins.property
    def utc_tow(self):
        """Message field 'utc_tow'."""
        return self._utc_tow

    @utc_tow.setter
    def utc_tow(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_tow' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'utc_tow' field must be an integer in [-2147483648, 2147483647]"
        self._utc_tow = value

    @builtins.property
    def utc_wnt(self):
        """Message field 'utc_wnt'."""
        return self._utc_wnt

    @utc_wnt.setter
    def utc_wnt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_wnt' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'utc_wnt' field must be an integer in [-32768, 32767]"
        self._utc_wnt = value

    @builtins.property
    def utc_ls(self):
        """Message field 'utc_ls'."""
        return self._utc_ls

    @utc_ls.setter
    def utc_ls(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_ls' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'utc_ls' field must be an integer in [-32768, 32767]"
        self._utc_ls = value

    @builtins.property
    def utc_wnf(self):
        """Message field 'utc_wnf'."""
        return self._utc_wnf

    @utc_wnf.setter
    def utc_wnf(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_wnf' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'utc_wnf' field must be an integer in [-32768, 32767]"
        self._utc_wnf = value

    @builtins.property
    def utc_dn(self):
        """Message field 'utc_dn'."""
        return self._utc_dn

    @utc_dn.setter
    def utc_dn(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_dn' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'utc_dn' field must be an integer in [-32768, 32767]"
        self._utc_dn = value

    @builtins.property
    def utc_lsf(self):
        """Message field 'utc_lsf'."""
        return self._utc_lsf

    @utc_lsf.setter
    def utc_lsf(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_lsf' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'utc_lsf' field must be an integer in [-32768, 32767]"
        self._utc_lsf = value

    @builtins.property
    def utc_spare(self):
        """Message field 'utc_spare'."""
        return self._utc_spare

    @utc_spare.setter
    def utc_spare(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_spare' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'utc_spare' field must be an integer in [-32768, 32767]"
        self._utc_spare = value

    @builtins.property
    def klob_a0(self):
        """Message field 'klob_a0'."""
        return self._klob_a0

    @klob_a0.setter
    def klob_a0(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_a0' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_a0' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_a0 = value

    @builtins.property
    def klob_a1(self):
        """Message field 'klob_a1'."""
        return self._klob_a1

    @klob_a1.setter
    def klob_a1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_a1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_a1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_a1 = value

    @builtins.property
    def klob_a2(self):
        """Message field 'klob_a2'."""
        return self._klob_a2

    @klob_a2.setter
    def klob_a2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_a2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_a2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_a2 = value

    @builtins.property
    def klob_a3(self):
        """Message field 'klob_a3'."""
        return self._klob_a3

    @klob_a3.setter
    def klob_a3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_a3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_a3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_a3 = value

    @builtins.property
    def klob_b0(self):
        """Message field 'klob_b0'."""
        return self._klob_b0

    @klob_b0.setter
    def klob_b0(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_b0' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_b0' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_b0 = value

    @builtins.property
    def klob_b1(self):
        """Message field 'klob_b1'."""
        return self._klob_b1

    @klob_b1.setter
    def klob_b1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_b1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_b1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_b1 = value

    @builtins.property
    def klob_b2(self):
        """Message field 'klob_b2'."""
        return self._klob_b2

    @klob_b2.setter
    def klob_b2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_b2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_b2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_b2 = value

    @builtins.property
    def klob_b3(self):
        """Message field 'klob_b3'."""
        return self._klob_b3

    @klob_b3.setter
    def klob_b3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'klob_b3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'klob_b3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._klob_b3 = value

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
