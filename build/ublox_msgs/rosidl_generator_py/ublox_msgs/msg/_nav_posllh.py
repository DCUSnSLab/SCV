# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavPOSLLH.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavPOSLLH(type):
    """Metaclass of message 'NavPOSLLH'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 2,
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
                'ublox_msgs.msg.NavPOSLLH')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_posllh
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_posllh
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_posllh
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_posllh
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_posllh

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
        return Metaclass_NavPOSLLH.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavPOSLLH.__constants['MESSAGE_ID']


class NavPOSLLH(metaclass=Metaclass_NavPOSLLH):
    """
    Message class 'NavPOSLLH'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_i_tow',
        '_lon',
        '_lat',
        '_height',
        '_h_msl',
        '_h_acc',
        '_v_acc',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'lon': 'int32',
        'lat': 'int32',
        'height': 'int32',
        'h_msl': 'int32',
        'h_acc': 'uint32',
        'v_acc': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
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
        self.lon = kwargs.get('lon', int())
        self.lat = kwargs.get('lat', int())
        self.height = kwargs.get('height', int())
        self.h_msl = kwargs.get('h_msl', int())
        self.h_acc = kwargs.get('h_acc', int())
        self.v_acc = kwargs.get('v_acc', int())

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
        if self.lon != other.lon:
            return False
        if self.lat != other.lat:
            return False
        if self.height != other.height:
            return False
        if self.h_msl != other.h_msl:
            return False
        if self.h_acc != other.h_acc:
            return False
        if self.v_acc != other.v_acc:
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
    def lon(self):
        """Message field 'lon'."""
        return self._lon

    @lon.setter
    def lon(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lon' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lon' field must be an integer in [-2147483648, 2147483647]"
        self._lon = value

    @builtins.property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lat' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lat' field must be an integer in [-2147483648, 2147483647]"
        self._lat = value

    @builtins.property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'height' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'height' field must be an integer in [-2147483648, 2147483647]"
        self._height = value

    @builtins.property
    def h_msl(self):
        """Message field 'h_msl'."""
        return self._h_msl

    @h_msl.setter
    def h_msl(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'h_msl' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'h_msl' field must be an integer in [-2147483648, 2147483647]"
        self._h_msl = value

    @builtins.property
    def h_acc(self):
        """Message field 'h_acc'."""
        return self._h_acc

    @h_acc.setter
    def h_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'h_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'h_acc' field must be an unsigned integer in [0, 4294967295]"
        self._h_acc = value

    @builtins.property
    def v_acc(self):
        """Message field 'v_acc'."""
        return self._v_acc

    @v_acc.setter
    def v_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'v_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'v_acc' field must be an unsigned integer in [0, 4294967295]"
        self._v_acc = value
