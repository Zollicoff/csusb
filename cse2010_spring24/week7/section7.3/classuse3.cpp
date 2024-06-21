#include <iostream>
using namespace std;

class Member {
   public:
      int GetAge();
      double GetHeight();
      void SetAge(int newAge);
      void SetHeight(double newHeight);
   private:
      int age;
      double height;
};

void Member::SetAge(int newAge) {
   age = newAge;
}

void Member::SetHeight(double newHeight) {   
   height = newHeight;
}

int Member::GetAge() {
   return age;
}

double Member::GetHeight() {
   return height;
}

int main() {
   Member member1;
   int inputAge;
   double inputHeight;

   cin >> inputAge;
   cin >> inputHeight;

   member1.SetAge(inputAge);
   member1.SetHeight(inputHeight);
   
   cout << "Age: " << member1.GetAge() << endl;
   cout << "Height: " << member1.GetHeight() << endl;

   return 0;
}