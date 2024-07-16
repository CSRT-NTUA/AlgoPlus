from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension, build_ext

VERSION = '1.0.1'
DESCRIPTION = 'AlgoPlus is a C++17 library for complex data structures and algorithms'


ext_modules = [
        Pybind11Extension(
            "tree",
            ["classes/tree/tree.cc"],
            define_macros=[("VERSION_INFO", VERSION)]
            ),
        ]

setup(
    name="algoplus_py",
    version=VERSION,
    author="Spiros Maggioros and the CSRT-NTUA team",
    author_email="<spirosmag@ieee.org>",
    description=DESCRIPTION,
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.8"
)
