# Zachary A. Hampton
# Lab 83005
# 12-08-2023
# Lab 14 Final

# This program calculates the total due for a shipment of products using quantity, weight, and cost of each item.

# Define user greeting function
def user_greeting():
    print("This program lets the user enter products to be shipped and calculates the subtotal, "
          "tax, shipping and handling, and the total due.")

# Define get product info function (quantity, weight, cost), with error checking on inputs
def get_product_info():
    product_info = []
    item_quantity = 1
    while item_quantity != 0:
        while True:
            try:
                item_quantity = int(input("\nEnter item quantity (enter 0 if done): "))
                break
            except ValueError:
                print("ERROR- Please enter a whole number.")
        if item_quantity != 0:
            while True:
                try:
                    item_weight = float(input("Enter item weight: "))
                    break
                except ValueError:
                    print("ERROR- Please enter a number.")
            while True:
                try:
                    item_cost = float(input("Enter cost of item: "))
                    break
                except ValueError:
                    print("ERROR- Please enter a number.")
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
    state = input("Please enter the 2 letter abbreviation of the state you are shipping to: ").upper()
    while state not in states:
        state = input("\nERROR- Please enter the 2 letter abbreviation of the state you are shipping to: ").upper()
    return state

# Define calculate function
def calculate(product_info):
    box_weight = 0
    sub_total = 0
    for item in product_info:
        item_quantity, item_weight, item_cost = item
        box_weight += item_quantity * item_weight
        sub_total += item_quantity * item_cost
    shipping_cost = box_weight * .25
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
    run = input("\nWould you like to fill another order? (y/n): ").lower()
    while run not in ['y', 'n']:
        run = input("ERROR- Please enter 'y' or 'n': ").lower()
    if run == 'n':
        print("\nThanks for using this program. Have a nice day!")
    return run == 'y'

# Define main function
def main():
    user_greeting()
    run_program = True
    while run_program:
        product_info = get_product_info()
        sub_total, shipping_handling = calculate(product_info)
        state = get_state()
        tax = sub_total * .08 if state == 'CA' else 0
        total_due = sub_total + shipping_handling + tax
        print()
        print(format('Subtotal:', '<25'), format(sub_total, '>10,.2f'))
        print(format('Tax:', '<25'), format(tax, '>10,.2f'))
        print(format('Shipping and Handling:', '<25'), format(shipping_handling, '>10,.2f'))
        print(format('Total Due:', '<25'), format(total_due, '>10,.2f'))
        run_program = run_again()

# Call main function
if __name__ == "__main__":
    main()
