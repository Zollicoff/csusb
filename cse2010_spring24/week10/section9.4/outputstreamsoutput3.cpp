#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
   ostringstream objectOSS;
   string object;
   int quantity;
   int price;

   object = "Phone charger";
   quantity = 6;
   price = 10;

   objectOSS << object << " total is $" << quantity * price;

   cout << objectOSS.str();

   return 0;
}
