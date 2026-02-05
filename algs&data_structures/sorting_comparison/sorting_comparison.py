import matplotlib.pyplot as plt
import pandas as pd


def load_csv(filename: str) -> pd.DataFrame:
    df = pd.read_csv(filename, header=None,
                     names=["size", "comparisons", "swaps", "time"])
    df = df.sort_values("size")
    return df

bubble    = load_csv("bubbleSort.csv")
insertion = load_csv("insertionSort.csv")
selection = load_csv("selectionSort.csv")
comb      = load_csv("combSort.csv")
shell     = load_csv("shellSort.csv")

datasets = {
    "Bubble Sort": bubble,
    "Insertion Sort": insertion,
    "Selection Sort": selection,
    "Comb Sort": comb,
    "Shell Sort": shell,
}


def plot_single_algorithm(name: str, df: pd.DataFrame) -> None:
    
    plt.figure(figsize=(7, 4))
    plt.plot(df["size"], df["comparisons"], marker="o")
    plt.xlabel("Array size")
    plt.ylabel("Comparisons")
    plt.title(f"{name} – Comparisons vs Array size")
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    
    plt.figure(figsize=(7, 4))
    plt.plot(df["size"], df["swaps"], marker="o")
    plt.xlabel("Array size")
    plt.ylabel("Swaps / assignments")
    plt.title(f"{name} – Swaps vs Array size")
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    
    plt.figure(figsize=(7, 4))
    plt.plot(df["size"], df["time"], marker="o")
    plt.xlabel("Array size")
    plt.ylabel("Time [ms]")
    plt.title(f"{name} – Execution time vs Array size")
    plt.grid(True)
    plt.tight_layout()
    plt.show()


def plot_combined(datasets: dict) -> None:
    plt.figure(figsize=(8, 5))
    for name, df in datasets.items():
        plt.plot(df["size"], df["comparisons"], marker="o", label=name)
    plt.xlabel("Array size")
    plt.ylabel("Comparisons")
    plt.yscale("log")  
    plt.title("Comparisons vs Array size (log scale)")
    plt.grid(True, which="both", ls="--", alpha=0.5)
    plt.legend()
    plt.tight_layout()
    plt.show()

    plt.figure(figsize=(8, 5))
    for name, df in datasets.items():
        plt.plot(df["size"], df["swaps"], marker="o", label=name)
    plt.xlabel("Array size")
    plt.ylabel("Swaps / assignments")
    plt.yscale("log")  
    plt.title("Swaps vs Array size (log scale)")
    plt.grid(True, which="both", ls="--", alpha=0.5)
    plt.legend()
    plt.tight_layout()
    plt.show()

    plt.figure(figsize=(8, 5))
    for name, df in datasets.items():
        plt.plot(df["size"], df["time"], marker="o", label=name)
    plt.xlabel("Array size")
    plt.ylabel("Execution time [ms]")
    plt.yscale("log")  
    plt.title("Execution time vs Array size (log scale)")
    plt.grid(True, which="both", ls="--", alpha=0.5)
    plt.legend()
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    
    for name, df in datasets.items():
        plot_single_algorithm(name, df)

    plot_combined(datasets)
