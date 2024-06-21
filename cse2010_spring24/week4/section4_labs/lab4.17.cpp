#include <iostream>
using namespace std;

int main() {

   string input;
   string output = "";

   getline(cin, input);

   for (size_t i = 0; i < input.length(); ++i) {
      if (isalpha(input[i])) {
         output += input[i];
      }
   }

   cout << output << endl;

   return 0;
}

