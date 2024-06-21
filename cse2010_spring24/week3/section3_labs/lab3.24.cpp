#include <iostream>
using namespace std;

int main() {

   int totalChange;
   
   cin >> totalChange;
   
   if (totalChange <= 0) {
      cout << "No change" << endl;
   } else {
      int dollars = totalChange / 100;
      totalChange %= 100;
      
      int quarters = totalChange / 25;
      totalChange %= 25;
      
      int dimes = totalChange / 10;
      totalChange %= 10;
      
      int nickels = totalChange / 5;
      totalChange %= 5;
      
      int pennies = totalChange;
      
      if (dollars > 0) {
         cout << dollars << (dollars == 1 ? " Dollar" : " Dollars") << endl;
      }
      if (quarters > 0) {
         cout << quarters << (quarters == 1 ? " Quarter" : " Quarters") << endl;
      }
      if (dimes > 0) {
         cout << dimes << (dimes == 1 ? " Dime" : " Dimes") << endl;
      }
      if (nickels > 0) {
         cout << nickels << (nickels == 1 ? " Nickel" : " Nickels") << endl;
      }
      if (pennies > 0) {
         cout << pennies << (pennies == 1 ? " Penny" : " Pennies") << endl;
      }
   }
      

   return 0;
}
