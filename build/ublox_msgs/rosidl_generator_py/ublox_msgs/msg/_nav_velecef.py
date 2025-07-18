# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavVELECEF.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavVELECEF(type):
    """Metaclass of message 'NavVELECEF'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 17,
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
                'ublox_msgs.msg.NavVELECEF')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_velecef
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_velecef
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_velecef
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_velecef
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_velecef

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
        return Metaclass_NavVELECEF.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavVELECEF.__constants['MESSAGE_ID']


class NavVELECEF(metaclass=Metaclass_NavVELECEF):
    """
    Message class 'NavVELECEF'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_i_tow',
        '_ecef_vx',
        '_ecef_vy',
        '_ecef_vz',
        '_s_acc',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'ecef_vx': 'int32',
        'ecef_vy': 'int32',
        'ecef_vz': 'int32',
        's_acc': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.ecef_vx = kwargs.get('ecef_vx', int())
        self.ecef_vy = kwargs.get('ecef_vy', int())
        self.ecef_vz = kwargs.get('ecef_vz', int())
        self.s_acc = kwargs.get('s_acc', int())

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
        if self.ecef_vx != other.ecef_vx:
            return False
        if self.ecef_vy != other.ecef_vy:
            return False
        if self.ecef_vz != other.ecef_vz:
            return False
        if self.s_acc != other.s_acc:
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
    def ecef_vx(self):
        """Message field 'ecef_vx'."""
        return self._ecef_vx

    @ecef_vx.setter
    def ecef_vx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_vx' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_vx' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_vx = value

    @builtins.property
    def ecef_vy(self):
        """Message field 'ecef_vy'."""
        return self._ecef_vy

    @ecef_vy.setter
    def ecef_vy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_vy' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_vy' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_vy = value

    @builtins.property
    def ecef_vz(self):
        """Message field 'ecef_vz'."""
        return self._ecef_vz

    @ecef_vz.setter
    def ecef_vz(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_vz' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_vz' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_vz = value

    @builtins.property
    def s_acc(self):
        """Message field 's_acc'."""
        return self._s_acc

    @s_acc.setter
    def s_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 's_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 's_acc' field must be an unsigned integer in [0, 4294967295]"
        self._s_acc = value
