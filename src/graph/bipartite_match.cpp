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
#define _N 100005
#define _M _N
#define PI acos(-1.0)

int g[_N][_M];
int limits[_M];
int vis[_M];
int match[_M];

bool dfs(int u, int m)
{
	FOR (v, 0, m) {
		if (g[u][v] && !vis[v]) {
			vis[v] = true;
			if (match[v] == -1 || dfs(match[v], m)) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int bipartite_match(int n, int m)
{
	int cnt = 0;
	MEM (match, -1);
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
