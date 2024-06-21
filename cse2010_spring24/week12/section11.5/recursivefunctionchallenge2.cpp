#include <iostream>
using namespace std;

int FindProduct(int inValue) {
   if (inValue <= 1) {
      return inValue;
   }

   /* Your code goes here */
   return inValue * FindProduct(inValue - 1);

}

int main() {
   int inValue;
   
   cin >> inValue;
	cout << FindProduct(inValue) << endl;
   
   return 0;
}

