# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/EsfMEAS.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'data'
# Member 'calib_t_tag'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EsfMEAS(type):
    """Metaclass of message 'EsfMEAS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 16,
        'MESSAGE_ID': 2,
        'FLAGS_TIME_MARK_SENT_MASK': 3,
        'TIME_MARK_NONE': 0,
        'TIME_MARK_EXT0': 1,
        'TIME_MARK_EXT': 2,
        'FLAGS_TIME_MARK_EDGE': 4,
        'FLAGS_CALIB_T_TAG_VALID': 8,
        'DATA_FIELD_MASK': 16777215,
        'DATA_TYPE_MASK': 1056964608,
        'DATA_TYPE_SHIFT': 24,
        'DATA_TYPE_NONE': 0,
        'DATA_TYPE_Z_AXIS_GYRO': 5,
        'DATA_TYPE_WHEEL_TICKS_FRONT_LEFT': 6,
        'DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT': 7,
        'DATA_TYPE_WHEEL_TICKS_REAR_LEFT': 8,
        'DATA_TYPE_WHEEL_TICKS_REAR_RIGHT': 9,
        'DATA_TYPE_SINGLE_TICK': 10,
        'DATA_TYPE_SPEED': 11,
        'DATA_TYPE_GYRO_TEMPERATURE': 12,
        'DATA_TYPE_GYRO_ANG_RATE_Y': 13,
        'DATA_TYPE_GYRO_ANG_RATE_X': 14,
        'DATA_TYPE_ACCELEROMETER_X': 16,
        'DATA_TYPE_ACCELEROMETER_Y': 17,
        'DATA_TYPE_ACCELEROMETER_Z': 18,
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
                'ublox_msgs.msg.EsfMEAS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__esf_meas
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__esf_meas
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__esf_meas
            cls._TYPE_SUPPORT = module.type_support_msg__msg__esf_meas
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__esf_meas

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FLAGS_TIME_MARK_SENT_MASK': cls.__constants['FLAGS_TIME_MARK_SENT_MASK'],
            'TIME_MARK_NONE': cls.__constants['TIME_MARK_NONE'],
            'TIME_MARK_EXT0': cls.__constants['TIME_MARK_EXT0'],
            'TIME_MARK_EXT': cls.__constants['TIME_MARK_EXT'],
            'FLAGS_TIME_MARK_EDGE': cls.__constants['FLAGS_TIME_MARK_EDGE'],
            'FLAGS_CALIB_T_TAG_VALID': cls.__constants['FLAGS_CALIB_T_TAG_VALID'],
            'DATA_FIELD_MASK': cls.__constants['DATA_FIELD_MASK'],
            'DATA_TYPE_MASK': cls.__constants['DATA_TYPE_MASK'],
            'DATA_TYPE_SHIFT': cls.__constants['DATA_TYPE_SHIFT'],
            'DATA_TYPE_NONE': cls.__constants['DATA_TYPE_NONE'],
            'DATA_TYPE_Z_AXIS_GYRO': cls.__constants['DATA_TYPE_Z_AXIS_GYRO'],
            'DATA_TYPE_WHEEL_TICKS_FRONT_LEFT': cls.__constants['DATA_TYPE_WHEEL_TICKS_FRONT_LEFT'],
            'DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT': cls.__constants['DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT'],
            'DATA_TYPE_WHEEL_TICKS_REAR_LEFT': cls.__constants['DATA_TYPE_WHEEL_TICKS_REAR_LEFT'],
            'DATA_TYPE_WHEEL_TICKS_REAR_RIGHT': cls.__constants['DATA_TYPE_WHEEL_TICKS_REAR_RIGHT'],
            'DATA_TYPE_SINGLE_TICK': cls.__constants['DATA_TYPE_SINGLE_TICK'],
            'DATA_TYPE_SPEED': cls.__constants['DATA_TYPE_SPEED'],
            'DATA_TYPE_GYRO_TEMPERATURE': cls.__constants['DATA_TYPE_GYRO_TEMPERATURE'],
            'DATA_TYPE_GYRO_ANG_RATE_Y': cls.__constants['DATA_TYPE_GYRO_ANG_RATE_Y'],
            'DATA_TYPE_GYRO_ANG_RATE_X': cls.__constants['DATA_TYPE_GYRO_ANG_RATE_X'],
            'DATA_TYPE_ACCELEROMETER_X': cls.__constants['DATA_TYPE_ACCELEROMETER_X'],
            'DATA_TYPE_ACCELEROMETER_Y': cls.__constants['DATA_TYPE_ACCELEROMETER_Y'],
            'DATA_TYPE_ACCELEROMETER_Z': cls.__constants['DATA_TYPE_ACCELEROMETER_Z'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_EsfMEAS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_EsfMEAS.__constants['MESSAGE_ID']

    @property
    def FLAGS_TIME_MARK_SENT_MASK(self):
        """Message constant 'FLAGS_TIME_MARK_SENT_MASK'."""
        return Metaclass_EsfMEAS.__constants['FLAGS_TIME_MARK_SENT_MASK']

    @property
    def TIME_MARK_NONE(self):
        """Message constant 'TIME_MARK_NONE'."""
        return Metaclass_EsfMEAS.__constants['TIME_MARK_NONE']

    @property
    def TIME_MARK_EXT0(self):
        """Message constant 'TIME_MARK_EXT0'."""
        return Metaclass_EsfMEAS.__constants['TIME_MARK_EXT0']

    @property
    def TIME_MARK_EXT(self):
        """Message constant 'TIME_MARK_EXT'."""
        return Metaclass_EsfMEAS.__constants['TIME_MARK_EXT']

    @property
    def FLAGS_TIME_MARK_EDGE(self):
        """Message constant 'FLAGS_TIME_MARK_EDGE'."""
        return Metaclass_EsfMEAS.__constants['FLAGS_TIME_MARK_EDGE']

    @property
    def FLAGS_CALIB_T_TAG_VALID(self):
        """Message constant 'FLAGS_CALIB_T_TAG_VALID'."""
        return Metaclass_EsfMEAS.__constants['FLAGS_CALIB_T_TAG_VALID']

    @property
    def DATA_FIELD_MASK(self):
        """Message constant 'DATA_FIELD_MASK'."""
        return Metaclass_EsfMEAS.__constants['DATA_FIELD_MASK']

    @property
    def DATA_TYPE_MASK(self):
        """Message constant 'DATA_TYPE_MASK'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_MASK']

    @property
    def DATA_TYPE_SHIFT(self):
        """Message constant 'DATA_TYPE_SHIFT'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_SHIFT']

    @property
    def DATA_TYPE_NONE(self):
        """Message constant 'DATA_TYPE_NONE'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_NONE']

    @property
    def DATA_TYPE_Z_AXIS_GYRO(self):
        """Message constant 'DATA_TYPE_Z_AXIS_GYRO'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_Z_AXIS_GYRO']

    @property
    def DATA_TYPE_WHEEL_TICKS_FRONT_LEFT(self):
        """Message constant 'DATA_TYPE_WHEEL_TICKS_FRONT_LEFT'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_WHEEL_TICKS_FRONT_LEFT']

    @property
    def DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT(self):
        """Message constant 'DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT']

    @property
    def DATA_TYPE_WHEEL_TICKS_REAR_LEFT(self):
        """Message constant 'DATA_TYPE_WHEEL_TICKS_REAR_LEFT'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_WHEEL_TICKS_REAR_LEFT']

    @property
    def DATA_TYPE_WHEEL_TICKS_REAR_RIGHT(self):
        """Message constant 'DATA_TYPE_WHEEL_TICKS_REAR_RIGHT'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_WHEEL_TICKS_REAR_RIGHT']

    @property
    def DATA_TYPE_SINGLE_TICK(self):
        """Message constant 'DATA_TYPE_SINGLE_TICK'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_SINGLE_TICK']

    @property
    def DATA_TYPE_SPEED(self):
        """Message constant 'DATA_TYPE_SPEED'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_SPEED']

    @property
    def DATA_TYPE_GYRO_TEMPERATURE(self):
        """Message constant 'DATA_TYPE_GYRO_TEMPERATURE'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_GYRO_TEMPERATURE']

    @property
    def DATA_TYPE_GYRO_ANG_RATE_Y(self):
        """Message constant 'DATA_TYPE_GYRO_ANG_RATE_Y'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_GYRO_ANG_RATE_Y']

    @property
    def DATA_TYPE_GYRO_ANG_RATE_X(self):
        """Message constant 'DATA_TYPE_GYRO_ANG_RATE_X'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_GYRO_ANG_RATE_X']

    @property
    def DATA_TYPE_ACCELEROMETER_X(self):
        """Message constant 'DATA_TYPE_ACCELEROMETER_X'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_ACCELEROMETER_X']

    @property
    def DATA_TYPE_ACCELEROMETER_Y(self):
        """Message constant 'DATA_TYPE_ACCELEROMETER_Y'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_ACCELEROMETER_Y']

    @property
    def DATA_TYPE_ACCELEROMETER_Z(self):
        """Message constant 'DATA_TYPE_ACCELEROMETER_Z'."""
        return Metaclass_EsfMEAS.__constants['DATA_TYPE_ACCELEROMETER_Z']


