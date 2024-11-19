# LaGuardia Airport (LGA) is a major airport serving New York City. LGA wanted to predict the arrival delay of an incoming flight based on the departure delay. 50 recent flights were randomly selected, and the arrival delays, departure delays, and departure times (in minutes) were recorded. Their data (not the same as the csv in Homework 7-2) is contained in flightsLGA2.csv
# Download flightsLGA2.csv
# Write code to predict the arrival delay for a flight with departure time of 1043 and departure delay of 47, and assign variable yHat with the prediction. Then calculate the slope coefficients for multipleModel and assign slope with the result.
# The provided code has the necessary imports, loads the dataset, fits the multiple regression model, and prints yHat and slope once calculated.

# Code:

# Import packages and functions
import pandas as pd
from sklearn.linear_model import LinearRegression

# Import flights and remove missing values
flights = pd.read_csv('flightsLGA2.csv').dropna()

# Define X and y and convert to proper format
X = flights[['dep_time', 'dep_delay']].values.reshape(-1, 2)
y = flights[['arr_delay']].values.reshape(-1, 1)

# Initialize a linear regression model
multipleModel = LinearRegression()

# Fit the linear model
multipleModel = multipleModel.fit(X, y)

# Predict the arrival delay and save the slope coefficient
# Your code goes here
yHat = multipleModel.predict([[1043, 47]])
slope = multipleModel.coef_

print('Predicted arrival delay:', yHat)
print('Slope coefficients:', slope)