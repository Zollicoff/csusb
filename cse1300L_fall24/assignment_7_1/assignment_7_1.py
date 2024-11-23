# The nbaallelo_slr.csv
# Download nbaallelo_slr.csv dataset contains information on 24391 NBA games between 1947 and 2015. The columns report the points made by one team, the Elo rating of that team coming into the game, the Elo rating of the team after the game, and the points made by the opposing team. The Elo score measures the relative skill of teams in a league.
#Load the dataset into a data frame.
# Create a new column y in the data frame that is the difference between the points made by the two teams.
# Use sklearn's LinearRegression() function to perform a simple linear regression on the y and elo_i columns.
# Compute the proportion of variation explained by the linear regression using the LinearRegression object's score method.
# Ex: If the Elo rating of the team after the game, elo_n, is used instead of elo_i, the output is:
# The intercept of the linear regression line is -49.501. 
# The slope of the linear regression line is 0.034. 
# The proportion of variation explained by the linear regression model is 0.082. 

# Import the necessary modules
import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

# Read in nbaallelo_slr.csv
nba = pd.read_csv('nbaallelo_slr.csv')

# Create a new column in the data frame that is the difference between pts and opp_pts
nba['y'] = nba['pts'] - nba['opp_pts']

# Store relevant columns as variables
X = nba[['elo_i']]  # Independent variable
y = nba['y']  # Dependent variable

# Initialize the linear regression model
SLRModel = LinearRegression()

# Fit the model on X and y
SLRModel.fit(X, y)

# Print the intercept
intercept = SLRModel.intercept_
print('The intercept of the linear regression line is ', end="")
print('%.3f' % intercept + ". ")

# Print the slope
slope = SLRModel.coef_
print('The slope of the linear regression line is ', end="")
print('%.3f' % slope[0] + ". ")

# Compute the proportion of variation explained by the linear regression using the LinearRegression object's score method
score = SLRModel.score(X, y)
print('The proportion of variation explained by the linear regression model is ', end="")
print('%.3f' % score + ". ")

# Plotting the data points and regression line
plt.scatter(X, y, color='blue', alpha=0.5, label='Data Points')
plt.plot(X, SLRModel.predict(X), color='red', linewidth=2, label='Regression Line')

# Adding labels and title
plt.xlabel('Elo Rating Before Game (elo_i)')
plt.ylabel('Points Difference (y)')
plt.title('Simple Linear Regression: Elo Rating vs Points Difference')
plt.legend()

# Show the plot
plt.show()
