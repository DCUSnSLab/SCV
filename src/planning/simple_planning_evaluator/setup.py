from glob import glob

from setuptools import find_packages
from setuptools import setup

package_name = 'simple_planning_evaluator'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', glob('config/*.yaml')),
        ('share/' + package_name + '/launch', glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    tests_require=['pytest'],
    zip_safe=True,
    maintainer='nevlife',
    maintainer_email='nevlife000720@gmail.com',
    description='Online planning quality metrics for simple_mppi_planner',
    license='Proprietary',
    entry_points={
        'console_scripts': [
            'simple_planning_evaluator_node = simple_planning_evaluator.simple_planning_evaluator_node:main',
        ],
    },
)
