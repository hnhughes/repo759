#!/usr/bin/env zsh

#SBATCH -J task3Slurm
#SBATCH -o task3Slurm-%j.out 
#SBATCH -e task3Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --gpus-per-task=1

module load nvidia/cuda/11.8.0 gcc/.11.3.0_cuda

nvcc task3.cu vscale.cu -Xcompiler -O3 -Xcompiler -Wall -Xptxas -O3 -std=c++17 -o task3

for i in {10..29}; do
    echo "$i $(./task3 $((2**i)) | head -n 1)"
done