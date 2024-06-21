#include <iostream>
using namespace std;

double GetMinutesAsHours(double origMinutes) {

   double hours = origMinutes / 60;
   return hours;

}

int main() {
   double minutes;

   cin >> minutes;

   // Will be run with 210.0, 3600.0, and 0.0.
   cout << GetMinutesAsHours(minutes) << endl;

   return 0;
}
