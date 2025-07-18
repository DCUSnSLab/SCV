# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmSVSISV.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmSVSISV(type):
    """Metaclass of message 'RxmSVSISV'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'FLAG_URA_MASK': 15,
        'FLAG_HEALTHY': 16,
        'FLAG_EPH_VAL': 32,
        'FLAG_ALM_VAL': 64,
        'FLAG_NOT_AVAIL': 128,
        'AGE_ALM_MASK': 15,
        'AGE_EPH_MASK': 240,
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
                'ublox_msgs.msg.RxmSVSISV')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_svsisv
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_svsisv
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_svsisv
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_svsisv
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_svsisv

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'FLAG_URA_MASK': cls.__constants['FLAG_URA_MASK'],
            'FLAG_HEALTHY': cls.__constants['FLAG_HEALTHY'],
            'FLAG_EPH_VAL': cls.__constants['FLAG_EPH_VAL'],
            'FLAG_ALM_VAL': cls.__constants['FLAG_ALM_VAL'],
            'FLAG_NOT_AVAIL': cls.__constants['FLAG_NOT_AVAIL'],
            'AGE_ALM_MASK': cls.__constants['AGE_ALM_MASK'],
            'AGE_EPH_MASK': cls.__constants['AGE_EPH_MASK'],
        }

    @property
    def FLAG_URA_MASK(self):
        """Message constant 'FLAG_URA_MASK'."""
        return Metaclass_RxmSVSISV.__constants['FLAG_URA_MASK']

    @property
    def FLAG_HEALTHY(self):
        """Message constant 'FLAG_HEALTHY'."""
        return Metaclass_RxmSVSISV.__constants['FLAG_HEALTHY']

    @property
    def FLAG_EPH_VAL(self):
        """Message constant 'FLAG_EPH_VAL'."""
        return Metaclass_RxmSVSISV.__constants['FLAG_EPH_VAL']

    @property
    def FLAG_ALM_VAL(self):
        """Message constant 'FLAG_ALM_VAL'."""
        return Metaclass_RxmSVSISV.__constants['FLAG_ALM_VAL']

    @property
    def FLAG_NOT_AVAIL(self):
        """Message constant 'FLAG_NOT_AVAIL'."""
        return Metaclass_RxmSVSISV.__constants['FLAG_NOT_AVAIL']

    @property
    def AGE_ALM_MASK(self):
        """Message constant 'AGE_ALM_MASK'."""
        return Metaclass_RxmSVSISV.__constants['AGE_ALM_MASK']

    @property
    def AGE_EPH_MASK(self):
        """Message constant 'AGE_EPH_MASK'."""
        return Metaclass_RxmSVSISV.__constants['AGE_EPH_MASK']


class RxmSVSISV(metaclass=Metaclass_RxmSVSISV):
    """
    Message class 'RxmSVSISV'.

    Constants:
      FLAG_URA_MASK
      FLAG_HEALTHY
      FLAG_EPH_VAL
      FLAG_ALM_VAL
      FLAG_NOT_AVAIL
      AGE_ALM_MASK
      AGE_EPH_MASK
    """

    __slots__ = [
        '_svid',
        '_sv_flag',
        '_azim',
        '_elev',
        '_age',
    ]

    _fields_and_field_types = {
        'svid': 'uint8',
        'sv_flag': 'uint8',
        'azim': 'int16',
        'elev': 'int8',
        'age': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.svid = kwargs.get('svid', int())
        self.sv_flag = kwargs.get('sv_flag', int())
        self.azim = kwargs.get('azim', int())
        self.elev = kwargs.get('elev', int())
        self.age = kwargs.get('age', int())

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
        if self.sv_flag != other.sv_flag:
            return False
        if self.azim != other.azim:
            return False
        if self.elev != other.elev:
            return False
        if self.age != other.age:
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
            assert value >= 0 and value < 256, \
                "The 'svid' field must be an unsigned integer in [0, 255]"
        self._svid = value

    @builtins.property
    def sv_flag(self):
        """Message field 'sv_flag'."""
        return self._sv_flag

    @sv_flag.setter
    def sv_flag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sv_flag' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sv_flag' field must be an unsigned integer in [0, 255]"
        self._sv_flag = value

    @builtins.property
    def azim(self):
        """Message field 'azim'."""
        return self._azim

    @azim.setter
    def azim(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'azim' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'azim' field must be an integer in [-32768, 32767]"
        self._azim = value

    @builtins.property
    def elev(self):
        """Message field 'elev'."""
        return self._elev

    @elev.setter
    def elev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'elev' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'elev' field must be an integer in [-128, 127]"
        self._elev = value

    @builtins.property
    def age(self):
        """Message field 'age'."""
        return self._age

    @age.setter
    def age(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'age' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'age' field must be an unsigned integer in [0, 255]"
        self._age = value
