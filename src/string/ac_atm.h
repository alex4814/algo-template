








const int SIGMA = 26;

struct Trie {
	int chr[MAXNODE][SIGMA];	// character
	int val[MAXNODE];			// weight or value
	int size;
	Trie() { size = 1; memset(chr[0], 0, sizeof(chr[0])); }
	
	void insert(char *s, int w) {
		int n = strlen(s), u = 0;
		for (int i = 0; i < n; ++i) {
			int v = s[i] - 'A';
			if (!chr[u][v]) {
				memset(chr[size], 0, sizeof(chr[size]));
				val[size] = 0;
				chr[u][v] = size++;
			}
			u = chr[u][v];
		}
		val[u] = w;
	}
}

char p[MAXN][MAXN], word[MAXN];

int r, c, w;
int fail[MAXN], val[MAXN], last[MAXN];

void find(char *s) {
	int n = strlen(s), j = 0;
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'A';
		while (j && !chr[j][c]) { j = fail[j]; }
		j = chr[j][c];
		if (val[j] != 0) {
			print(i, j);
		} else if (last[j] != 0) {
			print(i, last[j]);
		}
	}
}

void get_fail() {
	queue<int> q;
	fail[0] = 0;
	for (int u = 0; u < SIGMA; ++u) {
		int v = chr[0][u];
		if (v) { f[v] = 0; q.push(v); last[v] = 0; }
	}
	while (!q.empty()) {
		int r = q.front(); q.pop();
		for (int c = 0; c < SIGMA; ++c) {
			int u = chr[r][c];
			if (!u) continue; q.push(u);
			int v = fail[r];
			while (v && !chr[v][c]) { v = f[v]; }
			fail[u] = chr[v][c];
			last[u] = val[ fail[u] ] ? fail[u] : last[ fail[u] ];
		}
	}
}

