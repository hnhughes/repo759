#include <cuda.h>
#include <iostream>
#include <cstdio>
#include <random>

__global__ void slope(int* arr, int numa)
{
    arr[ threadIdx.x + blockIdx.x * 8] = numa * threadIdx.x + blockIdx.x;
}

int main (int argc, char* argv[]) {
    //From the host, allocates an array of 16 ints on the device called dA
    const int arraySize = 16;
    int hA[arraySize], *dA;

    //Generate the random number to send to the kernel
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand
    std::uniform_int_distribution<int> dist(1, 10);
    int a = dist(gen);

    //Allocate the memory
    cudaMalloc((void**)&dA, sizeof(int) * arraySize);
    cudaMemset(dA, 0, arraySize * sizeof(int));

    //Invoke the kernel with a
    slope<<<2,8>>>(dA, a);

    //Copy the device array to the host array
    cudaMemcpy(hA, dA, sizeof(int) * arraySize, cudaMemcpyDeviceToHost);

    for (int i=0; i<16; i++){
        std::printf("%d\n", hA[i]);
    }

    //MAKE SURE TO DEALLOCATE THE MEMORY WHEN DONE
    delete[] hA;
    cudaFree(dA);

    return 0;
}