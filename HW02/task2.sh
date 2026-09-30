#!/usr/bin/env zsh

#SBATCH -J task2Slurm
#SBATCH -o task2Slurm-%j.out 
#SBATCH -e task2Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G

g++ convolution.cpp task2.cpp -Wall -O3 -std=c++17 -o task2

./task2 3 5