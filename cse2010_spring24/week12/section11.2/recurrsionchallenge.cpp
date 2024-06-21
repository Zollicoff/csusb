#include <iostream>
using namespace std;

void BackwardsAlphabet(char currLetter){
   if (currLetter == 'a') {
      cout << currLetter << endl;
   }
   else{
      cout << currLetter << " ";
      BackwardsAlphabet(currLetter - 1);
   }
}

int main() {
   char startingLetter;

   cin >> startingLetter;

   /* Your solution goes here  */
   BackwardsAlphabet(startingLetter);
   
   return 0;
}