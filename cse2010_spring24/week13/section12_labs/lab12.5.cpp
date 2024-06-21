#include <string>
#include <iostream>

using namespace std;

int main() {
   string inputName;
   int age;
   // Set exception mask for cin stream
   cin.exceptions(ios::failbit);

   cin >> inputName;
   while(inputName != "-1") {
      try {
         cin >> age;
      } catch (ios_base::failure& e) {
         cin.clear();
         string garbage;
         getline(cin, garbage);
         age = 0;
      }
      // Increment age only if it's not 0
      if (age != 0) {
         age++;
      }
      cout << inputName << " " << age << endl;

      cin >> inputName;
   }
   
   return 0;
}