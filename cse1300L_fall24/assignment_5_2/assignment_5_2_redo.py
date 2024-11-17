# The hmeq_small dataset contains information on 5960 home equity loans, including 7 features on the characteristics of the loan.
# Load the hmeq_small.csv data set as a data frame.
# Standardize the data set as a new data frame.
# Normalize the data set as a new data frame.
# Print the means and standard deviations of both the standardized and normalized data.

# Import the required libraries
import pandas as pd
from sklearn import preprocessing
import numpy as np

# Read in the file hmeq_small.csv
hmeq = pd.read_csv('hmeq_small.csv')

# Handle missing values by filling them with the mean of the column
hmeq = hmeq.fillna(hmeq.mean())

# Standardize the data (zero mean, unit variance)
standardized = preprocessing.scale(hmeq)

# Output the standardized data as a data frame
hmeqStand = pd.DataFrame(standardized, columns=hmeq.columns)

# Normalize the data row-wise (L2 normalization)
normalized = preprocessing.normalize(hmeq, axis=1)

# Output the normalized data as a data frame
hmeqNorm = pd.DataFrame(normalized, columns=hmeq.columns)

# Print the means and standard deviations of hmeqStand
print("The means of hmeqStand are ", hmeqStand.mean())
print("The standard deviations of hmeqStand are ", hmeqStand.std())

# Print the means and standard deviations of hmeqNorm
print("The means of hmeqNorm are ", hmeqNorm.mean())
print("The standard deviations of hmeqNorm are ", hmeqNorm.std())

# Optional: Verify row-wise norms of normalized data
row_norms = np.linalg.norm(hmeqNorm, axis=1)
print("Row norms of hmeqNorm (should be close to 1):", row_norms)
