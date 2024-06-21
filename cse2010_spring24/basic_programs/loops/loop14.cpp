#include <iostream>
using namespace std;

int main() {
   int numIn;
   bool allValid = true;
   int i;   
   
   cin >> numIn;
   
   for (i = 0; i < numIn; ++i) {
      int num;
      cin >> num;
      
      if (num < -200 || num > -100) {
         allValid = false;
         break;
      }
   }

   if (allValid) {
      cout << "All valid" << endl;
   }
   else {
      cout << "Invalid value(s)" << endl;   
   }

   return 0;
}