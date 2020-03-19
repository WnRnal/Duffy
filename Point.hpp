#pragma once
#pragma once
#define Point_HPP
#include <iostream>
using namespace std;

class Point {
private:

	//Properties for x- and y-coordinates
	double x;
	double y;

public:
	// void operator<<(const Point& p);
	friend ostream& operator<<(ostream&, const Point&);

	void init(double xs, double ys); // LineSegment.cpp 에서 접근하기 위해 public 으로 변경
	//Constructors and destructor
	Point();
	Point(double xs, double ys);
	Point(const Point& source);
	virtual ~Point();

	//Selectors
	double X() const;	// Return x
	double Y() const; // Return y

	// const double X() != double X() const

	//Modifiers
	void X(double NewX);
	void Y(double NewY);
};

