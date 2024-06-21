#include <iostream>
#include <iomanip>
using namespace std;

int main() {

   int input;
   int sum = 0;
   double average;
   int max = 0;
   int count = 0;
    
   while (cin >> input && input >= 0) {
      sum += input;
      if (input > max) {
         max = input;
      }
      ++count;
   }
   
   if (count > 0) {
      average = static_cast<double>(sum) / count;
   } else {
      average = 0;
   }
      
   cout << fixed << setprecision(2) << max << " " << average << endl;

   return 0;
}
