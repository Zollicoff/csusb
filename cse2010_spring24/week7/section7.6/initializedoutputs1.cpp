#include <iostream>
#include <string>
using namespace std;

class Bicycle {
   public:
      void SetType(string bicycleType);
      void SetYear(int bicycleYear);
      void Print();
   private:
      string type = "NoType";  // NoType indicates brand was not set
      int year = -1;           // -1 indicates year was not set
};

void Bicycle::SetType(string bicycleType) {
   type = bicycleType;
}

void Bicycle::SetYear(int bicycleYear) {
   year = bicycleYear;
}

void Bicycle::Print() {
   cout << type << " " << year << endl;
}

int main() {
   Bicycle commuterBike;
   
   commuterBike.Print();
   
   commuterBike.SetYear(1903);

   commuterBike.Print();
   
   return 0;
}
