# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmEPH.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'sf1d'
# Member 'sf2d'
# Member 'sf3d'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmEPH(type):
    """Metaclass of message 'RxmEPH'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 2,
        'MESSAGE_ID': 49,
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
                'ublox_msgs.msg.RxmEPH')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_eph
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_eph
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_eph
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_eph
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_eph

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
        return Metaclass_RxmEPH.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_RxmEPH.__constants['MESSAGE_ID']


class RxmEPH(metaclass=Metaclass_RxmEPH):
    """
    Message class 'RxmEPH'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_svid',
        '_how',
        '_sf1d',
        '_sf2d',
        '_sf3d',
    ]

    _fields_and_field_types = {
        'svid': 'uint32',
        'how': 'uint32',
        'sf1d': 'sequence<uint32>',
        'sf2d': 'sequence<uint32>',
        'sf3d': 'sequence<uint32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.svid = kwargs.get('svid', int())
        self.how = kwargs.get('how', int())
        self.sf1d = array.array('I', kwargs.get('sf1d', []))
        self.sf2d = array.array('I', kwargs.get('sf2d', []))
        self.sf3d = array.array('I', kwargs.get('sf3d', []))

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
        if self.svid != other.svid:
            return False
        if self.how != other.how:
            return False
        if self.sf1d != other.sf1d:
            return False
        if self.sf2d != other.sf2d:
            return False
        if self.sf3d != other.sf3d:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def svid(self):
        """Message field 'svid'."""
        return self._svid

    @svid.setter
    def svid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'svid' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'svid' field must be an unsigned integer in [0, 4294967295]"
        self._svid = value

    @builtins.property
    def how(self):
        """Message field 'how'."""
        return self._how

    @how.setter
    def how(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'how' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'how' field must be an unsigned integer in [0, 4294967295]"
        self._how = value

    @builtins.property
    def sf1d(self):
        """Message field 'sf1d'."""
        return self._sf1d

    @sf1d.setter
    def sf1d(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'sf1d' array.array() must have the type code of 'I'"
            self._sf1d = value
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
                "The 'sf1d' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._sf1d = array.array('I', value)

    @builtins.property
    def sf2d(self):
        """Message field 'sf2d'."""
        return self._sf2d

    @sf2d.setter
    def sf2d(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'sf2d' array.array() must have the type code of 'I'"
            self._sf2d = value
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
                "The 'sf2d' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._sf2d = array.array('I', value)

    @builtins.property
    def sf3d(self):
        """Message field 'sf3d'."""
        return self._sf3d

    @sf3d.setter
    def sf3d(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'sf3d' array.array() must have the type code of 'I'"
            self._sf3d = value
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
                "The 'sf3d' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._sf3d = array.array('I', value)
