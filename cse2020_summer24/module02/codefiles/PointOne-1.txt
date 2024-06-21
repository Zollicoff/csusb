// The point definition and implementation are contained in one file Point.cpp

// Point.cpp
// contains the definition and implementation of Point class

#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point 
{
private:
int x;
int y;

public:   

Point():x(0), y(0)
{
//	x = 0;
//	y = 0;
} 

Point(int xvalue, int yvalue):x(xvalue), y(yvalue)
{}


int get_x() const
{
	return x;
}

int get_y() const
{
	return y;
}


void set_x(int xvalue)
{
	x = xvalue;
} 

void set_y(int yvalue)
{
	y = yvalue;
} 

void setPoint(int xvalue, int yvalue)
{
	x = xvalue;
	y = yvalue;
}

void printPoint() const
{
	std::cout << "(" << get_x() << ", " << get_y() << ")" << std::endl;
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
// The test driver program of Point class, which contains
// a normal array and a dynamic array of points

#include "Point.cpp"

const int N = 5;

int main()
{
	Point p1;
	p1.printPoint();
	p1.set_x(10);
	p1.set_y(10);
	p1.printPoint();

	p1.setPoint(20,20);
	cout << p1;
	
	Point p2(30,30);
	//p2.printPoint();
	cout << p2;
    
        cout << "Please input x and y values:" << endl;
        Point p3;
        cin >> p3;
        cout << "The point is: " << p3 << endl;

	Point* ptrp4 = new Point(40,40);
	(*ptrp4).printPoint();
	//ptrp4->printPoint();
	cout << *ptrp4;

	Point pointgroup1[N];
	for(int i = 0; i < N; i++)
 	{
		pointgroup1[i].printPoint();
		//cout << pointgroup1[i];
	}
    
	int k = 3;
	Point* pointgroup2 = new Point[k];
	for(int i = 0; i < k; i++)
	{
		pointgroup2[i].printPoint();
		cout << pointgroup2[i];
	}
	return 0;
}


// TestLinkedPoint.cpp

#include "Point.cpp"

using namespace std;

struct NodeType
{
      Point data;
      NodeType* next;

      NodeType(): data(), next(nullptr) {}
      NodeType(Point pt):data(pt),next(nullptr){}
};

int main()
{

	NodeType* head = nullptr;
	NodeType* cur = nullptr;

	int x, y;
	cout << "Enter x (int), y (int): ";
	cin >> x >> y;	
	Point pt(x, y);	

	head = new NodeType(pt);

	cout << "Enter x (int), y (int): ";
	cin >> x >> y;	

	while (x != 0)
	{
		
		Point pt(x, y);

		cur = new NodeType(pt);
		cur->next = head;
		head = cur;

		cout << "Enter x (int), y (int): ";
		cin >> x >> y;
	}

	cur = head;

	while (cur != nullptr)
	{
		cout << cur->data;
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
