# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgSBAS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgSBAS(type):
    """Metaclass of message 'CfgSBAS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 22,
        'MODE_ENABLED': 1,
        'MODE_TEST': 2,
        'USAGE_RANGE': 1,
        'USAGE_DIFF_CORR': 2,
        'USAGE_INTEGRITY': 4,
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
                'ublox_msgs.msg.CfgSBAS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_sbas
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_sbas
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_sbas
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_sbas
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_sbas

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'MODE_ENABLED': cls.__constants['MODE_ENABLED'],
            'MODE_TEST': cls.__constants['MODE_TEST'],
            'USAGE_RANGE': cls.__constants['USAGE_RANGE'],
            'USAGE_DIFF_CORR': cls.__constants['USAGE_DIFF_CORR'],
            'USAGE_INTEGRITY': cls.__constants['USAGE_INTEGRITY'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgSBAS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgSBAS.__constants['MESSAGE_ID']

    @property
    def MODE_ENABLED(self):
        """Message constant 'MODE_ENABLED'."""
        return Metaclass_CfgSBAS.__constants['MODE_ENABLED']

    @property
    def MODE_TEST(self):
        """Message constant 'MODE_TEST'."""
        return Metaclass_CfgSBAS.__constants['MODE_TEST']

    @property
    def USAGE_RANGE(self):
        """Message constant 'USAGE_RANGE'."""
        return Metaclass_CfgSBAS.__constants['USAGE_RANGE']

    @property
    def USAGE_DIFF_CORR(self):
        """Message constant 'USAGE_DIFF_CORR'."""
        return Metaclass_CfgSBAS.__constants['USAGE_DIFF_CORR']

    @property
    def USAGE_INTEGRITY(self):
        """Message constant 'USAGE_INTEGRITY'."""
        return Metaclass_CfgSBAS.__constants['USAGE_INTEGRITY']


class CfgSBAS(metaclass=Metaclass_CfgSBAS):
    """
    Message class 'CfgSBAS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      MODE_ENABLED
      MODE_TEST
      USAGE_RANGE
      USAGE_DIFF_CORR
      USAGE_INTEGRITY
    """

    __slots__ = [
        '_mode',
        '_usage',
        '_max_sbas',
        '_scanmode2',
        '_scanmode1',
    ]

    _fields_and_field_types = {
        'mode': 'uint8',
        'usage': 'uint8',
        'max_sbas': 'uint8',
        'scanmode2': 'uint8',
        'scanmode1': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mode = kwargs.get('mode', int())
        self.usage = kwargs.get('usage', int())
        self.max_sbas = kwargs.get('max_sbas', int())
        self.scanmode2 = kwargs.get('scanmode2', int())
        self.scanmode1 = kwargs.get('scanmode1', int())

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
        if self.mode != other.mode:
            return False
        if self.usage != other.usage:
            return False
        if self.max_sbas != other.max_sbas:
            return False
        if self.scanmode2 != other.scanmode2:
            return False
        if self.scanmode1 != other.scanmode1:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def usage(self):
        """Message field 'usage'."""
        return self._usage

    @usage.setter
    def usage(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'usage' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'usage' field must be an unsigned integer in [0, 255]"
        self._usage = value

    @builtins.property
    def max_sbas(self):
        """Message field 'max_sbas'."""
        return self._max_sbas

    @max_sbas.setter
    def max_sbas(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_sbas' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'max_sbas' field must be an unsigned integer in [0, 255]"
        self._max_sbas = value

    @builtins.property
    def scanmode2(self):
        """Message field 'scanmode2'."""
        return self._scanmode2

    @scanmode2.setter
    def scanmode2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'scanmode2' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'scanmode2' field must be an unsigned integer in [0, 255]"
        self._scanmode2 = value

    @builtins.property
    def scanmode1(self):
        """Message field 'scanmode1'."""
        return self._scanmode1

    @scanmode1.setter
    def scanmode1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'scanmode1' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'scanmode1' field must be an unsigned integer in [0, 4294967295]"
        self._scanmode1 = value
