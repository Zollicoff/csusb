# The nbaallelo_slr-3.csv

# Download nbaallelo_slr-3.csv dataset contains information on 126315 NBA games between 1947 and 2015. The columns report the points made by one team, the Elo rating of that team coming into the game, the Elo rating of the team after the game, and the points made by the opposing team. The Elo rating measures the relative skill of teams in a league.

# The code creates a new column y in the data frame that is the difference between pts and opp_pts.
# Split the data into 70 percent training set and 30 percent testing set using sklearn's train_test_split function. Set random_state=0.
# Store elo_i and y from the training data as the variables X and y.
# The code performs a simple linear regression on X and y.
# Store elo_i and y from the testing data as the variables X_test and y_test.
# Using the simple linear regression to calculate the predicted value y_pred basing on X_test
# Calculate the Mean Squared Error between y_test and y_pred

# Ex: If random_state=1 is used, the output is:
# The mean squared errors are 166.5489476597798

import pandas as pd
import numpy as np
from sklearn import metrics
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

# Load the dataset
nba = pd.read_csv("nbaallelo_slr-3.csv")

# Create a new column in the data frame that is the difference between pts and opp_pts
nba['y'] = nba['pts'] - nba['opp_pts']

# Split the data into training (70%) and test (30%) sets
train, test = train_test_split(nba, test_size=0.3, random_state=0)

# Store elo_i and y from training data as variables X and y
X = train[['elo_i']]  # Using double brackets to keep X as a dataframe
y = train['y']

# Initialize the linear regression model
SLRModel = LinearRegression()

# Fit the model on X and y
SLRModel.fit(X, y)

# Store elo_i from the test data as X_test, and y as y_test
X_test = test[['elo_i']]
y_test = test['y']

# Get the predicted values for X_test
y_pred = SLRModel.predict(X_test)

# Calculate Mean Squared Error between y_test and y_pred
meanSquaredError = metrics.mean_squared_error(y_test, y_pred)
print('The mean squared errors are', meanSquaredError)
