#include <iostream>
using namespace std;

void PrintVal(int number1, int number2) {
    int sum = 0;
    
    // If number1 is negative, start summing from 1, else start from number1
    int start = number1 < 1 ? 1 : number1;

    // Sum only if the start is less than or equal to number2 and number2 is positive
    if (start <= number2 && number2 > 0) {
        for (int i = start; i <= number2; ++i) {
            sum += i;
        }
        cout << sum << endl;
    } else {
        cout << 0 << endl; // Output 0 if there are no positive numbers in the range
    }
}

int main() {
    int number1;
    int number2;

    cin >> number1;
    cin >> number2;
    PrintVal(number1, number2);

    return 0;
}
