# A local parks and recreation board is considering building a new set of bike trails. Before building new trails, they decide to look at how many riders are using an existing bike trail over a random sample of 90 days.
# The parks and recreation board believes that the average number of riders per day (volume) is more than 325. Complete the code to test this hypothesis using ttest_1samp().
# The code provided loads the dataset and packages and prints the test statistic and p-value.

# Code:

# Import packages and functions
import pandas as pd
from scipy.stats import ttest_1samp

# Load the dataset
trails = pd.read_csv('trails.csv')

# Find the test statistic and p-value
test = ttest_1samp(trails['volume'], 325)

print('Test statistic:', test[0])
print('p-value:', test[1])
