#!/usr/bin/env zsh

#SBATCH -J task6Slurm
#SBATCH -o task6Slurm-%j.out 
#SBATCH -e task6Slurm-%j.err
#SBATCH -p instruction

g++ task6.cpp -Wall -O3 -std=c++17 -o task6
./task6 6