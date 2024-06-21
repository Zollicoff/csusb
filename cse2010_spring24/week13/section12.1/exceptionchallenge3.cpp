#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   string username1;
   string password1;

   cin >> username1;
   cin >> password1;

   try {
      
      if (password1.length() < 6) {
         throw runtime_error("Password is too short");
      }

      if (isalpha(username1[0]) == false) {
         throw runtime_error("User name must start with a letter");
      }
      
      cout << username1 << ": Login successful" << endl;

   }
   catch (runtime_error& excpt) {
      cout << "Error: " << excpt.what() << endl;
   }

   return 0;
}