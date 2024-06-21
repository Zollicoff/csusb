#include <iostream>
using namespace std;

double ConvertVolume(int fluidOunces, int tablespoons) {
   int numberOfTablespoons = fluidOunces * 2 + tablespoons;
   double numberOfMilliliters = numberOfTablespoons * 14.7868;
   return numberOfMilliliters;
}

int main() {
   int numFluidOunces;
   int numTablespoons;

   cin >> numFluidOunces;
   cin >> numTablespoons;

   cout << "The number of milliliters is ";
	cout << ConvertVolume(numFluidOunces, numTablespoons) << endl;

   return 0;
}
