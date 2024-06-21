#include <iostream>
using namespace std;

// Added parameters for dimes, nickels, and pennies
void ComputeChange(int totCents, int& numQuarters, int& numDimes, int& numNickels, int& numPennies) {
    numQuarters = totCents / 25;
    totCents %= 25;
    numDimes = totCents / 10;
    totCents %= 10;
    numNickels = totCents / 5;
    totCents %= 5;
    numPennies = totCents;
}

int main() {
    int userCents;
    int numQuarters, numDimes, numNickels, numPennies;

    cout << "Enter total cents: " << endl;
    cin >> userCents;

    // Calling ComputeChange with all necessary parameters
    ComputeChange(userCents, numQuarters, numDimes, numNickels, numPennies);

    cout << "Quarters: " << numQuarters << endl;
    cout << "Dimes: " << numDimes << endl;
    cout << "Nickels: " << numNickels << endl;
    cout << "Pennies: " << numPennies << endl;

    return 0;
}
