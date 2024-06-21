#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> hourlyScores;
   int vecLength;
   int sumOdds;
   unsigned int i;
   int score;

   cin >> vecLength;

   for (i = 0; i < vecLength; ++i) {
      cin >> score;
      hourlyScores.push_back(score);
   }

   sumOdds = 0;

   for (i = 0; i < hourlyScores.size(); ++i) {
      if (hourlyScores[i] % 2 == 1) {
         sumOdds += hourlyScores[i];
      }
   }

   cout << "Odd sum: " << sumOdds << endl;
   
   return 0;
}