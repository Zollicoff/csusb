// FoodItem.h

#ifndef FOODITEMH
#define FOODITEMH

#include <string>

using namespace std;

class FoodItem {
public:
   FoodItem();  // Default constructor
   FoodItem(string name, double fat, double carbs, double protein);  // Parameterized constructor

   string GetName();
   double GetFat();
   double GetCarbs();
   double GetProtein();
   double GetCalories(double numServings);
   void PrintInfo();

private:
   string name;
   double fat = 0.0;
   double carbs = 0.0;
   double protein = 0.0;
};

#endif
