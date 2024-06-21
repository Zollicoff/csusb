#include <iostream>
using namespace std;

void StartsWith(string inputString1, string inputString2) {
   if (inputString1.find(inputString2) == 0) {
      cout << inputString1 << "+++" << inputString2 << endl;
   } else {
      cout << "Failed to match." << endl;
   }
}

int main() {
   int i;
   string inputString1;
   string inputString2;

   cin >> inputString1;
   cin >> inputString2;

   StartsWith(inputString1, inputString2);

   return 0;
}
