// Employee.cpp
// Employee class definition and implementation file

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
int id;
string name;
string dept;

public:

Employee():id(0),name(""),dept("")
{}

Employee(int id, const string &name,  const string &dept):id(id), name(name), dept(dept)
{}

int get_id() const
{
	return id;
}

string get_name() const
{
	return name;
}

string get_dept() const
{
	return dept;
}

void set_id(int id)
{
	this->id = id;
}

void set_name(const string &name)
{
	this->name = name;
}

void set_dept(const string &dept)
{
	this->dept = dept;
}
    
void print() const
{
	std::cout << get_id() << ", "
		<< get_name() << ", "
		<< get_dept() << std::endl;
}

friend ostream &operator<<( ostream &output, const Employee &e )
{
         output <<  e.get_id() << " "<< e.get_name() << " " << e.get_dept();
         return output;
}

friend istream &operator>>( istream &input, Employee &e )
{
         input >>  e.id >> e.name >> e.dept;
         return input;
}

friend bool operator== (const Employee &e1, const Employee &e2)
{
	return (e1.id == e2.id &&
		e1.name == e2.name &&
		e1.dept == e2.dept);
}

friend bool operator!= (const Employee &e1, const Employee &e2)
{
	return !(e1.id == e2.id &&
		e1.name == e2.name &&
		e1.dept == e2.dept);
}

};
#endif



// TestEmployee.cpp
// The test driver program of Employee class, which 
// creates a dynamic array of employees

#include "Employee.cpp"


int main()
{
	
	Employee e1;
	e1.set_id(1);
	e1.set_name("Bob");
	e1.set_dept("CSE");
	e1.print();

	Employee e2(2, "Ellen", "Math");
	cout << e2 << endl;

	Employee* pe3 = new Employee( 3, "Jim", "Art");
	//pe3->print();
	cout << *pe3 << endl;

	int capacity = 3, size = 0, id = 0;
	string name, dept;

	Employee* group = new Employee[capacity];

	while (size < capacity)
	{
		cout << "Enter id (integer), name (string), dept (string): ";
		
		Employee new_empl;
        	cin >> new_empl;

		group[size] = new_empl;
		size++;
	}

	cout << "\nThe employee information:" << endl;
	for (int i = 0; i < size; i++)
    	{
		//group[i].print();
        	cout << group[i] << endl;
    	}

    return 0;
}

// TestLinkedEmployee.cpp
// The test driver program of Employee class, which 
// creates a linked structure of employees

#include "Employee.cpp"

struct NodeType{
      Employee data;
      NodeType* next;
    
      NodeType(): data(), next(nullptr) {}
      NodeType(Employee e):data(e),next(nullptr){}
};


int main()
{
	int id;
	string name, dept;

	NodeType* pre = nullptr;
	NodeType* cur = nullptr;
	NodeType* head = new NodeType();

    	head->data.set_id(5);
	head->data.set_name("Mary");
	head->data.set_dept("CSE");

	cout << head->data<< endl;// use overloaded <<
	pre = head;
	
	Employee e(6, "Bob", "CSE");
	cur = new NodeType(e);
	cout << cur->data << endl;

	pre->next = cur;
	pre = cur;

	Employee e1(7, "Lee", "Math");
	cur = new NodeType(e1);	
	cout << cur->data << endl;

	pre->next = cur;
	pre = cur;

	cout << "Enter id (integer), name (string), dept (string): ";
	cin >> id >> name >> dept;

	while (id != 0)
	{
		Employee e(id, name, dept);
		cur = new NodeType(e);
		pre->next = cur;
		pre = cur;

		cout << "Enter id (integer), name (string), dept (string): ";
		cin >> id >> name >> dept;
	}

	// print all employees
	cur = head;

	while (cur != nullptr)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}

	//search and remove
	cout << "\nEnter the employee id to be removed: ";
	cin >> id;	
	
	pre = head;
	if (head->data.get_id() == id)
	{
		head = head->next;
		delete pre;  		
	}
	else 
	{
		while ((pre->next != nullptr) && (pre->next-> data.get_id() != id) )
		{
			pre = pre->next;
		}
		
		if (pre->next != nullptr)
		{
			cur = pre->next;
			pre->next = cur->next; 	
			delete cur;
		}
		else
 			cout << "The employee is not in." << endl;
	}	

	// print all employees
	cur = head;

	while (cur != nullptr)
	{
        	cout << cur->data << endl;
		cur = cur->next;
	}
	
	// release all nodes
	while (head != nullptr)
	{
		cur = head;
		head = head->next;
     		delete cur;

	}

    	return 0;
}


// TestLinkedEmployeeTemplate.cpp
// The test driver program of Employee class, which 
// creates a linked structure of employees using template

#include "Employee.cpp"

template <typename T>
struct NodeType{
      T data;
      NodeType* next;
    
      NodeType(): data(), next(nullptr) {}
      NodeType(T d):data(d), next(nullptr) {}
};


int main()
{
	int id;
	string name, dept;

	NodeType<Employee>* head = nullptr;
	NodeType<Employee>* pre = nullptr;

	NodeType<Employee>* cur = new NodeType<Employee>();
	cur->data.set_id(5);
	cur->data.set_name("Mary");
	cur->data.set_dept("CSE");
	cout << cur->data << endl;// use overloaded <<

	head = cur;
	pre = head;
	
	Employee e1(6, "Bob", "CSE");
	cur = new NodeType<Employee>(e1);
	cout << cur->data;

	pre->next = cur;
	pre = cur;

	Employee e2(7, "Lee", "Math");
	cur = new NodeType<Employee>(e2);	
	cout << cur->data << endl;

	pre->next = cur;
	pre = cur;

	cout << "Enter id (integer), name (string), dept (string): ";
	cin >> id >> name >> dept;

	while (id != 0)
	{
		Employee e(id, name, dept);

		cur = new NodeType<Employee>(e);
		pre->next = cur;
		pre = cur;

		cout << "Enter id (integer), name (string), dept (string): ";
		cin >> id >> name >> dept;
	}

	// print all employees
	cur = head;

	while (cur != nullptr)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}

	cout << "\nEnter the employee id to be removed: ";
	cin >> id;	
	
	pre = head;
	if (head->data.get_id() == id)
	{
		head = head->next;
		delete pre;  		
	}
	else 
	{
		while ((pre->next != nullptr) && (pre->next->data.get_id() != id) )
		{
			pre = pre->next;
		}
		
		if (pre->next != nullptr)
		{
			cur = pre->next;
			pre->next = cur->next; 	
			delete cur;
		}
		else
 			cout << "The employee is not in." << endl;
	}	

	// print all employees
	cur = head;

	while (cur != nullptr)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
	
	// release all nodes
	while (head != nullptr)
	{
		cur = head;
		head = head->next;
     		delete cur;

	}

    	return 0;
}

