#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   float myFloat;

   myFloat = 31.4124;

   cout << scientific << setprecision(4) << myFloat;

   return 0;
}
