#include <iostream>
#include <vector>   // Must include vector library to use vectors
using namespace std;

int main() {

   vector<int> numberVector;
   int inputNumber;
   
   while (cin >> inputNumber && inputNumber >= 0) {
      numberVector.push_back(inputNumber);
   }
   
   if (numberVector.size() > 9) {
      cout << "Too many numbers" << endl;
   } else {
      int middleIndex = numberVector.size() /2;
      cout << "Middle item: " << numberVector[middleIndex] << endl;
   }

   return 0;
}
