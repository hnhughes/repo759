#include "scan.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>
#include <ratio>

int main(int argc, char *argv[]){
    //There should be one argument beyond the program name
    //If there isn't print out an error and exit
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    int n = std::atoi(argv[1]); //set n equal to the number of arguments in the array. atoi ensures this is and int

    //make sure the size of the array is a positive int
    if (n <= 0) {
        std::cerr << "n must be a positive integer\n";
        return 1;
    }

    // Provide some namespace shortcuts
    using std::cout;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration; 
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);    //set the distribution for the numbers to be generated
    float *arr = new float[n];  //allocated an array of n floats at runtime
    for (int i = 0; i < n; i++) {   //fill the array with random floats
        arr[i] = dist(gen);
    }

    float *output = new float[n];   //Create the array to store the output
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_ms;

    start = high_resolution_clock::now(); //captures the timestamp before scan is called
    scan(arr, output, static_cast<std::size_t>(n)); //need to cast n as an std::size_t from int
    end = high_resolution_clock::now();   //captures the timestamp after scan is called

    duration_ms = std::chrono::duration_cast<duration<double, std::milli>> (end - start);    //comput the time elapsed in milliseconds
    cout << duration_ms.count() << "\n";
    cout << output[0] << "\n";
    cout << output[n-1] << "\n";

    delete[] arr;
    delete[] output;

    return 0;
}
