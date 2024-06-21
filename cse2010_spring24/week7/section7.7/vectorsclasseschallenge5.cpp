#include <iostream>
#include <vector>
using namespace std;

class Town {
   public:
      bool ReadNameAndPopulation();
      void Print() const;
   private:
      string name;
      int population;
};

bool Town::ReadNameAndPopulation() {
	string newName;
	
	cin >> newName;
	if (newName == "done") {
		return false;
	}
	else {
		name = newName;
		cin >> population;
		return true;
	}
}

void Town::Print() const {
   cout << "Town: " << name << ", Population: " << population << endl;
}

int main() {
   vector<Town> townList;
   Town currTown;
   bool result;
   unsigned int i;

   result = currTown.ReadNameAndPopulation();

   while (result) {
      townList.push_back(currTown);
      result = currTown.ReadNameAndPopulation();
   }

   for (i = 0; i < townList.size(); ++i) {
      currTown = townList.at(i);
      currTown.Print();
   }
   
   return 0;
}
