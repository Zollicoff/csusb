#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> intVector;
   int value;
   int i;

   cin >> value;
   while (value != 0) {
      intVector.push_back(value);
      cin >> value;
   }

   if (!intVector.empty()) {
      int lastElement = intVector.back();
      for (i = 0; i < intVector.size(); ++i) {
         if (intVector[i] > lastElement) {
            cout << "OUCH" << endl;
         } else { 
            cout << intVector[i] << endl;
         }
      }
   }

   return 0;
}
