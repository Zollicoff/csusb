#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Animal {
   public:
      void SetSpecies(string animalSpecies);      
      void SetColor(string animalColor);      
      string GetSpecies() const;     
      string GetColor() const;        
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

string Animal::GetSpecies() const {
   return species;
}

string Animal::GetColor() const {
   return color;
}

int main() {
   Animal animal;
   string inputSpecies;
   string inputColor;

   cin >> inputSpecies;
   cin >> inputColor;
   animal.SetSpecies(inputSpecies);
   animal.SetColor(inputColor);

   cout << "Animal: " << animal.GetSpecies() << endl;
   cout << "Color: " << animal.GetColor() << endl;

   return 0;
}
