#include <cuda.h>
#include <iostream>
#include <cstdio>
#include <random>
#include "vscale.cuh"

int main(int argc, char *argv[]){
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    //Reading the arguments
    int n = std::atoi(argv[1]);

    //Declaring arrays
    float* a = new float[n];
    float* b = new float[n];
    float *devA, *devB;

    //Generating random numbers
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand
    std::uniform_real_distribution<float> dist_a(-10.0f, 10.0f);
    std::uniform_real_distribution<float> dist_b(0.0f, 1.0f);

    //Fill the arrays
    for (int i=0; i<n; i++){
        a[i] = dist_a(gen);
        b[i] = dist_b(gen);
    }

    //Need to pass a, b and n to the kernel
    cudaMalloc((void**)&devA, sizeof(int) * n);
    cudaMalloc((void**)&devB, sizeof(int) * n);
    cudaMemcpy(devA, a, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(devB, b, n * sizeof(int), cudaMemcpyHostToDevice);

    const int threadsPerBlock = 512;
    const int blocksPerGrid = (n + threadsPerBlock - 1)/threadsPerBlock;
    vscale<<<blocksPerGrid, threadsPerBlock>>>(devA, devB, n);

    cudaMemcpy(b, devB, sizeof(int) * n, cudaMemcpyDeviceToHost);

    delete[] a;
    delete[] b;
    cudaFree(devA);
    cudaFree(devB);

    return 0;
}