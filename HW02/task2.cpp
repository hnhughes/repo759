#include "convolution.h"
#include <cstdlib>
#include <iostream>
#include <random>

int main(int argc, char *argv[]){
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    std::random_device rd;
    std::mt19937 gen(rd()); //call the random device with rd and store it in gen using mt19937 to generate the rand

    //Creating the image matrix
    std::uniform_real_distribution<float> dist_n(-10.0f, 10.0f);    //set the distribution for the numbers to be generated
    float *image = new float[n*n];  //allocated an array of n*n floats at runtime
    std::cout<< "[";                               //TESTING ************************************************************
    for (int x=0; x<n; x++){
        for (int y=0; y<n; y++){
            image[x * n + y] = dist_n(gen);
            std::cout << image[x * n + y] << " "; //TESTING ************************************************************
        }
    }
    std::cout<< "]\n";                               //TESTING ************************************************************
    //Create an m by m mask matrix stored in 1D in row-major order
        //matrix should contain random float numbers
        //Numbers should be between -1.0 and 1.0 
        //m should be read as the second command line argument
    //Creating the mask matrix
    std::uniform_real_distribution<float> dist_m(-1.0f, 1.0f);    //set the distribution for the numbers to be generated
    float *mask = new float[m*m];  //allocated an array of n*n floats at runtime
    std::cout<< "[";                               //TESTING ************************************************************
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            mask[i * m + j] = dist_m(gen);
            std::cout << mask[i * m + j] << " "; //TESTING ************************************************************
        }
    }
    std::cout<< "]\n";                               //TESTING ************************************************************
//*******************************************************************************
    //Apply mask to image using the convolve function
    //Print out the time taken for the convolve function in milliseconds
    //Prints the first element of the output array
    //Prints the last element of the convolve array
    //Deallocated memory when necessary 
    return 0;
}