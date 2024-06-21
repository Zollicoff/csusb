#include <iostream>
using namespace std;

void PrintValues(int number1, int number2) {
   
   int newNumber;
   
   for (int i = number1; i <= number2; ++i) {
      double newNumber = i * 20;
      cout << newNumber << endl;
   }
}

int main() {
   int number1;
   int number2;

   cin >> number1;
   cin >> number2;
   PrintValues(number1, number2);

   return 0;
}
