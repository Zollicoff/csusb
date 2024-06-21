#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int GetWordFrequency(vector<string> wordsList, string currWord) {
   int count = 0;
   string searchWordLower = currWord;
   transform(searchWordLower.begin(), searchWordLower.end(), searchWordLower.begin(), ::tolower);
   
   for (const auto& word : wordsList) {
      string wordLower = word;
      transform(wordLower.begin(), wordLower.end(), wordLower.begin(), ::tolower);
      
      if (wordLower == searchWordLower) {
         count++;
      }
   }
   return count;
}

int main() {
   int numWords;
   cin >> numWords;
   
   vector<string> wordsList(numWords);
   for (int i = 0; i < numWords; ++i) {
      cin >> wordsList[i];
   }
   
   for (const auto& word : wordsList) {
      cout << word << " " << GetWordFrequency(wordsList, word) << endl;
   }

   return 0;
}
