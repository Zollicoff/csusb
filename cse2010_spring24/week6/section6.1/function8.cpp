#include <iostream>
using namespace std;

int ComputeVal(int firstParameter, int secondParameter) {
   int parameterCalculation = (2 * firstParameter) - secondParameter;
   return parameterCalculation;
}

int main() {
   int inputVal1, inputVal2;
   int result;
   
   cin >> inputVal1;
   cin >> inputVal2;
   
   result = ComputeVal(inputVal1, inputVal2);
   
   cout << result << endl;
   
   return 0;
}
