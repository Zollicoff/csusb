#include <iostream>
using namespace std;

void PrintNums(int a = 4, int b = 7, int c = 1) {
   cout << a << ", " << b << ", " << c << endl;
}

int main() {
   PrintNums(6, 2);
   PrintNums(9);
   PrintNums();

   return 0;
}
