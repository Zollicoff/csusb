#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   float myFloat;

   myFloat = 12.3423;

   cout << setprecision(3) << myFloat << endl;
   cout << setprecision(4) << myFloat << endl;

   return 0;
}
