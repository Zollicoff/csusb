#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
   string object1Info = "Pen 9 6";
   string object2Info = "Notepad 11 14";
   string object3Info = "Headphones 23 24";

   istringstream objectISS(object3Info);

   string object;
   int quantity;
   int price;

   objectISS >> object >> price >> quantity;

   cout << object << " x" << quantity << endl;
   cout << "Price: " << price;

   return 0;
}
