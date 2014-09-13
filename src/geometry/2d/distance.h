#include "cg.h"
#include "pv.h"







inline double dis_pp(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline double dis_pl(Point p, Point a, Point b) {
	Vector v1 = b - a, v2 = p - a;
	return fabs(cross(v1, v2)) / length(v1);
}
inline double dis_ps(Point p, Point a, Point b) {
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if (a == b) return length(p - a);
	if (sgn(dot(v1, v2)) < 0) return length(v2);
	if (sgn(dot(v1, v3)) > 0) return length(v3);
	return fabs(cross(v1, v2)) / length(v1);
}

