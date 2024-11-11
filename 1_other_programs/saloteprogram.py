# Program loop
run = True
while run:

    # Creating empty lists
    fruits = []
    weights = []

    # Initialize and create variable to control the user input loop
    again = True

    # User input and loop
    while again == True:
        fruit = input('Please enter a type of fruit: ')
        if fruit == '':
            again = False
        else:
            weight = input('Please enter the weight of the fruit in pounds: ')

            # Appending the lists (adding input to lists)
            fruits.append(fruit)
            weights.append(float(weight))
        print()

    # Initializing index variable to control print loop
    index = 0

    # Printing and formatting the list
    while index < len(fruits):
        print(f"{fruits[index]:<20} {weights[index]:>15.2f} lbs")  # Left-align fruit, right-align weight with 2 decimals
        index += 1
