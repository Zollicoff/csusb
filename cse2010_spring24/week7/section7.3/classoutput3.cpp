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
   string differentUserName;
   Person person1;

   userName = "John";
   differentUserName = "Max";

   person1.SetName(userName);
   cout << person1.GetName();
   person1.SetName(differentUserName);
   cout << " was " << person1.GetName();

   return 0;
}
