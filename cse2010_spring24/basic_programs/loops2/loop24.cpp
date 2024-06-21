#include <iostream>
using namespace std;

int main() {
   int inputValue;
   cin >> inputValue;
   
   for (int i = 0; i <= inputValue; ++i) {
      for(int j = 0; j < i; ++j) {
         cout << '%';
      }
      cout << i << endl;
   }

   return 0;
}
