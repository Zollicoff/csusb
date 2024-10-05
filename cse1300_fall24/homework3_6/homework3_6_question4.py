# A local parks and recreation board is considering building a new set of bike trails. Before building new trails, they decide to look at how ridership changes depending on seasonality.
# The parks and recreation board believes that the number of riders in the fall is different than the number of riders in all other seasons. Complete the code to test this hypothesis, assuming both groups do not have the same variance, using ttest_ind().
# The code provided loads the dataset and packages and prints the test statistic and p-value.

# Code:

# Import packages and functions
import pandas as pd
from scipy.stats import ttest_ind

# Load the dataset and define groups
trails = pd.read_csv('trails.csv')
group1 = trails[trails['season']=='fall']['volume']
group2 = trails[trails['season']!='fall']['volume']

# Find the test statistic and p-value
test = ttest_ind(group1, group2, equal_var=False)

print('Test statistic:', test[0])
print('p-value:', test[1])
