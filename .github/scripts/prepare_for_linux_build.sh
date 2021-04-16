#!/bin/bash

set -x
set -e


apt-get update -y && apt-get install -y \
  cmake \
  libsnappy-dev \
  liblz4-dev \
  libzstd-dev


git clone https://github.com/gflags/gflags.git
cd gflags
git checkout v2.2.2
cmake -DBUILD_SHARED_LIBS=ON .
make && make install
cd ..

