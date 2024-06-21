
#include <iostream>
using namespace std;

class Dog {
   public:
      void SetAge(int yearsToSet);
      void AddBirthday();
      int GetAge() const;
   private:
      int years;
};

void Dog::SetAge(int yearsToSet) {
   years = yearsToSet;
}

void Dog::AddBirthday() {
   years = years + 1;
}

int Dog::GetAge() const {
   return years;
}

int main() {
   Dog buddy;

   buddy.SetAge(4);
   buddy.AddBirthday();
   buddy.AddBirthday();
   buddy.AddBirthday();
   buddy.AddBirthday();
   buddy.AddBirthday();

   cout << buddy.GetAge();
   return 0;
}
