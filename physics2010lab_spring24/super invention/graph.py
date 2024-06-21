import pandas as pd

# Load the CSV files into DataFrames
exp1_df = pd.read_csv('/mnt/data/Shun Akiya PHYS2510L 03 - Final (Exp1).csv')
exp2_df = pd.read_csv('/mnt/data/Shun Akiya PHYS2510L 03 - Final (Exp2).csv')
exp3_df = pd.read_csv('/mnt/data/Shun Akiya PHYS2510L 03 - Final (Exp3).csv')

# Display the first few rows of each dataset to verify the format
exp1_df.head(), exp2_df.head(), exp3_df.head()

# Correcting headers and converting data types
# Drop the first row which is a duplicate header and convert data columns to float
exp1_df = exp1_df.drop(0).rename(columns={"4 Blue LED's": "Time (s)", "Unnamed: 1": "Voltage (V)", "Unnamed: 2": "Current (A)"}).astype({'Time (s)': 'float', 'Voltage (V)': 'float', 'Current (A)': 'float'})
exp2_df = exp2_df.drop(0).rename(columns={"1 Blue LED - 4 Red LEDs": "Time (s)", "Unnamed: 1": "Voltage (V)", "Unnamed: 2": "Current (A)"}).astype({'Time (s)': 'float', 'Voltage (V)': 'float', 'Current (A)': 'float'})
exp3_df = exp3_df.drop(0).rename(columns={"2 Blue - 2 Red LEDs": "Time (s)", "Unnamed: 1": "Voltage (V)", "Unnamed: 2": "Current (A)"}).astype({'Time (s)': 'float', 'Voltage (V)': 'float', 'Current (A)': 'float'})

# Plot Voltage and Current data
fig, ax1 = plt.subplots(figsize=(12, 8))

ax1.set_xlabel('Time (s)')
ax1.set_ylabel('Voltage (V)', color='tab:purple')
ax1.plot(exp1_df["Time (s)"], exp1_df["Voltage (V)"], color='purple', label="4 Blue LEDs Voltage")
ax1.plot(exp2_df["Time (s)"], exp2_df["Voltage (V)"], color='green', label="1 Blue + 4 Red LEDs Voltage")
ax1.plot(exp3_df["Time (s)"], exp3_df["Voltage (V)"], color='orange', label="2 Blue + 2 Red LEDs Voltage")
ax1.tick_params(axis='y', labelcolor='tab:purple')
ax1.legend(loc='upper left')

ax2 = ax1.twinx()
ax2.set_ylabel('Current (A)', color='tab:pink')
ax2.plot(exp1_df["Time (s)"], exp1_df["Current (A)"], color='pink', label="4 Blue LEDs Current")
ax2.plot(exp2_df["Time (s)"], exp2_df["Current (A)"], color='blue', label="1 Blue + 4 Red LEDs Current")
ax2.plot(exp3_df["Time (s)"], exp3_df["Current (A)"], color='red', label="2 Blue + 2 Red LEDs Current")
ax2.tick_params(axis='y', labelcolor='tab:pink')
ax2.legend(loc='upper right')

fig.tight_layout()
plt.title("Voltage and Current Comparison for Different LED Configurations")
plt.grid(visible=True, linestyle='--', which='both', axis='both')
plt.show()

