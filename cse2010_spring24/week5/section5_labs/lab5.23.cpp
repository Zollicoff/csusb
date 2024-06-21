#include <iostream>
#include <vector>
using namespace std;

int main() {

   int wordCount;
   cin >> wordCount;
   
   vector<string> words(wordCount);
   
   for (int i = 0; i < wordCount; ++i) {
      cin >> words[i];
   }
   
   char searchChar;
   cin >> searchChar;
   
   for (const string& word : words) {
      if (word.find(searchChar) != string::npos) {
         cout << word << ",";
      }
   }
   
   cout << endl;

   return 0;
}
