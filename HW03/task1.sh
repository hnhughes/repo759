#!/usr/bin/env zsh

#SBATCH -J task1Slurm
#SBATCH -o task1Slurm-%j.out 
#SBATCH -e task1Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH -c 20
#SBATCH --mem=16G

g++ task1.cpp matmul.cpp -Wall -O3 -std=c++17 -o task1 -fopenmp

./task1 1024 1
./task1 1024 2
./task1 1024 3
./task1 1024 4
./task1 1024 5
./task1 1024 6
./task1 1024 7
./task1 1024 8
./task1 1024 9
./task1 1024 10
./task1 1024 11
./task1 1024 12
./task1 1024 13
./task1 1024 14
./task1 1024 15
./task1 1024 16
./task1 1024 17
./task1 1024 18
./task1 1024 19
./task1 1024 20

