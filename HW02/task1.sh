#!/usr/bin/env zsh

#SBATCH -J p2task1
#SBATCH -o p2task1-%j.out 
#SBATCH -e p2task1-%j.err
#SBATCH -p instruction

g++ scan.cpp task1.cpp -Wall -O3 -std=c++17 -o task1
./task1 12