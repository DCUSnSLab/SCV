"""Turn config/cameras.yaml and the robot URDF into node parameters, remaps and static TF."""

import math
import xml.etree.ElementTree as ET

import numpy as np

OPTICAL_RPY = (-math.pi / 2, 0.0, -math.pi / 2)


def _rpy_matrix(roll, pitch, yaw):
    cr, sr, cp, sp, cy, sy = (
        math.cos(roll),
        math.sin(roll),
        math.cos(pitch),
        math.sin(pitch),
        math.cos(yaw),
        math.sin(yaw),
    )
    return np.array(
        [
            [cy * cp, cy * sp * sr - sy * cr, cy * sp * cr + sy * sr],
            [sy * cp, sy * sp * sr + cy * cr, sy * sp * cr - cy * sr],
            [-sp, cp * sr, cp * cr],
        ]
    )


def _joint_transform(joint):
    origin = joint.find('origin')
    xyz = [float(v) for v in origin.get('xyz', '0 0 0').split()]
    rpy = [float(v) for v in origin.get('rpy', '0 0 0').split()]
    transform = np.eye(4)
    transform[:3, :3] = _rpy_matrix(*rpy)
    transform[:3, 3] = xyz
    return transform


def _quaternion(r):
    w = math.sqrt(max(0.0, 1.0 + r[0, 0] + r[1, 1] + r[2, 2])) / 2.0
    x = math.copysign(
        math.sqrt(max(0.0, 1.0 + r[0, 0] - r[1, 1] - r[2, 2])) / 2.0, r[2, 1] - r[1, 2]
    )
    y = math.copysign(
        math.sqrt(max(0.0, 1.0 - r[0, 0] + r[1, 1] - r[2, 2])) / 2.0, r[0, 2] - r[2, 0]
    )
    z = math.copysign(
        math.sqrt(max(0.0, 1.0 - r[0, 0] - r[1, 1] + r[2, 2])) / 2.0, r[1, 0] - r[0, 1]
    )
    return [x, y, z, w]


def urdf_mounts(urdf, base, frames):
    """Return {frame: [x, y, z, qx, qy, qz, qw]} of each frame relative to base."""
    joints = {j.find('child').get('link'): j for j in ET.fromstring(urdf).findall('joint')}
    mounts = {}
    for frame in frames:
        transform = np.eye(4)
        link = frame
        while link != base:
            joint = joints[link]
            transform = _joint_transform(joint) @ transform
            link = joint.find('parent').get('link')
        mounts[frame] = [float(v) for v in transform[:3, 3]] + _quaternion(transform[:3, :3])
    return mounts


def resolve_instances(config, names):
    """Expand group names; keep the config order and drop duplicates."""
    wanted = set()
    for name in names:
        wanted.update(config['groups'].get(name, [name]))
    unknown = wanted - set(config['instances'])
    if unknown:
        raise RuntimeError(f'unknown cameras: {sorted(unknown)}')
    return [name for name in config['instances'] if name in wanted]


def camera_node_config(config, name):
    """Return (parameters, remappings) of the camera_dummy instance called name."""
    instance = config['instances'][name]
    model = config['models'][instance['model']]
    prefix = instance.get('frame_prefix', name)
    root = instance['root']
    parameters = {'streams': list(model['streams'])}
    remappings = []
    for stream, spec in model['streams'].items():
        for key, value in spec.items():
            if key not in ('topic', 'info_topic'):
                text = value.format(name=prefix) if isinstance(value, str) else value
                parameters[f'stream.{stream}.{key}'] = text
        parameters[f'stream.{stream}.plane_m'] = config['pattern']['plane_m']
        parameters[f'stream.{stream}.bar_m'] = config['pattern']['bar_m']
        remappings.append((f'~/output/{stream}/image', f'{root}/{spec["topic"]}'))
        remappings.append((f'~/output/{stream}/camera_info', f'{root}/{spec["info_topic"]}'))
    imu = model.get('imu')
    parameters['imu.enable'] = imu is not None
    if imu is not None:
        parameters['imu.frame_id'] = imu['frame_id'].format(name=prefix)
        parameters['imu.rate_hz'] = imu['rate_hz']
        parameters['imu.linear_acceleration'] = imu['linear_acceleration']
        remappings.append(('~/output/imu', f'{root}/{imu["topic"]}'))
    return parameters, remappings


def _joint(parent, child, xyz, rpy):
    return (
        f'<joint name="{child}_joint" type="fixed"><parent link="{parent}"/>'
        f'<child link="{child}"/><origin xyz="{" ".join(map(str, xyz))}" '
        f'rpy="{" ".join(map(str, rpy))}"/></joint>'
    )


def camera_frames_urdf(config, names, base):
    """Return a URDF with the frames of the instances that have a mount, or None."""
    links = [f'<link name="{base}"/>']
    joints = []
    for name in names:
        instance = config['instances'][name]
        model = config['models'][instance['model']]
        if 'root_frame' not in model:
            continue
        prefix = instance.get('frame_prefix', name)
        root_frame = model['root_frame'].format(name=prefix)
        mount = instance['mount']
        links.append(f'<link name="{root_frame}"/>')
        joints.append(_joint(base, root_frame, mount['xyz'], mount['rpy']))
        for frame in model['frames']:
            child = frame['child'].format(name=prefix)
            rpy = OPTICAL_RPY if frame.get('optical') else (0.0, 0.0, 0.0)
            links.append(f'<link name="{child}"/>')
            joints.append(
                _joint(
                    frame['parent'].format(name=prefix), child, frame.get('xyz', [0, 0, 0]), rpy
                )
            )
    if not joints:
        return None
    return f'<robot name="dummy_cameras">{"".join(links + joints)}</robot>'
