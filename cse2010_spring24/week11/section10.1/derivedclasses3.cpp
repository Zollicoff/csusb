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

class AnimalPowered : public Vehicle {
   public:
      void SetAnimal(string animalToSet) {
         animal = animalToSet;
      }

      void PrintAnimalSpeed() {
         cout << animal << " speed: ";
         PrintSpeed();
      }

   private:
      string animal;
};

int main() {
   Car myCar;
   AnimalPowered chariot;

   myCar.SetSpeed(30);
   chariot.SetSpeed(9);
   chariot.SetAnimal("Donkey");

   myCar.PrintCarSpeed();
   cout << endl;
   chariot.PrintAnimalSpeed();

   return 0;
}