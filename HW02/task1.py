import sys
import csv
import matplotlib
matplotlib.use("Agg")  # no display available on a compute node
import matplotlib.pyplot as plt

def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <data.csv> <output.pdf>")
        sys.exit(1)

    data_path = sys.argv[1]
    output_path = sys.argv[2]

    ns = []
    times_ms = []
    with open(data_path, newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            ns.append(int(row["n"]))
            times_ms.append(float(row["time_ms"]))

    fig, ax = plt.subplots()
    ax.plot(ns, times_ms, marker="o")

    # n spans several orders of magnitude (2^10 to 2^30), so log-log
    # makes the scaling trend visible across the whole range.
    ax.set_xscale("log")
    ax.set_yscale("log")

    ax.set_xlabel("n (array size)")
    ax.set_ylabel("time (ms)")
    ax.set_title("Scan function scaling: time vs. n")
    ax.grid(True, which="both", linestyle="--", alpha=0.5)

    fig.savefig(output_path)
    print(f"Saved plot to {output_path}")

if __name__ == "__main__":
    main()