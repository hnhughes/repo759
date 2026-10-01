#!/usr/bin/env zsh

#SBATCH -J task1Slurm
#SBATCH -o task1Slurm-%j.out 
#SBATCH -e task1Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G

g++ scan.cpp task1.cpp -Wall -O3 -std=c++17 -o task1

./task1 10000

# module load gnu15/15.2.0
# module load R/4.5.3

# rm -f results.txt

# DATA_FILE=task1_data.csv
# echo "n,time_ms" > "$DATA_FILE"
 
# for exponent in {10..30}
# do
#     n=$((2**exponent))

#     time=$(./task1 $n | head -n 1)

#     echo "$n $time" >> results.txt
# done

# Rscript plot.R