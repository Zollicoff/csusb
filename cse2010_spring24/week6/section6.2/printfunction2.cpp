#include <iostream>
using namespace std;

void PrintDetails(string myName, int myAge) {
   cout << myName << " is " << myAge << " years old." << endl;
}

int main() {
   string myName;
   int myAge;

   cin >> myName;
   cin >> myAge;

   PrintDetails(myName, myAge);

   return 0;
}
