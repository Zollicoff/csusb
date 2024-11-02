# Using the same dataset, normalize the data for the features Avg_Credit_Limit and Total_visits_bank.
# The provided code imports pandas and scikit-learn's preprocessing package, loads the dataset, subsets the data, and displays five lines of the normalized data.
# Code:

# Import packages and functions
import pandas as pd
from sklearn import preprocessing

# Load the dataset
df = pd.read_csv('credit_card_5-3.csv')

# Create a new dataframe with two features
ccOriginal = df[['Avg_Credit_Limit', 'Total_visits_bank']]

# Normalize dataframe and return as an array
normalizedArray = preprocessing.normalize(ccOriginal)

# Convert normalized array to dataframe
ccOriginalNormalized = pd.DataFrame(normalizedArray, columns=['Avg_Credit_Limit', 'Total_visits_bank'])

# Print five lines of the normalized data
print(ccOriginalNormalized[583:588])