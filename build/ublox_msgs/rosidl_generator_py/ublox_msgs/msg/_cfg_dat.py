# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgDAT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'datum_name'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgDAT(type):
    """Metaclass of message 'CfgDAT'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 6,
        'DATUM_NUM_WGS84': 0,
        'DATUM_NUM_USER': 65535,
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
                'ublox_msgs.msg.CfgDAT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_dat
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_dat
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_dat
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_dat
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_dat

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'DATUM_NUM_WGS84': cls.__constants['DATUM_NUM_WGS84'],
            'DATUM_NUM_USER': cls.__constants['DATUM_NUM_USER'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgDAT.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgDAT.__constants['MESSAGE_ID']

    @property
    def DATUM_NUM_WGS84(self):
        """Message constant 'DATUM_NUM_WGS84'."""
        return Metaclass_CfgDAT.__constants['DATUM_NUM_WGS84']

    @property
    def DATUM_NUM_USER(self):
        """Message constant 'DATUM_NUM_USER'."""
        return Metaclass_CfgDAT.__constants['DATUM_NUM_USER']


class CfgDAT(metaclass=Metaclass_CfgDAT):
    """
    Message class 'CfgDAT'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      DATUM_NUM_WGS84
      DATUM_NUM_USER
    """

    __slots__ = [
        '_datum_num',
        '_datum_name',
        '_maj_a',
        '_flat',
        '_d_x',
        '_d_y',
        '_d_z',
        '_rot_x',
        '_rot_y',
        '_rot_z',
        '_scale',
    ]

    _fields_and_field_types = {
        'datum_num': 'uint16',
        'datum_name': 'uint8[6]',
        'maj_a': 'double',
        'flat': 'double',
        'd_x': 'float',
        'd_y': 'float',
        'd_z': 'float',
        'rot_x': 'float',
        'rot_y': 'float',
        'rot_z': 'float',
        'scale': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 6),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.datum_num = kwargs.get('datum_num', int())
        if 'datum_name' not in kwargs:
            self.datum_name = numpy.zeros(6, dtype=numpy.uint8)
        else:
            self.datum_name = numpy.array(kwargs.get('datum_name'), dtype=numpy.uint8)
            assert self.datum_name.shape == (6, )
        self.maj_a = kwargs.get('maj_a', float())
        self.flat = kwargs.get('flat', float())
        self.d_x = kwargs.get('d_x', float())
        self.d_y = kwargs.get('d_y', float())
        self.d_z = kwargs.get('d_z', float())
        self.rot_x = kwargs.get('rot_x', float())
        self.rot_y = kwargs.get('rot_y', float())
        self.rot_z = kwargs.get('rot_z', float())
        self.scale = kwargs.get('scale', float())

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
        if self.datum_num != other.datum_num:
            return False
        if all(self.datum_name != other.datum_name):
            return False
        if self.maj_a != other.maj_a:
            return False
        if self.flat != other.flat:
            return False
        if self.d_x != other.d_x:
            return False
        if self.d_y != other.d_y:
            return False
        if self.d_z != other.d_z:
            return False
        if self.rot_x != other.rot_x:
            return False
        if self.rot_y != other.rot_y:
            return False
        if self.rot_z != other.rot_z:
            return False
        if self.scale != other.scale:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def datum_num(self):
        """Message field 'datum_num'."""
        return self._datum_num

    @datum_num.setter
    def datum_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'datum_num' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'datum_num' field must be an unsigned integer in [0, 65535]"
        self._datum_num = value

    @builtins.property
    def datum_name(self):
        """Message field 'datum_name'."""
        return self._datum_name

    @datum_name.setter
    def datum_name(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'datum_name' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 6, \
                "The 'datum_name' numpy.ndarray() must have a size of 6"
            self._datum_name = value
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
                "The 'datum_name' field must be a set or sequence with length 6 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._datum_name = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def maj_a(self):
        """Message field 'maj_a'."""
        return self._maj_a

    @maj_a.setter
    def maj_a(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'maj_a' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'maj_a' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._maj_a = value

    @builtins.property
    def flat(self):
        """Message field 'flat'."""
        return self._flat

    @flat.setter
    def flat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'flat' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'flat' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._flat = value

    @builtins.property
    def d_x(self):
        """Message field 'd_x'."""
        return self._d_x

    @d_x.setter
    def d_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'd_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'd_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._d_x = value

    @builtins.property
    def d_y(self):
        """Message field 'd_y'."""
        return self._d_y

    @d_y.setter
    def d_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'd_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'd_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._d_y = value

    @builtins.property
    def d_z(self):
        """Message field 'd_z'."""
        return self._d_z

    @d_z.setter
    def d_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'd_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'd_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._d_z = value

    @builtins.property
    def rot_x(self):
        """Message field 'rot_x'."""
        return self._rot_x

    @rot_x.setter
    def rot_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rot_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rot_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rot_x = value

    @builtins.property
    def rot_y(self):
        """Message field 'rot_y'."""
        return self._rot_y

    @rot_y.setter
    def rot_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rot_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rot_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rot_y = value

    @builtins.property
    def rot_z(self):
        """Message field 'rot_z'."""
        return self._rot_z

    @rot_z.setter
    def rot_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rot_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rot_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rot_z = value

    @builtins.property
    def scale(self):
        """Message field 'scale'."""
        return self._scale

    @scale.setter
    def scale(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'scale' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'scale' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._scale = value
