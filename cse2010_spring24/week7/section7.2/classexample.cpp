#include <iostream>
#include <string>
using namespace std;

class Restaurant {
private:
      string name;
      int rating;

public:
      void SetName(string newName) {
            name = newName;
      }

      void SetRating(int newRating) {
            rating = newRating;
      }

      void Print() {
            cout << "Name: " << name << ", Rating: " << rating << endl;
      }
};

int main() {
   Restaurant favLunchPlace;
   Restaurant favDinnerPlace;

   favLunchPlace.SetName("Central Deli");
   favLunchPlace.SetRating(4);

   favDinnerPlace.SetName("Friends Cafe");
   favDinnerPlace.SetRating(5);

   cout << "My favorite restaurants: " << endl;
   favLunchPlace.Print();
   favDinnerPlace.Print();

   return 0;
}

