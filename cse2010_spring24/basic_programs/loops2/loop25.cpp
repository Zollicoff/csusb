#include <iostream>
using namespace std;

int main() {
   int numRows;
   int numColumns;
   int currentRow;
   int currentRowInteger;
   int currentColumn;
   char currentColumnLetter;
   
   cin >> numRows;
   cin >> numColumns;

   for (currentRow = 1; currentRow <= numRows; ++currentRow) {
      for (currentColumn = 0; currentColumn < numColumns; ++currentColumn) {
         currentColumnLetter = 'A' + currentColumn;
         cout << currentRow << currentColumnLetter << " ";
      }
      cout << endl;
   }

   return 0;
}
