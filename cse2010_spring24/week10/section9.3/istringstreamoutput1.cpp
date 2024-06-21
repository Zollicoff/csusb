#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
   string objectInfo = "Shoes 14 17";
   istringstream objectISS(objectInfo);
   string object;
   int quantity;
   int price;
   
   objectISS >> object >> price >> quantity;
   
   cout << object << " x" << quantity << endl;
   cout << "Price: " << price;
   
   return 0;
}