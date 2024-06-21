#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int userAge;
   int avgMaxHeartRate;

   try {
      cin >> userAge;

      if (userAge < 0) {
         throw runtime_error("Invalid age");
      }

      // Source: https://www.heart.org/en/healthy-living/fitness
      avgMaxHeartRate = 220 - userAge;

      cout << "Avg: " << avgMaxHeartRate << endl;
   }
   catch (runtime_error& excpt) {
      cout << "Error: " << excpt.what() << endl;
   }

   return 0;
}