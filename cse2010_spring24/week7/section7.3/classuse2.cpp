#include <iostream>
using namespace std;

class PilotLicense {
   public:
      void SetYear(int newYear);
      void SetFee(int newFee);
      int GetYear();
      int GetFee();
   private:
      int year;
      int fee;
};

void PilotLicense::SetYear(int newYear) {
   year = newYear;
}

void PilotLicense::SetFee(int newFee) {   
   fee = newFee;
}

int PilotLicense::GetYear() {
   return year;
}

int PilotLicense::GetFee() {
   return fee;
}

int main() {
   PilotLicense pilot1;
   int inputYear;
   int inputFee;

   cin >> inputYear;
   cin >> inputFee;

   pilot1.SetYear(inputYear);
   pilot1.SetFee(inputFee);
   
   cout << "License year: " << pilot1.GetYear() << endl;
   cout << "License fee: " << pilot1.GetFee() << endl;

   return 0;
}
