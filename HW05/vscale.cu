#include "vscale.cuh"
#include <cuda.h>
#include <iostream>
#include <cstdio>


__global__ void vscale(const float *a, float *b, unsigned int n){
    for (int i=0; i<n; i++){
        b[i]*=a[i];
    }
    std::printf("%f\n", b[ threadIdx.x + 1]);
}