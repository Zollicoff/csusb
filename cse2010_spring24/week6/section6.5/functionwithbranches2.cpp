#include <iostream>
using namespace std;

int CalculateCost(int age, int units) {
   int cost;
   if (age >= 18 && age <= 25) {
      if (units > 11) {
         cost = (units - 11) * 200; 
      }
      else {
         cost = 0;
      }
   }
   else {
      if (units < 1) {
         cost = units * 200;
      }
      else {
         cost = (units - 0) * 400 + 100;
      }
   }
   return cost;
}
    
int main() {
   int costReturned = CalculateCost(19, 12);
   
   cout << costReturned << endl;
   
   return 0;
}
