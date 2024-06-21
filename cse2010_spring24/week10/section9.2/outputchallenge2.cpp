#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   float myFloat;

   myFloat = 42.6431;

   cout << setprecision(5) << myFloat << endl;
   cout << setprecision(6) << myFloat << endl;

   return 0;
}