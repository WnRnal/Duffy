#pragma once
#define Point_CPP
#include "Point.hpp"
//#include <iostream> ; header file에서 불러왔으면 body에서는 안 불러도 됨.
using namespace std;

ostream & operator<<(ostream& os, const Point& p)
{
	// TODO: insert return statement here
	os << "(" << p.X() << ", " << p.Y() << ")";
	return os;
}
// class Point{		//도 가능.
void Point::init(double xs, double ys)
{
	x = xs;
	y = ys;
}

Point::Point()
{ //Default constructor
	init(0.0, 0.0);
}

Point::Point(double xs, double ys)
{ //Normal constructor with coordinates
	init(xs, ys);
}

Point::Point(const Point & source)
{
	init(source.x, source.y); // init(source.X(), source.Y()); 도 가능할 듯.
}

Point::~Point()
{
	std::cout << "Point Destructed" << std::endl;
}

double Point::X() const
{
	return x;
}

double Point::Y() const
{
	return y;
}

void Point::X(double NewX)
{
	x = NewX;
}

void Point::Y(double NewY)
{
	y = NewY;
}

