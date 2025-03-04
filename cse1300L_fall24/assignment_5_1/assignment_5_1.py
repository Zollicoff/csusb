# The hmeq_small dataset contains information on 5960 home equity loans, including 7 features on the characteristics of the loan.
# Load the data set hmeq_small.csv as a data frame.
# Create a new data frame with all the rows with missing data deleted.
# Create a second data frame with all missing data filled in with the mean value of the column.
# Find the means of the columns for both new data frames.
# #Ex: Using only the first hundred rows, found in hmeq_sample.csv, the output is:

# Import the required libraries
import pandas as pd

# Read in hmeq_small.csv
hmeq = pd.read_csv('hmeq_small.csv')

# Create a new data frame with the rows with missing values dropped
hmeqDelete = hmeq.dropna()

# Create a new data frame with the missing values filled in by the mean of the column
hmeqReplace = hmeq.fillna(hmeq.mean())

# Print the means of the columns for each new data frame
print("Means for hmeqDelete are ", hmeqDelete.mean())
print("Means for hmeqReplace are ", hmeqReplace.mean())
