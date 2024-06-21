// Point.cpp
// contains Point template class definition and implementation

#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

template <typename T>
class Point 
{
private:
T x;
T y;

public:   

Point()
{
	x = 0;
	y = 0;
} 

Point(T xvalue, T yvalue):x(xvalue), y(yvalue)
{}


T get_x() const
{
	return x;
}

T get_y() const
{
	return y;
}


void set_x(T xvalue)
{
	x = xvalue;
} 

void set_y(T yvalue)
{
	y = yvalue;
} 

void setPoint(T xvalue, T yvalue)
{
	x = xvalue;
	y = yvalue;
}

void printPoint() const
{
	cout << "(" << get_x() << ", " << get_y() << ")" << endl;
}

friend ostream &operator<<( ostream &output, const Point &p )
{ 
         output <<  p.get_x() << ", "<< p.get_y()<< endl;
         return output;            
}

friend istream &operator>>( istream &input, Point &p )
{
        input >>  p.x >> p.y;
        return input;
}

};
#endif

// TestPoint.cpp
// The test driver of Point template class

#include "Point.cpp"

const int N = 5;

int main()
{
	Point<int> p1;
	p1.printPoint();
	p1.set_x(10);
	p1.set_y(10);
	p1.printPoint();

	p1.setPoint(20,20);
	cout << p1;
	
	Point<double> p2(30.3,30.3);
	//p2.printPoint();
	cout << p2;

	Point<int>* ptrp3 = new Point<int>(40,40);
	(*ptrp3).printPoint();
	ptrp3->printPoint();
	cout << *ptrp3;

	Point<int> pointgroup1[N];
	for(int i = 0; i < N; i++)
    	{
		pointgroup1[i].printPoint();
        	//cout << pointgroup1[i];
    	}
		
    	int k = 3;
	Point<double>* pointgroup2 = new Point<double>[k];
	for(int i = 0; i < k; i++)
    	{
		pointgroup2[i].printPoint();
        	//cout << pointgroup1[i];
    	}

	return 0;
}

// TestLinkedPoint.cpp
// The test driver of Point template class, which creates
// a linked structure of points

#include "Point.cpp"

using namespace std;
template <typename T>
struct NodeType{
      T data;
      NodeType* next;
      NodeType(): data(), next(nullptr) {}
      NodeType(T d):data(d),next(nullptr){}
};

int main()
{
	int x, y;
	cout << "Enter x (int), y (int): ";
	cin >> x >> y;	
	
	NodeType<Point<int> >* head = nullptr;
	NodeType<Point<int> >* cur = nullptr;
	NodeType<Point<int> >* pre = nullptr;

	Point<int> pt(x, y);
	head = new NodeType<Point<int> >(pt);
	pre = head;

	cout << "Enter x (int), y (int): ";
	cin >> x >> y;	

	while (x != 0)
	{
		
		Point<int> pt(x, y);

		cur = new NodeType<Point<int> >(pt);
		pre->next = cur;
		pre = cur;

		cout << "Enter x (int), y (int): ";
		cin >> x >> y;
	}

	cur = head;
	while (cur != nullptr)
	{
        	cout << cur->data; // overload << operator
		cur = cur->next;
	}

	while (head != nullptr)
	{
		cur = head;
		head = head->next;
		delete cur;
	}

	return 0;
}