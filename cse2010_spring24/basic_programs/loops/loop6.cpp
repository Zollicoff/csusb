#include <iostream>
using namespace std;

int main() {
    int numInput;
    int variable;
    int i;
   
    cin >> numInput;

    for (i = 0; i < numInput; ++i) {
        cin >> variable;
        if (i != numInput - 1) {
            cout << variable << ", " ;
        } else { 
            cout << variable << endl;
        }
    }

    return 0;
}
