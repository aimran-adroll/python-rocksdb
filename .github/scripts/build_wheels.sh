#!/bin/bash


set -e
set -x



apt-get install -y \
  cmake \
  libgflags-dev libsnappy-dev liblz4-dev libzstd-dev


python -m pip install cibuildwheel
python -m cibuildwheel --output-dir wheelhouse
