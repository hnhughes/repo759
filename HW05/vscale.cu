#include "vscale.cuh"
#include <cuda.h>


__global__ void vscale(const float *a, float *b, unsigned int n){
    int whichEntry = threadIdx.x + blockIdx.x * blockDim.x;
    if( whichEntry< n )
    b[whichEntry] *=a [whichEntry];
}