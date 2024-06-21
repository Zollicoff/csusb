#include <iostream>
using namespace std;

void SumValues(int val, int total) {
   cout << val;
	total = total + val;

   /* Your code goes here */
   
   if (val <= 4) {
      cout << " = " << total << endl;
   }

   else {
      cout << " + ";
		SumValues(val - 4, total);
   }
}

int main() {
   int val;
   
   cin >> val;
   SumValues(val, 0);
   
   return 0;
}