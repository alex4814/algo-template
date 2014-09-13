








int first[MAXV], next[MAXM];
int u[MAXM], v[MAXM], w[MAXM];
int d[MAXV];	// distance
int p[MAXV];	// parent

// O(nm)
// n vertices and m edges
// vertex start from 0
bool bellman_ford(int s) {
	for (int i = 0; i < n; ++i) {
		d[i] = INF;
	}
	d[s] = 0;
	for (int k = 0; k < n - 1; ++k) {
		for (int e = 0; e < m; ++e) {
			int x = u[e], y = v[e];
			if (d[y] > d[x] + w[e]) {
				d[y] = d[x] + w[e];
				p[y] = x;
			}
		}
	}
	for (int e = 0; e < m; ++e) {
		int x = u[e], y = v[e];
		if (d[y] > d[x] + w[e]) return false;
	}
	return true;
}

// queue-based improvement
// n vertices and m edges
// vertex start from 0
bool bellman_ford(int s) {
	static bool inq[MAXV];
	static int cnt[MAXV];
	queue<int> q;

	memset(inq, false, sizeof(inq));
	for (int i = 0; i < n; ++i) {
		d[i] = INF;
	}
	d[s] = 0;

	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		inq[x] = false;
		for (int e = first[x]; e != -1; e = next[e]) {
			if (d[ v[e] ] > d[x] + w[e]) {
				d[ v[e] ] = d[x] + w[e];
				if (!inq[ v[e] ]) {
					inq[ v[e] ] = true;
					q.push(v[e]);
					if (++cnt[ v[e] ] == n) return false;
				}
			}
		}
	}
	return true;
}

