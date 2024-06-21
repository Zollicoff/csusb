#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numDistance;
   unsigned int i;
	double averageDistance;
	int sumElementData = 0;

   cin >> numDistance;
   vector<int> walkingRoster(numDistance);

   for (i = 0; i < walkingRoster.size(); ++i) {
      cin >> walkingRoster.at(i);
		sumElementData += walkingRoster.at(i);
   }

	averageDistance = sumElementData / walkingRoster.size();

	cout << "Average: " << averageDistance << endl;
	cout << "Numbers less than average: ";

   for (i = 0; i < walkingRoster.size(); ++i) {
      if (walkingRoster.at(i) < averageDistance) {
         cout << walkingRoster.at(i) << " ";
      }
   }

   return 0;
}
