#include <iostream>
using namespace std;

class Lion {
   public:
      Lion(int ageValue, int weightValue);
      void Print();
   private:
      int age;
      int weight;
};
Lion::Lion(int ageValue, int weightValue) {
   age = ageValue;
   weight = weightValue;
}
void Lion::Print() {
   cout << "Lion's age: " << age << endl;
   cout << "Lion's weight: " << weight << endl;
}

int main() {
   Lion* myLion = nullptr;
   int ageValue;
   int weightValue;

   cin >> ageValue;
   cin >> weightValue;
   
   /* Your code goes here */
   myLion = new Lion(ageValue, weightValue); 
 
   myLion->Print();
   
   return 0;
}