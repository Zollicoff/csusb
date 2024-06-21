#include <iostream>
using namespace std;

int ComputeFibonacci(int N) {
   if (N <= 0) {
      return 0;
   }
   else if (N == 1) {
      return 1;
   }
   else {
      return ComputeFibonacci(N - 1) + ComputeFibonacci(N - 2);
   }
}

int main() {
   int N;       // F_N, starts at 0
 
   N = 4;
   
   cout << "F_" << N << " is "
        << ComputeFibonacci(N) << endl;
   
   return 0;
}
