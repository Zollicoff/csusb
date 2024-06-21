#include <iostream>
#include <vector>
using namespace std;

int main() {
   int inputSize;
   int quantityAsked;
   unsigned int i;

   cin >> inputSize;

   vector<int> quantityList(inputSize);
   vector<string> hueList(inputSize);

   for (i = 0; i < quantityList.size(); ++i) {
      cin >> quantityList.at(i);
      cin >> hueList.at(i);
   }

   cin >> quantityAsked;

   for (i = 0; i < quantityList.size(); ++i) {
      if (quantityList[i] == quantityAsked) {
         cout << "Index " << i << ": quantity " << quantityAsked << " matches the hue " << hueList[i] << endl;
      break;
      }
   }

   return 0;
}

