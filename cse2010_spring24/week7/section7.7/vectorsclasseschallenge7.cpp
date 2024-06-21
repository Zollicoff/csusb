#include <iostream>
#include <vector>
using namespace std;

class City {
   public:
      void ReadDetails();
      void Print() const;
   private:
      string name;
      char rating;
};

void City::ReadDetails() {
	cin >> name;
	cin >> rating;
}

void City::Print() const {
   cout << "City: " << name << ", Rating: " << rating << endl;
}

class SmallCities {
   public:
      void InputCities();
      void PrintCities();
   private:
      vector<City> cityList;
};

void SmallCities::InputCities() {
   City currCity;
   int lineNumber;

   cin >> lineNumber;
   while (lineNumber != -99) {
      currCity.ReadDetails();
      cityList.push_back(currCity);
      cin >> lineNumber;
   }
}

void SmallCities::PrintCities() {
   City currCity;
   unsigned int i;

   for (i = 0; i < cityList.size(); ++i) {
      currCity = cityList.at(i);
      currCity.Print();
   }
}

int main() {
   SmallCities smallCities;

   smallCities.InputCities();
   smallCities.PrintCities();
 
   return 0;
}
