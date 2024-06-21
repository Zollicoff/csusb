#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   float myFloat1;
   float myFloat2;

   myFloat1 = 93.9214;
   myFloat2 = 50.8423;

   cout << setprecision(3) << myFloat1 << endl;
   cout << myFloat2 << endl;

   return 0;
}
