#The Horse table has the following columns:
# ID - integer, primary key
# RegisteredName - variable-length string
# Breed - variable-length string
# Height - decimal number
# BirthDate - date
# Write a SELECT statement to select the registered name and height for only horses that have an above average height. Order the results by height (ascending).
# Hint: Use a subquery to find the average height.

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
horse_df = pd.read_csv('horse2-1.csv')

# Write the DataFrame to the SQL database
horse_df.to_sql('Horse', conn, index=False, if_exists='replace')

# SQL query to perform the LEFT JOIN and retrieve the desired columns
horse_query = """
SELECT RegisteredName, Height
FROM Horse
WHERE Height > (SELECT AVG(Height) FROM Horse)
ORDER BY Height ASC
"""

# Execute the query and load the result into a DataFrame
horse = pd.read_sql_query(horse_query, conn)
print(horse)
