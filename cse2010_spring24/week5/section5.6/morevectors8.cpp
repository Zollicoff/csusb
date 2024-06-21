#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> myVector(5);
   int myVectorSize = myVector.size();
   int numRemoved;
   int i;
   
   myVector.at(0) = 9;
	myVector.at(1) = 8;
	myVector.at(2) = 7;
	myVector.at(3) = 10;
	myVector.at(4) = 11;
   
   cin >> numRemoved;
   
   for (i = 0; i < myVector.size(); ++i) {
      cout << myVector.at(i) << " ";
   }
	cout << endl;

   for (i = 0; i < myVector.size(); ++i) {
      myVector.resize(myVectorSize - numRemoved);
   }

   for (i = 0; i < myVector.size(); ++i) {
      cout << myVector.at(i) << " ";
   }
	cout << endl;

   return 0;
}

