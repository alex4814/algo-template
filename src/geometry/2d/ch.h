#include "cg.h"
#include "pv.h"







// p[] for original points in polygon(sorted)
// ch[] for final points in convex hull
// return nums of points
// ch[ix] = ch[0]
// <= 0 for all points in a line, < otherwise
int convex_hull(Point ch[], Point p[], int n)
{
	sort(p, p + n);
	int ix = 0;
	for (int i = 0; i < n; ++i) {
		while (ix > 1 && xmult(ch[ix - 2], ch[ix - 1], p[i]) < 0) --ix;
		ch[ix++] = p[i];
	}
	int t = ix;
	for (int i = n - 2; i >= 0; --i) {
		while (ix > t && xmult(ch[ix - 2], ch[ix - 1], p[i]) < 0) --ix;
		ch[ix++] = p[i];
	}
	return n > 1 ? ix - 1 : ix;
}
