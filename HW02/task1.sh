#!/usr/bin/env zsh

#SBATCH -J task1Slurm
#SBATCH -o task1Slurm-%j.out 
#SBATCH -e task1Slurm-%j.err
#SBATCH -p instruction
#SBATCH -t 0-00:30:00
#SBATCH --mem=16G

g++ scan.cpp task1.cpp -Wall -O3 -std=c++17 -o task1

DATA_FILE=task1_data.csv
echo "n,time_ms" > "$DATA_FILE"
 
for k in $(seq 10 30); do
    n=$((2 ** k))
    echo "Running n = $n (2^$k)..."
 
    # Capture the program's stdout so we can pull the timing out of it
    program_output=$(./task1 "$n")
 
    # The line looks like: "Scan function took 12.345 ms"
    # Pull out the 4th whitespace-separated field, which is the number.
    time_ms=$(./task1 "$n" | head -n 1)
 
    echo "$n,$time_ms" >> "$DATA_FILE"
done
 
echo "All runs complete. Data written to $DATA_FILE"
 
# Generate the plot
python3 plot_task1.py "$DATA_FILE" task1.pdf