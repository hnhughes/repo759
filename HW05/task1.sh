#!/usr/bin/env zsh

#SBATCH -J task1Slurm
#SBATCH -o task1Slurm-%j.out 
#SBATCH -e task1Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --gpus-per-task=1

nvcc task1.cu -Xcompiler -O3 -Xcompiler -Wall -Xptxas -O3 -std=c++17 -o task1

./task1