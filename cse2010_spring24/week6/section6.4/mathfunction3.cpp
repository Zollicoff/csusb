#include <iostream>
#include <iomanip>
using namespace std;

double ComputeBaseArea(double baseLength, double baseWidth) {
   double pyramidArea = baseLength * baseWidth;
   return pyramidArea;
}

double ComputeVol(double baseLength, double baseWidth, double baseHeight) {
   double pyramidVolume = ComputeBaseArea(baseLength, baseWidth) * baseHeight * (1.0 / 3.0);
   return pyramidVolume;
}

int main() {
   double userBaseLength;
	double userBaseWidth;
	double userHeight;

   cin >> userBaseLength;
	cin >> userBaseWidth;
	cin >> userHeight;

   cout << fixed << setprecision(1);

   cout << "Base length: " << userBaseLength << endl;
	cout << "Base width: " << userBaseWidth << endl;
	cout << "Height: " << userHeight << endl;

   cout << "Base area: ";
   cout << ComputeBaseArea(userBaseLength, userBaseWidth) << endl;

   cout << "Volume: ";
   cout << ComputeVol(userBaseLength, userBaseWidth, userHeight) << endl;

   return 0;
}
