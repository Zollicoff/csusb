# Using the same datasets, append the data from animalsRight to animalsLeft using pd.concat() and the parameter axis=1.
# The provided code imports pandas, loads the datasets, and displays the enriched dataframe. It is normal if the output has duplicate columns.
# Code:

# Import packages
import pandas as pd

# Load the first dataset
animalsLeft = pd.read_csv('mammals_append_left.csv')

# Load the second dataset
animalsRight = pd.read_csv('mammals_append_right.csv')

# Join the first and second datasets using the parameter axis=1
enriched = pd.concat([animalsLeft, animalsRight], axis=1)

# Print enriched dataframe
print(enriched)