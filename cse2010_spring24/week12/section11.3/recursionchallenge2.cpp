#include <iostream>
#include <vector>
#include <string>
using namespace std;

void FindMatch(vector<string> dataVector, string queryItem, int startIndex, int endIndex) {
   int middleIndex;
   int rangeSize;

   rangeSize = (endIndex - startIndex) + 1;
   middleIndex = (startIndex + endIndex) / 2;

   /* Your code goes here */
   if (queryItem == dataVector.at(middleIndex)) {
      cout << queryItem << " is found at index " << middleIndex << endl;
   } else if (rangeSize == 1) {
      cout << queryItem << " is not in the list" << endl;
   } else {
      cout << queryItem << " is not a found at index " << middleIndex << endl;
   }
   
   return;

}

int main() {
   string queryItem;
   vector<string> dataList;
   int numData;
   int i;
   string item;

   cin >> queryItem;
   cin >> numData;
   for (i = 0; i < numData; ++i) {
      cin >> item;
      dataList.push_back(item);
   }
   FindMatch(dataList, queryItem, 0, dataList.size() - 1);

   return 0;
}