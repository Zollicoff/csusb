#include <iostream>
#include <vector>
using namespace std;

int main() {
   unsigned int i;
   int initListSize = 1;
   vector<int> myVector(initListSize);
   int inputSize;
   int firstNum;
   
   myVector.at(0) = 25;
   
   cin >> inputSize;
   cin >> firstNum;

   myVector.resize(inputSize);

   for (i = 1; i < myVector.size(); ++i) {
      myVector[i] = firstNum - 3 * i;
   }

   for (i = 0; i < myVector.size(); ++i) {
      cout << myVector.at(i) << " ";
   }
   cout << endl;

   return 0;
}
