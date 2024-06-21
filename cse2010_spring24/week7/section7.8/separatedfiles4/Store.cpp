#include <iostream>
#include "Store.h"
using namespace std;

void Store::SetName(string storeName) {
   name = storeName;
}

void Store::ReadAllProducts() {
   products.InputProducts();
}

void Store::PrintSale(int saleAmount) {
   cout << name << "'s sale:" << endl;
   products.PrintAfterDiscount(saleAmount);
}
