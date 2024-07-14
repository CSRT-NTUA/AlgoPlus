from setuptools import setup, find_packages

VERSION = '1.0.1'
DESCRIPTION = 'AlgoPlus is a C++17 library for complex data structures and algorithms'

setup(
    name="AlgoPlus-python",
    version=VERSION,
    author="Spiros Maggioros and the CSRT-NTUA team",
    author_email="<spirosmag@ieee.org>",
    description=DESCRIPTION,
    packages=find_packages()
)
