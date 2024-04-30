import pandas as pd
import glob

# Load all individual CSVs into a list of dataframes
df_list = [pd.read_csv(f) for f in glob.glob("Benchmarks/*.csv")]

# Concatenate all the dataframes into a single dataframe
df = pd.concat(df_list)

# Sort by Graph, Algorithm, and NumThreads
df = df.sort_values(by=["Graph", "Algorithm", "NumThreads"])

# Save the consolidated dataset to a new CSV file
df.to_csv("consolidated_performance_data.csv", index=False)
