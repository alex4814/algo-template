#include "cg.h"
#include "pv.h"
#include "distance.h"
#include "intersect.h"





// 计算直线与圆的交点,保证直线与圆有交点
// 计算线段与圆的交点可用这个函数后判点是否在线段上
void intersection_cl(Circle c, Point p, Vector v, Point &p1, Point &p2) {
	Point l1 = p, l2 = p + v;
	Vector u = Vector(-v.y, v.x);
	Point p0 = intersection_ll(p, v, c.c, u);
	double d1 = dis_pp(p0, c.c);
	double d2 = dis_pp(l1, l2);
	double t = sqrt(c.r * c.r - d1 * d1)/ d2;
	p1.x = p0.x + (l2.x - l1.x) * t;
	p1.y = p0.y + (l2.y - l1.y) * t;
	p2.x = p0.x - (l2.x - l1.x) * t;
	p2.y = p0.y - (l2.y - l1.y) * t;
}

// pre-req: 保证圆与圆有交点, 圆心不重合
void intersection_cc(Circle c1, Circle c2, Point& p1, Point& p2){
	double d = dis_pp(c1.c, c2.c);
	double t = (1.0 + (c1.r * c1.r - c2.r * c2.r) / d / d) / 2;
	Point u = Point(c1.c.x + (c2.c.x - c1.c.x) * t, c1.c.y + (c2.c.y - c1.c.y) * t);
	Point v = Point(u.x + c1.c.y - c2.c.y, u.y - c1.c.x + c2.c.x);
	intersection_cl(Circle c1, u, v - u, p1, p2);
}

// 计算圆外一点与圆的两个切点
void point_of_tangency_cp(Circle c, Point p, Point &p1, Point &p2) {
	double d = dis_pp(c.c, p);
	double theta = asin(c.r / d);
	Vector v1 = rotate(c.c - p, theta);
	Vector v2 = rotate(c.c - p, 2 * PI - theta);
	p1 = p + v1 / length(v1) * d * cos(theta);
	p2 = p + v2 / length(v2) * d * cos(theta);
}

Circle min_circle_cover(Point *p, int n) {
	Point c = p[0]; double r = 0;
	for (int i = 1; i < n; ++i) {
		if (sgn(dis_pp(c, p[i]) - r) <= 0) continue;
		c = p[i], r = 0;
		for (int j = 0; j < i; ++j) {
			if (sgn(dis_pp(c, p[j]) - r) <= 0) continue;
			c.x = (p[i].x + p[j].x) / 2;
			c.y = (p[i].y + p[j].y) / 2;
			r = dis_pp(c, p[j]);
			for (int k = 0; k < j; ++k) {
				if (sgn(dis_pp(c, p[k]) - r) <= 0) continue;
				c = circumcenter(p[i], p[j], p[k]);
				r = dis_pp(c, p[k]);
			}
		}
	}
	return Circle(c, r);
}


