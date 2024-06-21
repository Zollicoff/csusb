# Zachary A. Hampton
# Lab Section 83005
# October 22, 2023
# Lab 8

# This program lets a user do calculations with two numbers
# Addition, subtraction, multiplication, division, truncating division, and exponentiation

# User greeting and instructions for the program
print("This program will let you do addition, subtraction, multiplication,"
      "division, truncating division, and exponentiation for any two numbers.\n")
print("Enter 'a' for addition, 's' for subtraction, 'm' for multiplication,"
      "'d' for division, 't' for truncating division, and 'e' for exponentiation.")

# Initialize a variable to control the program loop
run_program = 'Y'

while run_program.upper() == 'Y':
    # Get the user input for the type of calculation they want to do
    operation = input("\nPlease choose the kind of calculation you want to do: ").lower()

    # Error check this input using a while loop
    while operation not in ['a', 's', 'm', 'd', 't', 'e']:
        operation = input("Error, please choose an 'a', 's', 'm', 'd', 't', or 'e': ").lower()

    # Get the user input for first and second number while error checking for proper input and division by zero
    while True:
        try:
            num1 = float(input("\nPlease enter the first number: "))
            num2 = float(input("Please enter the second number: "))
            if (operation in ['d', 't'] and num2 == 0):
                print("Error: Division by zero is not allowed. Please enter a non-zero second number.")
                continue
            break
        except ValueError:
            print("Invalid input. Please start over and enter a number or a decimal.")

    # Perform the appropriate calculation and assign the corresponding word to the variable
    if operation == 'a':
        result = num1 + num2
        message = 'plus'
    elif operation == 's':
        result = num1 - num2
        message = 'minus'
    elif operation == 'm':
        result = num1 * num2
        message = 'multiplied by'
    elif operation == 'd':
        result = num1 / num2
        message = 'divided by'
    elif operation == 't':
        result = num1 // num2
        message = 'truncating division by'
    elif operation == 'e':
        result = num1 ** num2
        message = 'raised to the power of'

    # Display and format the answer
    print("\n{} {} {} equals {:,}\n".format(num1, message, num2, result))

    # Ask the user if they want to run the program again
    run_program = input("Would you like to do another calculation? (Y or N): ")

    # Error check this input
    while run_program.upper() not in ['Y', 'N']:
        run_program = input("Error, please enter 'Y' for yes or 'N' for no: ")

# Display an exit message
print("\nThank you for using the Number Calculator. Goodbye!\n")

# Ask the user to press enter to end the program
input("Press enter to end the program...")
