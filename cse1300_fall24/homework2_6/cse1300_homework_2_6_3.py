# Using the loc() method, display all rows after and including row 1, and the passengers column of the taxisNY dataframe. (Note that the first row is row 0.)
# The provided code imports pandas, loads the dataset, and prints your result.
# Code:

# Loads necessary packages
import pandas as pd

# Loads the taxi.csv dataset
taxisNY = pd.read_csv('taxi.csv')

# Subset taxisNY by specifying columns and rows using the loc method
df = taxisNY.loc[1:, 'passengers']

# Prints the column
print(df)
