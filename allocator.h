#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <cuda_runtime_api.h>

namespace pytorch_malloc {

class Allocator {
 public:
  Allocator();
  ~Allocator();

  static Allocator *Instance() {
    static Allocator *allocator = new Allocator();
    return allocator;
  }

  cudaError_t malloc(void **devPtr, size_t size);
  cudaError_t free(void *devPtr);

 private:
  void *devPtr_ = nullptr;
};

}  // namespace pytorch_malloc

#endif  // ALLOCATOR_H