#include <iostream>
using namespace std;

double ConvertToCentimeters(int userInches) {
   const double IN_TO_CM = 2.54;
   
   return userInches * IN_TO_CM;

}

int main() {
   int inches;

   cin >> inches;

   cout << ConvertToCentimeters(inches);
	cout << " centimeters" << endl;

   return 0;
}
