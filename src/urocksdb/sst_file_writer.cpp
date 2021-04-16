#include <pybind11/pybind11.h>
#include "urocksdb.hpp"

namespace py = pybind11;

class PySstFileWriter: public SstFileWriter{

  public:

    using SstFileWriter::SstFileWriter;

    Status Open(const std::string& filepath) {
      return SstFileWriter::Open(filepath);
    }

    Status Put(const std::string& user_key, const std::string& value) {
      return SstFileWriter::Put(user_key, value); 
    }

    Status Merge(const std::string& user_key, const std::string& value) {
      return SstFileWriter::Merge(user_key, value);
    }

    Status Finish() {
      return SstFileWriter::Finish(nullptr);
    }

};

void init_sst_file_writer(py::module & m) {
  py::class_<SstFileWriter>(m, "_SstFileWriter");
  py::class_<PySstFileWriter, SstFileWriter>(m, "SstFileWriter")
    .def(py::init([] (const EnvOptions& e, const Options& o) {
          return std::unique_ptr<PySstFileWriter>(new PySstFileWriter(e, o, nullptr, true, Env::IOPriority::IO_TOTAL, false));}))
    .def("open", (Status (PySstFileWriter::*) (const std::string&)) &PySstFileWriter::Open)
    .def("put", (Status (PySstFileWriter::*) (const std::string&, const std::string&)) &PySstFileWriter::Put)
    .def("merge", (Status (PySstFileWriter::*) (const std::string&, const std::string&)) &PySstFileWriter::Merge)
    .def("finish", (Status (PySstFileWriter::*) ()) &PySstFileWriter::Finish);
}
