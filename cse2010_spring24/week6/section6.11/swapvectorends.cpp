#include <iostream>
#include <vector>
using namespace std;

void SwapVectorEnds(vector<int>& vctrVals) {
    if (!vctrVals.empty()) {
        int tmpVal = vctrVals.front();
        vctrVals.front() = vctrVals.back();
        vctrVals.back() = tmpVal;
    }
}

int main() {
   vector<int> sortVector(4);
   unsigned int i;
   int userNum;

   for (i = 0; i < sortVector.size(); ++i) {
      cin >> userNum;
      sortVector.at(i) = userNum;
   }

   SwapVectorEnds(sortVector);

   for (i = 0; i < sortVector.size(); ++i) {
      cout << sortVector.at(i) << " ";
   }
   cout << endl;

   return 0;
}
