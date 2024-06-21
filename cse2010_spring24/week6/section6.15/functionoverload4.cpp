#include <iostream>
#include <iomanip>
using namespace std;

void PrintPeachWeight(int peachWeight) {
   cout << "Peach weight as a whole number: " << peachWeight << " ounces" << endl;
}

void PrintPeachWeight(double peachWeight2) {
   cout << "Peach weight to one decimal place: " << fixed << setprecision(1) << peachWeight2 << " ounces" << endl;
}

int main() {
   int peachWeight1;
   double peachWeight2;

   cin >> peachWeight1;
   cin >> peachWeight2;

   PrintPeachWeight(peachWeight1);
   PrintPeachWeight(peachWeight2);

   return 0;
}
