#include <iostream>
#include <string>
using namespace std;

int main() {
   string codeWord;
   int index;
   
   cin >> codeWord;
   index = 0;

   while ((index = codeWord.find("abc", index)) != string::npos) {
      codeWord.replace(index, 3, "ngl");
      index += 3;
   }

   cout << "New password: " << codeWord << endl;
   
   return 0;
}
