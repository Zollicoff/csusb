#include <iostream>
using namespace std;

int FindTicketPrice(int travelerAge) {
   int ticketPrice = 0;
   if (travelerAge > 75 || travelerAge < 4) {
      ticketPrice = 2;
   }
   else if (travelerAge >= 17 && travelerAge <= 56) {
      ticketPrice = 27;
   }
   else {
      ticketPrice = 18;
   }
   return ticketPrice;
}

int main() {
   int travelerAge;
   cin >> travelerAge;
   cout << FindTicketPrice(travelerAge) << endl;
   return 0;
}
