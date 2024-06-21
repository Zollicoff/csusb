#include <iostream>
using namespace std;

int main() {
   int* numberPointer;
   int someNumber;
   int otherNumber;

   numberPointer = &someNumber;

   someNumber = 7;
   otherNumber = 6;

   cout << *numberPointer << endl;

   return 0;
}
