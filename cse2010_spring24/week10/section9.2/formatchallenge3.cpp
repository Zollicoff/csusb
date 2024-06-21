#include <iostream>
#include <iomanip>
using namespace std;

int main() {   
   string itemName;
   int itemCount;
  
   cin >> itemName;
   cin >> itemCount;
   
   cout << setfill('{') << setw(15) << left << itemName;
   cout << setfill('}') << setw(15) << right << itemCount << endl;

   return 0;
}
