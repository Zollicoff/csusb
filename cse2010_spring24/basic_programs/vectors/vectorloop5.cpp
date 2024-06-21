#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numDistance;
   int i;

   cin >> numDistance;
   vector<int> walkingRoster(numDistance);

   for (i = 0; i < walkingRoster.size(); ++i) {
      cin >> walkingRoster.at(i);
   }

   for (i = 0; i < walkingRoster.size(); ++i) {
      walkingRoster[i] = walkingRoster[i] + 3;
      cout << walkingRoster[i] << ", ";
   }

   return 0;
}
