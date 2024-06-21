#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SortVector(vector<int>& myVec) {
   sort(myVec.begin(), myVec.end(), [](int a, int b) {
      return a > b;
   });
}

int main() {
   int numElements, input;
   cin >> numElements;
   vector<int> myVec;
   
   for (int i = 0; i < numElements; ++i) {
      cin >> input;
      myVec.push_back(input);
   }
   
   SortVector(myVec);
   
   for (int num : myVec) {
      cout << num << ",";
   }
   cout << endl;
   
   return 0;
}
