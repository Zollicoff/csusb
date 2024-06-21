// Assign variable largestVal with the largest value of 8 positive floating-point values read from input.
// Ex: If the input is:
// 8.1 2.5 3.5 1.6 19.1 10.7 6.3 19.5
// then the output is:
// 19.5
// Note: The first value read is the largest value seen so far.All floating-point values are of type double.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double inVal;
    double largestVal;
    int i;

    cin >> largestVal;

    for (i = 1; i < 8; ++i) {
        cin >> inVal;

        if (inVal > largestVal) {
            largestVal = inVal;
        }
    }
   
    cout << largestVal << endl;

    return 0;
}