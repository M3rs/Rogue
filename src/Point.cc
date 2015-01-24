#include "Point.h"

Point::Point() : x(0), y(0) {

}

Point::Point(int x_, int y_) : x(x_), y(y_) {

}

Point Point::operator+(const Point& p) {

	Point newPoint;

	newPoint.x += p.x;
	newPoint.y += p.y;

	return newPoint;

}

bool Point::operator==(const Point& other) const {

	return (this->x == other.x) && (this->y == other.y);

}

bool Point::operator!=(const Point& other) const {

	return !(*this == other);

}

