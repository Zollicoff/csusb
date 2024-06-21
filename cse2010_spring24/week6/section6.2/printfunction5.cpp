#include <iostream>
using namespace std;

void PrintResult(int a, int b) {
   cout << "Sum: " << a + b << endl;
}

int main() {
   int a1;
   int b1;

   cin >> a1;
   cin >> b1;

   PrintResult(a1, b1);

   return 0;
}
