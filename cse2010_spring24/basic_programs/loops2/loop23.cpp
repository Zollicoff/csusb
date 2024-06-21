#include <iostream>
using namespace std;

int main() {
   int outerNum;
   int innerNum;
   int count;
   int i;
   int j;

   cin >> outerNum;
   cin >> innerNum;

   count = 0;
   for (i = 0; i < outerNum + 1; ++i) {
		for (j = 0; j < innerNum; ++j) {
         ++count;
      }
   }

   cout << "Inner loop ran " << count << " times" << endl;

   return 0;
}
