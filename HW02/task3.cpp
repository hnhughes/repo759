#include "matmul.h"
#include <random>
#include <iostream>
#include <chrono>

int main(int argc, char *argv[]){
    //Declare variables
    unsigned int n = 1500;
    double* A = new double[n*n];
    double* B = new double[n*n];
    double* C = new double[n*n];

    //Setting up the random generator
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand
    std::uniform_real_distribution<double> dist(-3.0, 3.0);    //set the distribution for the numbers to be generated

    //Setup for timing
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double, std::milli> duration_ms;

    //Generate matrix A and Matrix B
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<n; j++){
            A[i * n + j] = dist(gen);
            B[i * n + j] = dist(gen);
            C[i * n + j] = 0.0;   //Initialize all values in C to 0
        }
    }

    //Generate vectors for A and B
    std::vector<double> Av(A, A + n);
    std::vector<double> Bv(B, B + n);

    std::cout << n << "\n"; //Pint out the number of rows

    //mmul1
    start = std::chrono::high_resolution_clock::now();      //start time for mmul1
    mmul1(A, B, C, n);                                      //Generate dot product via mmul1
    end = std::chrono::high_resolution_clock::now();        //end time for mmul1
    duration_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>> (end - start);  //Calculate the duration
    std::cout << duration_ms.count() << "\n";               //Print out the duration
    std::cout << C[n * n - 1] << "\n";                      //Print out the last element of C
    duration_ms = std::chrono::duration<double, std::milli>(0); //Reset the duration to 0 to calculate the next duration

    //mmul2
    start = std::chrono::high_resolution_clock::now();      //start time for mmul1
    mmul2(A, B, C, n);                                      //Generate dot product via mmul1
    end = std::chrono::high_resolution_clock::now();        //end time for mmul1
    duration_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>> (end - start);  //Calculate the duration
    std::cout << duration_ms.count() << "\n";               //Print out the duration
    std::cout << C[n * n - 1] << "\n";                      //Print out the last element of C
    duration_ms = std::chrono::duration<double, std::milli>(0); //Reset the duration to 0 to calculate the next duration

    //mmul3
    start = std::chrono::high_resolution_clock::now();      //start time for mmul1
    mmul3(A, B, C, n);                                      //Generate dot product via mmul1
    end = std::chrono::high_resolution_clock::now();        //end time for mmul1
    duration_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>> (end - start);  //Calculate the duration
    std::cout << duration_ms.count() << "\n";               //Print out the duration
    std::cout << C[n * n - 1] << "\n";                      //Print out the last element of C
    duration_ms = std::chrono::duration<double, std::milli>(0); //Reset the duration to 0 to calculate the next duration

    //mmul4
    start = std::chrono::high_resolution_clock::now();      //start time for mmul1
    mmul4(Av, Bv, C, n);                                      //Generate dot product via mmul1
    end = std::chrono::high_resolution_clock::now();        //end time for mmul1
    duration_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>> (end - start);  //Calculate the duration
    std::cout << duration_ms.count() << "\n";               //Print out the duration
    std::cout << C[n * n - 1] << "\n";                      //Print out the last element of C
    duration_ms = std::chrono::duration<double, std::milli>(0); //Reset the duration to 0 to calculate the next duration
    
    return 0;
}