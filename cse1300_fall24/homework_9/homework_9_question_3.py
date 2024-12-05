# The sleep.csv
# Download sleep.csv dataset contains data on sleep habits for 22 randomly selected mammals. Each mammal is categorized as an omnivore, herbivore, carnivore, or insectivore.
# Initialize a k-nearest neighbors classification model with k=4.
# The provided code contains the necessary imports, loads the dataset, fits the model, and applies the model.

# Code:

# Import packages and functions
import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split

# Import dataset
sleep = pd.read_csv('sleep.csv')

# Create input matrix X and output matrix y
X = sleep[['brainwt', 'bodywt']]
y = sleep[['vore']]

# Initialize k-nearest neighbors classification model
knnModel = KNeighborsClassifier(n_neighbors=4)

# Fit the model
knnModel = knnModel.fit(X, np.ravel(y))

# Print predictions
print(knnModel.predict(X))
