# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmSFRBX.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'dwrd'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmSFRBX(type):
    """Metaclass of message 'RxmSFRBX'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 2,
        'MESSAGE_ID': 19,
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
                'ublox_msgs.msg.RxmSFRBX')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_sfrbx
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_sfrbx
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_sfrbx
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_sfrbx
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_sfrbx

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_RxmSFRBX.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_RxmSFRBX.__constants['MESSAGE_ID']


class RxmSFRBX(metaclass=Metaclass_RxmSFRBX):
    """
    Message class 'RxmSFRBX'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_gnss_id',
        '_sv_id',
        '_reserved0',
        '_freq_id',
        '_num_words',
        '_chn',
        '_version',
        '_reserved1',
        '_dwrd',
    ]

    _fields_and_field_types = {
        'gnss_id': 'uint8',
        'sv_id': 'uint8',
        'reserved0': 'uint8',
        'freq_id': 'uint8',
        'num_words': 'uint8',
        'chn': 'uint8',
        'version': 'uint8',
        'reserved1': 'uint8',
        'dwrd': 'sequence<uint32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.gnss_id = kwargs.get('gnss_id', int())
        self.sv_id = kwargs.get('sv_id', int())
        self.reserved0 = kwargs.get('reserved0', int())
        self.freq_id = kwargs.get('freq_id', int())
        self.num_words = kwargs.get('num_words', int())
        self.chn = kwargs.get('chn', int())
        self.version = kwargs.get('version', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.dwrd = array.array('I', kwargs.get('dwrd', []))

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
        if self.gnss_id != other.gnss_id:
            return False
        if self.sv_id != other.sv_id:
            return False
        if self.reserved0 != other.reserved0:
            return False
        if self.freq_id != other.freq_id:
            return False
        if self.num_words != other.num_words:
            return False
        if self.chn != other.chn:
            return False
        if self.version != other.version:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.dwrd != other.dwrd:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def gnss_id(self):
        """Message field 'gnss_id'."""
        return self._gnss_id

    @gnss_id.setter
    def gnss_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gnss_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gnss_id' field must be an unsigned integer in [0, 255]"
        self._gnss_id = value

    @builtins.property
    def sv_id(self):
        """Message field 'sv_id'."""
        return self._sv_id

    @sv_id.setter
    def sv_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sv_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sv_id' field must be an unsigned integer in [0, 255]"
        self._sv_id = value

    @builtins.property
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved0' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved0' field must be an unsigned integer in [0, 255]"
        self._reserved0 = value

    @builtins.property
    def freq_id(self):
        """Message field 'freq_id'."""
        return self._freq_id

    @freq_id.setter
    def freq_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'freq_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'freq_id' field must be an unsigned integer in [0, 255]"
        self._freq_id = value

    @builtins.property
    def num_words(self):
        """Message field 'num_words'."""
        return self._num_words

    @num_words.setter
    def num_words(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_words' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_words' field must be an unsigned integer in [0, 255]"
        self._num_words = value

    @builtins.property
    def chn(self):
        """Message field 'chn'."""
        return self._chn

    @chn.setter
    def chn(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chn' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'chn' field must be an unsigned integer in [0, 255]"
        self._chn = value

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
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved1' field must be an unsigned integer in [0, 255]"
        self._reserved1 = value

    @builtins.property
    def dwrd(self):
        """Message field 'dwrd'."""
        return self._dwrd

    @dwrd.setter
    def dwrd(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'dwrd' array.array() must have the type code of 'I'"
            self._dwrd = value
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
                "The 'dwrd' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._dwrd = array.array('I', value)
