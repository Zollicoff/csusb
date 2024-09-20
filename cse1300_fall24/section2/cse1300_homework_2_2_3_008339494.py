# Create a dictionary exampleDict with indexes 'tarantula', 'hornet', and 'tuna', and values 0.11, 0.05, and 1, respectively.
# Modify the value of the element with key 'tuna' to 0.98.
# Remove the element with key 'hornet' from exampleDict.

# The code provided prints all results.
 
# Code:

# Create a dictionary with indexes 'tarantula', 'hornet', and 'tuna', and values 0.11, 0.05, and 1
exampleDict = {'tarantula': 0.11, 'hornet': 0.05, 'tuna': 1}
print(exampleDict)

# Modify the value of the element with key 'tuna' to 0.98
exampleDict['tuna'] = 0.98
print(exampleDict)

# Remove element with key 'hornet'
exampleDict.pop('hornet')
print(exampleDict)
