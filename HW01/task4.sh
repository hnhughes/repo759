#!/usr/bin/env zsh

#SBATCH -c 2
#SBATCH -J FirstSlurm
#SBATCH -o FirstSlurm-%j.out 
#SBATCH -e FirstSlurm-%j.err
#SBATCH -p instruction

hostname
