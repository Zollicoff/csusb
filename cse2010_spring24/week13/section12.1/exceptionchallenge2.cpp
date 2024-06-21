#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int negVal;

   cin >> negVal;

   try {
      if (negVal >= 0) {
         throw runtime_error("Invalid value");
      }
      cout << "Negative number submitted: " << negVal << endl;
   }

   catch (runtime_error& excpt) {
      cout << "Negative number not found: Invalid value" << endl;
   }

   return 0;
}

