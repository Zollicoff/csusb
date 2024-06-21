#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   float myFloat;

   myFloat = 50.3423;

   cout << setprecision(3) << myFloat << endl;
   cout << fixed << myFloat << endl;

   return 0;
}
