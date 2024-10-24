# Import packages and functions
import pandas as pd

# Load the dataset
df = pd.read_csv('credit_card_q3.csv')

# Create a frequency table for Total_visits_bank
freqTable = df['Total_visits_bank'].value_counts()

# Display frequency table
print(freqTable)