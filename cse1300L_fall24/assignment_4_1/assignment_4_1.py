# The Horse table has the following columns:
# ID - integer, primary key
# RegisteredName - variable-length string
# Breed - variable-length string
# Height - decimal number
# BirthDate - date
# Write a SELECT statement to select the registered name and height for only horses that have a height between 15.0 and 16.0 (inclusive).

import pandas as pd
import sqlite3 # sql package
import warnings
warnings.filterwarnings("ignore")
# read csvfile horse1.csv
horse = pd.read_csv('horse1.csv')

pd.set_option('display.notebook_repr_html', False)
def create_connection():
    return sqlite3.connect(':memory:')
conn = create_connection()
# take data stored in Pandas DataFrame (df) and writes it into a SQL database table
horse.to_sql('horse', conn, if_exists='replace', index=False)
horse_query = "SELECT RegisteredName, Height FROM horse WHERE Height BETWEEN 15.0 AND 16.0"
horse = pd.read_sql_query(horse_query, conn)
print(horse)
