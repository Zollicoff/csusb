#include <iostream>
using namespace std;


// FINISH: Define CelsiusToFahrenheit function here
double CelsiusToFahrenheit(double tempC) {
   double tempF = (tempC * 9.0 / 5.0) + 32.0;
   return tempF;
}

int main() {
   double tempF;
   double tempC;

   cout << "Enter temperature in Celsius: " << endl;
   cin >> tempC;

   tempF = CelsiusToFahrenheit(tempC);

   cout << "Fahrenheit: " << tempF; 

   return 0;
}

