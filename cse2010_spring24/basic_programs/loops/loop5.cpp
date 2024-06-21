#include <iostream>
using namespace std;

int main() {
    int inputCount;
    int value;

    cin >> inputCount;

    for (int i = 0; i < inputCount; ++i) {
        cin >> value;
        cout << "{" << value << "}";
    }

    cout << endl; // End with a newline

   return 0;
}
