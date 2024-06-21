#include <iostream>
using namespace std;

void PrintUniversityLocation(string city, string university) {
   cout << city << " is the location of " << university << " University." << endl;
}

int main() {

   string cityOne;
   string cityTwo;
   string universityOne;
   string universityTwo;
   
   cin >> cityOne;
   cin >> cityTwo;
   cin >> universityOne;
   cin >> universityTwo;
   
   PrintUniversityLocation(cityOne, universityOne);
   PrintUniversityLocation(cityTwo, universityTwo);

   return 0;
}
