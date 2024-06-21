#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   char grade;

   cin >> grade;

   try {
      if (grade < 'A' || grade > 'F') {
         throw runtime_error("Grade must be between 'A' and 'F'");
      }
      cout << "Grade submitted: " << grade << endl;
   }
   catch (runtime_error& excpt) {
      cout << "Error: " << excpt.what() << endl;
   }

   return 0;
}
