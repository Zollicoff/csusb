class SodaMachineFSM:
    def __init__(self, soda_cost):
        self.state = "Init"
        self.tot = 0
        self.soda_cost = soda_cost

    def input_coin(self, coin_value):
        if self.state == "Wait":
            self.tot += coin_value
            print(f"Coin inserted: {coin_value}. Total: {self.tot}.")
            if self.tot >= self.soda_cost:
                self.transition_to_dispense()
        else:
            print(f"Cannot insert coin in current state: {self.state}")

    def press_dispense(self):
        if self.state == "DispSoda":
            print("Soda dispensed!")
            self.state = "DispChange" if self.tot > self.soda_cost else "Init"
            if self.state == "DispChange":
                print(f"Returning change: {self.tot - self.soda_cost}")
                self.tot = 0
        elif self.state == "DispChange":
            print("Change dispensed!")
            self.state = "Init"
        else:
            print(f"Cannot dispense in current state: {self.state}")

    def transition_to_dispense(self):
        if self.tot == self.soda_cost:
            self.state = "DispSoda"
            print("Exact amount reached. Ready to dispense soda.")
        elif self.tot > self.soda_cost:
            self.state = "DispChange"
            print("Overpaid. Dispensing soda and returning change.")
        else:
            self.state = "Wait"
            print("Insufficient funds. Waiting for more coins.")

    def reset(self):
        print("Resetting machine.")
        self.state = "Wait"  # Transition to Wait after resetting
        self.tot = 0

    def get_state(self):
        return self.state

# Example usage
if __name__ == "__main__":
    soda_cost = 8  # Cost of a soda
    fsm = SodaMachineFSM(soda_cost)

    fsm.reset()
    fsm.input_coin(5)  # Insert a coin
    fsm.input_coin(3)  # Insert another coin
    fsm.press_dispense()  # Press the dispense button
    fsm.press_dispense()  # Dispense change (if applicable)
