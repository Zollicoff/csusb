# Using a descriptive statistics method, generate a table of descriptive statistics for the volume of homes sold ("volume") over all cities.
# The provided code imports pandas, loads the dataset, and prints your result.

# Code:

# Import packages and functions
import pandas as pd

housing = pd.read_csv('txhousing.csv')

table = housing['volume'].describe()

print(table)
