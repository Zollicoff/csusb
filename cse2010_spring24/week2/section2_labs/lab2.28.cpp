#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int num1, num2, num3, num4;
   int intProduct, intSum, intAverage;
   double doubleProduct, doubleAverage;

   cin >> num1 >> num2 >> num3 >> num4;
   
   intProduct = num1 * num2 * num3 * num4;
   intSum = num1 + num2 + num3 + num4;
   intAverage = intSum / 4;
   
   cout << intProduct << " " << intAverage << endl;
   
   doubleProduct = static_cast<double>(num1) * num2 * num3 * num4;
   doubleAverage = static_cast<double>(intSum) / 4.0;
   
   cout << fixed << setprecision(3);
   cout << doubleProduct << " " << doubleAverage << endl;
   
   return 0;
}
