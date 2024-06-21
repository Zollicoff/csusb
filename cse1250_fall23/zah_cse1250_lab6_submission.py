# Zachary Hampton
# October 8, 2023
# Lab Section 83005
# Lab 6

# This program will calculate the cost of gasoline for a trip

# Welcome message and user instructions
print("This program will calculate the cost of gasoline for a trip.\n"
      "You will need to know your car's MPG, what you paid for a gallon of gas, and the distance in miles you traveled.\n")

# Get user input for distance, mpg, and cost per gallon - and error check
while True:
    try:
        distance = float(input("Please enter the distance traveled in miles: "))
        mpg = float(input("Please enter the Miles Per Gallon for this trip: "))
        cost_per_gallon = float(input("Enter the Cost Per Gallon paid: "))
        break
    except ValueError:
        print("Invalid input. Please enter a number or a decimal.\n")

# Calculate the total cost of gas for the trip
total_cost = ( distance / mpg ) * cost_per_gallon

# Print the total cost of gas for the trip and end of program salutation
print(f"\nThe cost of gas for this trip is/was: ${total_cost:.2f}\n\n"
      "Have a nice day!\n")

# Ask user to press enter to exit the program
input("Press enter to exit the program...")
