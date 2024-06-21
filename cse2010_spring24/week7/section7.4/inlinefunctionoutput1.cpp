#include <iostream>
#include <string>
using namespace std;

class State {
   public:
      void SetCapital(string stateCapital) {
         capital = stateCapital;
      }
      void SetName(string stateName) {
         name = stateName;
      }
      void Print() const;

   private:
      string capital;
      string name;
};

void State::Print() const {
   cout << capital << ": " << name << endl;
}

int main() {
   State stateToVisit;

   stateToVisit.SetCapital("Des Moines");
   stateToVisit.SetName("Iowa");

   stateToVisit.Print();

   return 0;
}
