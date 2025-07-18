# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/UpdSOSAck.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved0'
# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UpdSOSAck(type):
    """Metaclass of message 'UpdSOSAck'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 9,
        'MESSAGE_ID': 20,
        'CMD_BACKUP_CREATE_ACK': 2,
        'CMD_SYSTEM_RESTORED': 3,
        'BACKUP_CREATE_NACK': 0,
        'BACKUP_CREATE_ACK': 1,
        'SYSTEM_RESTORED_RESPONSE_UNKNOWN': 0,
        'SYSTEM_RESTORED_RESPONSE_FAILED': 1,
        'SYSTEM_RESTORED_RESPONSE_RESTORED': 2,
        'SYSTEM_RESTORED_RESPONSE_NOT_RESTORED': 3,
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
                'ublox_msgs.msg.UpdSOSAck')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__upd_sos_ack
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__upd_sos_ack
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__upd_sos_ack
            cls._TYPE_SUPPORT = module.type_support_msg__msg__upd_sos_ack
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__upd_sos_ack

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'CMD_BACKUP_CREATE_ACK': cls.__constants['CMD_BACKUP_CREATE_ACK'],
            'CMD_SYSTEM_RESTORED': cls.__constants['CMD_SYSTEM_RESTORED'],
            'BACKUP_CREATE_NACK': cls.__constants['BACKUP_CREATE_NACK'],
            'BACKUP_CREATE_ACK': cls.__constants['BACKUP_CREATE_ACK'],
            'SYSTEM_RESTORED_RESPONSE_UNKNOWN': cls.__constants['SYSTEM_RESTORED_RESPONSE_UNKNOWN'],
            'SYSTEM_RESTORED_RESPONSE_FAILED': cls.__constants['SYSTEM_RESTORED_RESPONSE_FAILED'],
            'SYSTEM_RESTORED_RESPONSE_RESTORED': cls.__constants['SYSTEM_RESTORED_RESPONSE_RESTORED'],
            'SYSTEM_RESTORED_RESPONSE_NOT_RESTORED': cls.__constants['SYSTEM_RESTORED_RESPONSE_NOT_RESTORED'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_UpdSOSAck.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_UpdSOSAck.__constants['MESSAGE_ID']

    @property
    def CMD_BACKUP_CREATE_ACK(self):
        """Message constant 'CMD_BACKUP_CREATE_ACK'."""
        return Metaclass_UpdSOSAck.__constants['CMD_BACKUP_CREATE_ACK']

    @property
    def CMD_SYSTEM_RESTORED(self):
        """Message constant 'CMD_SYSTEM_RESTORED'."""
        return Metaclass_UpdSOSAck.__constants['CMD_SYSTEM_RESTORED']

    @property
    def BACKUP_CREATE_NACK(self):
        """Message constant 'BACKUP_CREATE_NACK'."""
        return Metaclass_UpdSOSAck.__constants['BACKUP_CREATE_NACK']

    @property
    def BACKUP_CREATE_ACK(self):
        """Message constant 'BACKUP_CREATE_ACK'."""
        return Metaclass_UpdSOSAck.__constants['BACKUP_CREATE_ACK']

    @property
    def SYSTEM_RESTORED_RESPONSE_UNKNOWN(self):
        """Message constant 'SYSTEM_RESTORED_RESPONSE_UNKNOWN'."""
        return Metaclass_UpdSOSAck.__constants['SYSTEM_RESTORED_RESPONSE_UNKNOWN']

    @property
    def SYSTEM_RESTORED_RESPONSE_FAILED(self):
        """Message constant 'SYSTEM_RESTORED_RESPONSE_FAILED'."""
        return Metaclass_UpdSOSAck.__constants['SYSTEM_RESTORED_RESPONSE_FAILED']

    @property
    def SYSTEM_RESTORED_RESPONSE_RESTORED(self):
        """Message constant 'SYSTEM_RESTORED_RESPONSE_RESTORED'."""
        return Metaclass_UpdSOSAck.__constants['SYSTEM_RESTORED_RESPONSE_RESTORED']

    @property
    def SYSTEM_RESTORED_RESPONSE_NOT_RESTORED(self):
        """Message constant 'SYSTEM_RESTORED_RESPONSE_NOT_RESTORED'."""
        return Metaclass_UpdSOSAck.__constants['SYSTEM_RESTORED_RESPONSE_NOT_RESTORED']


class UpdSOSAck(metaclass=Metaclass_UpdSOSAck):
    """
    Message class 'UpdSOSAck'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      CMD_BACKUP_CREATE_ACK
      CMD_SYSTEM_RESTORED
      BACKUP_CREATE_NACK
      BACKUP_CREATE_ACK
      SYSTEM_RESTORED_RESPONSE_UNKNOWN
      SYSTEM_RESTORED_RESPONSE_FAILED
      SYSTEM_RESTORED_RESPONSE_RESTORED
      SYSTEM_RESTORED_RESPONSE_NOT_RESTORED
    """

    __slots__ = [
        '_cmd',
        '_reserved0',
        '_response',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'cmd': 'uint8',
        'reserved0': 'uint8[3]',
        'response': 'uint8',
        'reserved1': 'uint8[3]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd = kwargs.get('cmd', int())
        if 'reserved0' not in kwargs:
            self.reserved0 = numpy.zeros(3, dtype=numpy.uint8)
        else:
            self.reserved0 = numpy.array(kwargs.get('reserved0'), dtype=numpy.uint8)
            assert self.reserved0.shape == (3, )
        self.response = kwargs.get('response', int())
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
        if self.cmd != other.cmd:
            return False
        if all(self.reserved0 != other.reserved0):
            return False
        if self.response != other.response:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cmd(self):
        """Message field 'cmd'."""
        return self._cmd

    @cmd.setter
    def cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cmd' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cmd' field must be an unsigned integer in [0, 255]"
        self._cmd = value

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
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'response' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'response' field must be an unsigned integer in [0, 255]"
        self._response = value

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
