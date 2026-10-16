//This function sorts an array of integers in ascending order
//Input: An array of integers
//Output: An array of integers in acending order
#include "msort.h"
#include <utility>
#include <cstddef>

//Sorts an array smaller than the threshold
void singleSort(int* arr, const std::size_t n) {
    bool done = false;
    while (!done) {
        done = true;
        for (std::size_t i = 1; i < n; i++) {
            if (arr[i] < arr[i-1]) {
                std::swap(arr[i], arr[i-1]);
                done = false;
            }
        }
    }
}

//
void merge(int* arr, const std::size_t n) {
    const std::size_t mid = n / 2;
    int* tmp = new int[n];
    std::size_t lower = 0, upper = mid, num = 0;

    while (lower < mid && upper < n) {  //Keep running the loop until we either reached the end of the lower or upper half
        tmp[num++] = (arr[upper] < arr[lower]) ? arr[upper++] : arr[lower++];   //If the upper array value is less than the lower store the
    }                                                                           //upper value an increment it. Otherwise, store the lower value and increment it.
    while (lower < mid) tmp[num++] = arr[lower++];   //stores the rest of the lower if the upper is done sorting first
    while (upper < n)   tmp[num++] = arr[upper++];   //stores the rest of the upper if the lower is done sorting first

    for (std::size_t i = 0; i < n; i++) arr[i] = tmp[i];
    delete[] tmp;
}

void msort(int* arr, const std::size_t n, const std::size_t threshold){
    if (n < 2) return;

    if (n <= threshold) {
        singleSort(arr, n);
        return;
    }

    msort(arr, n/2, threshold);
    msort(arr + n/2, n - n/2, threshold);
    merge(arr, n);
}