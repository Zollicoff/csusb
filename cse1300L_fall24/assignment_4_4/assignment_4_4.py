# The Movie table has the following columns:
# ID - integer, primary key
# Title - variable-length string
# Genre - variable-length string
# RatingCode - variable-length string
# Year - integer
# The Rating table has the following columns:
# Code - variable-length string, primary key
# Description - variable-length string
# Write a SELECT statement to select the Title, Year, and rating Description. Display all movies, whether or not a RatingCode is available.
#Hint: Perform a LEFT JOIN on the Movie and Rating tables, matching the RatingCode and Code columns.

# Import the required libraries
import pandas as pd
import sqlite3
import warnings

# Suppress warnings
warnings.filterwarnings("ignore")
pd.set_option('display.notebook_repr_html', False)

# Create a connection to an in-memory SQLite database
def create_connection():
    return sqlite3.connect(':memory:')
conn = create_connection()

# Load the CSV file into a Pandas DataFrame
movie_df = pd.read_csv('movie2-1.csv')
rating_df = pd.read_csv('Rating.csv')

# Write the DataFrame to the SQL database
movie_df.to_sql('Movie', conn, index=False, if_exists='replace')
rating_df.to_sql('Rating', conn, index=False, if_exists='replace')

# SQL query to perform the LEFT JOIN and retrieve the desired columns
movie_query = """
SELECT Movie.Title, Movie.Year, Rating.Description
FROM Movie
LEFT JOIN Rating
ON Movie.RatingCode = Rating.Code
"""

# Execute the query and load the result into a DataFrame
movie = pd.read_sql_query(movie_query, conn)
print(movie)
