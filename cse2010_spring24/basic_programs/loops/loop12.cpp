#include <iostream>
using namespace std;

int main() {
   int valCount;
   bool allOdd = true;
   int i;
   int val;

   cin >> valCount;
   
   for (i = 0; i < valCount; ++i) {
      cin >> val;
      if (val % 2 == 0) {
         allOdd = false;
         break;
      }
   }

   if (allOdd) {
      cout << "All match" << endl;
   }
   else {
      cout << "Not all match" << endl;
   }

   return 0;
}