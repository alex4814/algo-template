#include "cg.h"
#include "pv.h"
#include "circle.h"
#include "intersect.h"
#include "distance.h"




// change < to <=, if improper
inline bool is_proper_intersection_ss(Point a1, Point a2, Point b1, Point b2) {
	double d1 = cross(a2 - a1, b1 - a1), d2 = cross(a2 - a1, b2 - a1);
	double d3 = cross(b2 - b1, a1 - b1), d4 = cross(b2 - b1, a2 - b1);
	return sgn(d1) * sgn(d2) < 0 && sgn(d3) * sgn(d4) < 0;
}
inline bool is_proper_intersection_ls(Point a1, Point a2, Point b1, Point b2) {
	double d1 = cross(a2 - a1, b1 - a1), d2 = cross(a2 - a1, b2 - a1);
	return sgn(d1) * sgn(d2) < 0;
}
inline bool is_on_ps(Point p, Point a, Point b) {
	return sgn(cross(a - p, b - p)) == 0 && sgn(dot(a - p, b - p)) < 0;
}
inline bool is_on_pl(Point p, Point a, Point b) {
	return sgn(cross(a - p, b - p)) == 0;
}
inline bool is_parallel_ll(Point a1, Point a2, Point b1, Point b2) {
	return sgn(cross(a2 - a1, b2 - b1)) == 0;
}
inline bool is_left_pl(Point p, Line l) {
	return cross(l.v, p - l.p) > 0;
}
// p[] for polygon, p[n] = p[0]
// function: whether point a is inside or on the boundry of polygon p
int is_in_pp(Point a, Point *p, int n) {
	int wn = 0;
	for (int i = 0; i < n; ++i) {
		if (is_on_ps(a, p[i], p[i + 1])) return -1;     // on edge;
		int k = sgn(xmult(p[i], p[i + 1], a));
		int d1 = sgn(p[i].y - a.y);
		int d2 = sgn(p[i + 1].y - a.y);
		if (k > 0 && d1 <= 0 && d2 > 0) ++wn;
		if (k < 0 && d2 <= 0 && d1 > 0) --wn;
	}
	return wn != 0;
}

// -1 for d > r, 0 for d == r, 1 for d < r
inline int relative_position_cl(Circle c, Point p, Vector v) {
	double d = dis_pl(c.c, p, p + v);
	return sgn(c.r - d);
}
// -1 for outside, 0 for on, 1 for inside
inline int relative_position_cp(Circle c, Point p) {
	double d = dis_pp(c.c, p);
	return sgn(c.r - d);
}

