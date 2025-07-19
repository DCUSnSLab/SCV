# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgVALDEL.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'keys'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

# Member 'reserved0'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgVALDEL(type):
    """Metaclass of message 'CfgVALDEL'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 140,
        'LAYER_BBR': 1,
        'LAYER_FLASH': 2,
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
                'ublox_msgs.msg.CfgVALDEL')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_valdel
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_valdel
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_valdel
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_valdel
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_valdel

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'LAYER_BBR': cls.__constants['LAYER_BBR'],
            'LAYER_FLASH': cls.__constants['LAYER_FLASH'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgVALDEL.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgVALDEL.__constants['MESSAGE_ID']

    @property
    def LAYER_BBR(self):
        """Message constant 'LAYER_BBR'."""
        return Metaclass_CfgVALDEL.__constants['LAYER_BBR']

    @property
    def LAYER_FLASH(self):
        """Message constant 'LAYER_FLASH'."""
        return Metaclass_CfgVALDEL.__constants['LAYER_FLASH']


class CfgVALDEL(metaclass=Metaclass_CfgVALDEL):
    """
    Message class 'CfgVALDEL'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      LAYER_BBR
      LAYER_FLASH
    """

    __slots__ = [
        '_version',
        '_layers',
        '_reserved0',
        '_keys',
    ]

    _fields_and_field_types = {
        'version': 'uint8',
        'layers': 'uint8',
        'reserved0': 'uint8[2]',
        'keys': 'sequence<uint32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.version = kwargs.get('version', int())
        self.layers = kwargs.get('layers', int())
        if 'reserved0' not in kwargs:
            self.reserved0 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved0 = numpy.array(kwargs.get('reserved0'), dtype=numpy.uint8)
            assert self.reserved0.shape == (2, )
        self.keys = array.array('I', kwargs.get('keys', []))

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
        if self.layers != other.layers:
            return False
        if all(self.reserved0 != other.reserved0):
            return False
        if self.keys != other.keys:
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
    def layers(self):
        """Message field 'layers'."""
        return self._layers

    @layers.setter
    def layers(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'layers' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'layers' field must be an unsigned integer in [0, 255]"
        self._layers = value

    @builtins.property
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved0' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved0' numpy.ndarray() must have a size of 2"
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved0' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved0 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def keys(self):
        """Message field 'keys'."""
        return self._keys

    @keys.setter
    def keys(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'keys' array.array() must have the type code of 'I'"
            self._keys = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'keys' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._keys = array.array('I', value)
