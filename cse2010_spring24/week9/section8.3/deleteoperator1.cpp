#include <iostream>
using namespace std;

class Point {
public:
   Point(double xValue = 0, double yValue = 0) : X(xValue), Y(yValue) {}
   void Print() {
      cout << "X = " << X << ", Y = " << Y << endl;
   }

   double X;
   double Y;
};

int main() {
   Point* point1 = new Point(73, 19);
   cout << "X = " << point1->X << endl;
   cout << "Y = " << point1->Y << endl;

   delete point1;

}
