#include <iostream>
using namespace std;

int main() {
   int startRange;
   int endRange;
   int count;
   int i;
   int j;

   cin >> startRange;
   cin >> endRange;

   count = 0;
   i = 0;
   while (i <= startRange) {
		j = 0;
		while (j <= endRange) {
         ++count;
         ++j;
      }
      ++i;
   }

   cout << "Inner loop ran " << count << " times" << endl;

   return 0;
}
