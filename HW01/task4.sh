#!/usr/bin/env zsh

#SBATCH -c 2
#SBATCH -J FirstSlurm
#SBATCH -o FirstSlurm-%j.out -e FirstSlurm-%j.err

echo "Running on: $(hostname)"
