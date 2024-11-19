# LaGuardia Airport (LGA) is a major airport serving New York City. LGA wanted to predict the arrival delay of an incoming flight based on the departure delay. 50 recent flights were randomly selected, and the arrival and departure delays (in minutes) were recorded. Their data is contained in flightsLGA.csv
# Download flightsLGA.csv
# Write code to initialize a linear regression model for predicting arrival delay based on departure delay, and fit the model.
# The provided code has the necessary imports, loads the dataset, and prints the model's intercept.

# Code:

# Import packages and functions
import pandas as pd
from sklearn.linear_model import LinearRegression

# Import flights and remove missing values
flights = pd.read_csv('flightsLGA.csv').dropna()

# Define X and y and convert to proper format
X = flights[['dep_delay']].values.reshape(-1, 1)
y = flights[['arr_delay']].values.reshape(-1, 1)

# Initialize and fit a linear regression model
linearModel = LinearRegression()
linearModel.fit(X, y)

print('Intercept:', linearModel.intercept_[0])