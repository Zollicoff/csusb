# Zachary A. Hampton
# Lab Section 83005
# Date 11-19-2023
# Lab 12

# This program converts temperatures between Celsius, Fahrenheit, and Kelvin

# Define a function to display a user greeting
def user_greeting():
    # Welcome message and display user instructions for program
    print("Hello and welcome to the temperature conversion program!"
          "\n\nThis program can convert Celsius, Farenheit, and Kelvin temperatures. "
          "Please enter numbers and decimals only.")

# define a function to ask the user if they want to run the program again, while checking for errors
def ask_again():
    while True:
        response = input("Do you want to run the program again? (yes/no): ")
        if response.lower() in ['yes', 'no']:
            return response.lower() == 'yes'
        else:
            print("Invalid input. Please enter 'yes' or 'no'.")

# define a function to get the conversion type from the user, while checking for errors
def get_conversion_type():
    while True:
        input_scale = input("\nEnter the scale of the input temperature (C for Celsius, F for Fahrenheit, K for Kelvin): ")
        output_scale = input("Enter the scale of the output temperature (C for Celsius, F for Fahrenheit, K for Kelvin): ")
        if input_scale.upper() in ['C', 'F', 'K'] and output_scale.upper() in ['C', 'F', 'K']:
            if input_scale.upper() != output_scale.upper():
                return input_scale.upper(), output_scale.upper()
            else:
                print("Invalid input. Please select two different temperature scales for conversion.")
        else:
            print("Invalid input. Please enter 'C', 'F', or 'K'.")

# Define conversion functions
def c_to_f(temp): return (temp * 9/5) + 32
def f_to_c(temp): return (temp - 32) * 5/9
def k_to_c(temp): return temp - 273.15
def c_to_k(temp): return temp + 273.15
def f_to_k(temp): return (temp + 459.67) * 5/9
def k_to_f(temp): return (temp * 9/5) - 459.67

# Define conversion dictionary
conversions = {
    'C': {'F': c_to_f, 'K': c_to_k},
    'F': {'C': f_to_c, 'K': f_to_k},
    'K': {'C': k_to_c, 'F': k_to_f}
}

# Define the main program function
def main_program():
    # Get the conversion type
    input_scale, output_scale = get_conversion_type()

    # Get user input for temperature and convert to float, while checking for errors
    while True:
        try:
            temperature = float(input(f"\nEnter a temperature in degrees {input_scale}: "))
            break
        except ValueError:
            print("Invalid input. Please enter a number.")

    # Perform conversion
    converted_temperature = conversions[input_scale][output_scale](temperature)

    print(f"\n{temperature} degrees {input_scale} is equal to {converted_temperature:.1f} degrees {output_scale}.\n")

    # Ask the user if they want to run the program again
    return ask_again()

# Call the User Greeting function
user_greeting()

# Initialize run_program variable and call the main program function
run_program = True

while run_program:
    run_program = main_program()

# Exit message
print("\nHave a great day!")
