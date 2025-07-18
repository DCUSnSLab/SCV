# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmRAWSV.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmRAWSV(type):
    """Metaclass of message 'RxmRAWSV'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'ublox_msgs.msg.RxmRAWSV')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_rawsv
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_rawsv
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_rawsv
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_rawsv
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_rawsv

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RxmRAWSV(metaclass=Metaclass_RxmRAWSV):
    """Message class 'RxmRAWSV'."""

    __slots__ = [
        '_cp_mes',
        '_pr_mes',
        '_do_mes',
        '_sv',
        '_mes_qi',
        '_cno',
        '_lli',
    ]

    _fields_and_field_types = {
        'cp_mes': 'double',
        'pr_mes': 'double',
        'do_mes': 'float',
        'sv': 'uint8',
        'mes_qi': 'int8',
        'cno': 'int8',
        'lli': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cp_mes = kwargs.get('cp_mes', float())
        self.pr_mes = kwargs.get('pr_mes', float())
        self.do_mes = kwargs.get('do_mes', float())
        self.sv = kwargs.get('sv', int())
        self.mes_qi = kwargs.get('mes_qi', int())
        self.cno = kwargs.get('cno', int())
        self.lli = kwargs.get('lli', int())

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
        if self.cp_mes != other.cp_mes:
            return False
        if self.pr_mes != other.pr_mes:
            return False
        if self.do_mes != other.do_mes:
            return False
        if self.sv != other.sv:
            return False
        if self.mes_qi != other.mes_qi:
            return False
        if self.cno != other.cno:
            return False
        if self.lli != other.lli:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cp_mes(self):
        """Message field 'cp_mes'."""
        return self._cp_mes

    @cp_mes.setter
    def cp_mes(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cp_mes' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'cp_mes' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._cp_mes = value

    @builtins.property
    def pr_mes(self):
        """Message field 'pr_mes'."""
        return self._pr_mes

    @pr_mes.setter
    def pr_mes(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pr_mes' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pr_mes' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pr_mes = value

    @builtins.property
    def do_mes(self):
        """Message field 'do_mes'."""
        return self._do_mes

    @do_mes.setter
    def do_mes(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'do_mes' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'do_mes' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._do_mes = value

    @builtins.property
    def sv(self):
        """Message field 'sv'."""
        return self._sv

    @sv.setter
    def sv(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sv' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sv' field must be an unsigned integer in [0, 255]"
        self._sv = value

    @builtins.property
    def mes_qi(self):
        """Message field 'mes_qi'."""
        return self._mes_qi

    @mes_qi.setter
    def mes_qi(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mes_qi' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'mes_qi' field must be an integer in [-128, 127]"
        self._mes_qi = value

    @builtins.property
    def cno(self):
        """Message field 'cno'."""
        return self._cno

    @cno.setter
    def cno(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cno' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'cno' field must be an integer in [-128, 127]"
        self._cno = value

    @builtins.property
    def lli(self):
        """Message field 'lli'."""
        return self._lli

    @lli.setter
    def lli(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lli' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'lli' field must be an unsigned integer in [0, 255]"
        self._lli = value
