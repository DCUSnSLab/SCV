# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgGNSS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgGNSS(type):
    """Metaclass of message 'CfgGNSS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 62,
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
                'ublox_msgs.msg.CfgGNSS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_gnss
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_gnss
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_gnss
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_gnss
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_gnss

            from ublox_msgs.msg import CfgGNSSBlock
            if CfgGNSSBlock.__class__._TYPE_SUPPORT is None:
                CfgGNSSBlock.__class__.__import_type_support__()

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
        return Metaclass_CfgGNSS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgGNSS.__constants['MESSAGE_ID']


class CfgGNSS(metaclass=Metaclass_CfgGNSS):
    """
    Message class 'CfgGNSS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_msg_ver',
        '_num_trk_ch_hw',
        '_num_trk_ch_use',
        '_num_config_blocks',
        '_blocks',
    ]

    _fields_and_field_types = {
        'msg_ver': 'uint8',
        'num_trk_ch_hw': 'uint8',
        'num_trk_ch_use': 'uint8',
        'num_config_blocks': 'uint8',
        'blocks': 'sequence<ublox_msgs/CfgGNSSBlock>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'CfgGNSSBlock')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.msg_ver = kwargs.get('msg_ver', int())
        self.num_trk_ch_hw = kwargs.get('num_trk_ch_hw', int())
        self.num_trk_ch_use = kwargs.get('num_trk_ch_use', int())
        self.num_config_blocks = kwargs.get('num_config_blocks', int())
        self.blocks = kwargs.get('blocks', [])

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
        if self.msg_ver != other.msg_ver:
            return False
        if self.num_trk_ch_hw != other.num_trk_ch_hw:
            return False
        if self.num_trk_ch_use != other.num_trk_ch_use:
            return False
        if self.num_config_blocks != other.num_config_blocks:
            return False
        if self.blocks != other.blocks:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def msg_ver(self):
        """Message field 'msg_ver'."""
        return self._msg_ver

    @msg_ver.setter
    def msg_ver(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'msg_ver' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'msg_ver' field must be an unsigned integer in [0, 255]"
        self._msg_ver = value

    @builtins.property
    def num_trk_ch_hw(self):
        """Message field 'num_trk_ch_hw'."""
        return self._num_trk_ch_hw

    @num_trk_ch_hw.setter
    def num_trk_ch_hw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_trk_ch_hw' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_trk_ch_hw' field must be an unsigned integer in [0, 255]"
        self._num_trk_ch_hw = value

    @builtins.property
    def num_trk_ch_use(self):
        """Message field 'num_trk_ch_use'."""
        return self._num_trk_ch_use

    @num_trk_ch_use.setter
    def num_trk_ch_use(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_trk_ch_use' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_trk_ch_use' field must be an unsigned integer in [0, 255]"
        self._num_trk_ch_use = value

    @builtins.property
    def num_config_blocks(self):
        """Message field 'num_config_blocks'."""
        return self._num_config_blocks

    @num_config_blocks.setter
    def num_config_blocks(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_config_blocks' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_config_blocks' field must be an unsigned integer in [0, 255]"
        self._num_config_blocks = value

    @builtins.property
    def blocks(self):
        """Message field 'blocks'."""
        return self._blocks

    @blocks.setter
    def blocks(self, value):
        if __debug__:
            from ublox_msgs.msg import CfgGNSSBlock
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
                 all(isinstance(v, CfgGNSSBlock) for v in value) and
                 True), \
                "The 'blocks' field must be a set or sequence and each value of type 'CfgGNSSBlock'"
        self._blocks = value
