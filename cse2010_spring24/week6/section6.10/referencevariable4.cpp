#include <iostream>
using namespace std;

void SwapHeight(double& height1, double& height2) {
   double tempHeight = height1;
   height1 = height2;
   height2 = tempHeight;
}

int main() {
   double height1;
	double height2;

	cin >> height1;
	cin >> height2;

   SwapHeight(height1, height2);

   cout << height1 << " " << height2 << endl;
   
   return 0;
}
