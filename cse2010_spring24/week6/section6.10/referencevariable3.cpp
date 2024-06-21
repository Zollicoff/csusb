#include <iostream>
using namespace std;

int main() {
   char rankValue;

   char& rankRef = rankValue;

   cin >> rankValue;
  
   cout << "Referenced rank is " << rankRef << "." << endl;

   return 0;
}
