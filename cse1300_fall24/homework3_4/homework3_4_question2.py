# Write Python code to calculate the following probabilities for a binomial distribution with variables n and pi (where n is the number of outcomes observed and pi denotes the probability of a success, not 3.14):
# P(X = 9)
# P(X <= 9)
# P(X > 9)
# The provided code loads the necessary package and function, reads the variables n and pi as input, and prints the calculated probabilities. (If you try to run the code, it will wait for you to enter n then pi before producing any output.)

# Code:

# Import packages and functions
from scipy.stats import binom

# Set values for n and pi
n = int(input())
pi = float(input())

# Calculate probabilities
# Your code goes here
pEqual = binom.pmf(9, n, pi)
pLess = binom.cdf(9, n, pi)
pGreater = 1 - pLess

# Print probabilities
print('P(X = 9) =', pEqual)
print('P(X <= 9) =', pLess)
print('P(X > 9) =', pGreater)
