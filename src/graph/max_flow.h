








// Max Flow (Edmonds-Karp Algorithm)
// - nodes numbered from 1 to n
int cap[MAXV][MAXV];
int flow[MAXV][MAXV];
int p[MAXV];	// parent
int rsd[MAXV];	// minimum residual of one augmenting path
queue<int> q;

int max_flow(int s, int t) {
	int f = 0;
	memset(flow, 0, sizeof(flow));

	while (1) {
		memset(rsd, 0, sizeof(rsd));
		rsd[s] = INT_MAX;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v = 1; v <= n; ++v) {	// iterate through all vertices
				if (!rsd[v] && cap[u][v] > flow[u][v]) {
					p[v] = u; q.push(v);
					rsd[v] = min(rsd[u], cap[u][v] - flow[u][v]);
				}
			}
		}
		if (rsd[t] == 0) break;
		for (int u = t; u != s; u = p[u]) {
			flow[ p[u] ][u] += rsd[t];
			flow[u][ p[u] ] -= rsd[t];
		}
		f += rsd[t];
	}
	return f;
}

