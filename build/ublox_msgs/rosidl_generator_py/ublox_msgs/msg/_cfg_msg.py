# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgMSG.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgMSG(type):
    """Metaclass of message 'CfgMSG'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 1,
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
                'ublox_msgs.msg.CfgMSG')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_msg

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
        return Metaclass_CfgMSG.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgMSG.__constants['MESSAGE_ID']


class CfgMSG(metaclass=Metaclass_CfgMSG):
    """
    Message class 'CfgMSG'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_msg_class',
        '_msg_id',
        '_rate',
    ]

    _fields_and_field_types = {
        'msg_class': 'uint8',
        'msg_id': 'uint8',
        'rate': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.msg_class = kwargs.get('msg_class', int())
        self.msg_id = kwargs.get('msg_id', int())
        self.rate = kwargs.get('rate', int())

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
        if self.msg_class != other.msg_class:
            return False
        if self.msg_id != other.msg_id:
            return False
        if self.rate != other.rate:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def msg_class(self):
        """Message field 'msg_class'."""
        return self._msg_class

    @msg_class.setter
    def msg_class(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'msg_class' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'msg_class' field must be an unsigned integer in [0, 255]"
        self._msg_class = value

    @builtins.property
    def msg_id(self):
        """Message field 'msg_id'."""
        return self._msg_id

    @msg_id.setter
    def msg_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'msg_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'msg_id' field must be an unsigned integer in [0, 255]"
        self._msg_id = value

    @builtins.property
    def rate(self):
        """Message field 'rate'."""
        return self._rate

    @rate.setter
    def rate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rate' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rate' field must be an unsigned integer in [0, 255]"
        self._rate = value
