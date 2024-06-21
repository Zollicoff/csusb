#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
   int numElements;
   unsigned int i;
   vector<double> pointsList;
	vector<double> newList;
   
   cin >> numElements;
   
   pointsList.resize(numElements);
	newList.resize(numElements);
	
	for (i = 0; i < pointsList.size(); ++i) {
		cin >> pointsList.at(i);
	}


   for (i = 1; i < pointsList.size(); ++i) {
        newList.at(i - 1) = pointsList.at(i);
    }

   newList.at(newList.size() - 1) = pointsList.at(0);

   cout << "Original points: ";
   for (i = 0; i < pointsList.size(); ++i) {
      cout << fixed << setprecision(1) << pointsList.at(i) << " ";
   }
   cout << endl;
	
	cout << "Updated points: ";
	for (i = 0; i < newList.size(); ++i) {
		cout << newList.at(i) << " ";
	}
	cout << endl;
   
   return 0;
}