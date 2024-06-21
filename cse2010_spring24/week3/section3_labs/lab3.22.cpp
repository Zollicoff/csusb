#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   
    int integer1, integer2, integer3;
   
    cin >> integer1 >> integer2 >> integer3;
   
    int smallest = min({integer1,integer2,integer3});
   
    cout << smallest << endl;

    return 0;
}
