# Zachary A. Hampton
# Lab 83005
# 12-08-2023
# Lab 14 Final

# This program calculates the total due for a shipment of products using quantity, weight, and cost of each item.

# Define user greeting function
def user_greeting():
    print("This program lets the user enter products to be shipped and calculates the subtotal, "
          "tax, shipping and handling, and the total due.")

# Define a generalized input validation function
def get_valid_input(prompt, error_message, input_type):
    while True:
        try:
            return input_type(input(prompt))
        except ValueError:
            print(error_message)

# Define get product info function (quantity, weight, cost), with error checking on inputs
def get_product_info():
    product_info = []
    while True:
        item_quantity = get_valid_input("\nEnter item quantity (enter 0 if done): ",
                                        "ERROR- Please enter a whole number.", int)
        if item_quantity == 0:
            break
        item_weight = get_valid_input("Enter item weight: ",
                                      "ERROR- Please enter a number.", float)
        item_cost = get_valid_input("Enter cost of item: ",
                                    "ERROR- Please enter a number.", float)
        product_info.append([item_quantity, item_weight, item_cost])
    return product_info

# Define get state function
def get_state():
    states = [
        'AL', 'AK', 'AZ', 'AR', 'CA', 'CO', 'CT', 'DE', 'FL', 'GA', 'HI', 'ID', 
        'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MD', 'MA', 'MI', 'MN',
        'MS', 'MO', 'MT', 'NE', 'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND',
        'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT',
        'VA', 'WA', 'WV', 'WI', 'WY'
    ]
    while True:
        state = input("Please enter the 2-letter abbreviation of the state you are shipping to: ").upper()
        if state in states:
            return state
        print("ERROR- Invalid state abbreviation. Please try again.")

# Define calculate function
def calculate(product_info):
    box_weight = 0
    sub_total = 0
    for item in product_info:
        item_quantity, item_weight, item_cost = item
        box_weight += item_quantity * item_weight
        sub_total += item_quantity * item_cost
    shipping_cost = box_weight * 0.25
    if box_weight < 10:
        handling = 1
    elif box_weight > 100:
        handling = 5
    else:
        handling = 3
    shipping_handling = shipping_cost + handling
    return sub_total, shipping_handling

# Define run again function
def run_again():
    while True:
        run = input("\nWould you like to fill another order? (y/n): ").lower()
        if run in ['y', 'n']:
            if run == 'n':
                print("\nThanks for using this program. Have a nice day!")
            return run == 'y'
        print("ERROR- Please enter 'y' or 'n'.")

# Define main function
def main():
    user_greeting()
    while True:
        product_info = get_product_info()
        sub_total, shipping_handling = calculate(product_info)
        state = get_state()
        tax = sub_total * 0.08 if state == 'CA' else 0
        total_due = sub_total + shipping_handling + tax
        print()
        print(format('Subtotal:', '<25'), format(sub_total, '>10,.2f'))
        print(format('Tax:', '<25'), format(tax, '>10,.2f'))
        print(format('Shipping and Handling:', '<25'), format(shipping_handling, '>10,.2f'))
        print(format('Total Due:', '<25'), format(total_due, '>10,.2f'))
        if not run_again():
            break

# Call main function
if __name__ == "__main__":
    main()
