class SodaMachineFSM:
    def __init__(self):
        self.state = "Init"
        self.tot = 0
        self.selected_soda = None

        # Soda menu with names and prices
        self.sodas = {
            "Coke": 3.00,
            "Pepsi": 3.75,
            "Sprite": 2.50,
            "Fanta": 3.25,
            "DrPepper": 2.75,
            "RootBeer": 3.50,
            "MountainDew": 3.00,
            "7Up": 2.25,
            "OrangeSoda": 2.00,
            "GingerAle": 3.00,
        }

        # Valid denominations in dollars
        self.valid_denominations = [0.01, 0.05, 0.10, 0.25, 1.00, 5.00]

    def display_menu(self):
        print("\nAvailable sodas:")
        for soda, price in self.sodas.items():
            print(f"{soda}: ${price:.2f}")

    def select_soda(self, soda_name):
        if self.state == "Init":
            if soda_name in self.sodas:
                self.selected_soda = soda_name
                self.state = "Wait"
                self.tot = 0
                print(f"Soda selected: {soda_name}. Price: ${self.sodas[soda_name]:.2f}")
            else:
                print(f"Soda '{soda_name}' not found. Please choose from the menu.")
        else:
            print(f"Soda selection not allowed in the current state: {self.state}")

    def input_money(self, amount):
        try:
            amount = float(amount)
        except ValueError:
            print(f"Invalid input: '{amount}' is not a valid number.")
            return

        if amount not in self.valid_denominations:
            print(f"Invalid denomination: ${amount:.2f}. Acceptable denominations are: {self.valid_denominations}")
            return

        if self.state == "Wait":
            self.tot += amount
            print(f"Money inserted: ${amount:.2f}. Total: ${self.tot:.2f}")
            soda_cost = self.sodas[self.selected_soda]

            if self.tot >= soda_cost:
                self.transition_to_dispense(soda_cost)
        else:
            print(f"Cannot insert money in the current state: {self.state}")

    def transition_to_dispense(self, soda_cost):
        if self.tot == soda_cost:
            self.state = "DispSoda"
            print("Exact amount received. Ready to dispense soda.")
        elif self.tot > soda_cost:
            self.state = "DispChange"
            print("Overpaid. Dispensing soda and returning change.")
        else:
            self.state = "Wait"
            print("Insufficient funds. Waiting for more money.")

    def press_dispense(self):
        if self.state == "DispSoda":
            print(f"Dispensing {self.selected_soda}. Enjoy your drink!")
            self.state = "Init"
            self.selected_soda = None
        elif self.state == "DispChange":
            change = self.tot - self.sodas[self.selected_soda]
            print(f"Dispensing {self.selected_soda}. Change returned: ${change:.2f}. Enjoy your drink!")
            self.state = "Init"
            self.selected_soda = None
            self.tot = 0
        elif self.state == "Init":
            print("No soda selected. Please select a soda first.")
        else:
            print(f"Cannot dispense in the current state: {self.state}")

    def reset(self):
        print("Resetting machine.")
        self.state = "Init"
        self.tot = 0
        self.selected_soda = None

    def get_state(self):
        return self.state


# Interactive Console
if __name__ == "__main__":
    fsm = SodaMachineFSM()

    print("Welcome to the Soda Machine!")
    while True:
        if fsm.state == "Init":
            fsm.display_menu()
            soda_name = input("\nSelect a soda by name (or type 'exit' to quit): ").strip()
            if soda_name.lower() == "exit":
                print("Goodbye!")
                break
            fsm.select_soda(soda_name)
        elif fsm.state == "Wait":
            money = input("Insert money (acceptable denominations: 0.01, 0.05, 0.10, 0.25, 1.00, 5.00) or type 'cancel' to reset: ").strip()
            if money.lower() == "cancel":
                fsm.reset()
            else:
                fsm.input_money(money)
        elif fsm.state in ["DispSoda", "DispChange"]:
            fsm.press_dispense()
