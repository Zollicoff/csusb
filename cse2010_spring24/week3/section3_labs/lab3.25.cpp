#include <iostream>
using namespace std;

int main() {
   int inputYear;
   bool isLeapYear = false;
   
   cin >> inputYear;
   
   if (inputYear % 4 == 0) {
      if (inputYear % 100 == 0) {
         if (inputYear % 400 == 0) {
            isLeapYear = true;
         }
      } else {
         isLeapYear = true;
      }
   }
   
   if (isLeapYear) {
      cout << inputYear << " - leap year" << endl;
   } else {
      cout << inputYear << " - not a leap year" << endl;
   }

   return 0;
}
