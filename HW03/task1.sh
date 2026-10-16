#!/usr/bin/env zsh

#SBATCH -J task1Slurm
#SBATCH -o task1Slurm-%j.out 
#SBATCH -e task1Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH -c 20
#SBATCH --mem=16G

g++ task1.cpp matmul.cpp -Wall -O3 -std=c++17 -o task1 -fopenmp

module load gnu15/15.2.0
module load R/4.5.3

rm -f results.txt

n=1024

DATA_FILE=task1_data.csv
echo "Threads,time_ms" > "$DATA_FILE"

for t in {1..20}
do
    time=$(./task1 $n $t | tail -n 1)
    echo "$t,$time" >> results.txt
done

Rscript plot.R

