# Using the loblolly pines dataset from question 2, calculate the mean squared error metric for the following model using the true values and the predicted values. Then calculate the root mean squared error.
# The provided code contains the necessary imports, loads the dataset, initializes the polynomial regression model, fits the model, and prints the metrics.

# Code:

# Import packages and functions
import pandas as pd
import numpy as np # Missing in template
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.metrics import mean_squared_error

# Load the dataset
pines = pd.read_csv('loblollySample.csv')

# Store relevant columns as variables
X = pines['age']
y = pines['height']

# Initialize the model -- polynomial regression model
polyFeatures = PolynomialFeatures(degree=2, include_bias=False)
xPoly = polyFeatures.fit_transform(X.values.reshape(-1, 1))
polyModel = LinearRegression()

# Fit the model
polyModel = polyModel.fit(xPoly, y)

# Make predictions
yPredicted = polyModel.predict(xPoly)

# Evaluate accuracy

# Calculate Mean Squared Error (MSE)
MSE = mean_squared_error(y, yPredicted)

# Calculate Root Mean Squared Error (RMSE)
RMSE = np.sqrt(MSE)

# Print metrics
print('Mean Squared Error (MSE) =', MSE)
print('Root Mean Squared Error (RMSE) =', RMSE)
