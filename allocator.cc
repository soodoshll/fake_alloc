#include <stdio.h>
#include <dlfcn.h>

#include <iostream>

#include "allocator.h"
#include "cnmem/cnmem.h"

namespace pytorch_malloc {

cudaError_t cnmemStatus2cudaError(cnmemStatus_t status) {
  switch (status) {
    case CNMEM_STATUS_SUCCESS:
      return cudaSuccess;
    case CNMEM_STATUS_CUDA_ERROR:
      return cudaErrorUnknown;
    case CNMEM_STATUS_INVALID_ARGUMENT:
      return cudaErrorInvalidValue;
    case CNMEM_STATUS_NOT_INITIALIZED:
      return cudaErrorInitializationError;
    case CNMEM_STATUS_OUT_OF_MEMORY:
      return cudaErrorMemoryAllocation;
    case CNMEM_STATUS_UNKNOWN_ERROR:
      return cudaErrorUnknown;
    default:
      return cudaErrorUnknown;
  }
}

Allocator::Allocator() {
  cnmemDevice_t device;
  device.device = 0;
  device.size = 0;
  device.numStreams = 0;
  device.streams = NULL;
  *(device.streamSizes) = 0;
  cnmemInit(1, &device, 0);
}

Allocator::~Allocator() {
  cnmemFinalize();
}

cudaError_t Allocator::malloc(void **devPtr, size_t size) {
  cnmemStatus_t status = cnmemMalloc(devPtr, size, NULL);
  return cnmemStatus2cudaError(status);
}


cudaError_t Allocator::free(void *devPtr) {
  cnmemStatus_t status = cnmemFree(devPtr, NULL);
  return cnmemStatus2cudaError(status);
}

}  // end pytorch_malloc
