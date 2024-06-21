#include <iostream>
#include <vector>
using namespace std;

bool IsSumLess(const vector<int>& inputVector, int threshold) {
   int sum = 0;
      
   for (int i = 0; i < inputVector.size(); ++i) {
      sum += inputVector.at(i);
   }
   
   return sum < threshold;
   
}
      
int main() {
   vector<int> inputVector;
   int size;
   int input;
   int i;
   int x;
   bool result;

   // Read the vector's size, and then the vector's elements
   cin >> size;
   for (i = 0; i < size; ++i) {
      cin >> input;
      inputVector.push_back(input);
   }

   cin >> x;

   result = IsSumLess(inputVector, x);

   if (result) {
		cout << "True, the sum of all the elements is less than " << x << "." << endl;
	}
	else {
		cout << "False, the sum of all the elements is not less than " << x << "." << endl;
	}

   return 0;
}