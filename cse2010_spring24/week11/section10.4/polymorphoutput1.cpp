#include <iostream>
#include <vector>
using namespace std;

class Watch {
public:
   void SetHours(int watchHours) {
      hours = watchHours;
   }

   void SetMins(int watchMins) {
      mins = watchMins;
   }

   virtual void PrintItem() {
      cout << hours << ":" << mins << endl;
   }

protected:
   int hours;
   int mins;
};

class SmartWatch : public Watch {
public:
   void SetPercentage(int watchPercentage) {
      batteryPercentage = watchPercentage;
   }

   void PrintItem() {
      cout << hours << ":" << mins << " " << batteryPercentage << "%" << endl;
   }

private:
   int batteryPercentage;
};

int main() {
   Watch* watch1;
   SmartWatch* watch2;
   Watch* watch3;

   vector<Watch*> watchList;
   unsigned int i;

   watch1 = new Watch();
   watch1->SetHours(3);
   watch1->SetMins(17);
   
   watch2 = new SmartWatch();
   watch2->SetHours(4);
   watch2->SetMins(56);
   watch2->SetPercentage(29);

   watch3 = new Watch();
   watch3->SetHours(11);
   watch3->SetMins(43);
   
   watchList.push_back(watch3);
   watchList.push_back(watch1);
   watchList.push_back(watch2);

   for (i = 0; i < watchList.size(); ++i) {
      watchList.at(i)->PrintItem();
   }
   
   return 0;
}