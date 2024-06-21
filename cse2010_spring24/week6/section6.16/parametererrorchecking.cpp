#include <iostream>
using namespace std;

int ConvertLength(int feet) {
   return feet * 12;
}

int ConvertLength(int feet, int inches) {
   return (feet * 12) + inches;
}

int main() {   
   int feetUsed;
   int inchesUsed;
   int totalInches1;
   int totalInches2;
  
   cin >> feetUsed;
   cin >> inchesUsed;
  
   totalInches1 = ConvertLength(feetUsed);
   cout << feetUsed << " feet yields " << totalInches1 << " inches." << endl;
   
   totalInches2 = ConvertLength(feetUsed, inchesUsed);
   cout << feetUsed << " feet and " << inchesUsed << " inches yields ";
   cout << totalInches2 << " inches." << endl;
   
   return 0;
}
