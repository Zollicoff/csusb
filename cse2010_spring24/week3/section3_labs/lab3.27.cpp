#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, lastName;
    int number;
    cin >> firstName >> lastName >> number;
    string firstPart = firstName.substr(0, min(6, static_cast<int>(firstName.length())));
    char lastInitial = lastName[0];
    int lastDigit = number % 10;
    string loginName = firstPart + lastInitial + "_" + to_string(lastDigit);
    cout << "Your login name: " << loginName << endl;
    return 0;
}
