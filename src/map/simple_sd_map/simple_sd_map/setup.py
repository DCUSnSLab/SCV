from glob import glob

from setuptools import find_packages, setup

package_name = 'simple_sd_map'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    tests_require=['pytest'],
    zip_safe=True,
    maintainer='nevlife',
    maintainer_email='nevlife000720@gmail.com',
    description='Publishes an OSM SD map in the map frame',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'simple_sd_map_node = simple_sd_map.simple_sd_map_node:main',
        ],
    },
)
