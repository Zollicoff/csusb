#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
   void SetName(string employeeName) {
      name = employeeName;
   }

   virtual void PrintInfo() {
      cout << name << endl;
   }

protected:
   string name;
};

class Author : public Employee {
public:
   void SetGenre(string setGenre) {
      genre = setGenre;
   }

   void PrintInfo() {
      cout << name << " writes " << genre << endl;
   }

private:
   string genre;
};

class Coach : public Employee {
public:
   void SetSport(string setSport) {
      sport = setSport;
   }

   void PrintInfo() {
      cout << name << " coaches " << sport << endl;
   }

private:
   string sport;
};

int main() {
   Employee* person1;
   Author* person2;
   Coach* person3;

   vector<Employee*> personList;
   unsigned int i;

   person1 = new Employee();
   person1->SetName("Mary");

   person2 = new Author();
   person2->SetName("Wes");
   person2->SetGenre("westerns");

   person3 = new Coach();
   person3->SetName("Cora");
   person3->SetSport("baseball");

   personList.push_back(person3);
   personList.push_back(person2);
   personList.push_back(person1);

   for (i = 0; i < personList.size(); ++i) {
      personList.at(i)->PrintInfo();
   }
   
   return 0;
}