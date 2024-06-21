#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> yearlyPrices;
   int numIn;
   unsigned int i;
   int price;

   cin >> numIn;

   for (i = 0; i < numIn; ++i) {
      cin >> price;
      yearlyPrices.push_back(price);
   }

   for (i = 0; i < yearlyPrices.size(); ++i) {
      cout << yearlyPrices.at(i);
      if (i < yearlyPrices.size() - 1) {
         cout << " * ";
      }
   }

   cout << endl;

   return 0;
}
