#include <iostream>
#include <string>
using namespace std;

class Person {
   public:
      void SetName(string userName) {
         lastName  = userName;
      }

      void SetAge(int numYears) {
         ageYears = numYears;
      }

      // Other parts omitted

      void PrintAll() {
         cout << "Name: " << lastName;
         cout << ", Age: "  << ageYears;
      }

   private:
      int ageYears;
      string lastName;
};

class Student: public Person {
   public:
      void SetID(int studentId) {
         idNum = studentId;
      }

      int GetID() {
         return idNum;
      }

   private:
      int idNum;
};

int main() {
   Student courseStudent;
      
   courseStudent.SetName("Smith");
   courseStudent.SetAge(20);
   courseStudent.SetID(9999);
   
   courseStudent.PrintAll();
   cout << ", ID: " << courseStudent.GetID() << endl;

   return 0;
}