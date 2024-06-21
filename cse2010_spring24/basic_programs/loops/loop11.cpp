//Integer numInput is read from input representing the number of integers to be read next.
//Use a loop to read the remaining integers from input. For each integer read, output 
//"Value read: " followed by the value. Then, output "Smallest: " followed by the smallest 
//of the integers read. End each output with a newline.
//Ex: If the input is:
//3
//370 255 -390
//then the output is:
//Value read: 370
//Value read: 255
//Value read: -390
//Smallest: -390

#include <iostream>
using namespace std;

int main() {
    int numInput;
    int inputVal;
    int smallestVal;
    int i;

    cin >> numInput;
    cin >> smallestVal;

    for (i = 1; i < numInput; ++i) {
        cin >> inputVal;
        cout << "Value read: " << inputVal << endl;
        if (inputVal < smallestVal) {
            smallestVal = inputVal;
        }
    }

    cout << "Smallest: " << smallestVal << endl;

        return 0;
}
