#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include "../../../src/classes/graph/graph.h"

namespace py = pybind11;

template <typename T>
void graph_handler(py::module &m, const std::string &typestr) {
    using graph_class = graph<T>;
    std::string pyclass_name = "graph_" + typestr;
    py::class_<graph_class>(m, pyclass_name.c_str())
    .def(py::init<std::string, std::vector<std::pair<T, std::vector<T>>>>())
    .def("add_edge", &graph_class::add_edge)
    .def("has_edge", &graph_class::has_edge)
    .def("clear", &graph_class::clear)
    .def("empty", &graph_class::empty)
    .def("size", &graph_class::size)
    .def("dfs", &graph_class::dfs)
    .def("bfs", &graph_class::bfs)
    .def("connected_components", &graph_class::connected_components)
    .def("cycle", &graph_class::cycle)
    .def("topological_sort", &graph_class::topological_sort)
    .def("bipartite", &graph_class::bipartite)
    .def("bridge", &graph_class::bridge)
    .def("scc", &graph_class::scc)
    .def("connected", &graph_class::connected)
    .def("eulerian", &graph_class::eulerian)
    .def("visualize", &graph_class::visualize);
}

template <typename T>
void weighted_graph_handler(py::module &m, const std::string &typestr) {
    using weighted_graph_class = weighted_graph<T>;
    std::string pyclass_name = "weighted_graph_" + typestr;
    py::class_<weighted_graph_class>(m, pyclass_name.c_str())
    .def(py::init<std::string, std::vector<std::pair<std::pair<T, T>, int64_t>>>())
    .def("add_edge", &weighted_graph_class::add_edge)
    .def("has_edge", &weighted_graph_class::has_edge)
    .def("clear", &weighted_graph_class::clear)
    .def("empty", &weighted_graph_class::empty)
    .def("size", &weighted_graph_class::size)
    .def("dfs", &weighted_graph_class::dfs)
    .def("bfs", &weighted_graph_class::bfs)
    .def("shortest_path", &weighted_graph_class::shortest_path)
    .def("connected_components", &weighted_graph_class::connected_components)
    .def("cycle", &weighted_graph_class::cycle)
    .def("topological_sort", &weighted_graph_class::topological_sort)
    .def("prim", &weighted_graph_class::prim)
    .def("bipartite", &weighted_graph_class::bipartite)
    .def("bridge", &weighted_graph_class::bridge)
    .def("scc", &weighted_graph_class::scc)
    .def("connected", &weighted_graph_class::connected)
    .def("eulerian", &weighted_graph_class::eulerian)
    .def("bellman_ford", &weighted_graph_class::bellman_ford)
    .def("visualize", &weighted_graph_class::visualize);
}

PYBIND11_MODULE(graph, m) {
    graph_handler<int>(m, "int");
    graph_handler<float>(m, "float");
    graph_handler<double>(m, "double");
    graph_handler<int64_t>(m, "int64");

    weighted_graph_handler<int>(m, "int");
    weighted_graph_handler<float>(m, "float");
    weighted_graph_handler<double>(m, "double");
    weighted_graph_handler<int64_t>(m, "int64");
}