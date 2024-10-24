# The Movie table has the following columns:
# ID - integer, primary key
# Title - variable-length string
# Genre - variable-length string
# RatingCode - variable-length string
# Year - integer
# #Write a SELECT statement to select the distinct movie Ratings of year 2020, and order your result in descending order.
# Hint: Use the WHERE and DISTINCT clause.

import pandas as pd
import sqlite3
import warnings

warnings.filterwarnings("ignore")

# Read the CSV file
movie = pd.read_csv('movie1.csv')

# Display the DataFrame to check column names
print(movie.columns)

# Create an in-memory SQLite database
conn = sqlite3.connect(':memory:')

# Write the DataFrame to the SQLite database
movie.to_sql('movie', conn, if_exists='replace', index=False)

# Define the SQL query
movie_query = """
SELECT DISTINCT RatingCode 
FROM movie 
WHERE Year = 2020 
ORDER BY RatingCode DESC
"""

# Execute the query and read the results into a DataFrame
result = pd.read_sql_query(movie_query, conn)

# Print the result
print(result)
