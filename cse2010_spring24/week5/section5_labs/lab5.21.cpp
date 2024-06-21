#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

   int numFloats;
   cin >> numFloats;
   
   vector<double> floatsVector(numFloats);
   
   for (int i = 0; i < numFloats; ++i) {
      cin >> floatsVector[i];
   }
   
   double maxVal = *max_element(floatsVector.begin(), floatsVector.end());
   
   cout << fixed << setprecision(2);
   
   for (int i = 0; i < numFloats; ++i) {
      cout << floatsVector[i] / maxVal << " ";
   }
   
   cout << endl;
   
   return 0;
}
