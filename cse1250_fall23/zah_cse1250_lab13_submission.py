# Zachary A. Hampton
# Lab 83005
# 11-26-2023
# Lab 13

# This program converts ounces to grams, inches to centimeters, and kilometers to miles.

# Define greet user function
def greet_user():
    # Greet the user
    print("\nWelcome to the conversion program!"
          "\n\nThis program will convert Inches/Centimeters, Ounces/Grams, and Kilometers/Miles either way depending on which is entered first.")

# Define calculate and display function
def get_conversion_type():
    # Get the conversion type from the user
    while True:
        conversion_type = input("\nEnter I or C to convert from Inches or Centimeters.\n"
                                "Enter O or G to convert from Ounces or Grams.\n"
                                "Enter M or K to convert from Miles to Kilometers.\n"
                                "\nEnter the conversion you would like to do: ").upper()
        if conversion_type in ["O", "G", "I", "C", "M", "K"]:
            return conversion_type
        else:
            print("Invalid input. Please try again.")

# Define ask to continue function
def calculate_and_display(conversion_type):
    # Get the value from the user and perform the conversion
    while True:
        try:
            value = float(input("\nEnter a measure/weight to convert: "))
            break
        except ValueError:
            print("Invalid input. Please enter a number.")
    if conversion_type == "O":
        result = value * 28.3495231
        message = format(value, '.2f') + " ounces is equal to " + format(result, '.2f') + " grams."
    elif conversion_type == "G":
        result = value / 28.3495231
        message = format(value, '.2f') + " grams is equal to " + format(result, '.2f') + " ounces."
    elif conversion_type == "I":
        result = value * 2.54
        message = format(value, '.2f') + " inches is equal to " + format(result, '.2f') + " centimeters."
    elif conversion_type == "C":
        result = value / 2.54
        message = format(value, '.2f') + " centimeters is equal to " + format(result, '.2f') + " inches."
    elif conversion_type == "M":
        result = value * 1.609344
        message = format(value, '.2f') + " miles is equal to " + format(result, '.2f') + " kilometers."
    else:  # conversion_type == "K"
        result = value / 1.609344
        message = format(value, '.2f') + " kilometers is equal to " + format(result, '.2f') + " miles."
    print("\n" + message)

# def ask to continue function
def ask_to_continue():
    # Ask the user if they want to continue
    while True:
        continue_choice = input("\nWould you like to run the program again? (y/n): ").lower()
        if continue_choice in ['y', 'n']:
            return continue_choice == 'y'
        else:
            print("Invalid input. Please enter 'y' or 'n'.")

# Define show exit message function
def show_exit_message():
    # Show exit message
    print("\nHave a nice day!")

# Define main program function
def main():
    # Main program
    greet_user()
    run_program = True
    while run_program:
        conversion_type = get_conversion_type()
        calculate_and_display(conversion_type)
        run_program = ask_to_continue()
    show_exit_message()

if __name__ == "__main__":
    main()
    