#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Member {
   public:
      void SetName(string memberName); 
      void SetAge(int memberAge);      
      string GetName() const;                        
      int GetAge() const;                        
      void Print() const;              
   private:
      string name;
      int age;
};

void Member::SetName(string memberName) {
   name = memberName;
}

void Member::SetAge(int memberAge) {
   age = memberAge;
}

string Member::GetName() const {
   return name;
}

int Member::GetAge() const {
   return age;
}

int main() {
   Member person;
   string inputName;
   int inputAge;

   cin >> inputName;
   cin >> inputAge;
   person.SetName(inputName);
   person.SetAge(inputAge);
 
   cout << "Description: " << person.GetName();
   cout << "'s age is " << person.GetAge() << " years old" << endl;

   return 0;
}
