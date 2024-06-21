#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numMembers;
   int firstMember;
   int lastMember;
   unsigned int i;

   cin >> numMembers;
   cin >> firstMember;
   cin >> lastMember;

   vector<int> walkingListings(numMembers);
   
   walkingListings.at(0) = firstMember;
   walkingListings.at(walkingListings.size() - 1) = lastMember;

   for (i = 0; i < walkingListings.size(); ++i) {
      cout << walkingListings.at(i) << " ";
   }
   cout << endl;

   return 0;
}
