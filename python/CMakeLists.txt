cmake_minimum_required(VERSION 3.4)
project(AlgoPlus-python VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(pybind11)

# build tree files for import tree 
file(GLOB_RECURSE ALL_TREE_FILES "classes/tree/*.cc")
pybind11_add_module(tree ${ALL_TREE_FILES})
