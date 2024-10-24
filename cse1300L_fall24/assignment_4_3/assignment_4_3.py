# The Movie table has the following columns:
# ID - integer, primary key
# Title - variable-length string
# Genre - variable-length string
# RatingCode - variable-length string
# Year - integer
# Write a SELECT statement to select the year and the total number of movies for that year, the total number of movies for that year should be greater or equal to 2. Hint: Use the COUNT() function, GROUP BY and HAVING clause.

import pandas as pd
import sqlite3 # sql package
import warnings

warnings.filterwarnings("ignore")

# read csvfile movie1.csv
movie = pd.read_csv('movie2.csv')

# Display the DataFrame to check column names
pd.set_option('display.notebook_repr_html', False)
def create_connection():
    return sqlite3.connect(':memory:')
conn = create_connection()

# take data stored in Pandas DataFrame (df) and writes it into a SQL database table
movie.to_sql('Movie', conn, if_exists='replace', index=False)
movie_query = '''
SELECT Year, COUNT(*) as Total
FROM Movie
GROUP BY Year
HAVING COUNT(*) >= 2
''' 

movie = pd.read_sql_query(movie_query, conn)
print(movie)
