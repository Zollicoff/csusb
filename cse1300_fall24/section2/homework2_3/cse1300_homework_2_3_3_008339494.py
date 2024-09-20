# Write a function header for show() with parameters l, m, n, in that order, where m has a default value of 
# 7 and n has a default value of 12.

# The code provided includes the function body and calls the function with various arguments.

# Code:

# Defines the function show()
def show(l, m=7, n=12):
    print(str(n) + '/' + str(l) + '/' + str(m))
  
show(3, 1)
show(m=16, l=14)
show(n=15, l=4)
