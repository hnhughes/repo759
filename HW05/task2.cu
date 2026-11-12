int main (int argc, char* argv[]) {
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