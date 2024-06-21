#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Animal {
   public:
      void SetSpecies(string animalSpecies);      
      void SetColor(string animalColor);     
      void Print() const;   
   private:
      string species;
      string color;
};

void Animal::SetSpecies(string animalSpecies) {
   species = animalSpecies;
}

void Animal::SetColor(string animalColor) {
   color = animalColor;
}

void Animal::Print() const {
   cout << "Animal: " << species << endl;
   cout << "Color: " << color << endl;
}

int main() {
   Animal animal;
   string inputSpecies;
   string inputColor;

   cin >> inputSpecies;
   cin >> inputColor;
   animal.SetSpecies(inputSpecies);
   animal.SetColor(inputColor);

   animal.Print();

   return 0;
}