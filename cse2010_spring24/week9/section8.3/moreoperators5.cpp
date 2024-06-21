#include <iostream>
using namespace std;

class BallObject {
   public:
      BallObject();
      void Read();
      void Print();
      ~BallObject();
   private:
      int forceApplied;
      int contactArea;
};
BallObject::BallObject() {
   forceApplied = 0;
   contactArea = 0;
}
void BallObject::Read() {
   cin >> forceApplied;
   cin >> contactArea;
}
void BallObject::Print() {
   cout << "BallObject's forceApplied: " << forceApplied << endl;
   cout << "BallObject's contactArea: " << contactArea << endl;
}
BallObject::~BallObject() { // Covered in section on Destructors.
   cout << "BallObject with forceApplied " << forceApplied << " and contactArea " << contactArea << " is deallocated." <<  endl;
}

int main() {
   BallObject* myBallObjects = nullptr;
   int count;
   int i;
   
   /* Your code goes here */
   cin >> count;
   myBallObjects = new BallObject[count];
   for (i = 0; i < count; i++) {
      myBallObjects[i].Read();
   }
   for (i = 0; i < count; i++) {
      myBallObjects[i].Print();
   }
   
   delete[] myBallObjects;
  
   return 0;
}
