#ifndef STORE_H
#define STORE_H

#include "Products.h"

class Store {
   public:
      void SetName(std::string storeName);
      void ReadAllProducts();
      void PrintSale(int saleAmount);
   private:
      std::string name;
      Products products;
};
#endif
