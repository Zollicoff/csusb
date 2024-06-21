#include <iostream>
using namespace std;

void PrintTime(int weeks) {
   cout << "Total " << weeks << " weeks" << endl;
}

void PrintTime(int weeks, int days) {
   cout << "Total " << weeks << " weeks and " << days << " days" << endl;
}

int main() {
   int weeksUsed;
   int daysUsed;
   
   cin >> weeksUsed;
   cin >> daysUsed;
   
   PrintTime(weeksUsed);
   PrintTime(weeksUsed, daysUsed);
   
   return 0;
}
