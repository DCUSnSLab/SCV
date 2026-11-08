from setuptools import find_packages
from setuptools import setup

package_name = 'radio_map'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nev',
    maintainer_email='pcdpcd100@gmail.com',
    description='Builds a map of link quality by place from recorded LinkQuality messages',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'build_radio_map = radio_map.build:main',
        ],
    },
)
