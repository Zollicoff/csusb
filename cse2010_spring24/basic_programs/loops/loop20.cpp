#include <iostream>
using namespace std;

int main() {
   enum GroceryItem {GR_APPLES, GR_BANANAS, GR_JUICE, GR_WATER};
   GroceryItem userItem;

   userItem = GR_APPLES; /* Your code will be tested with GR_APPLES and other values for userItem */

   if (userItem == GR_APPLES || userItem == GR_BANANAS) {
      cout << "Fruit" << endl;
   } else if (userItem == GR_JUICE || userItem == GR_WATER) {
      cout << "Drink" << endl;
   } else {
      cout << "Unknown" << endl;
   }
      

   return 0;
}
