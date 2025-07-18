# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgNAVX5.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
# Member 'reserved3'
# Member 'reserved4'
# Member 'reserved5'
# Member 'reserved6'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgNAVX5(type):
    """Metaclass of message 'CfgNAVX5'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 35,
        'MASK1_MIN_MAX': 4,
        'MASK1_MIN_CNO': 8,
        'MASK1_INITIAL_FIX_3D': 64,
        'MASK1_WKN_ROLL': 512,
        'MASK1_ACK_AID': 1024,
        'MASK1_PPP': 8192,
        'MASK1_AOP': 16384,
        'MASK2_ADR': 64,
        'MASK2_SIG_ATTEN_COMP_MODE': 128,
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
                'ublox_msgs.msg.CfgNAVX5')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_navx5
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_navx5
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_navx5
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_navx5
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_navx5

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'MASK1_MIN_MAX': cls.__constants['MASK1_MIN_MAX'],
            'MASK1_MIN_CNO': cls.__constants['MASK1_MIN_CNO'],
            'MASK1_INITIAL_FIX_3D': cls.__constants['MASK1_INITIAL_FIX_3D'],
            'MASK1_WKN_ROLL': cls.__constants['MASK1_WKN_ROLL'],
            'MASK1_ACK_AID': cls.__constants['MASK1_ACK_AID'],
            'MASK1_PPP': cls.__constants['MASK1_PPP'],
            'MASK1_AOP': cls.__constants['MASK1_AOP'],
            'MASK2_ADR': cls.__constants['MASK2_ADR'],
            'MASK2_SIG_ATTEN_COMP_MODE': cls.__constants['MASK2_SIG_ATTEN_COMP_MODE'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgNAVX5.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgNAVX5.__constants['MESSAGE_ID']

    @property
    def MASK1_MIN_MAX(self):
        """Message constant 'MASK1_MIN_MAX'."""
        return Metaclass_CfgNAVX5.__constants['MASK1_MIN_MAX']

    @property
    def MASK1_MIN_CNO(self):
        """Message constant 'MASK1_MIN_CNO'."""
        return Metaclass_CfgNAVX5.__constants['MASK1_MIN_CNO']

    @property
    def MASK1_INITIAL_FIX_3D(self):
        """Message constant 'MASK1_INITIAL_FIX_3D'."""
        return Metaclass_CfgNAVX5.__constants['MASK1_INITIAL_FIX_3D']

    @property
    def MASK1_WKN_ROLL(self):
        """Message constant 'MASK1_WKN_ROLL'."""
        return Metaclass_CfgNAVX5.__constants['MASK1_WKN_ROLL']

    @property
    def MASK1_ACK_AID(self):
        """Message constant 'MASK1_ACK_AID'."""
        return Metaclass_CfgNAVX5.__constants['MASK1_ACK_AID']

    @property
    def MASK1_PPP(self):
        """Message constant 'MASK1_PPP'."""
        return Metaclass_CfgNAVX5.__constants['MASK1_PPP']

    @property
    def MASK1_AOP(self):
        """Message constant 'MASK1_AOP'."""
        return Metaclass_CfgNAVX5.__constants['MASK1_AOP']

    @property
    def MASK2_ADR(self):
        """Message constant 'MASK2_ADR'."""
        return Metaclass_CfgNAVX5.__constants['MASK2_ADR']

    @property
    def MASK2_SIG_ATTEN_COMP_MODE(self):
        """Message constant 'MASK2_SIG_ATTEN_COMP_MODE'."""
        return Metaclass_CfgNAVX5.__constants['MASK2_SIG_ATTEN_COMP_MODE']


class CfgNAVX5(metaclass=Metaclass_CfgNAVX5):
    """
    Message class 'CfgNAVX5'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      MASK1_MIN_MAX
      MASK1_MIN_CNO
      MASK1_INITIAL_FIX_3D
      MASK1_WKN_ROLL
      MASK1_ACK_AID
      MASK1_PPP
      MASK1_AOP
      MASK2_ADR
      MASK2_SIG_ATTEN_COMP_MODE
    """

    __slots__ = [
        '_version',
        '_mask1',
        '_mask2',
        '_reserved1',
        '_min_svs',
        '_max_svs',
        '_min_cno',
        '_reserved2',
        '_ini_fix3d',
        '_reserved3',
        '_ack_aiding',
        '_wkn_rollover',
        '_sig_atten_comp_mode',
        '_reserved4',
        '_use_ppp',
        '_aop_cfg',
        '_reserved5',
        '_aop_orb_max_err',
        '_reserved6',
        '_use_adr',
    ]

    _fields_and_field_types = {
        'version': 'uint16',
        'mask1': 'uint16',
        'mask2': 'uint32',
        'reserved1': 'uint8[2]',
        'min_svs': 'uint8',
        'max_svs': 'uint8',
        'min_cno': 'uint8',
        'reserved2': 'uint8',
        'ini_fix3d': 'uint8',
        'reserved3': 'uint8[2]',
        'ack_aiding': 'uint8',
        'wkn_rollover': 'uint16',
        'sig_atten_comp_mode': 'uint8',
        'reserved4': 'uint8[5]',
        'use_ppp': 'uint8',
        'aop_cfg': 'uint8',
        'reserved5': 'uint8[2]',
        'aop_orb_max_err': 'uint16',
        'reserved6': 'uint8[7]',
        'use_adr': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 5),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 7),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.version = kwargs.get('version', int())
        self.mask1 = kwargs.get('mask1', int())
        self.mask2 = kwargs.get('mask2', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (2, )
        self.min_svs = kwargs.get('min_svs', int())
        self.max_svs = kwargs.get('max_svs', int())
        self.min_cno = kwargs.get('min_cno', int())
        self.reserved2 = kwargs.get('reserved2', int())
        self.ini_fix3d = kwargs.get('ini_fix3d', int())
        if 'reserved3' not in kwargs:
            self.reserved3 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved3 = numpy.array(kwargs.get('reserved3'), dtype=numpy.uint8)
            assert self.reserved3.shape == (2, )
        self.ack_aiding = kwargs.get('ack_aiding', int())
        self.wkn_rollover = kwargs.get('wkn_rollover', int())
        self.sig_atten_comp_mode = kwargs.get('sig_atten_comp_mode', int())
        if 'reserved4' not in kwargs:
            self.reserved4 = numpy.zeros(5, dtype=numpy.uint8)
        else:
            self.reserved4 = numpy.array(kwargs.get('reserved4'), dtype=numpy.uint8)
            assert self.reserved4.shape == (5, )
        self.use_ppp = kwargs.get('use_ppp', int())
        self.aop_cfg = kwargs.get('aop_cfg', int())
        if 'reserved5' not in kwargs:
            self.reserved5 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved5 = numpy.array(kwargs.get('reserved5'), dtype=numpy.uint8)
            assert self.reserved5.shape == (2, )
        self.aop_orb_max_err = kwargs.get('aop_orb_max_err', int())
        if 'reserved6' not in kwargs:
            self.reserved6 = numpy.zeros(7, dtype=numpy.uint8)
        else:
            self.reserved6 = numpy.array(kwargs.get('reserved6'), dtype=numpy.uint8)
            assert self.reserved6.shape == (7, )
        self.use_adr = kwargs.get('use_adr', int())

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
        if self.version != other.version:
            return False
        if self.mask1 != other.mask1:
            return False
        if self.mask2 != other.mask2:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.min_svs != other.min_svs:
            return False
        if self.max_svs != other.max_svs:
            return False
        if self.min_cno != other.min_cno:
            return False
        if self.reserved2 != other.reserved2:
            return False
        if self.ini_fix3d != other.ini_fix3d:
            return False
        if all(self.reserved3 != other.reserved3):
            return False
        if self.ack_aiding != other.ack_aiding:
            return False
        if self.wkn_rollover != other.wkn_rollover:
            return False
        if self.sig_atten_comp_mode != other.sig_atten_comp_mode:
            return False
        if all(self.reserved4 != other.reserved4):
            return False
        if self.use_ppp != other.use_ppp:
            return False
        if self.aop_cfg != other.aop_cfg:
            return False
        if all(self.reserved5 != other.reserved5):
            return False
        if self.aop_orb_max_err != other.aop_orb_max_err:
            return False
        if all(self.reserved6 != other.reserved6):
            return False
        if self.use_adr != other.use_adr:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'version' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'version' field must be an unsigned integer in [0, 65535]"
        self._version = value

    @builtins.property
    def mask1(self):
        """Message field 'mask1'."""
        return self._mask1

    @mask1.setter
    def mask1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mask1' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'mask1' field must be an unsigned integer in [0, 65535]"
        self._mask1 = value

    @builtins.property
    def mask2(self):
        """Message field 'mask2'."""
        return self._mask2

    @mask2.setter
    def mask2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mask2' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'mask2' field must be an unsigned integer in [0, 4294967295]"
        self._mask2 = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved1' numpy.ndarray() must have a size of 2"
            self._reserved1 = value
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def min_svs(self):
        """Message field 'min_svs'."""
        return self._min_svs

    @min_svs.setter
    def min_svs(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min_svs' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'min_svs' field must be an unsigned integer in [0, 255]"
        self._min_svs = value

    @builtins.property
    def max_svs(self):
        """Message field 'max_svs'."""
        return self._max_svs

    @max_svs.setter
    def max_svs(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_svs' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'max_svs' field must be an unsigned integer in [0, 255]"
        self._max_svs = value

    @builtins.property
    def min_cno(self):
        """Message field 'min_cno'."""
        return self._min_cno

    @min_cno.setter
    def min_cno(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min_cno' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'min_cno' field must be an unsigned integer in [0, 255]"
        self._min_cno = value

    @builtins.property
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved2' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved2' field must be an unsigned integer in [0, 255]"
        self._reserved2 = value

    @builtins.property
    def ini_fix3d(self):
        """Message field 'ini_fix3d'."""
        return self._ini_fix3d

    @ini_fix3d.setter
    def ini_fix3d(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ini_fix3d' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ini_fix3d' field must be an unsigned integer in [0, 255]"
        self._ini_fix3d = value

    @builtins.property
    def reserved3(self):
        """Message field 'reserved3'."""
        return self._reserved3

    @reserved3.setter
    def reserved3(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved3' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved3' numpy.ndarray() must have a size of 2"
            self._reserved3 = value
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved3' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved3 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def ack_aiding(self):
        """Message field 'ack_aiding'."""
        return self._ack_aiding

    @ack_aiding.setter
    def ack_aiding(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ack_aiding' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ack_aiding' field must be an unsigned integer in [0, 255]"
        self._ack_aiding = value

    @builtins.property
    def wkn_rollover(self):
        """Message field 'wkn_rollover'."""
        return self._wkn_rollover

    @wkn_rollover.setter
    def wkn_rollover(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'wkn_rollover' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'wkn_rollover' field must be an unsigned integer in [0, 65535]"
        self._wkn_rollover = value

    @builtins.property
    def sig_atten_comp_mode(self):
        """Message field 'sig_atten_comp_mode'."""
        return self._sig_atten_comp_mode

    @sig_atten_comp_mode.setter
    def sig_atten_comp_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sig_atten_comp_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sig_atten_comp_mode' field must be an unsigned integer in [0, 255]"
        self._sig_atten_comp_mode = value

    @builtins.property
    def reserved4(self):
        """Message field 'reserved4'."""
        return self._reserved4

    @reserved4.setter
    def reserved4(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved4' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 5, \
                "The 'reserved4' numpy.ndarray() must have a size of 5"
            self._reserved4 = value
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
                 len(value) == 5 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved4' field must be a set or sequence with length 5 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved4 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def use_ppp(self):
        """Message field 'use_ppp'."""
        return self._use_ppp

    @use_ppp.setter
    def use_ppp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'use_ppp' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'use_ppp' field must be an unsigned integer in [0, 255]"
        self._use_ppp = value

    @builtins.property
    def aop_cfg(self):
        """Message field 'aop_cfg'."""
        return self._aop_cfg

    @aop_cfg.setter
    def aop_cfg(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'aop_cfg' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'aop_cfg' field must be an unsigned integer in [0, 255]"
        self._aop_cfg = value

    @builtins.property
    def reserved5(self):
        """Message field 'reserved5'."""
        return self._reserved5

    @reserved5.setter
    def reserved5(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved5' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved5' numpy.ndarray() must have a size of 2"
            self._reserved5 = value
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved5' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved5 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def aop_orb_max_err(self):
        """Message field 'aop_orb_max_err'."""
        return self._aop_orb_max_err

    @aop_orb_max_err.setter
    def aop_orb_max_err(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'aop_orb_max_err' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'aop_orb_max_err' field must be an unsigned integer in [0, 65535]"
        self._aop_orb_max_err = value

    @builtins.property
    def reserved6(self):
        """Message field 'reserved6'."""
        return self._reserved6

    @reserved6.setter
    def reserved6(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved6' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 7, \
                "The 'reserved6' numpy.ndarray() must have a size of 7"
            self._reserved6 = value
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
                 len(value) == 7 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved6' field must be a set or sequence with length 7 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved6 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def use_adr(self):
        """Message field 'use_adr'."""
        return self._use_adr

    @use_adr.setter
    def use_adr(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'use_adr' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'use_adr' field must be an unsigned integer in [0, 255]"
        self._use_adr = value
