#include <iostream>
using namespace std;

class Dog {
   public:
      Dog();
      void Print();

      int age;
      int weight;
};
Dog::Dog() {
   age = 0;
   weight = 0;
}
void Dog::Print() {
   cout << "Dog's age: " << age << endl;
   cout << "Dog's weight: " << weight <<  endl;
}

int main() {
   int ageValue;
   int weightValue;
   
   /* Additional variable declarations go here */
   Dog* myDog = nullptr;
  
   cin >> ageValue;
   cin >> weightValue;
  
   /* Your code goes here */
   myDog = new Dog();
   myDog->age = ageValue;
   myDog->weight =weightValue;
   
   myDog->Print();
   
   return 0;
}