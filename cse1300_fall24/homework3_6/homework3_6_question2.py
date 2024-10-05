# A local parks and recreation board is considering building a new set of bike trails. Before building new trails, they decide to look at how many riders are using an existing bike trail over a random sample of 90 days. Each day is rated as "high volume" or "low volume" (1 means yes, 0 means no).
# The parks and recreation board believes that less than 50% of days are high volume. Complete the code to test this hypothesis using proportions_ztest().
# The code provided loads the dataset and packages, calculates the number of high volume days, and prints the test statistic and p-value.

# Code:

# Import packages and functions
import pandas as pd
from statsmodels.stats.proportion import proportions_ztest

# Load the dataset
trails = pd.read_csv('trails.csv')

x = trails['highvolume'].value_counts()
n = trails.shape[0]

# Find the test statistic and p-value
test = proportions_ztest(x[1], n, 0.5)

print('Test statistic:', test[0])
print('p-value:', test[1])
