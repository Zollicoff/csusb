# The US Forest Service regularly monitors weather conditions to predict which areas are at risk of wildfires. Data scientists working with the US Forest Service would like to predict whether a wildfire will occur based on humidity.
# Using the fires.csv
# Download fires.csv data and the fitted logistic regression model, logisticModel, write code to calculate the probability of a fire on a day with humidity = 50. Assign the probability to prob.
# The provided code contains all imports, loads the dataset, and prints the probabilities.

# Code:

# Import packages and functions
import pandas as pd
import numpy as np
from sklearn.linear_model import LogisticRegression

# Load the dataset
fires = pd.read_csv('fires.csv')

# Create input matrix X and output matrix y
X = fires['humidity'].values.reshape(-1, 1)
y = np.ravel(fires['fire'])

# Define and fit the logistic regression model
logisticModel = LogisticRegression()
logisticModel = logisticModel.fit(X, y)

# Calculate the probabilities and assign to prob
prob = logisticModel.predict_proba([[50]])

# Print the predicted value
print('Probability of no wildfire:', prob[0][0])
print('Probability of a wildfire:', prob[0][1])
