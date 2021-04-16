from python:3.7.10-slim-buster

# update
RUN apt-get update -y && apt-get install -y \
  # git
  git \
	# Install cmake
	cmake \
	# Install python
	python3-dev python3-pip \ 
	# Install gflags
	libgflags-dev \ 
	# Install snappy
	libsnappy-dev \
	# Install zlib
	zlib1g-dev \
	# Install bzip2
	libbz2-dev \
	# Install lz4
	liblz4-dev \
	# Install zstandard
	libzstd-dev

RUN python -m pip install --upgrade pip setuptools wheel twine \ 
    pip install flake8 pytest


#RUN git clone https://github.com/aimran-adroll/python-rocksdb.git --recursive -b pybind11-exp-add-ingest 
#WORKDIR /python-rocksdb

#RUN python setup.py install

ENTRYPOINT ["/bin/bash"]
