#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numElements;
   int quantityThreshold;
   int matchCount;
   unsigned int i;
  
   cin >> numElements;

   vector<string> inventoryList(numElements);
   vector<int> quantityList(numElements);

   for (i = 0; i < inventoryList.size(); ++i) {
      cin >> inventoryList.at(i);
      cin >> quantityList.at(i);
   }

   cin >> quantityThreshold;

   matchCount = 0;
   
   for (i = 0; i < numElements; ++i) {
      if (quantityList[i] >= quantityThreshold) {
         cout << inventoryList[i] << endl;
         matchCount++;
      }
   }
      
   cout << "Total: " << matchCount;

   return 0;
}  
