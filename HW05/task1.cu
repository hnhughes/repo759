//Computes the factorial of integers from 1-8
//using a GPU kernel with one block and 8 threads
#include <cuda.h>
#include <iostream>
#include <cstdio>

__global__ void factorial(){
    int product = 1;
    for (int i = 1; i < 9; i++){
        product = product * i;
        std::printf("%d!=%d\n", i, product);
    }
}

int main (int argc, char* argv[]) {

    factorial<<<1, 8>>>();
    cudaDeviceSynchronize();

    return 0;
}