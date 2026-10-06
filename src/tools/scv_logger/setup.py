from glob import glob

from setuptools import find_packages, setup

package_name = 'scv_logger'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml', 'README.md']),
        ('share/' + package_name + '/config', glob('config/*.yaml')),
        ('share/' + package_name + '/config/profiles', glob('config/profiles/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='backgroundmin',
    maintainer_email='zxc81808080@gmail.com',
    description='SCV 주행 로깅 GUI — 녹화 프로파일, 토픽 상태 감시, 세션 기록',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'scv_logger = scv_logger.gui.app:main',
            'scv_logger_monitor = scv_logger.ros.monitor_node:main',
            'scv_logger_scan = scv_logger.ros.scan:main',
        ],
    },
)
