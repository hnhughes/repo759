#!/usr/bin/env zsh

#SBATCH -J task2Slurm
#SBATCH -o task2Slurm-%j.out 
#SBATCH -e task2Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --gpus-per-task=1

module load nvidia/cuda/11.8.0 gcc/.11.3.0_cuda

nvcc task2.cu -Xcompiler -O3 -Xcompiler -Wall -Xptxas -O3 -std=c++17 -o task2

./task2