#pragma once
#define LineSegment_HPP
#include "Point.hpp"

class LineSegment {
	// A Line segment consisting of two points.

private:
	Point e1; // End Point of line
	Point e2; // End point of line
	void init(const Point& xs, const Point& ys);

public:
	//Consturctors
	LineSegment();	//Line with both end Points at the origin
	LineSegment(const Point& p1, const Point& p2);
	LineSegment(const LineSegment& l);	// Copy constructor
	virtual ~LineSegment();		// virtual destructor

	// Accessing functions
	Point start() const;			// Synonym for e1
	Point end() const;				// Synonym for e2

	// Modifiers
	void start(const Point& pt);	// Set Point e1.
	void end(const Point& pt);	// Set Point e2.

	// Arithmetic
	double length() const;			// Length of line

	// Interaction with Points
	Point midPoint() const;			// MidPoint of line


	// Print a line, the code is "default" inline
	void print() {
		cout << "Two composite points of this line are: " << e1 << " and " << e2 << "." << endl;
	};
};
