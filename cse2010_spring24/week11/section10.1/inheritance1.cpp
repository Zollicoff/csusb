#include <iostream>
#include <string>
using namespace std;

class Business {
   public:
      void SetName(string busName) {
         name = busName;
      }

      void SetAddress(string busAddress) {
         address = busAddress;
      }

      string GetDescription() const {
         return name + " -- " + address;
      }

   private:
      string name;
      string address;
};

class Restaurant : public Business {
   public:
      void SetRating(int userRating) {
         rating = userRating;
      }

      int GetRating() const {
         return rating;
      }

   private:
      int rating;
};

int main() {
   Business someBusiness;
   Restaurant favoritePlace;

   someBusiness.SetName("ACME");
   someBusiness.SetAddress("4 Main St");

   favoritePlace.SetName("Friends Cafe");
   favoritePlace.SetAddress("500 W 2nd Ave");
   favoritePlace.SetRating(5);

   cout << someBusiness.GetDescription() << endl;
   cout << favoritePlace.GetDescription() << endl;
   cout << "  Rating: " << favoritePlace.GetRating() << endl;

   return 0;
}