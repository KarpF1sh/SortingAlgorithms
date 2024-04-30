import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV files
merge_df = pd.read_csv("merge.csv")
insertion_df = pd.read_csv("insertion.csv")

# Plotting
plt.figure(figsize=(10, 6))

# Plot merge sort data
plt.plot(merge_df["Amount"], merge_df["Time(ms)"], label="Merge Sort")

# Plot insertion sort data
plt.plot(insertion_df["Amount"], insertion_df["Time(ms)"], label="Insertion Sort")

# Add labels and title
plt.xlabel("Data Amount")
plt.ylabel("Time (ms)")
plt.title("Comparison of Merge Sort and Insertion Sort")
plt.legend()

# Show plot
plt.grid(True)
plt.show()
