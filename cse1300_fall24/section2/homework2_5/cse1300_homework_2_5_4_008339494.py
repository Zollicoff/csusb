# Flatten myArray in row-major order.

# Code:

# Load necessary package
import numpy as np

# Create array
myArray = [[4, 5, 1, 6], [3, 2, 9, 8]]

# Flatten array
myArray = np.array(myArray).flatten()

# Print the array
print(myArray)
