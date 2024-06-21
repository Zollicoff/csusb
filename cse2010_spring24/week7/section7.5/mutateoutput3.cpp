#include <iostream>
using namespace std;

class Dog {
   public:
      void SetWeight(int weightToSet);
      string GetSize() const;
   private:
      int weight;
      string size;
};

void Dog::SetWeight(int weightToSet) {
   weight = weightToSet;


   if (weight <= 15) {
      size = "small";
   }
   else if (weight <= 55) {
      size = "medium";
   }
   else {
      size = "large";
   }
}

string Dog::GetSize() const {
   return size;
}

int main() {
   Dog buddy;

   buddy.SetWeight(49);

   cout << "Your dog is " << buddy.GetSize();
   return 0;
}