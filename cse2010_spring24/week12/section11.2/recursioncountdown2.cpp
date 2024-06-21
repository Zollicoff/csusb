#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void CountDown(int countInt) {
   if (countInt <= 0) {
      cout << "Go!\n";
   }
   else {
      cout << countInt << endl;
      this_thread::sleep_for(chrono::seconds(1));
      CountDown(countInt - 1);
   }
}

int main() {
   int count;
   cout << "Enter a number to count down from: ";
   cin >> count;
   CountDown(count);
   return 0;
}