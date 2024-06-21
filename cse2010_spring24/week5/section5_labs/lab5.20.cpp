#include <iostream>
#include <vector>
using namespace std;

int main() {

   int numInts;
   cin >> numInts;
   
   vector<int> integers(numInts);
   
   for (int i = 0; i < numInts; ++i) {
      cin >> integers[i];
   }
   
   int threshold;
   cin >> threshold;
   
   for (int i = 0; i < numInts; ++i) {
      if (integers[i] <= threshold) {
         cout << integers[i] << ",";
      }
   }
   
   cout << endl;
   
   return 0;
}
