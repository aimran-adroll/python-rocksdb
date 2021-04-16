#include <pybind11/pybind11.h>
#include <iostream>
#include "urocksdb.hpp"

namespace py = pybind11;

void init_slice(py::module & m) {
  py::class_<Slice>(m, "Slice");
}
