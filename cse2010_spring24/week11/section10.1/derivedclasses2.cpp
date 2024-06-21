#include <iostream>
using namespace std;

class Vehicle {
   public:
      void SetSpeed(int speedToSet) {
         speed = speedToSet;
      }

      void PrintSpeed() {
         cout << speed;
      }

   private:
      int speed;
};

class Car : public Vehicle {
   public:
      void PrintCarSpeed() {
         cout << "Speed: ";
         PrintSpeed();
      }
};

int main() {
   Car myCar;
   myCar.SetSpeed(35);

   myCar.PrintCarSpeed();

   return 0;
}