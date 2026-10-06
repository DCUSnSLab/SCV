from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'bring_up'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
         glob(os.path.join('launch', '*.launch.py'))
         + glob(os.path.join('launch', '*.launch.xml'))
         + glob(os.path.join('launch', '*.launch.yaml'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='scv',
    maintainer_email='pcdpcd100@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'd555_velodyne_bev = bring_up.d555_velodyne_bev:main',
        ],
    },
)
