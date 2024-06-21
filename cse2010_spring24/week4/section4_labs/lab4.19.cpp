#include <iostream>
#include <string>
using namespace std;

int main() {
   
   string input;
   
   do {
      getline(cin, input);
   
      if (input == "Done" || input == "done" || input == "d") {
         break;
      }

      for (int i = input.length() - 1; i >=0; --i) {
         cout << input[i];
      }
      cout << endl;
   
   } while (true);

   return 0;
}
