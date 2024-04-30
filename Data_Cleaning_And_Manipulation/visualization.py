import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# Load the consolidated data
df = pd.read_csv("consolidated_metrics.csv")

# Speedup bar chart per algorithm
plt.figure(figsize=(12, 6))
sns.barplot(x="Algorithm", y="Speedup", hue="NumThreads", data=df)
plt.title("Speedup per Algorithm and Thread Count")
plt.tight_layout()
plt.savefig("speedup_per_algorithm.png")

# Efficiency bar chart per algorithm
plt.figure(figsize=(12, 6))
sns.barplot(x="Algorithm", y="Efficiency", hue="NumThreads", data=df)
plt.title("Efficiency per Algorithm and Thread Count")
plt.tight_layout()
plt.savefig("efficiency_per_algorithm.png")

# Scatter plot for Coloring Time (Greedy) vs. Speedup
plt.figure(figsize=(12, 6))
sns.scatterplot(x="ColoringTime", y="Speedup", hue="Algorithm", data=df)
plt.title("Speedup vs. Coloring Time (Greedy)")
plt.tight_layout()
plt.savefig("speedup_vs_coloringtime_greedy.png")

