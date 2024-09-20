# Insert 'r' into the last row of myArr.

# Code:

# Load necessary package
import numpy as np

# Create array
myArr = np.array([['n', 'x', 's', 'y'], ['q', 'v', 'l', 'p']])

# Insert character 'r' into the last row of the array
myArr[-1] = np.append(myArr[-1], 'r')

# Print the array
print(myArr)
