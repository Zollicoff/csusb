#include <iostream>
using namespace std;

int main() {
   int numIn;
   bool allValid = true;
   int i;   
   
   cin >> numIn;
   
   for (i = -200; i <= -100; ++i) {
      if (numIn != i) {
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