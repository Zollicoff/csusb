# Write Python code to calculate the following probabilities for a normal distribution with variables mu and sigma (where mu denotes the mean and sigma is the standard deviation):
# P(X <= -2)
# P(X > -2)
# The provided code loads the necessary package and function, reads the variables mu and sigma as input, and prints the calculated probabilities. (If you try to run the code, it will wait for you to enter mu then sigma before producing any output.)

# Code:

# Import packages and functions
from scipy.stats import norm

# Set values for mu and sigma
mu = int(input())
sigma = float(input())

# Calculate probabilities
# Your code goes here
pLess = norm.cdf(-2, mu, sigma)
pGreater = 1 - pLess

# Print probabilities
print('P(X <= -2) =', pLess)
print('P(X > -2) =', pGreater)
