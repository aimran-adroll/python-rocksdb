#include "urocksdb.hpp"


namespace py = pybind11;


void init_compression_types(py::module& m) {
  
  py::enum_<rocksdb::CompressionType>(m, "CompressionType")
    .value("zstd_compression", rocksdb::CompressionType::kZSTD)
    .value("snappy_compression", rocksdb::CompressionType::kSnappyCompression)
    .export_values();

};
