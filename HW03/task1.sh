#!/usr/bin/env zsh

#SBATCH -J task1Slurm
#SBATCH -o task1Slurm-%j.out 
#SBATCH -e task1Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G

g++ task1.cpp matmul.cpp -Wall -O3 -std=c++17 -o task1 -fopenmp

./task1 1024 5