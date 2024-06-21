#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int identifier;
   double score;
   char grade;
   
   int *identifierPointer = &identifier;
   double *scorePointer = &score;
   char *gradePointer = &grade;
   
   cin >> identifier;
   cin >> score;
   cin >> grade;

   cout << "ID number: " << *identifierPointer << endl;
	cout << "Score: " << fixed << setprecision(1) << *scorePointer << endl;
	cout << "Grade: " << *gradePointer << endl;

   return 0;
}
