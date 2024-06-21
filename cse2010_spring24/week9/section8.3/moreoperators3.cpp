#include <iostream>
#include <iomanip>
using namespace std;

class BallObject {
   public:
      BallObject(double forceAppliedValue, double contactAreaValue);
      void IncreaseForceAppliedAndContactArea();
      void Print();
   private:
      double forceApplied;
      double contactArea;
};
BallObject::BallObject(double forceAppliedValue, double contactAreaValue) {
   forceApplied = forceAppliedValue;
   contactArea = contactAreaValue;
}
void BallObject::IncreaseForceAppliedAndContactArea() {
	forceApplied = forceApplied * 6.0;
	contactArea = contactArea * 6.0;
   cout << "BallObject's forceApplied and contactArea are increased." << endl;
}
void BallObject::Print() {
   cout << "BallObject's forceApplied: " << fixed << setprecision(1) << forceApplied << endl;
   cout << "BallObject's contactArea: " << fixed << setprecision(1) << contactArea <<  endl;
}


int main() {
   
   /* Additional variable declarations go here */
   double forceAppliedValue;
   double contactAreaValue;
   BallObject* myBallObject = nullptr;
   
   cin >> forceAppliedValue;
   cin >> contactAreaValue;
   
   /* Your code goes here */
   myBallObject = new BallObject(forceAppliedValue, contactAreaValue);   
   
   myBallObject->IncreaseForceAppliedAndContactArea();

   myBallObject->Print();
   
   return 0;
}