#include <iostream>
#include <vector>
#include <string>
using namespace std;

void FindMatch(vector<string> statesData, int lowerIndex, int upperIndex) {
   int midIndex;
   int rangeSize;

   /* Your code goes here */
   rangeSize = upperIndex - lowerIndex + 1;
   midIndex = (lowerIndex + upperIndex) / 2;  

   cout << "Number of elements in the range: " << rangeSize << endl;
   cout << "Middle index: " << midIndex << endl;
   cout << "Element at middle index: " << statesData.at(midIndex) << endl;
}

int main() {
   vector<string> dataList;
   int numData;
   int i;
   string item;

   cin >> numData;
   for (i = 0; i < numData; ++i) {
      cin >> item;
      dataList.push_back(item);
   }
   FindMatch(dataList, 0, dataList.size() - 1);

   return 0;
}