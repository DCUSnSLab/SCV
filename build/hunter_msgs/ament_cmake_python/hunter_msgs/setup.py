from setuptools import find_packages
from setuptools import setup

setup(
    name='hunter_msgs',
    version='0.0.1',
    packages=find_packages(
        include=('hunter_msgs', 'hunter_msgs.*')),
)
