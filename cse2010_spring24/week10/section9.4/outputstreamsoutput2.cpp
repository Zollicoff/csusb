#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
   ostringstream objectOSS;
   string object;
   int quantity;
   int discount;

   object = "Headphones";
   quantity = 18;
   discount = 30;

   objectOSS << object << " x" << quantity << endl;
   objectOSS << discount << "% off";

   cout << objectOSS.str();

   return 0;
}
