#include "msort.h"
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <random>
#include <chrono>
#include <ratio>

int main(int argc, char *argv[]){
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    //Reading the arguments
    int n = std::atoi(argv[1]);
    int t = std::atoi(argv[2]);
    int threshold = std::atoi(argv[3]);

    //intializing variables
    int* arr = new int[n];
    omp_set_num_threads(t);

    //Setting up the random generator
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand
    std::uniform_int_distribution<int> dist(-1000, 1000);

    //setup timing
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double, std::milli> duration_ms;

    for (int i=0; i<n; i++){
        arr[i] = dist(gen);
    }

    start = std::chrono::high_resolution_clock::now();
    msort(arr, static_cast<std::size_t>(n), static_cast<std::size_t>(threshold));
    end = std::chrono::high_resolution_clock::now();   //captures the timestamp after convolve is called
    duration_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>> (end - start);    //comput the time elapsed in milliseconds

    //Printed outputs
    std::cout << arr[0] << "\n";                //Prints the first element of the array
    std::cout << arr[n-1] << "\n";              //Prints the last element of the array
    std::cout << duration_ms.count() << "\n";   //Print out the time taken for the function in milliseconds

    delete[] arr;
}