#include <iostream>
using namespace std;

int main() {
   int firstInt;
   int secondInt;

   cin >> firstInt;
   cin >> secondInt;

   if (secondInt < firstInt) {
      cout << "Second integer can't be less than the first." << endl;
   }
   else {
      for (int i = firstInt; i <= secondInt; i += 5) {
         cout << i << " ";
      }
      cout << endl;
   }

   return 0;
}

