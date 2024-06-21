#include <iostream>
using namespace std;

int FindLowestVal() {
   int userNum;
   int minVal;
   
   cin >> userNum;
   minVal = userNum;
   
   while (userNum <= 0) {
      if (userNum < minVal) {
         minVal = userNum;
      }
      cin >> userNum;
   }
   
   return minVal;
   
}

int main() {
   int minVal;
   
   minVal = FindLowestVal();
   
   cout << minVal << endl;
   
   return 0;
}
 