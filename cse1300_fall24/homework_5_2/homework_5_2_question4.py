# Import packages and functions
import pandas as pd
import numpy as np

# Load the dataset
df = pd.read_csv('credit_card_q4.csv')

# Create a contingency table for Total_visits_online and Total_visits_bank
contingencyTable = pd.crosstab(df['Total_visits_online'], df['Total_visits_bank'])

# Display contingency table
print(contingencyTable)