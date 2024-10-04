# Display all rows of the taxisNY dataframe where the total column is >= 10.
# The provided code imports pandas, loads the dataset, and prints your result.
# Code:

# Loads necessary packages
import pandas as pd

# Loads the taxi.csv dataset
taxisNY = pd.read_csv('taxi.csv')

# Subset taxisNY using comparison operators
df = taxisNY[taxisNY['total'] >= 10]

# Prints the column
print(df)
