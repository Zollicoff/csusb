#include <iostream>
using namespace std;
// Program converts a trip's kilometers and liters into miles, gallons, and mpg

double ConvKilometersToMiles(double numKm) {
   double milesPerKm = 0.621371;
   return numKm * milesPerKm;
}

double ConvLitersToGallons(double numLiters) {
   double gallonsPerLiter = 0.264172;
   return numLiters * gallonsPerLiter;
}

double CalcMpg(double distMiles, double gasGallons) {
   double milesPerGallon = distMiles / gasGallons;
   return milesPerGallon;
}

int main() {
   double distKm;
   double distMiles;
   double gasLiters;
   double gasGal;
   double userMpg;
   
   cout << "Enter kilometers driven: " << endl;
   cin >> distKm;
   cout << "Enter liters of gas consumed: " << endl;
   cin >> gasLiters;
   
   distMiles = ConvKilometersToMiles(distKm);
   gasGal = ConvLitersToGallons(gasLiters);
   userMpg = CalcMpg(distMiles, gasGal);
   
   cout << "Miles driven: " << distMiles << endl;
   cout << "Gallons of gas: " << gasGal << endl;
   cout << "Mileage: " << userMpg << " mpg" << endl;
   
   return 0;
}
