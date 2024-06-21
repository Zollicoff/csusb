# Program description

# Program loop
run = True 
while run:
    
    # User greeting
    print("Please type R for Red, G for Green, or B for Blue.")
    print()

    # Error loop
    runAgain = True
    while runAgain:
        
        # Get input for color choice
        colorChoice = input("Enter a color (R/G/B): ").upper()
        print()
        
        # Display output based on colorChoice
        if colorChoice == 'R':
            print('Your chosen color is RED')
            runAgain = False
        elif colorChoice == 'G':
            print('Your chosen color is GREEN')
            runAgain = False
        elif colorChoice == 'B':
            print('Your chosen color is BLUE')
            runAgain = False
        else:
            print('INPUT ERROR: Please type a R, G, or B.')

    print()
    
    error = True
    while error == False:
        # Run again input
        choice = input('Would you like to run the program again (y or n): ').lower()

        # Control program loop
        if choice == 'n':
            run = False
            error = False
        elif choice != 'y':
            print('INPUT ERROR: Please type a y or n.')
    
    print()
    print()

# Exit mesage
print("Have a nice day!!!")