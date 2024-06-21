#include <iostream>
using namespace std;

int main() {
   int weightVal;       // User defined weight (lbs)
   int heightVal;       // User defined height (in)
   float bmiCalc;       // Resulting BMI
   char quitCmd;        // Indicates quit/continue

   quitCmd = 'a';
   
   while (quitCmd != 'q') {
      
      // Get user data
      cout << "Enter weight (in pounds): ";
      cin >> weightVal;
      
      cout << "Enter height (in inches): ";
      cin >> heightVal;
      
      // Calculate BMI value
      bmiCalc = (static_cast<float>(weightVal) /
                 static_cast<float>(heightVal * heightVal)) * 703.0;
      
      // Print user health info
      // Source: http://www.cdc.gov/
      cout << "BMI: " << bmiCalc << endl;
      cout << "(CDC: 18.6-24.9 normal)" << endl;
      
      // Prompt user to continue/quit
      cout << endl << "Enter any key ('q' to quit): ";
      cin >> quitCmd;
   }
   
   return 0;
}
