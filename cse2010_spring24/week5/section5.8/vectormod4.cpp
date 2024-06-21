#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numElements;
   unsigned int i;
   vector<int> valuesList;
   
   cin >> numElements;
   
   valuesList.resize(numElements);
   
   for (i = 0; i < valuesList.size(); ++i) {
      cin >> valuesList.at(i);
   }
   
   cout << "Original values: ";
   for (i = 0; i < valuesList.size(); ++i) {
      cout << valuesList.at(i) << " ";
   }
   cout << endl;


   for (i = 0; i < valuesList.size(); ++i) {
      if (valuesList.at(i) % 2 == 0) {
         valuesList.at(i) -= 1;
      }
   }

   cout << "Nearest odd values: ";
   for (i = 0; i < valuesList.size(); ++i) {
      cout << valuesList.at(i) << " ";
   }
   cout << endl;
   
   return 0;
}
