# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgINFBlock.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
# Member 'inf_msg_mask'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgINFBlock(type):
    """Metaclass of message 'CfgINFBlock'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'PROTOCOL_ID_UBX': 0,
        'PROTOCOL_ID_NMEA': 1,
        'INF_MSG_ERROR': 1,
        'INF_MSG_WARNING': 2,
        'INF_MSG_NOTICE': 4,
        'INF_MSG_TEST': 8,
        'INF_MSG_DEBUG': 16,
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
                'ublox_msgs.msg.CfgINFBlock')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_inf_block
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_inf_block
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_inf_block
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_inf_block
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_inf_block

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PROTOCOL_ID_UBX': cls.__constants['PROTOCOL_ID_UBX'],
            'PROTOCOL_ID_NMEA': cls.__constants['PROTOCOL_ID_NMEA'],
            'INF_MSG_ERROR': cls.__constants['INF_MSG_ERROR'],
            'INF_MSG_WARNING': cls.__constants['INF_MSG_WARNING'],
            'INF_MSG_NOTICE': cls.__constants['INF_MSG_NOTICE'],
            'INF_MSG_TEST': cls.__constants['INF_MSG_TEST'],
            'INF_MSG_DEBUG': cls.__constants['INF_MSG_DEBUG'],
        }

    @property
    def PROTOCOL_ID_UBX(self):
        """Message constant 'PROTOCOL_ID_UBX'."""
        return Metaclass_CfgINFBlock.__constants['PROTOCOL_ID_UBX']

    @property
    def PROTOCOL_ID_NMEA(self):
        """Message constant 'PROTOCOL_ID_NMEA'."""
        return Metaclass_CfgINFBlock.__constants['PROTOCOL_ID_NMEA']

    @property
    def INF_MSG_ERROR(self):
        """Message constant 'INF_MSG_ERROR'."""
        return Metaclass_CfgINFBlock.__constants['INF_MSG_ERROR']

    @property
    def INF_MSG_WARNING(self):
        """Message constant 'INF_MSG_WARNING'."""
        return Metaclass_CfgINFBlock.__constants['INF_MSG_WARNING']

    @property
    def INF_MSG_NOTICE(self):
        """Message constant 'INF_MSG_NOTICE'."""
        return Metaclass_CfgINFBlock.__constants['INF_MSG_NOTICE']

    @property
    def INF_MSG_TEST(self):
        """Message constant 'INF_MSG_TEST'."""
        return Metaclass_CfgINFBlock.__constants['INF_MSG_TEST']

    @property
    def INF_MSG_DEBUG(self):
        """Message constant 'INF_MSG_DEBUG'."""
        return Metaclass_CfgINFBlock.__constants['INF_MSG_DEBUG']


class CfgINFBlock(metaclass=Metaclass_CfgINFBlock):
    """
    Message class 'CfgINFBlock'.

    Constants:
      PROTOCOL_ID_UBX
      PROTOCOL_ID_NMEA
      INF_MSG_ERROR
      INF_MSG_WARNING
      INF_MSG_NOTICE
      INF_MSG_TEST
      INF_MSG_DEBUG
    """

    __slots__ = [
        '_protocol_id',
        '_reserved1',
        '_inf_msg_mask',
    ]

    _fields_and_field_types = {
        'protocol_id': 'uint8',
        'reserved1': 'uint8[3]',
        'inf_msg_mask': 'uint8[6]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 6),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.protocol_id = kwargs.get('protocol_id', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(3, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (3, )
        if 'inf_msg_mask' not in kwargs:
            self.inf_msg_mask = numpy.zeros(6, dtype=numpy.uint8)
        else:
            self.inf_msg_mask = numpy.array(kwargs.get('inf_msg_mask'), dtype=numpy.uint8)
            assert self.inf_msg_mask.shape == (6, )

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
        if self.protocol_id != other.protocol_id:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if all(self.inf_msg_mask != other.inf_msg_mask):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def protocol_id(self):
        """Message field 'protocol_id'."""
        return self._protocol_id

    @protocol_id.setter
    def protocol_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'protocol_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'protocol_id' field must be an unsigned integer in [0, 255]"
        self._protocol_id = value

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

    @builtins.property
    def inf_msg_mask(self):
        """Message field 'inf_msg_mask'."""
        return self._inf_msg_mask

    @inf_msg_mask.setter
    def inf_msg_mask(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'inf_msg_mask' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 6, \
                "The 'inf_msg_mask' numpy.ndarray() must have a size of 6"
            self._inf_msg_mask = value
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
                 len(value) == 6 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'inf_msg_mask' field must be a set or sequence with length 6 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._inf_msg_mask = numpy.array(value, dtype=numpy.uint8)
