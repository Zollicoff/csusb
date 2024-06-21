#include <iostream>
using namespace std;

int main() {
    int highwayNumber;
   
    cin >> highwayNumber;

    int servingNumber = highwayNumber % 100;
   
    if (highwayNumber >= 1 && highwayNumber <= 99) {
        if (highwayNumber % 2 == 0) {
            cout << "I-" << highwayNumber << " is primary, going east/west." << endl;
        } else {
            cout << "I-" << highwayNumber << " is primary, going north/south." << endl;
        }
    }
    else if (highwayNumber >= 100 && highwayNumber <= 999) {
        if (servingNumber == 0) {
            cout << highwayNumber << " is not a valid interstate highway number." << endl;
        }
        else if (highwayNumber % 2 == 0) {
            cout << "I-" << highwayNumber << " is auxiliary, serving I-" << servingNumber << ", going east/west." << endl;
        } else {
            cout << "I-" << highwayNumber << " is auxiliary, serving I-" << servingNumber << ", going north/south." << endl;
        }
    }
    else {
        cout << highwayNumber << " is not a valid interstate highway number." << endl;
    }
    return 0;
}
