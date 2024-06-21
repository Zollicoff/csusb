#include <iostream>
using namespace std;

double FindEmployeeTax(int earnings, int dependents) {
   double taxRate;
   double taxOwed;
   
   if (earnings < 275000) {
      if (dependents <= 3) {
         taxRate = 0.17; 
      }
      else if (dependents >= 4 && dependents <= 7) {
         taxRate = 0.07;
      }
      else if (dependents > 7) {
         taxRate = 0;
      }
   }
   
   else if (earnings >= 275000 && earnings <= 875000) {
      if (dependents <= 3) {
         taxRate = 0.22; 
      }
      else if (dependents >= 4 && dependents <= 7) {
         taxRate = 0.17;
      }
      else if (dependents > 7) {
         taxRate = 0.17;
      }
   }
   
   else if (earnings > 875000) {
      if (dependents <= 3) {
         taxRate = 0.35; 
      }
      else if (dependents >= 4 && dependents <= 7) {
         taxRate = 0.22;
      }
      else if (dependents > 7) {
         taxRate = 0.22;
      }
   }
   
   return taxRate;
   
}

int main() {
   int earnings;
   int dependents;

   cin >> earnings;
   cin >> dependents;
   
   cout << FindEmployeeTax(earnings, dependents) << endl;

   return 0;
}