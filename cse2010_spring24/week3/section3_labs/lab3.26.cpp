#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, lastName, middleName;
    cin >> firstName >> lastName;
    if (cin >> middleName) {
        string temp = lastName;
        lastName = middleName;
        middleName = temp;
    }
    string firstInitial = firstName.substr(0, 1);
    if (!middleName.empty()) {
        string middleInitial = middleName.substr(0, 1);
        cout << lastName << ", " << firstInitial << "." << middleInitial << "." << endl;
    } else {
        cout << lastName << ", " << firstInitial << "." << endl;
    }
    return 0;
}
