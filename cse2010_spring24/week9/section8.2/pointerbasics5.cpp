#include <iostream>
using namespace std;

int main() {
   int size1;
   int size2;
   int* sizePointer;

   cin >> size1;
   cin >> size2;

   /* Your code goes here */
   if (size1 < size2) {
      sizePointer = &size1;
   } else if (size2 < size1) {
      sizePointer = &size2;
   } else if (size1 == size2) {
      sizePointer = nullptr;
   }

   if (sizePointer == nullptr) {
      cout << "The sizes are the same." << endl;
   }
   else {
      cout << *sizePointer << " is the smaller size." << endl;
      
      if (sizePointer == &size1) {
         cout << "sizePointer points to size1." << endl;
      }
      if (sizePointer == &size2) {
         cout << "sizePointer points to size2." << endl;
      }
   }

   return 0;
}