#include <iostream>
using namespace std;

void PrintStateCode(string stateCode, string myState) {
   cout << "** " << stateCode << " **" << endl;
   cout << " is " << myState << "'s state code." << endl;
}

int main() {
   string stateCode;
   string myState;

   cin >> stateCode;
   cin >> myState;

   PrintStateCode(stateCode, myState);

   return 0;
}
