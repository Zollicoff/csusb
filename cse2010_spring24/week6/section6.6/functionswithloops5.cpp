#include <iostream>
using namespace std;

bool InspectVals() {
   int inputNum;
   cin >> inputNum;
   bool allNegative = true;
   
   while (inputNum != 0) {
      if (inputNum >= 0) {
         allNegative = false;
      }
      cin >> inputNum;
   }
   
   return allNegative;
   
}   

int main() {
   bool allNegative;

   allNegative = InspectVals();
   if (allNegative) {
      cout << "All true" << endl;
   }
   else {
      cout << "Not all true" << endl;   
   }

   return 0;
}