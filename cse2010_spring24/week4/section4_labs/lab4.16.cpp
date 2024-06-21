#include <iostream>
#include <string>
using namespace std;

int main() {

   char userChar;
   string userString;
   int count = 0;
   
   cin >> userChar;
   cin.ignore();
   getline(cin, userString);
   
   for (size_t i = 0; i < userString.length(); ++i) {
      if (userString[i] == userChar) {
         ++count;
      }
   }
   
   if (count == 1) {
      cout << count << " " << userChar << endl;
   } else {
      cout << count << " " << userChar << "'s" << endl;
   }
   
   return 0;
}
