#include "cg.h"








Point circumcenter(Point a, Point b, Point c) {
	double x1 = b.x - a.x, y1 = b.y - a.y, e1 = (x1 * x1 + y1 * y1) / 2;
	double x2 = c.x - a.x, y2 = c.y - a.y, e2 = (x2 * x2 + y2 * y2) / 2;
	double _d = x1 * y2 - x2 * y1;
	double _x = a.x + (e1 * y2 - e2 * y1) / _d;
	double _y = a.y + (x1 * e2 - x2 * e1) / _d;
	return Point(_x, _y);
}

