# importing the Numpy library, and set the short name, np
import numpy as np

# Question : Create a 1D array, array1, of numbers from 0 to 9
array1 = np.arange(10)
print(array1)

# Question : Create a 2×3×3 numpy array, array2, of all one’s
array2 = np.ones((2,3,3))
print(array2)

# Question: Convert a 1D array, array1, to a 2D array with 2 rows, array3 
# (tips: the item numbers are the same, and you may use '-1' if you are not sure about the column value)
array3 = array1.reshape(2, -1)
print(array3)

# Question: Print the median, medianArray3 of array3
medianArray3 = np.median(array3)
print(medianArray3)