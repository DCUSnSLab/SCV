# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmSVSI.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmSVSI(type):
    """Metaclass of message 'RxmSVSI'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 2,
        'MESSAGE_ID': 32,
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
                'ublox_msgs.msg.RxmSVSI')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_svsi
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_svsi
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_svsi
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_svsi
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_svsi

            from ublox_msgs.msg import RxmSVSISV
            if RxmSVSISV.__class__._TYPE_SUPPORT is None:
                RxmSVSISV.__class__.__import_type_support__()

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
        return Metaclass_RxmSVSI.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_RxmSVSI.__constants['MESSAGE_ID']


class RxmSVSI(metaclass=Metaclass_RxmSVSI):
    """
    Message class 'RxmSVSI'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_i_tow',
        '_week',
        '_num_vis',
        '_num_sv',
        '_sv',
    ]

    _fields_and_field_types = {
        'i_tow': 'int32',
        'week': 'int16',
        'num_vis': 'uint8',
        'num_sv': 'uint8',
        'sv': 'sequence<ublox_msgs/RxmSVSISV>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'RxmSVSISV')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.week = kwargs.get('week', int())
        self.num_vis = kwargs.get('num_vis', int())
        self.num_sv = kwargs.get('num_sv', int())
        self.sv = kwargs.get('sv', [])

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
        if self.week != other.week:
            return False
        if self.num_vis != other.num_vis:
            return False
        if self.num_sv != other.num_sv:
            return False
        if self.sv != other.sv:
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
            assert value >= -2147483648 and value < 2147483648, \
                "The 'i_tow' field must be an integer in [-2147483648, 2147483647]"
        self._i_tow = value

    @builtins.property
    def week(self):
        """Message field 'week'."""
        return self._week

    @week.setter
    def week(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'week' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'week' field must be an integer in [-32768, 32767]"
        self._week = value

    @builtins.property
    def num_vis(self):
        """Message field 'num_vis'."""
        return self._num_vis

    @num_vis.setter
    def num_vis(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_vis' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_vis' field must be an unsigned integer in [0, 255]"
        self._num_vis = value

    @builtins.property
    def num_sv(self):
        """Message field 'num_sv'."""
        return self._num_sv

    @num_sv.setter
    def num_sv(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_sv' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_sv' field must be an unsigned integer in [0, 255]"
        self._num_sv = value

    @builtins.property
    def sv(self):
        """Message field 'sv'."""
        return self._sv

    @sv.setter
    def sv(self, value):
        if __debug__:
            from ublox_msgs.msg import RxmSVSISV
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
                 all(isinstance(v, RxmSVSISV) for v in value) and
                 True), \
                "The 'sv' field must be a set or sequence and each value of type 'RxmSVSISV'"
        self._sv = value
