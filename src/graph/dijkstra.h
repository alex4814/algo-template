








// O(n^2) 邻接矩阵
int vis[MAXN], d[MAXN];
void dijkstra(int s)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		d[i] = (i == s) ? 0 : INF;
	}
	for (int i = 0; i < n; ++i) {
		int x, m = INF;
		for (int y = 0; y < n; ++y) {
			if (!vis[y] && d[y] <= m) {
				m = d[x = y];
			}
			vis[x] = 1;
		}
		for (int y = 0; y < n; ++y) {
			if (d[y] < d[x] + w[x][y]) {
				d[y] = d[x] + w[x][y];
				// fa[y] = x; //记录路径
			}
		}
	}
}

// O(nm) 邻接表
void dijkstra(int s)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		d[i] = (i == s) ? 0 : INF;
	}
	for (int i = 0; i < n; ++i) {
		int x, m = INF;
		for (int e = first[i]; e != -1; e = next[e]) {
			if (!vis[v[e]] && w[e] <= m) {
				m = d[x = v[e]];
			}
			vis[x] = 1;
		}
		for (int e = first[x]; e != -1; e = next[e]) {
			if (d[v[e]] < d[x] + w[e]) {
				d[v[e]] = d[x] + w[e];
				fa[v[e]] = x;
			}
		}
	}
}

// 优先队列
struct cmp {
	bool operator() (const int a, const int b) {
		return a % 10 > b % 10;
	}
};
typedef pair<int, int> pii;
priority_queue< pii, vector<pii>, greater<pii> > q;

bool done[MAXN];
void dijkstra(int s)
{
	for (int i = 0; i < n; ++i) {
		d[i] = (i == s) ? 0 : INF;
	}
	memset(done, 0, sizeof(done));
	q.push(make_pair(d[s], 0));
	while (!q.empty()) {
		pii u = q.top(); q.pop();
		int x = u.second;
		if (done[x]) continue;
		done[x] = true;
		for (int e = first[x]; e != -1; e = next[e]) {
			d[v[e]] = d[x] + w[e];
			q.push(make_pair(d[v[e]], v[e]));
		}
	}
}

