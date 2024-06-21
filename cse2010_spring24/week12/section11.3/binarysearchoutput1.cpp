#include <iostream>
using namespace std;

void FindNumber(int number, int lowVal, int highVal) {
   int midVal;

   midVal = (highVal + lowVal) / 2;
   cout << number;
   cout << " ";
   cout << midVal;

   if (number == midVal) {
      cout << " g" << endl;
   }
   else {
      if (number < midVal) {
         cout << " h" << endl;
         FindNumber(number, lowVal, midVal);
      }
      else {
         cout << " i" << endl;
         FindNumber(number, midVal + 1, highVal);
      }
   }
}

int main() {
   int number;

   cin >> number;
   FindNumber(number, 0, 10);
   
   return 0;
}