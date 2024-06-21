#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> myVector;
   int numVals;
   unsigned int i;
   int listSize;
   int begNum;

   cin >> listSize;
   cin >> begNum;

   myVector.resize(listSize);

   for (i = 0; i < myVector.size(); ++i) {
      myVector[i] = begNum * (i / 2 + 1);
   }
   
   for (i = 0; i < myVector.size(); ++i) {
      cout << myVector.at(i) << " ";
   }
   cout << endl;

   return 0;
}
