# Zachary Hampton
# Lab Section 83005
# October 9, 2023
# Lab 7

# This program prompts the user to enter either 'A', 'B', or 'C', and displays a corresponding sentence.

# Welcome message salutation
print("Please enter an A, B, or C to display a particular sentence. Use capital letters.")

# Get and check user input and apply to fruit variable
while True:
    letter = input("\n Please enter an A, B, or C: ")
    if letter in ['A', 'B', 'C']:
        break
    else:
        print("\nInvalid input. Please enter A, B, or C.")

# Check against user input and display corresponding sentence
if letter == 'A':
    print("\nYou got an Apple!")
elif letter == 'B':
    print("\nYou got a Banana!")
elif letter == 'C':
    print("\nYou got a Coconut!")

# Exit message salutation
print("\nThank you for using this program.\n\n"
      "Have a nice day!")

# Exit program prompt
input("\nPress enter to exit the program...")
