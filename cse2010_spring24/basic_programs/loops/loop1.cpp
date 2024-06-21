#include <iostream>
using namespace std;

int main() {
    double inVal;
	double sumInRange;
	
	sumInRange = 0.0;
   
    while (cin >> inVal) {
        if (inVal <= -35.0 || inVal >= 30.0) {
            break;
        }
        sumInRange += inVal;
    }
   
    cout << sumInRange << endl;
   
    return 0;
}
