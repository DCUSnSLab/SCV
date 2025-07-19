# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/Ack.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Ack(type):
    """Metaclass of message 'Ack'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 5,
        'NACK_MESSAGE_ID': 0,
        'ACK_MESSAGE_ID': 1,
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
                'ublox_msgs.msg.Ack')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ack
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ack
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ack
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ack
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ack

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'NACK_MESSAGE_ID': cls.__constants['NACK_MESSAGE_ID'],
            'ACK_MESSAGE_ID': cls.__constants['ACK_MESSAGE_ID'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_Ack.__constants['CLASS_ID']

    @property
    def NACK_MESSAGE_ID(self):
        """Message constant 'NACK_MESSAGE_ID'."""
        return Metaclass_Ack.__constants['NACK_MESSAGE_ID']

    @property
    def ACK_MESSAGE_ID(self):
        """Message constant 'ACK_MESSAGE_ID'."""
        return Metaclass_Ack.__constants['ACK_MESSAGE_ID']


class Ack(metaclass=Metaclass_Ack):
    """
    Message class 'Ack'.

    Constants:
      CLASS_ID
      NACK_MESSAGE_ID
      ACK_MESSAGE_ID
    """

    __slots__ = [
        '_cls_id',
        '_msg_id',
    ]

    _fields_and_field_types = {
        'cls_id': 'uint8',
        'msg_id': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cls_id = kwargs.get('cls_id', int())
        self.msg_id = kwargs.get('msg_id', int())

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
        if self.cls_id != other.cls_id:
            return False
        if self.msg_id != other.msg_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cls_id(self):
        """Message field 'cls_id'."""
        return self._cls_id

    @cls_id.setter
    def cls_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cls_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cls_id' field must be an unsigned integer in [0, 255]"
        self._cls_id = value

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
