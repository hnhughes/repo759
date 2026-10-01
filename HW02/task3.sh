#!/usr/bin/env zsh

#SBATCH -J task3Slurm
#SBATCH -o task3Slurm-%j.out 
#SBATCH -e task3Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G

 g++ task3.cpp matmul.cpp -Wall -O3 -std=c++17 -o task3

./task3