# Zachary A. Hampton
# Lab Section 83005
# Date 11-12-2023
# Lab 11

# This program lets the user lookup a state's name from a state's abbreviation or a state abbreviation from a state's name

# Create state list for lookup
states = [
    'ALABAMA', 'ALASKA', 'ARIZONA', 'ARKANSAS', 'CALIFORNIA', 'COLORADO',
    'CONNECTICUT', 'DELAWARE', 'FLORIDA', 'GEORGIA', 'HAWAII', 'IDAHO',
    'ILLINOIS', 'INDIANA', 'IOWA', 'KANSAS', 'KENTUCKY', 'LOUISIANA',
    'MAINE', 'MARYLAND', 'MASSACHUSETTS', 'MICHIGAN', 'MINNESOTA',
    'MISSISSIPPI', 'MISSOURI', 'MONTANA', 'NEBRASKA', 'NEVADA',
    'NEW HAMPSHIRE', 'NEW JERSEY', 'NEW MEXICO', 'NEW YORK',
    'NORTH CAROLINA', 'NORTH DAKOTA', 'OHIO', 'OKLAHOMA', 'OREGON',
    'PENNSYLVANIA', 'RHODE ISLAND', 'SOUTH CAROLINA', 'SOUTH DAKOTA',
    'TENNESSEE', 'TEXAS', 'UTAH', 'VERMONT', 'VIRGINIA', 'WASHINGTON',
    'WEST VIRGINIA', 'WISCONSIN', 'WYOMING'
]

# Create state abbreviation list for lookup
abbreviations = [
    'AL', 'AK', 'AZ', 'AR', 'CA', 'CO', 'CT', 'DE', 'FL', 'GA', 'HI', 'ID',
    'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MD', 'MA', 'MI', 'MN',
    'MS', 'MO', 'MT', 'NE', 'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND',
    'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT',
    'VA', 'WA', 'WV', 'WI', 'WY'
] 

# Greet the user an tell them what the program does
print("Welcome to the State Lookup Program!"
      "\nThis program will let you type in a state name and display that "
      "state's abbreviation, or type in a state abbreviation and display "
      "that state's name.")

# Main program loop that runs until the user wants to quit
while True:
    # Prompt the user for the type of look S for state name or A for state abbreviation
    type_of_lookup = input("\nPlease type 'S' to lookup by state name or 'A' to "
                           "lookup by state abbreviation: ").upper()

    # Error check the type of lookup
    if type_of_lookup not in ['S', 'A']:
        print("\nInvalid input. Please enter either 'S' or 'A'.")
        continue

    # Get the state's name from the user and error check the input
    if type_of_lookup == 'S':
        found = False
        first_iteration = True
        while not found:
            state = input("Please enter a state name: " if first_iteration else 
                          "\nINPUT ERROR: Please enter a correct state name: ").upper()
            first_iteration = False
            for i in range(len(states)):
                if states[i] == state:
                    print("\nThe abbreviation for", state, "is", abbreviations[i])
                    found = True
                    break
    # Get the state's abbreviation from the user and error check the input 
    else:
        found = False
        first_iteration = True
        while not found:
            abbreviation = input("Please enter a state abbreviation: " if first_iteration else 
                                 "\nINPUT ERROR: Please enter a correct state abbreviation: ").upper()
            first_iteration = False
            for i in range(len(abbreviations)):
                if abbreviations[i] == abbreviation:
                    print("\nThe state with abbreviation", abbreviation, "is", states[i])
                    found = True
                    break
    
    # Prompt the user if they want to run the program again and error check the input
    while True:
        run_again = input("\nDo you want to run the program again? (yes/no): ").lower()
        if run_again not in ['yes', 'no']:
            print("\nInvalid input. Please enter either 'yes' or 'no'.")
        else:
            break

    if run_again != 'yes':
        break

# Exit message
print("\nThank you for using the State Lookup Program!"
      "\n\nHave a nice day!")
