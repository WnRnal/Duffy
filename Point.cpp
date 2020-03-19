#pragma once
#define Point_CPP
#include "Point.hpp"
//#include <iostream> ; header file���� �ҷ������� body������ �� �ҷ��� ��.
using namespace std;

ostream & operator<<(ostream& os, const Point& p)
{
	// TODO: insert return statement here
	os << "(" << p.X() << ", " << p.Y() << ")";
	return os;
}
// class Point{		//�� ����.
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
	init(source.x, source.y); // init(source.X(), source.Y()); �� ������ ��.
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

