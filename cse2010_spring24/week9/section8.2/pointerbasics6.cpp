#include <iostream>
using namespace std;

void GetWeight(int* weightPointer) {

   /* Your code goes here */
   if (weightPointer != nullptr) {
      cin >> *weightPointer;
   }
   else {
      cout << "weightPointer is null." << endl;
   }

}

int main() {
   int weight;
   int* weightPointer;
   char action;
   
   weight = 0;
   cin >> action;
   
   if (action == 'Y') {
      weightPointer = &weight;
   }
   else {
      weightPointer = nullptr;
   }
  
   GetWeight(weightPointer);
	cout << "Weight is " << weight << "." << endl;

   return 0;
}