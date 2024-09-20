# Create the object subFirst with value 9.
# Create the object subSecond with value 40.
#Print the return value of the function sumDiff() using difference, subFirst, subSecond, and 8 as arguments.

# The code provided defines the functions.

# Code:

# Defines the function difference
def difference(x, y):
    result = x - y
    return result

# Defines the function sumDiff
def sumDiff(operation, x, y, z):
     return operation(x, y) + z

# Creates an object called subFirst with value 9
subFirst = 9

# Creates an object called subSecond with value 40
subSecond = 40

# Prints the output of the function sumDiff() using difference, subFirst, subSecond, and 8 as arguments
print(sumDiff(difference, subFirst, subSecond, 8))
