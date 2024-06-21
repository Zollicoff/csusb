// "New" means new compared to previous level
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
// END Product class

// New: Products class has been added
class Products {
   public:
      void InputProducts();
      void PrintAfterDiscount(int discountPrice);
   private:
      vector<Product> productList;
};

void Products::InputProducts() {
   Product currProduct;
   int currPrice;
   string currName;

   cin >> currPrice;
   while (currPrice > 0) {
      cin >> currName;
      currProduct.SetPriceAndName(currPrice, currName);
      productList.push_back(currProduct);
      cin >> currPrice;
   }
}

void Products::PrintAfterDiscount(int discountPrice) {
   unsigned int i;
   int currDiscountPrice;

   for (i = 0; i < productList.size(); ++i) {
      currDiscountPrice = productList.at(i).GetPrice() - discountPrice;
      cout << "$" << currDiscountPrice << " " << productList.at(i).GetName() << endl;
   }
}
// New: END Products class

int main() {

   // New: main() now uses Products class
   Products allProducts;

   allProducts.InputProducts();
   allProducts.PrintAfterDiscount(3);

   return 0;
}
