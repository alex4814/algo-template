








// building adjacency list
// n vertices and m edges
int first[MAXV], next[MAXE];
int u[MAXE], v[MAXE], w[MAXE];

void adj_list(int m) {
	memset(first, -1, sizeof(first));
	for (int e = 0; e < m; ++e) {
		scanf("%d %d %d", u + e, v + e, w + e);
		next[e] = first[ u[e] ];
		first[ u[e] ] = e;
	}
}

