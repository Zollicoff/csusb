#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numMostPopular;
   unsigned int i;
   vector<string> janMostPopular;
   vector<string> julMostPopular;
   vector<string> julBackup;
   
   cin >> numMostPopular;
   
   janMostPopular.resize(numMostPopular);
   julMostPopular.resize(numMostPopular);
   
   cout << "January's most popular grocery items: ";
   for (i = 0; i < janMostPopular.size(); ++i) {
      cin >> janMostPopular.at(i);
      cout << janMostPopular.at(i) << " ";
   }
   cout << endl;
   
   cout << "July's most popular grocery items: ";
   for (i = 0; i < julMostPopular.size(); ++i) {
      cin >> julMostPopular.at(i);
      cout << julMostPopular.at(i) << " ";
   }
   cout << endl;

   if (janMostPopular == julMostPopular) {
      cout << "January's most popular grocery items are the same as July's most popular grocery items." << endl;
   } else {
      cout << "January's most popular grocery items are not the same as July's most popular grocery items." << endl;
   }
   
   julBackup = julMostPopular;
      
   cout << "July's backup: ";
   for (i = 0; i < julBackup.size(); ++i) {
      cout << julBackup.at(i) << " ";
   }
   cout << endl;
   
   return 0;
}
