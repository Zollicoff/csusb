#include <iostream>
#include <vector>
using namespace std;

int main() {
   double distance1;
	double distance2;
	double distance3;
	double distance4;
	double distance5;
	unsigned int i;

   cin >> distance1;
	cin >> distance2;
	cin >> distance3;
	cin >> distance4;
	cin >> distance5;
	
   vector<double> swimmingDistance(10);
   
   swimmingDistance.at(1) = distance1;
   swimmingDistance.at(3) = distance2;
   swimmingDistance.at(5) = distance3;
   swimmingDistance.at(7) = distance4;
   swimmingDistance.at(9) = distance5;
   
   for (i = 0; i < swimmingDistance.size(); ++i) {
      cout << swimmingDistance.at(i) << " ";
   }
   cout << endl;
   
   return 0;
}
