# For all questions, the taxisNY dataframe is a dataframe created from a file called taxi.csv. The file contents are as follows:
# passengers,distance,fare,tip,tolls,total
# 1,1.05,6.5,1.0,0.0,11.3
# 1,2.07,10.0,2.7,0.0,13.5
# 1,1.1,7.5,1.0,0.0,12.3
# 2,8.55,26.0,7.01,5.76,42.07
# 1,0.53,6.5,2.16,0.0,12.96
# 1,2.25,13.0,0.0,0.0,13.8
# 1,0.75,4.5,0.0,0.0,8.8
# 0,2.3,12.5,1.2,0.0,17.0
# 1,1.28,6.5,0.0,0.0,9.8
# 1,0.5,5.0,0.42,0.0,8.72
# Create a dataframe containing the tolls column of the taxisNY dataframe.
# The provided code imports pandas, loads the dataset, and prints the column using the dataframe you created.

# Code:
# Loads necessary packages
import pandas as pd

# Loads the taxi.csv dataset
taxisNY = pd.read_csv('taxi.csv')

# Subset a column of the taxisNY dataframe by specifying the column name
tolls = taxisNY['tolls']

# Prints the column
print(tolls)