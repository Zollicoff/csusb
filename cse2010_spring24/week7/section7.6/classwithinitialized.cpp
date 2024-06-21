#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Volume {
   public:
      void SetGallons(double volumeGallons);      
      double GetGallons() const;                        
      void PrintInCups();
   private:
      double gallons;
      double ConvertToCups();                
};

void Volume::SetGallons(double volumeGallons) {
   gallons = volumeGallons;
}

double Volume::GetGallons() const {
   return gallons;
}

double Volume::ConvertToCups() {
   return gallons * 16;
}

void Volume::PrintInCups() {
   cout << fixed << setprecision(1) << ConvertToCups() << " cups" << endl;
}

int main() {
   Volume volume1;
   double inputGallons;

   cin >> inputGallons;
   volume1.SetGallons(inputGallons);

   volume1.PrintInCups();

   return 0;
}
