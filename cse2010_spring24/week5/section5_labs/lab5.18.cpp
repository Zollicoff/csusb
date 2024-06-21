#include <iostream>
#include <vector>   // Must include vector library to use vectors
#include <algorithm>
using namespace std;

int main() {
   vector<int> userInts; // A vector to hold the user's input integers
   int numInts;
   int inputNum;
   
   cin >> numInts;
   
   for (int i = 0; i < numInts; ++i) {
      cin >> inputNum;
      userInts.push_back(inputNum);
   }
   
   reverse(userInts.begin(), userInts.end()); // Using algorithm reverse is way smarter than doing it manually
   
   for (int num : userInts) {
      cout << num << ",";
   }

   cout << endl;
   
   return 0;
}
