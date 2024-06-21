#include <iostream>
#include <vector>
using namespace std;

class Order {
   public:
      void SetDetails(string newFood, char newOption);
		char GetOption() const;
		void Print() const;
   private:
      string food;
      char option;
};

void Order::SetDetails(string newFood, char newOption) {
   food = newFood;
   option = newOption;
}

char Order::GetOption() const {
	return option;
}

void Order::Print() const {
	cout << "Order: " << food << ", Option: " << option << endl;
}

class Ledger {
   public:
      void InputOrders();
      void PrintSelectedOrders();
   private:
      vector<Order> orderList;
};

void Ledger::InputOrders() {
   Order currOrder;
   string currFood;
   char currOption;
   int orderCount;
   unsigned int i;
  
   cin >> orderCount;
   for (i = 0; i < orderCount; ++i) {
      cin >> currFood;
      cin >> currOption;
      
      currOrder.SetDetails(currFood, currOption);
      orderList.push_back(currOrder);
   }     
}

void Ledger::PrintSelectedOrders() {
   Order currOrder;
   unsigned int i;
   char selectedOption = 'A'; // Set the selected option to 'A'
   
   for (i = 0; i < orderList.size(); ++i) {
      currOrder = orderList.at(i);
      if (currOrder.GetOption() == selectedOption) {
         currOrder.Print();
      }
   }
}

int main() {
   Ledger ledger;
  
   ledger.InputOrders();
   ledger.PrintSelectedOrders();
   
   return 0;
}