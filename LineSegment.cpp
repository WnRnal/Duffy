#define LineSegment_CPP
#include "LineSegment.hpp"
#include <iostream>
using namespace std;


void LineSegment::init(const Point & xs, const Point & ys)
{
	e1.init(xs.X(), xs.Y());
	e2.init(ys.X(), ys.Y());
}

LineSegment::LineSegment()
{
	e1.init(0.0, 0.0);
	e2.init(0.0, 0.0);

}

LineSegment::LineSegment(const Point & p1, const Point & p2)
{
	e1.init(p1.X(), p1.Y());
	e2.init(p2.X(), p2.Y());
}

LineSegment::LineSegment(const LineSegment & l)
{
	e1 = l.e1;
	e2 = l.e2;
}

LineSegment::~LineSegment() { cout << "Line segment destructed" << endl; }

Point LineSegment::start() const
{
	return e1;
}

Point LineSegment::end() const
{
	return e2;
}

void LineSegment::start(const Point & pt)
{
	e1 = pt;
}

void LineSegment::end(const Point & pt)
{
	e2 = pt;
}

double LineSegment::length() const
{
	double len = sqrt(pow(e2.X() - e1.X(), 2) + pow(e2.Y() - e1.Y(), 2));
	return len;
}

Point LineSegment::midPoint() const
{
	Point mid(0.5*(e2.X() + e1.X()), 0.5*(e2.Y() + e1.Y()));
	return mid;
}
