# Insert 'r' into the last row of myArr.

# Code:

# Load necessary package
import numpy as np

# Create array
myArr = [['n', 'x', 's', 'y'], ['q', 'v', 'l', 'p']]

# Insert character into the last row of array
myArr = np.array(myArr)
myArr[-1, 0] = 'r'

# Print the array
print(myArr)
