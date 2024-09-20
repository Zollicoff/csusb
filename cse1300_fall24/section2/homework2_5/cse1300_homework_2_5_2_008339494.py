# Insert 'r' into the last row of myArr.

# Code:

# Load necessary package
import numpy as np

# Create array
myArr = [['n', 'x', 's', 'y'], ['q', 'v', 'l', 'p']]

# Insert character into the last row of array
myArr = np.insert(myArr, 1, 'r', axis=0)

# Print the array
print(myArr)
