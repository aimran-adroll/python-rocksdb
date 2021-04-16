urocksdb
=========

![ci status](https://github.com/aimran-adroll/python-rocksdb/actions/workflows/main.yml/badge.svg)

Python bindings for RocksDB.

This project is under development, and more features are coming soon.

For any other usage, please follow https://twmht.github.io/python-rocksdb/index.html 

Quick Install
-------------

Quick install for debian/ubuntu like linux distributions.


```
git clone https://github.com/aimran-adroll/python-rocksdb.git --recursive -b  pybind11-exp-add-ingest 
cd python-rocksdb
python3 setup.py install
```

Quick Usage Guide
-----------------

```python
import urocksdb
db = urocksdb.DB()
opts = urocksdb.Options()
# for multi-thread
opts.IncreaseParallelism()
opts.OptimizeLevelStyleCompaction()
opts.create_if_missing = True
s = db.open(opts, '/path/to/db')
assert(s.ok())
# put
opts = urocksdb.WriteOptions()
s = db.put(opts, b"key1", b"value1")
assert (s.ok())
# get
opts = urocksdb.ReadOptions()
blob = db.get(opts, b"key1")
print (blob.data) # b"value1"
print (blob.status.ok()) # true
#delete
opts = urocksdb.WriteOptions()
s = db.delete(opts, b"key1")
assert(s.ok())
db.close()
```

### Complete example using external SST files

```python
import urocksdb as pb

e = pb.EnvOptions()
o = pb.Options()
ifo = pb.IngestExternalFileOptions()
ro = pb.ReadOptions()

#create micro ssts
for i in range(5,10):
    w = pb.SstFileWriter(e,o)
    s = w.open(f'/tmp/{i:03d}.sst')
    assert(s.ok())
    s = w.put(f'key_{i:03d}'.encode(), f'val_{i:03d}'.encode())
    assert(s.ok())
    s = w.finish()
    assert(s.ok())

o.create_if_missing = True
db = pb.DB()
s = db.open(o, "/tmp/roshgulla")
assert(s.ok())
sst_files = [f'/tmp/{i:03d}.sst' for i in range(5,10)]

#use the sst files
s = db.ingest_external_file(sst_files, ifo)
assert(s.ok())
db.close()

#verify
o.create_if_missing = False
db = pb.DB()
s = db.open(o, "/tmp/roshgulla")
assert(s.ok())
for i in range(5,10):
    blob = db.get(ro, f'key_{i:03d}')
    print(f'key_{i:03d}', " -- ", blob.data)

db.close()
```



