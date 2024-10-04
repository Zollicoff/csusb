# The gpa dataset is a toy dataset containing the features height and gpa for 35 students. Use the statsmodels function proportions_ztest , proportion_confint and the user defined values for the proportion for the null hypothesis value and the gpa cutoff cutoff to perform the following tasks:

# Load the gpa.csv data set.
# Find the number of students with a gpa greater than cutoff.
# Find the total number of students.
# Perform a z-test for the user input expected proportion.
# Determine if the hypothesis that the actual proportion is different from the expected proportion should be rejected at the alpha = 0.01 significance level.
# Find the 95% confidence interval for counts, nobs, alpha and method

# Ex: When the input is:
# 0.5
# 2.0
# the ouput is:
# (4.902, 0.000)
# The two-tailed p-value, 0.000, is less than α. Thus, sufficient evidence exists to support the hypothesis that the proportion is different from 0.5
# (0.822, 1.000)

# Here is the template:
import statsmodels.stats as st
from statsmodels.stats.proportion import proportions_ztest, proportion_confint
import pandas as pd

# Read in gpa.csv
gpa = pd.read_csv('gpa.csv')

# Get the value of the proportion for the null hypothesis
value = float(input())

# Get the gpa cutoff
cutoff = float(input())

# Determine the number of students with a gpa higher than cutoff
counts = int(gpa[gpa['gpa'] > cutoff].count()['gpa'])

# Determine the total number of students
nobs = int(gpa['gpa'].count())

# Perform z-test for counts, nobs, and value
ztest = proportions_ztest(counts, nobs, value)
print("(", end="")
print('%.3f' % ztest[0] + ", ", end="")
print('%.3f' % ztest[1] + ")")

if ztest[1] < 0.01:
    print("The two-tailed p-value, ", end="")
    print('%.3f' % ztest[1] + ", is less than \u03B1. Thus, sufficient evidence exists to support the hypothesis that the proportion is different from", value)
else:
    print("The two-tailed p-value, ", end="")
    print('%.3f' % ztest[1] + ", is greater than \u03B1. Thus, insufficient evidence exists to support the hypothesis that the proportion is different from", value)

# Find the 95% confidence interval for counts, nobs, alpha and method
confint = proportion_confint(counts, nobs, alpha=0.05, method='normal')
print("(", end="")
print('%.3f' % confint[0] + ", ", end="")
print('%.3f' % confint[1] + ")")
