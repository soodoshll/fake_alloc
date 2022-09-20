libcudart.so:
	nvcc cudart.cc allocator.cc cnmem/cnmem.cpp --compiler-options '-fPIC' -shared --cudart=none -o fake_libcudart.so

fake_alloc.so:
	c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) fake_alloc.cc -o fake_alloc.so

all: libcudart.so fake_alloc.so