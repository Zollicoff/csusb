#include <iostream>
#include <cstdlib>
using namespace std;

string CoinFlip () {
   if (rand() % 2 == 0) {
      return "Tails";
   } else {
      return "Heads";
   }
}

int main() {
   int numFlips;
   
   srand(2);  // Unique seed

   cin >> numFlips;
   
   for (int i = 0; i < numFlips; ++i) {
      cout << CoinFlip() << endl;
   }

   return 0;
}
