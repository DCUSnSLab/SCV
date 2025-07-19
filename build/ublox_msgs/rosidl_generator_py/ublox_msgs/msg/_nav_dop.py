# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavDOP.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavDOP(type):
    """Metaclass of message 'NavDOP'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 4,
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
                'ublox_msgs.msg.NavDOP')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_dop
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_dop
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_dop
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_dop
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_dop

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
        return Metaclass_NavDOP.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavDOP.__constants['MESSAGE_ID']


class NavDOP(metaclass=Metaclass_NavDOP):
    """
    Message class 'NavDOP'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_i_tow',
        '_g_dop',
        '_p_dop',
        '_t_dop',
        '_v_dop',
        '_h_dop',
        '_n_dop',
        '_e_dop',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'g_dop': 'uint16',
        'p_dop': 'uint16',
        't_dop': 'uint16',
        'v_dop': 'uint16',
        'h_dop': 'uint16',
        'n_dop': 'uint16',
        'e_dop': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.g_dop = kwargs.get('g_dop', int())
        self.p_dop = kwargs.get('p_dop', int())
        self.t_dop = kwargs.get('t_dop', int())
        self.v_dop = kwargs.get('v_dop', int())
        self.h_dop = kwargs.get('h_dop', int())
        self.n_dop = kwargs.get('n_dop', int())
        self.e_dop = kwargs.get('e_dop', int())

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
        if self.g_dop != other.g_dop:
            return False
        if self.p_dop != other.p_dop:
            return False
        if self.t_dop != other.t_dop:
            return False
        if self.v_dop != other.v_dop:
            return False
        if self.h_dop != other.h_dop:
            return False
        if self.n_dop != other.n_dop:
            return False
        if self.e_dop != other.e_dop:
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
    def g_dop(self):
        """Message field 'g_dop'."""
        return self._g_dop

    @g_dop.setter
    def g_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'g_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'g_dop' field must be an unsigned integer in [0, 65535]"
        self._g_dop = value

    @builtins.property
    def p_dop(self):
        """Message field 'p_dop'."""
        return self._p_dop

    @p_dop.setter
    def p_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'p_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'p_dop' field must be an unsigned integer in [0, 65535]"
        self._p_dop = value

    @builtins.property
    def t_dop(self):
        """Message field 't_dop'."""
        return self._t_dop

    @t_dop.setter
    def t_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 't_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 't_dop' field must be an unsigned integer in [0, 65535]"
        self._t_dop = value

    @builtins.property
    def v_dop(self):
        """Message field 'v_dop'."""
        return self._v_dop

    @v_dop.setter
    def v_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'v_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'v_dop' field must be an unsigned integer in [0, 65535]"
        self._v_dop = value

    @builtins.property
    def h_dop(self):
        """Message field 'h_dop'."""
        return self._h_dop

    @h_dop.setter
    def h_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'h_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'h_dop' field must be an unsigned integer in [0, 65535]"
        self._h_dop = value

    @builtins.property
    def n_dop(self):
        """Message field 'n_dop'."""
        return self._n_dop

    @n_dop.setter
    def n_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'n_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'n_dop' field must be an unsigned integer in [0, 65535]"
        self._n_dop = value

    @builtins.property
    def e_dop(self):
        """Message field 'e_dop'."""
        return self._e_dop

    @e_dop.setter
    def e_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'e_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'e_dop' field must be an unsigned integer in [0, 65535]"
        self._e_dop = value