class EsfMEAS(metaclass=Metaclass_EsfMEAS):
    """
    Message class 'EsfMEAS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FLAGS_TIME_MARK_SENT_MASK
      TIME_MARK_NONE
      TIME_MARK_EXT0
      TIME_MARK_EXT
      FLAGS_TIME_MARK_EDGE
      FLAGS_CALIB_T_TAG_VALID
      DATA_FIELD_MASK
      DATA_TYPE_MASK
      DATA_TYPE_SHIFT
      DATA_TYPE_NONE
      DATA_TYPE_Z_AXIS_GYRO
      DATA_TYPE_WHEEL_TICKS_FRONT_LEFT
      DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT
      DATA_TYPE_WHEEL_TICKS_REAR_LEFT
      DATA_TYPE_WHEEL_TICKS_REAR_RIGHT
      DATA_TYPE_SINGLE_TICK
      DATA_TYPE_SPEED
      DATA_TYPE_GYRO_TEMPERATURE
      DATA_TYPE_GYRO_ANG_RATE_Y
      DATA_TYPE_GYRO_ANG_RATE_X
      DATA_TYPE_ACCELEROMETER_X
      DATA_TYPE_ACCELEROMETER_Y
      DATA_TYPE_ACCELEROMETER_Z
    """

    __slots__ = [
        '_time_tag',
        '_flags',
        '_id',
        '_data',
        '_calib_t_tag',
    ]

    _fields_and_field_types = {
        'time_tag': 'uint32',
        'flags': 'uint16',
        'id': 'uint16',
        'data': 'sequence<uint32>',
        'calib_t_tag': 'sequence<uint32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.time_tag = kwargs.get('time_tag', int())
        self.flags = kwargs.get('flags', int())
        self.id = kwargs.get('id', int())
        self.data = array.array('I', kwargs.get('data', []))
        self.calib_t_tag = array.array('I', kwargs.get('calib_t_tag', []))

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
        if self.time_tag != other.time_tag:
            return False
        if self.flags != other.flags:
            return False
        if self.id != other.id:
            return False
        if self.data != other.data:
            return False
        if self.calib_t_tag != other.calib_t_tag:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def time_tag(self):
        """Message field 'time_tag'."""
        return self._time_tag

    @time_tag.setter
    def time_tag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_tag' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'time_tag' field must be an unsigned integer in [0, 4294967295]"
        self._time_tag = value

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

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'id' field must be an unsigned integer in [0, 65535]"
        self._id = value

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'data' array.array() must have the type code of 'I'"
            self._data = value
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
                "The 'data' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._data = array.array('I', value)

    @builtins.property
    def calib_t_tag(self):
        """Message field 'calib_t_tag'."""
        return self._calib_t_tag

    @calib_t_tag.setter
    def calib_t_tag(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'calib_t_tag' array.array() must have the type code of 'I'"
            self._calib_t_tag = value
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
                "The 'calib_t_tag' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._calib_t_tag = array.array('I', value)
