class State:
    def __init__(self, fsm):
        self.fsm = fsm

    def handle(self):
        raise NotImplementedError("Each state must implement its own handle method.")


class InitState(State):
    def handle(self):
        self.fsm.display_menu()
        soda_name = input("\nSelect a soda by name (or type 'exit' to quit): ").strip()
        if soda_name.lower() == "exit":
            print("Goodbye!")
            exit()
        if soda_name in self.fsm.sodas:
            self.fsm.selected_soda = soda_name
            self.fsm.transition_to("Wait")
        else:
            print(f"Soda '{soda_name}' not found. Please choose from the menu.")


class WaitState(State):
    def handle(self):
        action = input("Insert money (acceptable: 0.01, 0.05, 0.10, 0.25, 1.00, 5.00), or type 'change' to cancel and dispense money: ").strip()
        if action.lower() == "change":
            self.fsm.press_dispense_change()
        else:
            self.fsm.input_money(action)


class DispenseSodaState(State):
    def handle(self):
        print(f"Dispensing {self.fsm.selected_soda}. Enjoy your drink!")
        self.fsm.reset()


class DispenseChangeState(State):
    def handle(self):
        change = self.fsm.tot - self.fsm.sodas[self.fsm.selected_soda]
        print(f"Dispensing {self.fsm.selected_soda}. Change returned: ${change:.2f}. Enjoy your drink!")
        self.fsm.reset()


class SodaMachineFSM:
    def __init__(self):
        self.state = None
        self.states = {
            "Init": InitState(self),
            "Wait": WaitState(self),
            "DispSoda": DispenseSodaState(self),
            "DispChange": DispenseChangeState(self),
        }
        self.transition_to("Init")

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
        self.tot = 0
        self.selected_soda = None

    def transition_to(self, state_name):
        self.state = self.states[state_name]

    def display_menu(self):
        print("\nAvailable sodas:")
        for soda, price in self.sodas.items():
            print(f"{soda}: ${price:.2f}")

    def input_money(self, amount):
        try:
            amount = float(amount)
        except ValueError:
            print(f"Invalid input: '{amount}' is not a valid number.")
            return

        if amount not in self.valid_denominations:
            print(f"Invalid denomination: ${amount:.2f}. Acceptable denominations are: {self.valid_denominations}")
            return

        self.tot += amount
        print(f"Money inserted: ${amount:.2f}. Total: ${self.tot:.2f}")
        soda_cost = self.sodas[self.selected_soda]

        if self.tot >= soda_cost:
            if self.tot == soda_cost:
                self.transition_to("DispSoda")
            else:
                self.transition_to("DispChange")

    def press_dispense_change(self):
        print(f"Returning inserted money: ${self.tot:.2f}.")
        self.reset()

    def reset(self):
        self.tot = 0
        self.selected_soda = None
        self.transition_to("Init")

    def run(self):
        print("Welcome to the Soda Machine!")
        while True:
            self.state.handle()


# Interactive Console
if __name__ == "__main__":
    fsm = SodaMachineFSM()
    fsm.run()
