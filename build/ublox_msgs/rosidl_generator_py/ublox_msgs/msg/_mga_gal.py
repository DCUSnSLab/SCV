# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/MgaGAL.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
# Member 'reserved2'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MgaGAL(type):
    """Metaclass of message 'MgaGAL'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 19,
        'MESSAGE_ID': 2,
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
                'ublox_msgs.msg.MgaGAL')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mga_gal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mga_gal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mga_gal
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mga_gal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mga_gal

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
        return Metaclass_MgaGAL.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_MgaGAL.__constants['MESSAGE_ID']


class MgaGAL(metaclass=Metaclass_MgaGAL):
    """
    Message class 'MgaGAL'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_type',
        '_version',
        '_svid',
        '_reserved0',
        '_iod_nav',
        '_delta_n',
        '_m0',
        '_e',
        '_sqrt_a',
        '_omega0',
        '_i0',
        '_omega',
        '_omega_dot',
        '_i_dot',
        '_cuc',
        '_cus',
        '_crc',
        '_crs',
        '_cic',
        '_cis',
        '_toe',
        '_af0',
        '_af1',
        '_af2',
        '_sisaindex_e1_e5b',
        '_toc',
        '_bgd_e1_e5b',
        '_reserved1',
        '_health_e1b',
        '_data_validity_e1b',
        '_health_e5b',
        '_data_validity_e5b',
        '_reserved2',
    ]

    _fields_and_field_types = {
        'type': 'uint8',
        'version': 'uint8',
        'svid': 'uint8',
        'reserved0': 'uint8',
        'iod_nav': 'uint16',
        'delta_n': 'int16',
        'm0': 'int32',
        'e': 'uint32',
        'sqrt_a': 'uint32',
        'omega0': 'int32',
        'i0': 'int32',
        'omega': 'int32',
        'omega_dot': 'int32',
        'i_dot': 'int16',
        'cuc': 'int16',
        'cus': 'int16',
        'crc': 'int16',
        'crs': 'int16',
        'cic': 'int16',
        'cis': 'int16',
        'toe': 'uint16',
        'af0': 'int32',
        'af1': 'int32',
        'af2': 'int8',
        'sisaindex_e1_e5b': 'uint8',
        'toc': 'uint16',
        'bgd_e1_e5b': 'int16',
        'reserved1': 'uint8[2]',
        'health_e1b': 'uint8',
        'data_validity_e1b': 'uint8',
        'health_e5b': 'uint8',
        'data_validity_e5b': 'uint8',
        'reserved2': 'uint8[4]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.type = kwargs.get('type', int())
        self.version = kwargs.get('version', int())
        self.svid = kwargs.get('svid', int())
        self.reserved0 = kwargs.get('reserved0', int())
        self.iod_nav = kwargs.get('iod_nav', int())
        self.delta_n = kwargs.get('delta_n', int())
        self.m0 = kwargs.get('m0', int())
        self.e = kwargs.get('e', int())
        self.sqrt_a = kwargs.get('sqrt_a', int())
        self.omega0 = kwargs.get('omega0', int())
        self.i0 = kwargs.get('i0', int())
        self.omega = kwargs.get('omega', int())
        self.omega_dot = kwargs.get('omega_dot', int())
        self.i_dot = kwargs.get('i_dot', int())
        self.cuc = kwargs.get('cuc', int())
        self.cus = kwargs.get('cus', int())
        self.crc = kwargs.get('crc', int())
        self.crs = kwargs.get('crs', int())
        self.cic = kwargs.get('cic', int())
        self.cis = kwargs.get('cis', int())
        self.toe = kwargs.get('toe', int())
        self.af0 = kwargs.get('af0', int())
        self.af1 = kwargs.get('af1', int())
        self.af2 = kwargs.get('af2', int())
        self.sisaindex_e1_e5b = kwargs.get('sisaindex_e1_e5b', int())
        self.toc = kwargs.get('toc', int())
        self.bgd_e1_e5b = kwargs.get('bgd_e1_e5b', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (2, )
        self.health_e1b = kwargs.get('health_e1b', int())
        self.data_validity_e1b = kwargs.get('data_validity_e1b', int())
        self.health_e5b = kwargs.get('health_e5b', int())
        self.data_validity_e5b = kwargs.get('data_validity_e5b', int())
        if 'reserved2' not in kwargs:
            self.reserved2 = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.reserved2 = numpy.array(kwargs.get('reserved2'), dtype=numpy.uint8)
            assert self.reserved2.shape == (4, )

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
        if self.type != other.type:
            return False
        if self.version != other.version:
            return False
        if self.svid != other.svid:
            return False
        if self.reserved0 != other.reserved0:
            return False
        if self.iod_nav != other.iod_nav:
            return False
        if self.delta_n != other.delta_n:
            return False
        if self.m0 != other.m0:
            return False
        if self.e != other.e:
            return False
        if self.sqrt_a != other.sqrt_a:
            return False
        if self.omega0 != other.omega0:
            return False
        if self.i0 != other.i0:
            return False
        if self.omega != other.omega:
            return False
        if self.omega_dot != other.omega_dot:
            return False
        if self.i_dot != other.i_dot:
            return False
        if self.cuc != other.cuc:
            return False
        if self.cus != other.cus:
            return False
        if self.crc != other.crc:
            return False
        if self.crs != other.crs:
            return False
        if self.cic != other.cic:
            return False
        if self.cis != other.cis:
            return False
        if self.toe != other.toe:
            return False
        if self.af0 != other.af0:
            return False
        if self.af1 != other.af1:
            return False
        if self.af2 != other.af2:
            return False
        if self.sisaindex_e1_e5b != other.sisaindex_e1_e5b:
            return False
        if self.toc != other.toc:
            return False
        if self.bgd_e1_e5b != other.bgd_e1_e5b:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.health_e1b != other.health_e1b:
            return False
        if self.data_validity_e1b != other.data_validity_e1b:
            return False
        if self.health_e5b != other.health_e5b:
            return False
        if self.data_validity_e5b != other.data_validity_e5b:
            return False
        if all(self.reserved2 != other.reserved2):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'type' field must be an unsigned integer in [0, 255]"
        self._type = value

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
            assert value >= 0 and value < 256, \
                "The 'version' field must be an unsigned integer in [0, 255]"
        self._version = value

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
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved0' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved0' field must be an unsigned integer in [0, 255]"
        self._reserved0 = value

    @builtins.property
    def iod_nav(self):
        """Message field 'iod_nav'."""
        return self._iod_nav

    @iod_nav.setter
    def iod_nav(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'iod_nav' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'iod_nav' field must be an unsigned integer in [0, 65535]"
        self._iod_nav = value

    @builtins.property
    def delta_n(self):
        """Message field 'delta_n'."""
        return self._delta_n

    @delta_n.setter
    def delta_n(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'delta_n' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'delta_n' field must be an integer in [-32768, 32767]"
        self._delta_n = value

    @builtins.property
    def m0(self):
        """Message field 'm0'."""
        return self._m0

    @m0.setter
    def m0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm0' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'm0' field must be an integer in [-2147483648, 2147483647]"
        self._m0 = value

    @builtins.property
    def e(self):
        """Message field 'e'."""
        return self._e

    @e.setter
    def e(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'e' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'e' field must be an unsigned integer in [0, 4294967295]"
        self._e = value

    @builtins.property
    def sqrt_a(self):
        """Message field 'sqrt_a'."""
        return self._sqrt_a

    @sqrt_a.setter
    def sqrt_a(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sqrt_a' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sqrt_a' field must be an unsigned integer in [0, 4294967295]"
        self._sqrt_a = value

    @builtins.property
    def omega0(self):
        """Message field 'omega0'."""
        return self._omega0

    @omega0.setter
    def omega0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'omega0' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'omega0' field must be an integer in [-2147483648, 2147483647]"
        self._omega0 = value

    @builtins.property
    def i0(self):
        """Message field 'i0'."""
        return self._i0

    @i0.setter
    def i0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'i0' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'i0' field must be an integer in [-2147483648, 2147483647]"
        self._i0 = value

    @builtins.property
    def omega(self):
        """Message field 'omega'."""
        return self._omega

    @omega.setter
    def omega(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'omega' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'omega' field must be an integer in [-2147483648, 2147483647]"
        self._omega = value

    @builtins.property
    def omega_dot(self):
        """Message field 'omega_dot'."""
        return self._omega_dot

    @omega_dot.setter
    def omega_dot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'omega_dot' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'omega_dot' field must be an integer in [-2147483648, 2147483647]"
        self._omega_dot = value

    @builtins.property
    def i_dot(self):
        """Message field 'i_dot'."""
        return self._i_dot

    @i_dot.setter
    def i_dot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'i_dot' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'i_dot' field must be an integer in [-32768, 32767]"
        self._i_dot = value

    @builtins.property
    def cuc(self):
        """Message field 'cuc'."""
        return self._cuc

    @cuc.setter
    def cuc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cuc' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'cuc' field must be an integer in [-32768, 32767]"
        self._cuc = value

    @builtins.property
    def cus(self):
        """Message field 'cus'."""
        return self._cus

    @cus.setter
    def cus(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cus' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'cus' field must be an integer in [-32768, 32767]"
        self._cus = value

    @builtins.property
    def crc(self):
        """Message field 'crc'."""
        return self._crc

    @crc.setter
    def crc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'crc' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'crc' field must be an integer in [-32768, 32767]"
        self._crc = value

    @builtins.property
    def crs(self):
        """Message field 'crs'."""
        return self._crs

    @crs.setter
    def crs(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'crs' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'crs' field must be an integer in [-32768, 32767]"
        self._crs = value

    @builtins.property
    def cic(self):
        """Message field 'cic'."""
        return self._cic

    @cic.setter
    def cic(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cic' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'cic' field must be an integer in [-32768, 32767]"
        self._cic = value

    @builtins.property
    def cis(self):
        """Message field 'cis'."""
        return self._cis

    @cis.setter
    def cis(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cis' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'cis' field must be an integer in [-32768, 32767]"
        self._cis = value

    @builtins.property
    def toe(self):
        """Message field 'toe'."""
        return self._toe

    @toe.setter
    def toe(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'toe' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'toe' field must be an unsigned integer in [0, 65535]"
        self._toe = value

    @builtins.property
    def af0(self):
        """Message field 'af0'."""
        return self._af0

    @af0.setter
    def af0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'af0' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'af0' field must be an integer in [-2147483648, 2147483647]"
        self._af0 = value

    @builtins.property
    def af1(self):
        """Message field 'af1'."""
        return self._af1

    @af1.setter
    def af1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'af1' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'af1' field must be an integer in [-2147483648, 2147483647]"
        self._af1 = value

    @builtins.property
    def af2(self):
        """Message field 'af2'."""
        return self._af2

    @af2.setter
    def af2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'af2' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'af2' field must be an integer in [-128, 127]"
        self._af2 = value

    @builtins.property
    def sisaindex_e1_e5b(self):
        """Message field 'sisaindex_e1_e5b'."""
        return self._sisaindex_e1_e5b

    @sisaindex_e1_e5b.setter
    def sisaindex_e1_e5b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sisaindex_e1_e5b' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sisaindex_e1_e5b' field must be an unsigned integer in [0, 255]"
        self._sisaindex_e1_e5b = value

    @builtins.property
    def toc(self):
        """Message field 'toc'."""
        return self._toc

    @toc.setter
    def toc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'toc' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'toc' field must be an unsigned integer in [0, 65535]"
        self._toc = value

    @builtins.property
    def bgd_e1_e5b(self):
        """Message field 'bgd_e1_e5b'."""
        return self._bgd_e1_e5b

    @bgd_e1_e5b.setter
    def bgd_e1_e5b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'bgd_e1_e5b' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'bgd_e1_e5b' field must be an integer in [-32768, 32767]"
        self._bgd_e1_e5b = value

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
    def health_e1b(self):
        """Message field 'health_e1b'."""
        return self._health_e1b

    @health_e1b.setter
    def health_e1b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'health_e1b' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'health_e1b' field must be an unsigned integer in [0, 255]"
        self._health_e1b = value

    @builtins.property
    def data_validity_e1b(self):
        """Message field 'data_validity_e1b'."""
        return self._data_validity_e1b

    @data_validity_e1b.setter
    def data_validity_e1b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'data_validity_e1b' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'data_validity_e1b' field must be an unsigned integer in [0, 255]"
        self._data_validity_e1b = value

    @builtins.property
    def health_e5b(self):
        """Message field 'health_e5b'."""
        return self._health_e5b

    @health_e5b.setter
    def health_e5b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'health_e5b' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'health_e5b' field must be an unsigned integer in [0, 255]"
        self._health_e5b = value

    @builtins.property
    def data_validity_e5b(self):
        """Message field 'data_validity_e5b'."""
        return self._data_validity_e5b

    @data_validity_e5b.setter
    def data_validity_e5b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'data_validity_e5b' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'data_validity_e5b' field must be an unsigned integer in [0, 255]"
        self._data_validity_e5b = value

    @builtins.property
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved2' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'reserved2' numpy.ndarray() must have a size of 4"
            self._reserved2 = value
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved2' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved2 = numpy.array(value, dtype=numpy.uint8)
