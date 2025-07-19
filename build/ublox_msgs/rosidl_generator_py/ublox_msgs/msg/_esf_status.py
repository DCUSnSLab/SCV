# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/EsfSTATUS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
# Member 'reserved2'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EsfSTATUS(type):
    """Metaclass of message 'EsfSTATUS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 16,
        'MESSAGE_ID': 16,
        'FUSION_MODE_INIT': 0,
        'FUSION_MODE_FUSION': 1,
        'FUSION_MODE_SUSPENDED': 2,
        'FUSION_MODE_DISABLED': 3,
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
                'ublox_msgs.msg.EsfSTATUS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__esf_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__esf_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__esf_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__esf_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__esf_status

            from ublox_msgs.msg import EsfSTATUSSens
            if EsfSTATUSSens.__class__._TYPE_SUPPORT is None:
                EsfSTATUSSens.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FUSION_MODE_INIT': cls.__constants['FUSION_MODE_INIT'],
            'FUSION_MODE_FUSION': cls.__constants['FUSION_MODE_FUSION'],
            'FUSION_MODE_SUSPENDED': cls.__constants['FUSION_MODE_SUSPENDED'],
            'FUSION_MODE_DISABLED': cls.__constants['FUSION_MODE_DISABLED'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_EsfSTATUS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_EsfSTATUS.__constants['MESSAGE_ID']

    @property
    def FUSION_MODE_INIT(self):
        """Message constant 'FUSION_MODE_INIT'."""
        return Metaclass_EsfSTATUS.__constants['FUSION_MODE_INIT']

    @property
    def FUSION_MODE_FUSION(self):
        """Message constant 'FUSION_MODE_FUSION'."""
        return Metaclass_EsfSTATUS.__constants['FUSION_MODE_FUSION']

    @property
    def FUSION_MODE_SUSPENDED(self):
        """Message constant 'FUSION_MODE_SUSPENDED'."""
        return Metaclass_EsfSTATUS.__constants['FUSION_MODE_SUSPENDED']

    @property
    def FUSION_MODE_DISABLED(self):
        """Message constant 'FUSION_MODE_DISABLED'."""
        return Metaclass_EsfSTATUS.__constants['FUSION_MODE_DISABLED']


class EsfSTATUS(metaclass=Metaclass_EsfSTATUS):
    """
    Message class 'EsfSTATUS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FUSION_MODE_INIT
      FUSION_MODE_FUSION
      FUSION_MODE_SUSPENDED
      FUSION_MODE_DISABLED
    """

    __slots__ = [
        '_i_tow',
        '_version',
        '_reserved1',
        '_fusion_mode',
        '_reserved2',
        '_num_sens',
        '_sens',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'version': 'uint8',
        'reserved1': 'uint8[7]',
        'fusion_mode': 'uint8',
        'reserved2': 'uint8[2]',
        'num_sens': 'uint8',
        'sens': 'sequence<ublox_msgs/EsfSTATUSSens>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 7),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'EsfSTATUSSens')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.version = kwargs.get('version', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(7, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (7, )
        self.fusion_mode = kwargs.get('fusion_mode', int())
        if 'reserved2' not in kwargs:
            self.reserved2 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved2 = numpy.array(kwargs.get('reserved2'), dtype=numpy.uint8)
            assert self.reserved2.shape == (2, )
        self.num_sens = kwargs.get('num_sens', int())
        self.sens = kwargs.get('sens', [])

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
        if self.version != other.version:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.fusion_mode != other.fusion_mode:
            return False
        if all(self.reserved2 != other.reserved2):
            return False
        if self.num_sens != other.num_sens:
            return False
        if self.sens != other.sens:
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
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 7, \
                "The 'reserved1' numpy.ndarray() must have a size of 7"
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
                 len(value) == 7 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 7 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def fusion_mode(self):
        """Message field 'fusion_mode'."""
        return self._fusion_mode

    @fusion_mode.setter
    def fusion_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fusion_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fusion_mode' field must be an unsigned integer in [0, 255]"
        self._fusion_mode = value

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
    def num_sens(self):
        """Message field 'num_sens'."""
        return self._num_sens

    @num_sens.setter
    def num_sens(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_sens' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_sens' field must be an unsigned integer in [0, 255]"
        self._num_sens = value

    @builtins.property
    def sens(self):
        """Message field 'sens'."""
        return self._sens

    @sens.setter
    def sens(self, value):
        if __debug__:
            from ublox_msgs.msg import EsfSTATUSSens
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
                 all(isinstance(v, EsfSTATUSSens) for v in value) and
                 True), \
                "The 'sens' field must be a set or sequence and each value of type 'EsfSTATUSSens'"
        self._sens = value
