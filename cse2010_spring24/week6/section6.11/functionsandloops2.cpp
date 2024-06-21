#include <iostream>
#include <vector>
using namespace std;

void CheckValues(const string& inputStr, char x, vector<bool>& outputVec) {
   for (char currentChar : inputStr) {
      if (currentChar != x) {
         outputVec.push_back(true);
      } else {
         outputVec.push_back(false);
      }
   }
}

int main() {
   string inputString;
   int i;
   char x;
   vector<bool> results;
   
   cin >> inputString;
   cin >> x;

   CheckValues(inputString, x, results);

   for (i = 0; i < results.size(); ++i) {
      if (results.at(i)) {
         cout << inputString.at(i) << " is not equal to " << x << endl;
      }
      else {
         cout << inputString.at(i) << " is equal to " << x << endl;
      }
   }

   return 0;
}
