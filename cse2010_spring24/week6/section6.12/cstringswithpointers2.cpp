#include <iostream>
#include <cstring>
using namespace std;

void MakeSentenceExcited(char* sentenceText) {
   int i;
   size_t len = strlen(sentenceText);
   
   for (i = 0; i < len; ++i) {
      if (sentenceText[i] == '.') {
         sentenceText[i] = '!';
      }
   }
}

int main() {
   const int TEST_STR_SIZE = 50;
   char testStr[TEST_STR_SIZE];

   cin.getline(testStr, TEST_STR_SIZE);
   MakeSentenceExcited(testStr);
   cout << testStr << endl;

   return 0;
}
