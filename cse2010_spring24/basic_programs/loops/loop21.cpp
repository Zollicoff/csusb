#include <iostream>
using namespace std;

int main() {
   string password;
   bool goodPassword = false;
   
   int count = 0;
      
   getline(cin, password);
   
   for (int i = 0; i < password.length(); ++i) {
      if (isdigit(password[i])) {
         ++count;
      }
   }
   
   if (count > 3 && password.length() > 4) {
      goodPassword = true;
   }

   if (goodPassword) {
      cout << "Valid" << endl;
   }
   else {
      cout << "Invalid" << endl;
   }
   
   return 0;
}
