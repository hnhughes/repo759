

//Launches a kernel with 2 blocks, each block having 8 threads.
//Each thread computes ax+y and writes the result in one distinct entry of the dA array. Here,
//x is the thread’s threadIdx;
//y is the thread’s blockIdx;
//a is an integer argument that the kernel takes (so all threads use the same a). You need
//to generate a randomly and then call the kernel with it. It is up to you how you generate
//this random number, one possible approach is described here BestPractice.
//Copies back the data stored in the device array dA into a host array called hA.
//Prints (from the host) the 16 values stored in the host array separated by a single space each.
int main (int argc, char* argv[]) {
    //From the host, allocates an array of 16 ints on the device called dA.
    int *hostArray
    const int arraySize = 8;
    int *hostArray, *devArray;
    for (int i = 0; i < arraySize; i++){
        hostArray[i] = i+1;
    }
    //allocate memory on the device (GPU); zero out all entries in this device array
    cudaMalloc((void**)&devArray, sizeof(int) * arraySize);
    cudaMemcpy(devArray, hostArray, sizeof(int) * arraySize, cudaMemcpyHostToDevice);

    //Send data from the CPU to the GPU
    factorial<<<1, 8>>>(devArray, arraySize);

    //Wait for the kernal to finish printing before returning to main
    cudaDeviceSynchronize();

    //Send the result of the GPU back to the CPU
    cudaMemcpy(hostArray, devArray, sizeof(int) * arraySize, cudaMemcpyDeviceToHost);

    //Deallocate memory
    cleanupHost(hostArray);
    cleanupDevice(devArray);

    return 0;
}