# Zachary A. Hampton
# Lab Section 83005
# October 29, 2023
# Lab 9

# Greeting message and information
print("Welcome to the Metric Conversion program!\n\nThis program will convert Inches to Centimeters, Centimeters to Inches, Ounces to Grams, Grams to Ounces, Miles to Kilometers, or Kilometers to Miles.")

# Define conversion factors and messages
conversion_dict = {
    'i': {'factor': 2.54, 'message': 'inches equals {} centimeters.'},
    'c': {'factor': 1 / 2.54, 'message': 'centimeters equals {} inches.'},
    'o': {'factor': 28.3495231, 'message': 'ounces equals {} grams.'},
    'g': {'factor': 1 / 28.3495231, 'message': 'grams equals {} ounces.'},
    'm': {'factor': 1.609344, 'message': 'miles equals {} kilometers.'},
    'k': {'factor': 1 / 1.609344, 'message': 'kilometers equals {} miles.'}
}

# Main Program Loop
while True:
    # Explain the conversion list to the user
    print("\nEnter I to convert from Inches to Centimeters, C to convert from Centimeters to Inches, O to convert from Ounces to Grams, G to convert from Grams to Ounces, M to convert from Miles to Kilometers, or K to convert from Kilometers to Miles.")

    # Get conversion type input from user
    conversion_type = input("\nEnter the type of conversion of conversion you would like to do: ").lower()

    # Error check conversion type
    while conversion_type not in conversion_dict.keys():
        conversion_type = input("\nInvalid input. Please enter a valid conversion type: ").lower()

    # Get input value with error check
    while True:
        try:
            input_value = float(input("\nEnter a measure/weight to convert: "))
            break
        except ValueError:
            print("\nInvalid input. Please enter a valid number.")

    # Perform conversion and create output message
    output_value = input_value * conversion_dict[conversion_type]['factor']
    message = format(input_value, '.2f') + " " + conversion_dict[conversion_type]['message'].format(format(output_value, '.2f'))

    # Print output message
    print("\n" + message)

    # Ask to run again and get input
    run_again = input("\nWould you like to make another conversion? (y/n): ").lower()

    # Error check run again input
    while run_again not in ['y', 'n']:
        run_again = input("Invalid input. Please enter 'y' or 'n': ").lower()

    # Check if program should continue
    if run_again == 'n':
        break

# Exit message
print("\nThank you for using the Metric Conversion program. Goodbye!")
