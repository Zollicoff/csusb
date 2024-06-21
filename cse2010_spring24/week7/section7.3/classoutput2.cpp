#include <iostream>
using namespace std;

class Person {
   public:
      void SetFirstName(string firstNameToSet);
      void SetLastName(string lastNameToSet);
      string GetFullName();
   private:
      string first;
      string last;
};

void Person::SetFirstName(string firstNameToSet) {
   first = firstNameToSet;
}

void Person::SetLastName(string lastNameToSet) {
   last = lastNameToSet;
}

string Person::GetFullName() {
   return  first + "-" + last;
}

int main() {
   string userFirstName;
   string userLastName;
   Person person1;

   userFirstName = "Bob";
   userLastName = "Kent";

   person1.SetFirstName(userFirstName);
   person1.SetLastName(userLastName);
   cout << "He is " << person1.GetFullName();

   return 0;
}