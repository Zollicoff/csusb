#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
   public:
      void SetPriceAndName(int productPrice, string productName) {
         price = productPrice;
         name = productName;
      };
      int GetPrice() const { return price; };
      string GetName() const { return name; };
   private:
      int price; // in dollars
      string name;
};

int main() {
   vector<Product> productList;
   Product currProduct;
   int currPrice;
   string currName;
   unsigned int i;
   Product resultProduct;

   cin >> currPrice;
   while (currPrice > 0) {
      cin >> currName;
      currProduct.SetPriceAndName(currPrice, currName);
      productList.push_back(currProduct);
      cin >> currPrice;
   }

   resultProduct = productList.at(0);
   for (i = 0; i < productList.size(); ++i) {
      if (productList.at(i).GetPrice() > resultProduct.GetPrice()) {
         resultProduct = productList.at(i);
      }
   }

   cout << "$" << resultProduct.GetPrice() << " " << resultProduct.GetName() << endl;

   return 0;
}
