#include <iostream>
#include <iomanip>
using namespace std;

class MovingBody {
   public:
      MovingBody();
      void Read();
      void Print();
      ~MovingBody();
   private:
      double force;
      double displacement;
};
MovingBody::MovingBody() {
   force = 0.0;
   displacement = 0.0;
}
void MovingBody::Read() {
   cin >> force;
   cin >> displacement;
}  
void MovingBody::Print() {
   cout << "MovingBody's force: " << fixed << setprecision(1) << force << endl;
   cout << "MovingBody's displacement: " << fixed << setprecision(1) << displacement << endl;
}  
MovingBody::~MovingBody() { // Covered in section on Destructors.
   cout << "MovingBody with force " << force << " and displacement " << displacement << " is deallocated." <<  endl;
}

int main() {
   MovingBody* myMovingBody = nullptr;
   
   /* Your code goes here */
   myMovingBody = new MovingBody();
   myMovingBody->Read();
   myMovingBody->Print();
   delete myMovingBody;   

   return 0;
}