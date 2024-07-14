#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>

#include "../../../src/classes/tree/avl_tree.h"
#include "../../../src/classes/tree/234_tree.h"
#include "../../../src/classes/tree/interval_tree.h"
#include "../../../src/classes/tree/bst.h"
#include "../../../src/classes/tree/trie.h"
#include "../../../src/classes/tree/splay_tree.h"

namespace py = pybind11;

template <typename T>
void ttf_tree_class_handler(py::module &m, const std::string &typestr) {
    using ttf_class = ttf_tree<T>;
    std::string pyclass_name = "ttf_tree_" + typestr;
    py::class_<ttf_class>(m, pyclass_name.c_str())
    .def(py::init<std::vector<T>>())
        .def("insert", &ttf_class::insert)
        .def("search", &ttf_class::search)
        .def("size", &ttf_class::size)
        .def("level_order", &ttf_class::level_order);
}

template <typename T>
void bst_class_handler(py::module &m, const std::string &typestr) {
    using bst_class = bst<T>;
    std::string pyclass_name = "bst_" + typestr;
    py::class_<bst_class>(m, pyclass_name.c_str())
        .def(py::init<std::vector<T>>())
        .def("insert", &bst_class::insert)
        .def("search", &bst_class::search)
        .def("remove", &bst_class::remove)
        .def("begin", &bst_class::begin)
        .def("end", &bst_class::end)
        .def("size", &bst_class::size)
        .def("inorder", &bst_class::inorder)
        .def("preorder", &bst_class::preorder)
        .def("postorder", &bst_class::postorder)
        .def("level_order", &bst_class::level_order)
        .def("visualize", &bst_class::visualize);
}

template <typename T>
void avl_class_handler(py::module &m, const std::string &typestr) {
    using avl_class = avl_tree<T>;
    std::string pyclass_name = "avl_" + typestr;
    py::class_<avl_class>(m, pyclass_name.c_str())
        .def(py::init<std::vector<T>>())
        .def("insert", &avl_class::insert)
        .def("search", &avl_class::search)
        .def("remove", &avl_class::remove)
        .def("begin", &avl_class::begin)
        .def("end", &avl_class::end)
        .def("size", &avl_class::size)
        .def("inorder", &avl_class::inorder)
        .def("preorder", &avl_class::preorder)
        .def("postorder", &avl_class::postorder)
        .def("level_order", &avl_class::level_order)
        .def("visualize", &avl_class::visualize);
}

template <typename T>
void interval_tree_class_handler(py::module &m, const std::string &typestr) {
    using interval_class = interval_tree<T>;
    std::string pyclass_name = "interval_tree_" + typestr;
    py::class_<interval_class>(m, pyclass_name.c_str())
    .def(py::init<std::vector<std::pair<T, T>>>())
        .def("insert", &interval_class::insert)
        .def("search", &interval_class::search)
        .def("remove", &interval_class::remove)
        .def("begin", &interval_class::begin)
        .def("end", &interval_class::end)
        .def("size", &interval_class::size)
        .def("inorder", &interval_class::inorder)
        .def("preorder", &interval_class::preorder)
        .def("postorder", &interval_class::postorder)
        .def("level_order", &interval_class::level_order)
        .def("visualize", &interval_class::visualize);
}

template <typename T>
void splay_tree_class_handler(py::module &m, const std::string &typestr) {
    using splay_class = splay_tree<T>;
    std::string pyclass_name = "splay_tree_" + typestr;
    py::class_<splay_class>(m, pyclass_name.c_str())
        .def(py::init<std::vector<T>>())
        .def("insert", &splay_class::insert)
        .def("search", &splay_class::search)
        .def("remove", &splay_class::remove)
        .def("begin", &splay_class::begin)
        .def("end", &splay_class::end)
        .def("size", &splay_class::size)
        .def("inorder", &splay_class::inorder)
        .def("preorder", &splay_class::preorder)
        .def("postorder", &splay_class::postorder)
        .def("level_order", &splay_class::level_order)
        .def("visualize", &splay_class::visualize);
}


void trie_tree_class_handler(py::module &m, const std::string &typestr) {
    std::string pyclass_name = "trie";
    py::class_<trie>(m, pyclass_name.c_str())
    .def(py::init<std::vector<std::string>>())
        .def("insert", &trie::insert)
        .def("search", &trie::search)
        .def("remove", &trie::remove)
        .def("empty", &trie::empty)
        .def("size", &trie::size);
}


PYBIND11_MODULE(tree, m) {
  avl_class_handler<int>(m, "int");
  avl_class_handler<float>(m, "float");
  avl_class_handler<double>(m, "double");
  avl_class_handler<char>(m, "char");

  bst_class_handler<int>(m, "int");
  bst_class_handler<float>(m, "float");
  bst_class_handler<double>(m, "double");
  bst_class_handler<char>(m, "char");

  ttf_tree_class_handler<int>(m, "int");
  ttf_tree_class_handler<float>(m, "float");
  ttf_tree_class_handler<double>(m, "double");
  ttf_tree_class_handler<char>(m, "char");

  interval_tree_class_handler<int>(m, "int");
  interval_tree_class_handler<float>(m, "float");
  interval_tree_class_handler<double>(m, "double");
  interval_tree_class_handler<char>(m, "char");

  splay_tree_class_handler<int>(m, "int");
  splay_tree_class_handler<float>(m, "float");
  splay_tree_class_handler<double>(m, "double");
  splay_tree_class_handler<char>(m, "char");
  
  trie_tree_class_handler(m, "string");
}
