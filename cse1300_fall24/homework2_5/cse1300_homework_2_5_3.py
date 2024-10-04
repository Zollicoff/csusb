# Delete row 1 of myArr.

# Code:

# Load necessary package
import numpy as np

# Create array
myArr = np.array([[7, 6, 1], [9, 4, 8]])

# Delete row 1 of array
myArr = np.delete(myArr, 0, axis=0)

# Print the array
print(myArr)
