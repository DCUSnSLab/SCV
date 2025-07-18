# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgUSB.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
# Member 'reserved2'
# Member 'vendor_string'
# Member 'product_string'
# Member 'serial_number'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgUSB(type):
    """Metaclass of message 'CfgUSB'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 27,
        'FLAGS_RE_ENUM': 0,
        'FLAGS_POWER_MODE': 2,
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
                'ublox_msgs.msg.CfgUSB')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_usb
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_usb
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_usb
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_usb
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_usb

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FLAGS_RE_ENUM': cls.__constants['FLAGS_RE_ENUM'],
            'FLAGS_POWER_MODE': cls.__constants['FLAGS_POWER_MODE'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgUSB.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgUSB.__constants['MESSAGE_ID']

    @property
    def FLAGS_RE_ENUM(self):
        """Message constant 'FLAGS_RE_ENUM'."""
        return Metaclass_CfgUSB.__constants['FLAGS_RE_ENUM']

    @property
    def FLAGS_POWER_MODE(self):
        """Message constant 'FLAGS_POWER_MODE'."""
        return Metaclass_CfgUSB.__constants['FLAGS_POWER_MODE']


class CfgUSB(metaclass=Metaclass_CfgUSB):
    """
    Message class 'CfgUSB'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FLAGS_RE_ENUM
      FLAGS_POWER_MODE
    """

    __slots__ = [
        '_vendor_id',
        '_product_id',
        '_reserved1',
        '_reserved2',
        '_power_consumption',
        '_flags',
        '_vendor_string',
        '_product_string',
        '_serial_number',
    ]

    _fields_and_field_types = {
        'vendor_id': 'uint16',
        'product_id': 'uint16',
        'reserved1': 'uint8[2]',
        'reserved2': 'uint8[2]',
        'power_consumption': 'uint16',
        'flags': 'uint16',
        'vendor_string': 'int8[32]',
        'product_string': 'int8[32]',
        'serial_number': 'int8[32]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 32),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 32),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 32),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vendor_id = kwargs.get('vendor_id', int())
        self.product_id = kwargs.get('product_id', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (2, )
        if 'reserved2' not in kwargs:
            self.reserved2 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved2 = numpy.array(kwargs.get('reserved2'), dtype=numpy.uint8)
            assert self.reserved2.shape == (2, )
        self.power_consumption = kwargs.get('power_consumption', int())
        self.flags = kwargs.get('flags', int())
        if 'vendor_string' not in kwargs:
            self.vendor_string = numpy.zeros(32, dtype=numpy.int8)
        else:
            self.vendor_string = numpy.array(kwargs.get('vendor_string'), dtype=numpy.int8)
            assert self.vendor_string.shape == (32, )
        if 'product_string' not in kwargs:
            self.product_string = numpy.zeros(32, dtype=numpy.int8)
        else:
            self.product_string = numpy.array(kwargs.get('product_string'), dtype=numpy.int8)
            assert self.product_string.shape == (32, )
        if 'serial_number' not in kwargs:
            self.serial_number = numpy.zeros(32, dtype=numpy.int8)
        else:
            self.serial_number = numpy.array(kwargs.get('serial_number'), dtype=numpy.int8)
            assert self.serial_number.shape == (32, )

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
        if self.vendor_id != other.vendor_id:
            return False
        if self.product_id != other.product_id:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if all(self.reserved2 != other.reserved2):
            return False
        if self.power_consumption != other.power_consumption:
            return False
        if self.flags != other.flags:
            return False
        if all(self.vendor_string != other.vendor_string):
            return False
        if all(self.product_string != other.product_string):
            return False
        if all(self.serial_number != other.serial_number):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def vendor_id(self):
        """Message field 'vendor_id'."""
        return self._vendor_id

    @vendor_id.setter
    def vendor_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vendor_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'vendor_id' field must be an unsigned integer in [0, 65535]"
        self._vendor_id = value

    @builtins.property
    def product_id(self):
        """Message field 'product_id'."""
        return self._product_id

    @product_id.setter
    def product_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'product_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'product_id' field must be an unsigned integer in [0, 65535]"
        self._product_id = value

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
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved2' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved2' numpy.ndarray() must have a size of 2"
            self._reserved2 = value
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
                "The 'reserved2' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved2 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def power_consumption(self):
        """Message field 'power_consumption'."""
        return self._power_consumption

    @power_consumption.setter
    def power_consumption(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'power_consumption' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'power_consumption' field must be an unsigned integer in [0, 65535]"
        self._power_consumption = value

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
            assert value >= 0 and value < 65536, \
                "The 'flags' field must be an unsigned integer in [0, 65535]"
        self._flags = value

    @builtins.property
    def vendor_string(self):
        """Message field 'vendor_string'."""
        return self._vendor_string

    @vendor_string.setter
    def vendor_string(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'vendor_string' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 32, \
                "The 'vendor_string' numpy.ndarray() must have a size of 32"
            self._vendor_string = value
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
                 len(value) == 32 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'vendor_string' field must be a set or sequence with length 32 and each value of type 'int' and each integer in [-128, 127]"
        self._vendor_string = numpy.array(value, dtype=numpy.int8)

    @builtins.property
    def product_string(self):
        """Message field 'product_string'."""
        return self._product_string

    @product_string.setter
    def product_string(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'product_string' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 32, \
                "The 'product_string' numpy.ndarray() must have a size of 32"
            self._product_string = value
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
                 len(value) == 32 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'product_string' field must be a set or sequence with length 32 and each value of type 'int' and each integer in [-128, 127]"
        self._product_string = numpy.array(value, dtype=numpy.int8)

    @builtins.property
    def serial_number(self):
        """Message field 'serial_number'."""
        return self._serial_number

    @serial_number.setter
    def serial_number(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'serial_number' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 32, \
                "The 'serial_number' numpy.ndarray() must have a size of 32"
            self._serial_number = value
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
                 len(value) == 32 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'serial_number' field must be a set or sequence with length 32 and each value of type 'int' and each integer in [-128, 127]"
        self._serial_number = numpy.array(value, dtype=numpy.int8)
