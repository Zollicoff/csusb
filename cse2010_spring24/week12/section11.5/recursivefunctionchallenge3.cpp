#include <iostream>
using namespace std;

void DepositAmount(int day, int amount) {
   cout << "day: " << day << ", amount: " << amount << endl;
	
	if (day == 3) {
      cout << "End of study" << endl;
   }
   else {

      /* Your code goes here */
      
      if (amount >= 1000) {
         DepositAmount(day +1, amount + 30);
      } else {
         DepositAmount(day + 1, amount + 50);
      }

   }
}

int main() {
   int amount;
   
   cin >> amount;
   DepositAmount(1, amount);
   
   return 0;
}