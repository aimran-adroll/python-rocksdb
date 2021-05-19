#include <pybind11/pybind11.h>
#include "urocksdb.hpp"

namespace py = pybind11;

class PySstFileReader: public SstFileReader{

  public:

    using SstFileReader::SstFileReader;

    Status Open(const std::string& filepath) {
      return SstFileReader::Open(filepath);
    }

    std::unique_ptr<IteratorWrapper> NewIterator(const ReadOptions& options) {
      return std::unique_ptr<IteratorWrapper>(new IteratorWrapper(SstFileReader::NewIterator(options))); 
    }

};

void init_sst_file_reader(py::module & m) {
  py::class_<SstFileReader>(m, "_SstFileReader");
  py::class_<PySstFileReader, SstFileReader>(m, "SstFileReader")
    .def(py::init([] (const Options& o) {
          return std::unique_ptr<PySstFileReader>(new PySstFileReader(o));}))
    .def("open", (Status (PySstFileReader::*) (const std::string&)) &PySstFileReader::Open)
    .def("iterator", &PySstFileReader::NewIterator);
}
