// The point class definition and implementation are in separated files


// Point.h
// Point class definition

#ifndef POINT_H
#define POINT_H

class Point 
{
private:
	int x;
	int y;

public:   
	// Default constructor
	Point(); 

	Point(int xvalue, int yvalue); 

	int get_x() const; 

	int get_y() const; 

	void set_x(int xvalue); 

	void set_y(int yvalue);

	void setPoint(int xvalue, int yvalue); 

	void printPoint() const;
};
#endif

// Point.cpp
// Point class implementation

#include <iostream>
#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
} 

Point::Point(int xvalue, int yvalue):x(xvalue), y(yvalue)
{}


int Point::get_x() const
{
	return x;
}

int Point::get_y() const
{
	return y;
}


void Point::set_x(int xvalue)
{
	x = xvalue;
} 

void Point::set_y(int yvalue)
{
	y = yvalue;
} 

void Point::setPoint(int xvalue, int yvalue)
{
	x = xvalue;
	y = yvalue;
}

void Point::printPoint() const
{
	std::cout << "(" << get_x() << ", " << get_y() << ")" << std::endl;
}

// TestPoint.cpp
// The test driver program of Point class

#include "Point.h"

const int N = 5;

int main()
{
	Point p1;
	p1.printPoint();
	p1.set_x(10);
	p1.set_y(10);
	p1.printPoint();

	p1.setPoint(20,20);
	p1.printPoint();

	
	Point p2(30,30);
	p1.printPoint();

	Point pointgroup1[N];
	for(int i = 0; i < N; i++)	
		pointgroup1[i].printPoint();

	Point* pointgroup2 = new Point[N];
	for(int i = 0; i < N; i++)	
		pointgroup2[i].printPoint();

	return 0;
}
