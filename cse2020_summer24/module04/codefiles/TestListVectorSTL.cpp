#include <list>
#include <vector>
#include <string>

#include "Employee.cpp"

int main()
{
	string name, dept;
	int id = 0;

	list<Employee> team;
	cout << "Enter id, name, dept (stop adding when entering id 0):";
	cin >> id >> name >> dept;
	while (id != 0)
	{
		Employee e(id, name, dept);
		team.push_back(e);
		cout << "Enter id, name, dept (stop adding when entering id 0):";
		cin >> id >> name >> dept;
	}
        cout << team.size() << endl;

	for ( list<Employee>::iterator it= team.begin(); it != team.end(); ++it)
		 cout << ' ' << *it;

	cout << endl;
	
	list<string> sl;
	string s;
        cout << "Enter 10 strings: ";

	for (int i = 0; i < 10; i++)
	{
		cin >> s;
		sl.push_back(s);
	}	

	for ( list<string>::iterator it= sl.begin(); it != sl.end(); ++it)
		 cout << ' ' << *it;
	cout << endl;
	
	int x = 0;	
	vector<int> v;
        cout << "Enter 10 integers: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		v.push_back(x);
	}
        cout << v.size() << endl;

	for ( vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
		 cout << ' ' << *it;
	
	char del = 'N';
	cout << "delete the last element?";
	cin >> del;
	while (del == 'Y')
	{
		
		v.pop_back();
		cout << "delete the last element? ";
		cin >> del;

	}
	for ( vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
		 cout << ' ' << *it;	
	
	double y = 0;
	vector<double> dv(20);
        cout << "Enter 10 doubles: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> y;
		dv.push_back(y);
	}
	for ( vector<int>::iterator it = dv.begin() ; it != dv.end(); ++it)
		 cout << ' ' << *it;
	
	return 0;
}