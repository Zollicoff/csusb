# Using the iloc() method, display the first 3 columns and the first 4 rows of the taxisNY dataframe.
# The provided code imports pandas, loads the dataset, and prints your result.
# Code:

# Loads necessary packages
import pandas as pd

# Loads the taxi.csv dataset
taxisNY = pd.read_csv('taxi.csv')

# Subset taxisNY using the iloc method
df = taxisNY.iloc[:4, :3]

# Prints the column
print(df)
