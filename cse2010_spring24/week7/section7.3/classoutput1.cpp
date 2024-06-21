#include <iostream>
using namespace std;

class Person {
   public:
      void SetName(string nameToSet);
      string GetName();
   private:
      string name;
};

void Person::SetName(string nameToSet) {
   name = nameToSet;
}

string Person::GetName() {
   return name;
}

int main() {
   string userName;
   Person person1;

   userName = "Max";

   person1.SetName(userName);
   cout << "He is " << person1.GetName();

   return 0;
}
