#include <iostream>
#include <string>
using namespace std;

int main() {

   int x;

   cin >> x;

   string binary;

   while (x > 0) {
      binary += to_string(x % 2);
      x = x / 2;
   }

   cout << binary << endl;
   
   return 0;
}
