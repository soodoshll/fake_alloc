# Custom PyTorch Memory Management

Compile with `nvcc`:

```bash
cd pytorch_malloc
make
```

Note that we need `--cudart=none` to prevent linking the static libcudart.so.

For more information about the nvcc flags: https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/index.html

To make pytorch allocate without the inherit caching mechanism, run with `PYTORCH_NO_CUDA_MEMORY_CACHING`:

```bash
LD_PRELOAD=./libcudart.so PYTORCH_NO_CUDA_MEMORY_CACHING=1 python3 your_model.py
```

## profile

Use the `profiler` branch to profile the memory usage of your model:

```bash
git checkout profiler
make
```

Run the example script with:

```bash
> LD_PRELOAD=./libcudart.so PYTORCH_NO_CUDA_MEMORY_CACHING=1 python3 torch_example.py
start allocate 0
[Allocator] create allocator
[Allocator] free mem: 33094893568 B, total mem: 34089730048 B.
[Allocator] malloc(139996541485056): 64 B, time: 357 us.
end allocate 0
start allocate 1
[Allocator] malloc(139996541485568): 64 B, time: 639 us.
[Allocator] free(139996541485056): 64 B, time: 699 us.
end allocate 1
start allocate 2
[Allocator] malloc(139996541485056): 64 B, time: 754 us.
[Allocator] free(139996541485568): 64 B, time: 781 us.
end allocate 2
[Allocator] free(139996541485056): 64 B, time: 14273 us
```
