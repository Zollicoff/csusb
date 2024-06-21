#include <iostream>
using namespace std;

int main() {
    int currentNum;
    int previousNum;
   
    cin >> previousNum;
    cin >> currentNum;
    cout << "Sequence starts at " << previousNum << "." << endl;

    while (currentNum < previousNum) {
        cout << currentNum << " is less than " << previousNum << ". Sequence is decreasing." << endl;
        previousNum = currentNum;
        cin >> currentNum;
    }

    return 0;
}
