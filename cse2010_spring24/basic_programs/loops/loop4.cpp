#include <iostream>
using namespace std;

int main() {
    int inputCount;
    int value;
    int i;

    cin >> inputCount;

    for (i = 0; i < inputCount; ++i) {
        cin >> value; // Read the next integer into value
        cout << value << " foxes" << endl; // Output the value followed by " foxes"
    }

    return 0;
}
