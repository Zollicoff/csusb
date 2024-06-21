# Zachary A. Hampton
# Lab Section 83005
# Date 11-05-2023
# Lab 10

# This program prompts the user to enter a fruit and weight; then displays the information.

# Greeting message and information
print("This program will let you create a list of fruist and how many pounds "
      "there are of each and then display them back to you."
      "\nWhen you are done please press return without entering a fruit.")

# Initialize two empty lists, one for the fruit types and one for the weights
fruitTypes = []
fruitWeights = []

# Initialize program_run to True
program_run = True

# Main program loop
while program_run:
    fruit = input("\nPlease enter a type of fruit (or just hit Enter to finish and "
                  "print your list): ")
    if fruit == '':
        program_run = False
    else:
        while True:
            weight = input("Please enter the weight of the fruit in pounds: ")
            try:
                float(weight)  # Try to convert the weight to a float
                break  # If the conversion succeeds, break the loop
            except ValueError:
                print("Invalid input. Please enter a number.")
        fruitTypes.append(fruit)
        fruitWeights.append(weight)

# Print the list of fruits and their weights
print("\nHere's your list of fruits and their weights:")

for i in range(len(fruitTypes)):
    message = format(fruitTypes[i], '<20') + " " + format(fruitWeights[i], '>5') + " lbs."
    print(message)

# Exit message
print("\nHave a nice day!!!!")
