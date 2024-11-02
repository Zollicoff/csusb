# Using the same dataset, calculate and print the mean value of sunshine_hours. Then replace the missing values of sunshine_hours in the original dataframe with the mean of sunshine_hours.
# The provided code imports pandas, loads the dataset, and displays healthy['sunshine_hours'] to show the final result.
# Code:

# Import packages and functions
import pandas as pd

# Load the dataset
healthy = pd.read_csv('healthy_example.csv')

# Calculate the mean value of sunshine_hours
mean_sunshine_hours = healthy['sunshine_hours'].mean()
print('Mean:', mean_sunshine_hours, '\n')

# Replace missing values of sunshine_hours with the mean value
healthy['sunshine_hours'] = healthy['sunshine_hours'].fillna(mean_sunshine_hours)

# Display the final result
print(healthy['sunshine_hours'])