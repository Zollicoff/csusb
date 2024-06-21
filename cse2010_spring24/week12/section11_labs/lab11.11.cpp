#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PrintAllPermutations(const vector<string> &permList, const vector<string> &nameList) {
   if (permList.size() == nameList.size()) {
      for (size_t i = 0; i < permList.size(); ++i) {
         cout << permList.at(i);
         if (i < permList.size() - 1) {
            cout << ", ";
         }
      }
      cout << endl;
   } else {
      for (size_t i = 0; i < nameList.size(); ++i) {
         bool alreadyUsed = false;
         for (size_t j = 0; j < permList.size(); ++j) {
            if (nameList.at(i) == permList.at(j)) {
               alreadyUsed = true;
            }
         }
         if (!alreadyUsed) {
            vector<string> newPermList = permList;
            newPermList.push_back(nameList.at(i));
            PrintAllPermutations(newPermList, nameList);
         }
      }
   }
}

int main() {
   vector<string> nameList;
   vector<string> permList;
   string name;

   while (cin >> name && name != "-1") {
      nameList.push_back(name);
   }
   
   PrintAllPermutations(permList, nameList);
   
   return 0;
}