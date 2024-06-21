#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> numberVector;
   int value;
   int i;

   cin >> value;
   while (value != -1) {
      numberVector.push_back(value);
      cin >> value;
   }

   for (i = 0; i < numberVector.size() - 1; ++i) {
      cout << numberVector[i] - numberVector.back() << endl;
   }

   return 0;
}
