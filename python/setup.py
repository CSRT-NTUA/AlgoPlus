from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension, build_ext
import os

root = os.path.abspath(os.path.dirname(__file__))

VERSION = '1.0.1'
DESCRIPTION = 'AlgoPlus is a C++17 library for complex data structures and algorithms'

ext_modules = [
    Pybind11Extension(
        "algoplus_py.tree",
        ["classes/tree/tree.cc"],
        define_macros=[("VERSION_INFO", VERSION)],
    ),
]

setup(
    name="algoplus_py",
    version=VERSION,
    author="Spiros Maggioros and the CSRT-NTUA team",
    author_email="spirosmag@ieee.org",
    description=DESCRIPTION,
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    packages=find_packages(),
    python_requires=">=3.8",
)
