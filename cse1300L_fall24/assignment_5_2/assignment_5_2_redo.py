# The hmeq_small dataset contains information on 5960 home equity loans, including 7 features on the characteristics of the loan.
# Load the hmeq_small.csv data set as a data frame.
# Standardize the data set as a new data frame.
# Normalize the data set as a new data frame.
# Print the means and standard deviations of both the standardized and normalized data.

# Import the required libraries
import pandas as pd
from sklearn.preprocessing import StandardScaler, MinMaxScaler

# Read in hmeq_small.csv
hmeq = pd.read_csv('hmeq_small.csv')

# Handle missing values by filling them with the mean of the column
hmeq = hmeq.fillna(hmeq.mean())

# Standardize the data
scaler_standard = StandardScaler()
standardized = scaler_standard.fit_transform(hmeq)

# Output the standardized data as a data frame
hmeqStand = pd.DataFrame(standardized, columns=hmeq.columns)

# Normalize the data using MinMaxScaler
scaler_minmax = MinMaxScaler()
normalized = scaler_minmax.fit_transform(hmeq)

# Output the normalized data as a data frame
hmeqNorm = pd.DataFrame(normalized, columns=hmeq.columns)

# Print the means and standard deviations of hmeqStand and hmeqNorm
print("The means of hmeqStand are:\n", hmeqStand.mean())
print("\nThe standard deviations of hmeqStand are:\n", hmeqStand.std())
print("\nThe means of hmeqNorm are:\n", hmeqNorm.mean())
print("\nThe standard deviations of hmeqNorm are:\n", hmeqNorm.std())
