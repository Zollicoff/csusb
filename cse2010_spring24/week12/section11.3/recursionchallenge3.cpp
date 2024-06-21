#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Find(vector<string> namesData, string targetItem, int startIndex, int endIndex) {
   int middleIndex;
   int rangeSize;
   string middleValue;

   rangeSize = (endIndex - startIndex) + 1;
   middleIndex = (startIndex + endIndex) / 2;
   middleValue = namesData.at(middleIndex);

   if (targetItem == middleValue) {
      cout << targetItem << " is found at index " << middleIndex << endl;
   }
   else if (rangeSize == 1) {
      cout << targetItem << " is not in the list" << endl;
   }
   else {

      /* Your code goes here */
      if (targetItem < middleValue) {
         cout << "Search lower half" << endl;
         Find(namesData, targetItem, startIndex, middleIndex);
      } else {
         cout << "Search upper half" << endl;
         Find (namesData, targetItem, middleIndex + 1, endIndex);
      }

   }
}

int main() {
   string targetItem;
   vector<string> dataList;
   int numData;
   int i;
   string item;

   cin >> targetItem;
   cin >> numData;
   for (i = 0; i < numData; ++i) {
      cin >> item;
      dataList.push_back(item);
   }
   Find(dataList, targetItem, 0, dataList.size() - 1);

   return 0;
}