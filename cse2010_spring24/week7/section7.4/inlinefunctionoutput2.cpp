#include <iostream>
#include <string>
using namespace std;

class State {
   public:
      void SetName(string stateName) {
         name = stateName;
      }
      void SetCode(string stateCode) {
         code = stateCode;
      }
      void Print() const {
         cout << name << ": " << code << endl;   
      }

   private:
      string name;
      string code;
};


int main() {
   State favoriteState;

   favoriteState.SetName("Tennessee");
   favoriteState.SetCode("TN");

   favoriteState.Print();

   return 0;
}
