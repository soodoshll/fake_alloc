This repo is a memory footprint predictor(emulator) for cuda applications.

It is based on [pytorch-malloc](https://github.com/zhuzilin/pytorch-malloc/), a repo showing how to replace the pytorch memory allocator as a customized one.

### Usage

1. install ``pybind11``;
2. run ``build.sh``;
3. run ``LD_PRELOAD=./fake_libcudart.so python torch_example.py``
