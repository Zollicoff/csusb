#include <iostream>
using namespace std;

int Fibonacci(int num) {
   
   if (num < 0) {
      return -1;
   }
   
   if (num <= 1) {
      return num;
   }
   
   int previous = 0, current = 1, next;
   for (int i = 2; i <= num; i++) {
      next = previous + current;
      previous = current;
      current = next;
   }
   
   return current;
   
}

int main() {
   int startNum;
      
   cin >> startNum;
   cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;

   return 0;
}
