#include "matmul.h"
#include <random> 
#include <iostream>
#include <chrono>
#include <array>

int main (int argc, char *argv[]){
    //Reading the arguments
    unsigned int n = std::atoi(argv[1]);
    int t = std::atoi(argv[2]);
    omp_set_num_threads(t);
    
    //Declare variables
    float* A = new float[n*n];
    float* B = new float[n*n];
    float* C = new float[n*n];

    //Setting up the random generator
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand
    std::uniform_real_distribution<float> dist(-3.0f, 3.0f);    //set the distribution for the numbers to be generated

    //Setup for timing
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double, std::milli> duration_ms;

    //Generate matrix A and Matrix B
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<n; j++){
            A[i * n + j] = dist(gen);
            B[i * n + j] = dist(gen);
            C[i * n + j] = 0.0f;   //Initialize all values in C to 0
        }
    }

    start = std::chrono::high_resolution_clock::now();      //start time for mmul
    mmul(A, B, C, n);
    end = std::chrono::high_resolution_clock::now();    //End time for mmul
    duration_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>> (end - start);  //Calculate the duration

    //Print out the first element of C
    std::cout << C[0] << "\n";
    std::cout << C[n * n - 1] << "\n";
    std::cout << duration_ms.count() << "\n";   //Print out the duration

    delete[] A;
    delete[] B;
    delete[] C;
    
}