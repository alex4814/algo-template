#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define _N 100005
#define _M 105
#define PI acos(-1.0)

int n;
int g[_N][_N], s[_N][_N], e[_N][_N];
int mx[_N], my[_N];
int lx[_N], ly[_N];
int q[_N], qf, qb;
int py[_N];

bool match(int r)
{
	while (true) {
		MEM (py, -1);
		for (qf = 0, qb = 1, q[0] = r; qf < qb; ) {
			for (int x = q[qf++], y = 0; y < n; ++y) {
				if (lx[x] + ly[y] == g[x][y] && py[y] == -1) {
					q[qb++] = my[y]; py[y] = x;
					if (my[y] == -1) {
						for (int ty = 0; ty != -1; y = ty) {
							ty = mx[x = py[y]], my[y] = x, mx[x] = y;
						}
						return true;
					}
				}
			}
		}
		int d = INF;
		FOR (i, 0, qb) FOR (y, 0, n) if (py[y] == -1) {
			if (g[ q[i] ][y] != INF) {
				d = min(d, lx[ q[i] ] + ly[y] - g[ q[i] ][y]);
			}
		}
		if (d == INF) break;

		FOR (i, 0, qb) { lx[ q[i] ] -= d; }
		FOR (y, 0, n) if (py[y] != -1) { ly[y] += d; }
	}
	return false;
}

int	kuhn_munkres()
{
	MEM (mx, -1); MEM (my, -1);
	MEM (lx, 0); MEM (ly, 0);
	FOR (x, 0, n) FOR (y, 0, n) { lx[x] = max(lx[x], g[x][y]); }
	FOR (x, 0, n) if (!match(x)) { mx[x] = -1; } 

	int cost = 0;
	FOR (x, 0, n) if (mx[x] != -1) { cost += g[x][ mx[x] ]; }
	return cost;
}

int main()
{

	return 0;
}
