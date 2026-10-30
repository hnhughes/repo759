#!/usr/bin/env zsh

#SBATCH -J task2Slurm
#SBATCH -o task2Slurm-%j.out 
#SBATCH -e task2Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH -c 20
#SBATCH --mem=16G

g++ task2.cpp -Wall -O3 -std=c++17 -o task2

./task2 100 10.0