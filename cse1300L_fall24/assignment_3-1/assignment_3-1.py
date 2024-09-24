# The mtcars dataset contains data from the 1974 Motor Trends magazine, and includes 10 features of performance and design from a sample of 32 cars.
# Import the csv file mtcars.csv 
# Download mtcars.csv as a data frame using a pandas module function.
# Select a sample of 10 cars, without replacement, set the random state as 5, from the cars dataframe
# Find the mean, median, and mode of the column wt.
# Find the standard deviation of the column mpg, from the sample10Cars dataframe
# Find the standard deviation of the column mpg, from the cars dataframe
# Calculate the disp features' skewness, from the cars dataframe.

# Here is the template:

import pandas as pd

# Read in the file mtcars.csv
cars = pd.read_csv('mtcars.csv')

# Select a sample of 10 cars, without replacement, set the random state as 5
# from the cars dataframe
sample10Cars = cars.sample(n=10, replace=False, random_state=5)
print(sample10Cars)

# Find the mean of the column wt, from the cars dataframe
mean = cars['wt'].mean()# Your code here

# Find the median of the column wt, from the cars dataframe
median = cars['wt'].median()# Your code here

# Find the standard deviation of the column mpg, from the sample10Cars dataframe
stdSample = sample10Cars['mpg'].std(ddof=1)

# Find the standard deviation of the column mpg, from the cars dataframe
std = cars['mpg'].std(ddof=0)

# Calculate the disp features' skewness, from the cars dataframe. 
skew = cars['disp'].skew()

print("mean = {:.5f}, median = {:.3f}".format(mean, median))
print("stdSample = {:.3f}, std = {:.3f}".format(stdSample, std))
print("skew = {:.3f}".format(skew))