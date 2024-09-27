# For the next two questions, the housing dataframe is a dataframe created from a file called txhousing.csv. The file contents are as follows:

# city,year,month,sales,volume,sales_price,listings,inventory,date
# Waco,2015,6,280,49171360,151800,999,4.5,2015.416667
# Killeen-Fort Hood,2015,6,277,41102980,135900,1361,5.6,2015.416667
# Brownsville,2015,6,82,11833474,115000,744,10.7,2015.416667
# Dallas,2015,6,6532,1960556658,242300,11014,2.2,2015.416667
# Port Arthur,2015,6,79,10864768,118900,513,7.2,2015.416667
# Kerrville,2015,6,81,16859871,175000,648,10.4,2015.416667
# Harlingen,2015,6,93,12099797,120800,1724,20.1,2015.416667
# Beaumont,2015,6,296,48007961,145200,1567,6.7,2015.416667
# Montgomery County,2015,6,1032,350936735,256300,3305,4.3,2015.416667
# Wichita Falls,2015,6,143,18820752,118800,770,6.2,2015.416667
# Midland,2015,6,218,63667557,257700,797,4.9,2015.416667
# Austin,2015,6,3301,1086689918,270200,7419,2.8,2015.416667
# Collin County,2015,6,1789,614959441,300400,2314,1.7,2015.416667
# Fort Worth,2015,6,1287,248314498,159300,2221,2.2,2015.416667
# San Antonio,2015,6,2919,701375402,199400,9105,4,2015.416667
# Bryan-College Station,2015,6,403,84025416,187400,939,3.5,2015.416667
# NE Tarrant County,2015,6,1128,364781158,241400,1451,1.8,2015.416667
# Houston,2015,6,8449,2490238594,222400,22311,3.2,2015.416667
# Temple-Belton,2015,6,213,35933886,148900,858,5.5,2015.416667
# Garland,2015,6,212,35772714,154800,208,1.2,2015.416667
# Odessa,2015,6,107,20320574,176800,245,2.5,2015.416667

# Using a descriptive statistics method, calculate the median number of homes sold ("sales") over all cities.
# The provided code imports pandas, loads the dataset, and prints your result.
# Code:

# Import packages and functions
import pandas as pd

housing = pd.read_csv('txhousing.csv')

medianHomes = housing['sales'].median()

print('Median:', medianHomes)
