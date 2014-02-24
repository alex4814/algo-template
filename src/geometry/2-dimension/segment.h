#include "cg.h"








int seg_union(Segment *s, int &n) {
	int m = 0;
	for (int i = 1; i < n; ++i) {
		if (s[m].b.x < s[i].a.x) {
			s[++m] = s[i];
		} else {
			s[m].a.x = min(s[m].a.x, s[i].a.x);
			s[m].b.x = max(s[m].b.x, s[i].b.x);
		}
	}
	return n = m + 1;
}
