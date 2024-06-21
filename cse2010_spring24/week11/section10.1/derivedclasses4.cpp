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

class ElectricCar : public Car {
   public:
      void SetBatteryLevel(int levelToSet) {
         batteryLevel = levelToSet;
      }

      void PrintBatteryLevel() {
         cout << "Battery: " << batteryLevel;
      }

   private:
      int batteryLevel;
};

int main() {
   ElectricCar myCar;

   myCar.SetSpeed(60);
   myCar.SetBatteryLevel(65);

   myCar.PrintCarSpeed();
   cout << endl;
   myCar.PrintBatteryLevel();

   return 0;
}