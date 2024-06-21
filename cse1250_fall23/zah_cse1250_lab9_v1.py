# Zachary A. Hampton
# Lab Section 83005
# October 29, 2023
# Lab 9

# Greeting message and information
print("Welcome to the Metric Conversion program!"
      "\n\nThis program will convert Inches to Centimeters, "
      "Centimeters to Inches, Ounces to Grams, Grams to Ounces, "
      "Miles to Kilometers, or Kilometers to Miles.")

# Main Program Loop
run_program = True
while run_program:
    # Explain the conversion list to the user
    print("\nEnter I to convert from Inches to Centimeters."
          "\nEnter C to convert from Centimeters to Inches."
          "\nEnter O to convert from Ounces to Grams."
          "\nEnter G to convert from Grams to Ounces."
          "\nEnter M to convert from Miles to Kilometers."
          "\nEnter K to convert from Kilometers to Miles.")

    # Get conversion type input from user
    conversion_type = input("\nEnter the type of conversion of conversion you would like to do: ").lower()

    # Error check conversion type
    while conversion_type not in ['i', 'c', 'o', 'g', 'm', 'k']:
        conversion_type = input("\nInvalid input. Please enter a valid conversion type: ").lower()
    
    # Get input value with error check
    while True:
        try:
            input_value = float(input("\nEnter a measure/weight to convert: "))
            break
        except ValueError:
            print("\nInvalid input. Please enter a valid number.")
    
    # Perform conversion and create output message
    if conversion_type == 'i':
        output_value = input_value * 2.54
        message = f"{input_value} inches equals {output_value:.2f} centimeters."
    elif conversion_type == 'c':
        output_value = input_value / 2.54
        message = f"{input_value} centimeters equals {output_value:.2f} inches."
    elif conversion_type == 'o':
        output_value = input_value * 28.3495231
        message = f"{input_value} ounces equals {output_value:.2f} grams."
    elif conversion_type == 'g':
        output_value = input_value / 28.3495231
        message = f"{input_value} grams equals {output_value:.2f} ounces."
    elif conversion_type == 'm':
        output_value = input_value * 1.609344
        message = f"{input_value} miles equals {output_value:.2f} kilometers."
    elif conversion_type == 'k':
        output_value = input_value / 1.609344
        message = f"{input_value} kilometers equals {output_value:.2f} miles."
    
    # Print output message
    print(f"\n{message}")

    # Ask to run again and get input
    run_again = input("\nWould you like to make another conversion? (y/n): ").lower()

    # Error check run again input
    while run_again not in ['y', 'n']:
        run_again = input("Invalid input. Please enter 'y' or 'n': ").lower()

    # Check if program should continue
    if run_again == 'n':
        run_program = False

# Exit message
print("\nThank you for using the Metric Conversion program. Goodbye!")
