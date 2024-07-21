cmake_minimum_required(VERSION 3.4)
project(AlgoPlus-python VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(pybind11)

if(APPLE)
  set_target_properties(${MODULE} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
endif(APPLE)

# Build tree files for import tree 
file(GLOB_RECURSE ALL_TREE_FILES "classes/tree/*.cc")
file(GLOB_RECURSE ALL_DSU_FILES "classes/disjoint_set/*.cc")
file(GLOB_RECURSE ALL_GRAPH_FILES "classes/graph/*.cc")

pybind11_add_module(tree ${ALL_TREE_FILES})
pybind11_add_module(dsu ${ALL_DSU_FILES})
pybind11_add_module(graph ${ALL_GRAPH_FILES})
