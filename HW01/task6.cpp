#include <iostream>
#include <cstdlib>
#include <cstdio>

int main(int argc, char *argv[]) {
    int N = std::atoi(argv[1]);
    for (int i=0; i<=N; i++){
        std::printf("%d",i);
        if (i<N) {
            std::printf(" ");
        }
    }
    std::printf("\n");

    for (int i=N; i>=0; i--){
        std::cout << i;
        if (i>0){
            std::cout << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
