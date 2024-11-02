# The credit_card_5-3.csv dataset contains information on credit card customers, including the customer's average credit limit and number of visits to the bank.
# credit_card_5-3.csvDownload credit_card_5-3.csv
# Use Python to standardize the data for the features Avg_Credit_Limit and Total_visits_bank.
# The provided code imports pandas and scikit-learn's preprocessing package, loads the dataset, subsets the data, and displays five lines of the standardized data.
# Code:

# Import packages and functions
import pandas as pd
from sklearn import preprocessing

# Load the dataset
df = pd.read_csv('credit_card_5-3.csv')

# Create a new dataframe with two features
ccOriginal = df[['Avg_Credit_Limit', 'Total_visits_bank']]

# Standardize dataframe and return as an array
standardizedArray = preprocessing.scale(ccOriginal)

# Convert standardized array to dataframe
ccOriginalStandardized = pd.DataFrame(standardizedArray, columns=['Avg_Credit_Limit', 'Total_visits_bank'])

# Print five lines of the standardized data
print(ccOriginalStandardized[71:76])