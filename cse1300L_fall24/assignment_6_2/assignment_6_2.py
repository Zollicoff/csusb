# The titanic dataset contains data on 887 Titanic passengers, including each passenger's survival status, embarkation location, cabin class, and sex. Write a program that performs the following tasks:

# Load the dataset in titanic.csv as titanic. titanic.csv 

# Download titanic.csv
# Create a new data frame, firstSouth, by subsetting titanic to include instances where a passenger is in the first class cabin (pclass feature is 1) and boarded from Southampton (embarked feature is S).
# Create a new data frame, secondThird, by subsetting titanic to include instances where a passenger is either in the second (pclass feature is 2) or third class (pclass feature is 3) cabin.
# Create bar charts for the following:

# Passengers in first class who embarked in Southampton grouped by sex
# Passengers in second and third class grouped by survival status

# Please complete the following code:

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load titanic.csv
titanic = pd.read_csv('titanic.csv')

# Subset the titanic dataset to include first class passengers who embarked in Southampton
firstSouth = titanic[(titanic['pclass'] == 1) & (titanic['embarked'] == 'S')]

# Subset the titanic dataset to include either second or third class passengers
secondThird = titanic[(titanic['pclass'] == 2) | (titanic['pclass'] == 3)]

# Print the first few rows for debugging
print(firstSouth.head())
print(secondThird.head())

# Create a bar chart for the first class passengers who embarked in Southampton grouped by sex
plt.figure(figsize=(10, 5))
sns.countplot(data=firstSouth, x='pclass', hue='sex', palette=['#1f77b4', '#ff7f0e'])  # Blue for female, orange for male
plt.title('First Class Passengers from Southampton by Sex')
plt.xlabel('pclass')
plt.ylabel('count')
plt.legend(title="Sex")
plt.savefig('titanic_bar_1.png')
plt.show()

# Create a bar chart for the second and third class passengers grouped by survival status
plt.figure(figsize=(10, 5))
sns.countplot(data=secondThird, x='pclass', hue='survived', palette=['#1f77b4', '#ff7f0e'])  # Orange for not survived, blue for survived
plt.title('Second and Third Class Passengers by Survival Status')
plt.xlabel('pclass')
plt.ylabel('count')
plt.legend(labels=["Not Survived", "Survived"], title="Survived")
plt.savefig('titanic_bar_2.png')
plt.show()
