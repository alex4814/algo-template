#include "cg.h"
#include "pv.h"
#include "intersect.h"






Point symmetry_pl(Point p, Point a, Point b) {
	Vector v1 = b - a, v2 = Vector(-v1.y, v1.x);
	Point m = intersection_ll(a, v1, p, v2);
	return p + (m - p) * 2;
}
