#include <iostream>
#include <string>
using namespace std;

class RentalCar {
   public:
      RentalCar();
      void SetRenter(string rentalCarRenter);
		void SetGasTank(int rentalCarGasTank);
      void Print();

   private:
      string renter;
		int gasTank;
};

RentalCar::RentalCar() {
   renter = "Unspecified";
   gasTank = 0;
}

void RentalCar::SetRenter(string rentalCarRenter) {
	renter = rentalCarRenter;
}

void RentalCar::SetGasTank(int rentalCarGasTank) {
	gasTank = rentalCarGasTank;
}

void RentalCar::Print() {
   cout << "Renter: " << renter << ", Gas tank: " << gasTank << endl;
}

int main() {
   string newRenter;
	int newGasTank;
   RentalCar rentalCar1;

   rentalCar1.Print();
   
   cin >> newRenter;
	cin >> newGasTank;

   rentalCar1.SetRenter(newRenter);
	rentalCar1.SetGasTank(newGasTank);

   rentalCar1.Print();

   return 0;
}
