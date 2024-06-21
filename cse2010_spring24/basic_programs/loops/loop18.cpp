#include <iostream>
#include <string>
using namespace std;

int main() {
   string keyString;
   unsigned int i;
   
   getline(cin, keyString);

   for (i = 0; i < keyString.length(); ++i) {
      if (!isalpha(keyString[i])) {
         keyString[i] = 'x';
      }
   }

   cout << "Valid password: " << keyString << endl;
   
   return 0;
}
