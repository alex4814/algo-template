#include "cg.h"
#include "pv.h"







struct Face {
	int v[3];
	Vector3 normal(Point3 *p) const {
		return cross(p[v[1]] - p[v[0]], p[v[2]] - p[v[0]]);
	}
	bool cansee(Point3 *p, int i) const {
		return dot(p[i] - p[v[0]], normal(p)) > 0;
	}
};

vector<Face> convex_hull3(Point3 *p, int n) {
	static int vis[MAXN][MAXN];
	vector<Face> ch;
	ch.push_back((Face){{ 0, 1, 2 }});
	ch.push_back((Face){{ 2, 1, 0 }});
	for (int i = 3; i < n; ++i) {
		vector<Face> next;
		// calculate the left visibility of each edge
		for (int j = 0; j < ch.size(); ++j) {
			Face &f = ch[j];
			int ret = f.cansee(p, i);
			if (!ret) next.push_back(f);
			for (int k = 0; k < 3; ++k) {
				vis[ f.v[k] ][ f.v[(k + 1) % 3] ] = ret;
			}
		}
		for (int j = 0; j < ch.size(); ++j) {
			for (int k = 0; k < 3; ++k) {
				int a = ch[j].v[k], b = ch[j].v[(k + 1) % 3];
				if (vis[a][b] != vis[b][a] && vis[a][b]) {	// (a, b)'s left is visible to p[i]
					next.push_back((Face){{ a, b, i }});
				}
			}
		}
		ch = next;
	}
	return ch;
}

