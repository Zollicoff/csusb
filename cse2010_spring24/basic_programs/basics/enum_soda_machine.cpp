#include <iostream>
using namespace std;

int main() {
   enum AcceptedCoins {ADD_QUARTER, ADD_DIME, ADD_NICKEL};
   int totalDeposit;
   int userInput;

   totalDeposit = 0;
   cin >> userInput;

   if (userInput == ADD_QUARTER) {
      totalDeposit = totalDeposit + 25;
   }
   
   else if (userInput == ADD_DIME) {
      totalDeposit = totalDeposit + 10;
   }
   
   else if (userInput == ADD_NICKEL) {
      totalDeposit = totalDeposit + 5;
   }

   else {
      cout << "Invalid coin selection." << endl;
   }

   cout << "totalDeposit: " << totalDeposit << endl;

   return 0;
}
