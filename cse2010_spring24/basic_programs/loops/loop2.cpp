#include <iostream>
using namespace std;

int main() {
    string stringToFind;
	string inputString;
	int expectedCount;

	cin >> stringToFind;
	cin >> inputString;

	expectedCount = 1;

    while (inputString != "Stop") {
        if (inputString == stringToFind) {
            expectedCount = expectedCount + 1;
        }
        cin >> inputString;
    }

	cout << stringToFind << " occurs " << expectedCount << " time(s)." << endl;

   return 0;
}
