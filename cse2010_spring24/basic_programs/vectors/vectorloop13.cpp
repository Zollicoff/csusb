#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> hourlyMiles;
   int vecVals;
   unsigned int i;
   int mile;

   cin >> vecVals;

   for (i = 0; i < vecVals; ++i) {
      cin >> mile;
      hourlyMiles.push_back(mile);
   }

   for (i = vecVals / 2; i < hourlyMiles.size(); ++i) {
      cout << hourlyMiles.at(i);
      if (i < hourlyMiles.size() - 1) {
         cout << " - ";
      }
   }

   cout << endl;

   return 0;
}
