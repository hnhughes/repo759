#include "matmul.h"

void mmul1(const double* A, const double* B, double* C, const unsigned int n){
    for(unsigned int i=0; i<n; i++){                            //i is the rows of C
        for(unsigned int j=0; j<n; j++){                        //j is the columns of C
            C[i * n + j] = 0.0;
            for (unsigned int k=0; k<n; k++){                   //k allows is to move by n in both directions
                C[i * n + j] += A[i * n + k] * B[k * n + j];    //With A we are moving the column and with B we are moviing the row
            }
        }
    }
}

void mmul2(const double* A, const double* B, double* C, const unsigned int n){
        for(unsigned int i=0; i<n; i++){                            //i is the rows of C
            for(unsigned int k=0; k<n; k++){                        //k is the number we are moving by
            for (unsigned int j=0; j<n; j++){                   //Now we are finding all the column values for C first?
                C[i * n + j] += A[i * n + k] * B[k * n + j];    //A is remaining the same with each move of the column while B is shifting
            }                                                   //the column with every loop
        }
    }
}

void mmul3(const double* A, const double* B, double* C, const unsigned int n){
    for(unsigned int j=0; j<n; j++){                            //j is the columns of C
        for(unsigned int k=0; k<n; k++){                        //k is what we are moving by
            for (unsigned int i=0; i<n; i++){                   //i is the rows in C
                C[i * n + j] += A[i * n + k] * B[k * n + j];    //With A we are moving our row every loop. With B we stay the same with each
            }                                                   //inner loop
        }
    }
}

void mmul4(const std::vector<double>& A, const std::vector<double>& B, double* C, const unsigned int n){
    for(unsigned int i=0; i<n; i++){                            //i is the rows of C
        for(unsigned int j=0; j<n; j++){                        //j is the columns of C
            C[i * n + j] = 0.0;
            for (unsigned int k=0; k<n; k++){                   //k allows is to move by n in both directions
                C[i * n + j] += A[i * n + k] * B[k * n + j];    //With A we are moving the column and with B we are moviing the row
            }
        }
    }
}