#include <iostream>
using namespace std;

class Car {
   public:
      Car(int distanceToSet = 0);
      void AddMiles(int milesToAdd);
   private:
      int distanceTraveled;
};

Car::Car(int distanceToSet) {
   distanceTraveled = distanceToSet;
   cout << "Traveled: " << distanceTraveled << endl;
}

void Car::AddMiles(int milesToAdd) {
   distanceTraveled = distanceTraveled + milesToAdd;
   cout << "Total miles: " << distanceTraveled << endl;
}

int main() {
   Car* myCar1 = nullptr;

   myCar1 = new Car(90);
   myCar1->AddMiles(10);

   return 0;
}