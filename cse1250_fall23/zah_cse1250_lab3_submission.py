# Zachary Hampton
# September 11, 2023
# Lab Section 83005
# Lab 3

# This program lets a user enter any integer base and integer exponent and displays the result

# Welcome message and user instructions for program
print("This program will let you raise any integer to any integer power.")
print("Remmber to use only Whole numbers.")
print()

# User input for the base and exponent
base = int(input("Please enter the base Number? "))
exponent = int(input("What power of " + str(base) + "? "))
print()

# The calculation process
result = base ** exponent

# Output displays the result of the calculation
print(base, "to the power of", exponent, "is", result)
print()

# Exit message
print("Thanks you for using the Power Calculator!")
print("Have a nice day!")

# Require user to press enter to exit program
input("Press Enter to exit the program...")