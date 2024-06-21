#include <iostream>
#include <string>

using namespace std;

class Business {   
   protected: // Members accessible by self and derived classes
      string name;
   
   private:   // Members accessible only by self
      string address;

   public:    // Members accessible by anyone
      void PrintMembers() {
         cout << "Name: " << name << endl;
         cout << "Address: " << address << endl;
      }

      Business(string n, string a) : name(n), address(a) {}
};

class Restaurant : public Business {
   private:
      int rating;

   public:
      Restaurant(string n, string a, int r) : Business(n, a), rating(r) {}

      void DisplayRestaurant() {
         // Attempted accesses
         PrintMembers();             // OK
         name = "Gyro Hero";         // OK    ("protected" above made this possible)
         // address = "5 Fifth St";     // ERROR
         cout << "Rating: " << rating << endl;
      }

      // Other class members ...

};

int main() {
   
   Business business("Business Name", "Business Address");
   Restaurant restaurant("Restaurant Name", "Restaurant Address", 5);
   
   // Attempted accesses
   business.PrintMembers();          // OK
   // business.name  = "Gyro Hero";     // ERROR (protected only applies to derived classes)
   // business.address = "5 Fifth St";  // ERROR
   
   restaurant.DisplayRestaurant();         // OK
   // restaurant.name  = "Gyro Hero";    // ERROR
   // restaurant.rating = 5;  // ERROR
   
   return 0;
}
