#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> intVector;
   int value;
   int i;

   cin >> value;
   while (value != -1) {
      intVector.push_back(value);
      cin >> value;
   }

   for (i = intVector.size() - 1; i >= 0; --i) {
      if (intVector[i] > 0) {
         cout << intVector[i] << endl;
      }
   }
   
   return 0;
}
