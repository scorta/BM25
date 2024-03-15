#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "header/BM25.hpp"
#include "header/text.hpp"
#include "header/utility.hpp"

namespace py = pybind11;

PYBIND11_MODULE(bm25, m) {
    py::class_<Text>(m, "Text")
        .def(py::init<const std::string&>())
        .def_readwrite("content", &Text::content)
        .def_readwrite("tokens", &Text::tokens);

    py::class_<Document, Text>(m, "Document")
        .def(py::init<const std::string&>())
        .def_readwrite("score", &Document::score);

    py::class_<BM25>(m, "BM25")
        .def(py::init<const std::vector<Text>&, const std::vector<Document>&>())
        .def("score", &BM25::score);

    m.def("remove_vn_tone", &utility::remove_vn_tone);
    m.def("remove_meaningless_char", &utility::remove_meaningless_char);
}