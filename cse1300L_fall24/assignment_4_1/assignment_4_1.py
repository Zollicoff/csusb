# The Horse table has the following columns:
# ID - integer, primary key
# RegisteredName - variable-length string
# Breed - variable-length string
# Height - decimal number
# BirthDate - date
# Write a SELECT statement to select the registered name and height for only horses that have a height between 15.0 and 16.0 (inclusive).

import pandas as pd
import sqlite3
import warnings

warnings.filterwarnings("ignore")

# Read the corrected CSV file
horse = pd.read_csv('horse1.csv')

# Display the DataFrame to check column names
print(horse.columns)

# Create an in-memory SQLite database
conn = sqlite3.connect(':memory:')

# Write the DataFrame to the SQLite database
horse.to_sql('horse', conn, if_exists='replace', index=False)

# Define the SQL query
horse_query = "SELECT RegisteredName, Height FROM horse WHERE Height BETWEEN 15.0 AND 16.0"

# Execute the query and read the results into a DataFrame
result = pd.read_sql_query(horse_query, conn)

# Print the result
print(result)
