#include <iostream>
#include <iomanip>
using namespace std;

int main() {   
   double chardWeight1;
   double chardWeight2;
   double updatedWeight;
  
   cin >> chardWeight1;
   cin >> chardWeight2;
   updatedWeight = chardWeight1 - chardWeight2;

   cout << fixed << setprecision(3) << right;

   cout << setw(16) << right << chardWeight1 << endl;
   cout << "- " << left;
   cout << setw(14) << right << chardWeight2 << endl;

   cout << setfill('=') << setw(16) << "" << endl; // Output the horizontal separator
   cout << setfill(' ') << setw(16) << updatedWeight << endl; // Output result

   return 0;
}