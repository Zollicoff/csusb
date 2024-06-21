#include <iostream>
using namespace std;

void CountDown(int countInt) {
   if (countInt <= 0) {
      cout << "Go!\n";
   }
   else {
      cout << countInt << endl;
      CountDown(countInt - 1);
   }
}

int main() {
   CountDown(2);
   return 0;
}
