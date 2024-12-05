# Researchers collected measurements from loblolly pines, and their findings are contained in loblollySample.csv

# Download loblollySample.csv. Split the dataset into training/validation and test datasets using train_test_split() with the following parameters:

# The original dataframe
# The test_size parameter set to the test proportion
# The random_state parameter set to rng (which is defined in the provided code)

# The provided code imports the relevant libraries, loads the dataset, sets the proportions of training, validation, and test data, splits the dataset, prints the sizes of these samples, and prints the test dataset.

# Code:

# Import packages and functions
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split

# Use the new-style random number generator
rng = np.random.default_rng(41)
# Extract an integer seed from rng to use as random_state
seed = rng.integers(0, 4294967295) 

# Load the dataset
loblolly = pd.read_csv('loblollySample.csv')

# Set proportions of train-validate-test split
trainProportionPercent = 0.7
validateProportionPercent = 0.1
testProportionPercent = 0.2

# Split dataset into training/validation data and testing data
trainAndValidate, testDataset = train_test_split(
    loblolly,
    test_size=testProportionPercent,
    random_state=seed
)

# Split training/validation data into training data and validation data
# Use the same seed to keep things consistent
trainDataset, validateDataset = train_test_split(
    trainAndValidate, 
    train_size=trainProportionPercent/(trainProportionPercent+validateProportionPercent),
    random_state=seed
)

# Print split sizes and test dataset
print('original dataset:', len(loblolly), 
    '\ntrain_data:', len(trainDataset), 
    '\nvalidation_data:', len(validateDataset), 
    '\n\ntest_data:', len(testDataset),
    '\n', testDataset
)
