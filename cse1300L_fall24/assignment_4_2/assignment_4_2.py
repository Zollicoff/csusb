# The Movie table has the following columns:
# ID - integer, primary key
# Title - variable-length string
# Genre - variable-length string
# RatingCode - variable-length string
# Year - integer
# #Write a SELECT statement to select the distinct movie Ratings of year 2020, and order your result in descending order.
# Hint: Use the WHERE and DISTINCT clause.

import pandas as pd
import sqlite3 # sql package
import warnings

warnings.filterwarnings("ignore")
# read csvfile movie1.csv

movie = pd.read_csv('movie1.csv')
pd.set_option('display.notebook_repr_html', False)
def create_connection():
    return sqlite3.connect(':memory:')
conn = create_connection()
# take data stored in Pandas DataFrame (df) and writes it into a SQL database table
movie.to_sql('movie', conn, if_exists='replace', index=False)
movie_query = """
SELECT DISTINCT RatingCode
FROM movie
WHERE Year = 2020
ORDER BY RatingCode DESC
"""

movie = pd.read_sql_query(movie_query, conn)
print(movie)
