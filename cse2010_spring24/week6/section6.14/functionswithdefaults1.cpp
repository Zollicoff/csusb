#include <iostream>
using namespace std;

void PrintNums(int a, int b, int c = 6) {
   cout << a << ", " << b << ", " << c << endl;
}

int main() {
   PrintNums(2, 5);
   PrintNums(8, 6, 4);

   return 0;
}