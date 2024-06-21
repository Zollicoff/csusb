#include <iostream>
using namespace std;

// Returns false if value is not prime, true if value is prime
bool IsPrime(int testVal, int divVal) {
   // Base case 1: 0 and 1 are not prime, testVal is not prime
   if (testVal <= 1) {
      return false;
   }

   // Base case 2: testVal only divisible by 1, testVal is prime
   if (divVal == 1) {
      return true;
   }

   // Recursive Case
   // Check if testVal can be evenly divided by divVal
   // Hint: use the % operator
   if (testVal % divVal == 0) {
      return false;
   }

   // If not, recursive call to IsPrime with testVal and (divVal - 1)
   return IsPrime(testVal, divVal - 1);
}

int main() {
   int primeCheckVal;     // Value checked for prime
   
   // Check primes for values 1 to 10
   for (primeCheckVal = 1; primeCheckVal <= 10; ++primeCheckVal) {
      if (IsPrime(primeCheckVal, (primeCheckVal - 1))) {
         cout << primeCheckVal << " is prime." << endl;
      }
      else {
         cout << primeCheckVal << " is not prime." << endl;
      }
   }

   return 0;
}
