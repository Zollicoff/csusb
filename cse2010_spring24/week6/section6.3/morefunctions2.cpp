#include <iostream>
using namespace std;

double MphAndMinutesToMiles(double milesPerHour, double minutesTraveled) {
   double miles = milesPerHour * minutesTraveled / 60;
   return miles;
}

int main() {
   double milesPerHour;
   double minutesTraveled;

   cin >> milesPerHour;
   cin >> minutesTraveled;

   cout << "Miles: " << MphAndMinutesToMiles(milesPerHour, minutesTraveled) << endl;

   return 0;
}

