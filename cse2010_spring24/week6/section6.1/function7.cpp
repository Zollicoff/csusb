#include <iomanip>
#include <iostream>
using namespace std;

double CalculateNum(double parameter) {
   double newParameter = parameter - 8.6;
   return newParameter;
}

int main() {
   double valueRead;
   double result;
   
   cin >> valueRead;
   
   result = CalculateNum(valueRead);
   
   cout << fixed << setprecision(2) << result << endl;
   
   return 0;
}
