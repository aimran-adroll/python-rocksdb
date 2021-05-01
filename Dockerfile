from python:3.7.10-slim-buster

# update
RUN apt-get update -y && apt-get install -y \
  git python3-dev python3-pip cmake libsnappy-dev liblz4-dev libzstd-dev libgflags-dev 

#RUN python -m pip install --upgrade pip setuptools wheel twine \ 
#    pip install flake8 pytest

#RUN python setup.py install

ENTRYPOINT ["/bin/bash"]
