#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

#include "../../../src/classes/disjoint_set/disjoint_set.h"

namespace py = pybind11;

void disjoint_set_handler(py::module &m) {
  using disjoint_class = dsu;
  std::string pyclass_name = "disjoint_set";
  py::class_<disjoint_class>(m, pyclass_name.c_str())
    .def(py::init<int>())
    .def("find", &disjoint_class::find)
    .def("join", &disjoint_class::join)
    .def("same", &disjoint_class::same)
    .def("get", &disjoint_class::get)
    .def("size", &disjoint_class::size)
    .def("get_max", &disjoint_class::get_max)
    .def("get_min", &disjoint_class::get_min);
}


PYBIND11_MODULE(dsu, m) {
  disjoint_set_handler(m);
}

