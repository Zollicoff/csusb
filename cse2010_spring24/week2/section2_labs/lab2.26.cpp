#include <iostream>
#include <iomanip>
using namespace std;

int main() {

   double age;
   double weight;
   double heartRate;
   double minutes;
   double calories;

   cin >> age;
   cin >> weight;
   cin >> heartRate;
   cin >> minutes;
   
   calories = ((age * 0.2757 + weight * 0.03295 + heartRate * 1.0781 - 75.4991) * minutes) / 8.368;   

   cout << "Calories: " << fixed << setprecision(2) << calories << " calories" << endl;

   return 0;
}
