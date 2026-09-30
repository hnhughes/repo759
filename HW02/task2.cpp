#include "convolution.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>
#include <ratio>

int main(int argc, char *argv[]){
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    //Reading the arguments
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);

    //Setting up the random generator
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand

    //Creating the image matrix
    std::uniform_real_distribution<float> dist_n(-10.0f, 10.0f);    //set the distribution for the numbers to be generated
    float *image = new float[n*n];  //allocated an array of n*n floats at runtime
    for (int x=0; x<n; x++){
        for (int y=0; y<n; y++){
            image[x * n + y] = dist_n(gen);
        }
    }
 
    //Creating the mask matrix
    std::uniform_real_distribution<float> dist_m(-1.0f, 1.0f);    //set the distribution for the numbers to be generated
    float *mask = new float[m*m];  //allocated an array of n*n floats at runtime
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            mask[i * m + j] = dist_m(gen);
        }
    }

    //Apply mask to image using the convolve function
    float *output = new float[n*n];
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double, std::milli> duration_ms;

    start = std::chrono::high_resolution_clock::now(); //captures the timestamp before convolve is called
    convolve(image, output, static_cast<std::size_t>(n), mask, static_cast<std::size_t>(m));
    end = std::chrono::high_resolution_clock::now();   //captures the timestamp after convolve is called
    duration_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>> (end - start);    //comput the time elapsed in milliseconds
    
    //Printed outputs
    std::cout << duration_ms.count() << "\n";   //Print out the time taken for the convolve function in milliseconds
    std::cout << output[0] << "\n";             //Prints the first element of the output array
    std::cout << output[(n*n)-1] << "\n";       //Prints the last element of the convolve array
    
    //Deallocate memory 
    delete[] image;
    delete[] output;
    delete[] mask;
    return 0;
}