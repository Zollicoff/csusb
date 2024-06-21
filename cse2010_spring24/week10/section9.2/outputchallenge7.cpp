#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   cout << setfill('#') << left;
   cout << setw(8) << "Ann" << endl;
   cout << setw(8) << "Andy" << endl;

   return 0;
}
