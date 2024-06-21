#include <iostream>

void PrintValue(int* valuePointer) {
   if (valuePointer == nullptr) {
      std::cout << "Pointer is null" << std::endl;
   }
   else {
      std::cout << *valuePointer << std::endl;
   }
}

int main() {
   int someInt = 5;
   int* valPointer = nullptr;

   PrintValue(valPointer);
   valPointer = &someInt;    
   PrintValue(valPointer);

   return 0;
}