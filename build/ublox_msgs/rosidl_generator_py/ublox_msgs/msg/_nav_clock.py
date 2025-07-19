# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavCLOCK.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavCLOCK(type):
    """Metaclass of message 'NavCLOCK'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 34,
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
                'ublox_msgs.msg.NavCLOCK')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_clock
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_clock
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_clock
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_clock
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_clock

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
        return Metaclass_NavCLOCK.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavCLOCK.__constants['MESSAGE_ID']


class NavCLOCK(metaclass=Metaclass_NavCLOCK):
    """
    Message class 'NavCLOCK'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_i_tow',
        '_clk_b',
        '_clk_d',
        '_t_acc',
        '_f_acc',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'clk_b': 'int32',
        'clk_d': 'int32',
        't_acc': 'uint32',
        'f_acc': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.clk_b = kwargs.get('clk_b', int())
        self.clk_d = kwargs.get('clk_d', int())
        self.t_acc = kwargs.get('t_acc', int())
        self.f_acc = kwargs.get('f_acc', int())

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
        if self.clk_b != other.clk_b:
            return False
        if self.clk_d != other.clk_d:
            return False
        if self.t_acc != other.t_acc:
            return False
        if self.f_acc != other.f_acc:
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
    def clk_b(self):
        """Message field 'clk_b'."""
        return self._clk_b

    @clk_b.setter
    def clk_b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'clk_b' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'clk_b' field must be an integer in [-2147483648, 2147483647]"
        self._clk_b = value

    @builtins.property
    def clk_d(self):
        """Message field 'clk_d'."""
        return self._clk_d

    @clk_d.setter
    def clk_d(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'clk_d' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'clk_d' field must be an integer in [-2147483648, 2147483647]"
        self._clk_d = value

    @builtins.property
    def t_acc(self):
        """Message field 't_acc'."""
        return self._t_acc

    @t_acc.setter
    def t_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 't_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 't_acc' field must be an unsigned integer in [0, 4294967295]"
        self._t_acc = value

    @builtins.property
    def f_acc(self):
        """Message field 'f_acc'."""
        return self._f_acc

    @f_acc.setter
    def f_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'f_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'f_acc' field must be an unsigned integer in [0, 4294967295]"
        self._f_acc = value
