#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 100005

const double EPS = 1e-8;
const double PI = M_PI;

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

typedef struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
} Vector;

struct Segment {
	Point a, b;
	Segment(Point a, Point b): a(a), b(b) {}
};

struct Line {
	Point p;
	Vector v;
	double a;
	Line(Point p = Point(), Vector v = Vector(1, 0)): p(p), v(v) { a = atan2(v.y, v.x); }
	bool operator < (const Line &b) const { return a < b.a; }
};

struct Circle {
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0): c(c), r(r) {}
};

