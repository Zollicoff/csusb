#include <iostream>
#include <string>
using namespace std;

class Eatery {
   public:
      void SetState(string eateryState);
		void SetRating(int eateryRating);
		void SetName(string eateryName);
      void Print();

   private:

      string state = "Unstated";
      int rating = -1;
      string name = "Incomplete";

};

void Eatery::SetState(string eateryState) {
	state = eateryState;
}

void Eatery::SetRating(int eateryRating) {
	rating = eateryRating;
}

void Eatery::SetName(string eateryName) {
	name = eateryName;
}

void Eatery::Print() {
   cout << "State: " << state << ", Rating: " << rating << ", Name: " << name << "'s Food Truck" << endl;
}

int main() {
   string newState;
	int newRating;
	string newName;
   Eatery eatery1;

   eatery1.Print();

   cin >> newState;
	cin >> newRating;
	cin >> newName;

   eatery1.SetState(newState);
	eatery1.SetRating(newRating);
	eatery1.SetName(newName);

   eatery1.Print();

   return 0;
}