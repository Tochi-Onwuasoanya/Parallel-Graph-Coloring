import pandas as pd

# Load the consolidated data from the CSV file
df = pd.read_csv("consolidated_performance_data.csv")

# For each graph type and algorithm pair, calculate speedup
df['Speedup'] = df.apply(lambda row: df[(df['Graph'] == row['Graph']) & (df['Algorithm'] == 'Greedy')]['ColoringTime'].values[0] / row['ColoringTime'] if row['Algorithm'] != 'Greedy' else 1, axis=1)


# For parallel algorithms, compute efficiency
df['Efficiency'] = df.apply(lambda row: row['Speedup'] / row['NumThreads'] if row['Algorithm'] != 'Greedy' else 1, axis=1)


# Save to a new CSV for subsequent analyses
df.to_csv("consolidated_metrics.csv", index=False)
