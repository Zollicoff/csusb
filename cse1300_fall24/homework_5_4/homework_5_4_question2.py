# The healthy_example.csv dataset contains information on lifestyle measures such as the annual hours worked, sunshine, life expectancy, and happiness levels for 44 major cities around the world.
# healthy_example.csvDownload healthy_example.csv
# Using Python, drop instances with duplicate values of annual_hours_worked from the dataset.
# The provided code imports pandas, loads the dataset, and displays healthyClean.info().
# Code:

# Import packages and functions
import pandas as pd

# Load the dataset
healthy = pd.read_csv('healthy_example.csv')

# Remove instances with duplicate values of annual_hours_worked 
healthyClean = healthy.drop_duplicates(subset='annual_hours_worked')

# Display the cleaned dataset information
healthyClean.info()