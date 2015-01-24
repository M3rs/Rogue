#ifndef ROGUE_POINT_H
#define ROGUE_POINT_H

class Point {
 public:
	
	int x;
	int y;

	Point();
	Point(int x_, int y_);

	Point operator+(const Point& p); 
	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

};

#endif // ROGUE_POINT_H

