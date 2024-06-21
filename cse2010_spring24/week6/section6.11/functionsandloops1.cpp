#include <iostream>
using namespace std;

int GetFirstIndex(string inputString, char x) {

   for (int i = 0; i < inputString.size(); ++i) {
      if (x == inputString.at(i)) {
         return i;
      }
   }
   
   return -1;
   
}

int main() {
   string inputString;
   char x;
   int result;

   cin >> inputString;
   cin >> x;

   result = GetFirstIndex(inputString, x);

   cout << result << endl;

   return 0;
}
