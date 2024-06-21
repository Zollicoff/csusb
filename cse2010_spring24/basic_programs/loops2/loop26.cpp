#include <iostream>
#include <string>
using namespace std;

int main() {
   string simonPattern;
   string userPattern;
   int userScore = 0;

   cin >> simonPattern;
   cin >> userPattern;

   for (int i = 0; i < simonPattern.length(); ++i) {
      if (simonPattern[i] == userPattern[i]) {
         userScore++;
      } else {
         break;
      }
   }

   cout << "userScore: " << userScore << endl; // Output the userScore

   return 0;
}
