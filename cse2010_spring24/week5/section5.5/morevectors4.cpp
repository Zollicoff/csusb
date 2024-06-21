#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numElements;
   unsigned int i;
   
   cin >> numElements;

   vector<int> quantityList(numElements);
   vector<string> furnitureList(numElements);
   
   for (i = 0; i < numElements; ++i) {
   cin >> quantityList[i]; // Read integer
   cin >> furnitureList[i]; // Read string
   }
   
   for (i = 0; i < quantityList.size(); ++i) {
      cout << "Quantity: " << quantityList.at(i) << ", ";
      cout << "Furniture: " << furnitureList.at(i) << endl;
   }
    
   return 0;
}
