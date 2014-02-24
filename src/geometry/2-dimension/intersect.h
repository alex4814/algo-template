#include "cg.h"
#include "pv.h"







Point intersection_ll(Point a, Vector i, Point b, Vector j) {
	Vector k = a - b;
	double t = cross(j, k) / cross(i, j);
	return a + i * t;
}
Point intersection_ll(Line a, Line b) {
	Vector u = a.p - b.p;
	double t = cross(b.v, u) / cross(a.v, b.v);
	return a.p + a.v * t;
}
Point projection_pl(Point p, Point a, Point b) {
	Vector v = b - a;
	return a + v * (dot(v, p - a) / dot(v, v));
}
