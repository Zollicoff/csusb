#include <iostream>
using namespace std;

int CoordTransform(int xValUser, int yValUser, int& xValNew, int& yValNew) {
   xValNew = (xValUser + 1) * 2;
   yValNew = (yValUser + 1) * 2;
}

int main() {
   int xValNew;
   int yValNew;
   int xValUser;
   int yValUser;

   cin >> xValUser;
   cin >> yValUser;

   CoordTransform(xValUser, yValUser, xValNew, yValNew);
   cout << "(" << xValUser << ", " << yValUser << ") becomes (" << xValNew << ", " << yValNew << ")" << endl;

   return 0;
}