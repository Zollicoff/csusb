# The hmeq_small dataset contains information on 5960 home equity loans, including 7 features on the characteristics of the loan.
# Load the hmeq_small.csv data set as a data frame.
# Standardize the data set as a new data frame.
# Normalize the data set as a new data frame.
# Print the means and standard deviations of both the standardized and normalized data.

# Import the required libraries
import pandas as pd
from sklearn import preprocessing

hmeq = pd.read_csv('hmeq_small.csv')

# Standardize the data
standardized = preprocessing.scale(hmeq)

# Output the standardized data as a data frame
hmeqStand = pd.DataFrame(standardized, columns=hmeq.columns)

# Normalize the data
normalized = preprocessing.normalize(hmeq)

# Output the normalized data as a data frame
hmeqNorm = pd.DataFrame(normalized, columns=hmeq.columns)

# Print the means and standard deviations of hmeqStand and hmeqNorm
print("The means of hmeqStand are ", hmeqStand.mean())
print("The standard deviations of hmeqStand are ", hmeqStand.std())
print("The means of hmeqNorm are ", # Your code here)
print("The standard deviations of hmeqNorm are ", hmeqNorm.std()))
