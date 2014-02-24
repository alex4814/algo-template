#include "cg.h"
#include "pv.h"







inline double dis_pp(Point3 a, Point3 b) {
	return length(a - b);
}
inline double dis_pf(Point3 p, Point3 p0, Vector3 n) {
	return fabs(dot(p - p0, n));
}
inline Point3 projection_pf(Point3 p, Point3 p0, Vector3 n) {
	return p - n * dot(p - p0, n);
}
inline Point3 intersection_lf(Point3 a, Point3 b, Point3 p0, Vector3 n) {
	Vector3 v = b - a;
	double t = dot(n, p0 - a) / dot(n, b - a);
	return a + v * t;
}

inline double dis_pl(Point3 p, Point3 a, Point3 b) {
	Vector3 v1 = b - a, v2 = p - a;
	return length(cross(v1, v2)) / length(v1);
}
inline double dis_ps(Point3 p, Point3 a, Point3 b) {
	if (a == b) return length(p - a);
	Vector3 v1 = b - a, v2 = p - a, v3 = p - b;
	if (sgn(dot(v1, v2)) < 0) return length(v2);
	if (sgn(dot(v1, v3)) > 0) return length(v3);
	return length(cross(v1, v2)) / length(v1);
}


