# The mammals_append_left.csv and mammals_append_right.csv datasets contain information on a variety of animals.
# mammals_append_left.csvDownload mammals_append_left.csv
# mammals_append_right.csvDownload mammals_append_right.csv
# Append the data from animalsRight to animalsLeft using dataframe.merge() with the parameters how='right' and sort=True.
# The provided code imports pandas, loads the datasets, and displays the enriched dataframe.
# Code:

# Import packages
import pandas as pd

# Load the first dataset
animalsLeft = pd.read_csv('mammals_append_left.csv')

# Load the second dataset
animalsRight = pd.read_csv('mammals_append_right.csv')

# Join the first and second datasets using the parameters how='right' and sort=True
enriched = animalsLeft.merge(animalsRight, how='right', sort=True)

# Print enriched dataframe
print(enriched)
