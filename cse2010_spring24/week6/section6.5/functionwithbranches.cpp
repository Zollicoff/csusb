#include <iostream>
using namespace std;

int NormalizeGrade(int grade) {
   int upperBound = 86;
   int lowerBound = 52;

   if (grade > upperBound) {
      return upperBound;
   }
   else if (grade <= lowerBound){
      return lowerBound;
   }
   else {
      return grade;   
   }
}
    
int main() {
   int grade1 = NormalizeGrade(17);
   int grade2 = NormalizeGrade(93);
   int grade3 = NormalizeGrade(55);

   cout << grade1 << endl;
   cout << grade2 << endl;
   cout << grade3 << endl;
   
   return 0;
}
