#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s, v) memset(s, v, sizeof(s))
#define EPS 1e-8
#define _N 40
#define _M 40
#define MAXN 100005
#define PI acos(-1.0)

int g[_N][_M];
int limits[_M];
int vis[_M];
int match[_M][MAXN];
int n_match[_M];

bool dfs(int u, int m)
{
	FOR (v, 0, m) {
		if (g[u][v] && !vis[v]) {
			vis[v] = true;
			if (n_match[v] < limits[v]) {
				match[v][ n_match[v]++ ] = u;
				return true;
			} else {
				FOR (i, 0, n_match[v]) {
					if (dfs(match[v][i], m)) {
						match[v][i] = u;
						return true;
					}
				}
			}
		}
	}
	return false;
}

int bipartite_multi_match(int n, int m)
{
	int cnt = 0;
	MEM (n_match, 0);
	FOR (i, 0, n) {
		MEM (vis, false);
		if (dfs(i, m)) ++cnt;
	}
	return cnt;
}


int main()
{

	return 0;
}
