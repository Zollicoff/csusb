# The dataset SDSS.csv
#D ownload SDSS.csv contains 17 observational features and one class feature for 10000 deep sky objects observed by the Sloan Digital Sky Survey. Use sklearn's KNeighborsClassifier function to perform kNN classification to classify each object by the object's redshift and u-g color.

# Import the necessary modules for kNN classification
# Create a dataframe X with features redshift and u_g
# Create dataframe y with feature class
# Initialize a kNN model with k=3
# Fit the model using the training data
# Find the predicted classes for the test data
# Calculate the accuracy score and confusion matrix

# Ex: If the feature u is used rather than u_g, the output is:

# Accuracy score is 0.979
# [[1452    7   38]
# [  18  268    0]
# [   0    0 1217]]

## Import needed packages for classification
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split

# Import packages for evaluation
from sklearn.metrics import accuracy_score, confusion_matrix

import pandas as pd
import numpy as np

# Load the dataset
skySurvey = pd.read_csv('SDSS.csv')

# Create a new feature from u - g
skySurvey['u_g'] = skySurvey['u'] - skySurvey['g']

# Create dataframe X with features redshift and u_g
X = skySurvey[['redshift', 'u_g']]

# Create dataframe y with feature class
y = skySurvey['class']

np.random.seed(42)

# Split data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

# Initialize model with k=3
skySurveyKnn = KNeighborsClassifier(n_neighbors=3)

# Fit model using X_train and y_train
skySurveyKnn.fit(X_train, y_train)

# Find the predicted classes for X_test
y_pred = skySurveyKnn.predict(X_test)

# Calculate accuracy score
score = accuracy_score(y_test, y_pred)

# Print accuracy score
print('Accuracy score is %.3f' % score)

# Print confusion matrix
print(confusion_matrix(y_test, y_pred))
