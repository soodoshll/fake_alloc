libcudart.so:
	nvcc cudart.cc allocator.cc cnmem/cnmem.cpp --compiler-options '-fPIC' -shared --cudart=none -o libcudart.so