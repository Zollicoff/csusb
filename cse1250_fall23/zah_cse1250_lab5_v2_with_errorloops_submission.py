# Zachary Hampton
# October 1, 2023
# Lab Section 83005
# Lab 5

# This program will convert degrees Celsius to degrees Fahrenheit.

# Welcome message and user instructions for program
print("This program will convert degrees Celsius to degrees Fahrenheit.")
print("Please enter the temperature in Celsius; you may use decimals.")
print()

# Get user input for degrees Celsius with error loop to prevent invalid input
while True:
    try:
        celsius = float(input("Enter a temperature in degrees Celsius: "))
        break
    except ValueError:
        print("Invalid input. Only numbers are allowed.")
        print()

# Perform arithmetic operations and store results in variables
fahrenheit = (celsius * 9/5) + 32

# Display results
print()
print(f"{celsius} degrees Celsius is equal to {fahrenheit:.1f} degrees Fahrenheit.")

# End of program salutation
print()
print("Have a great day!")
