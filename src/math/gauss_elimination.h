








// O(n^3)
typedef double Matrix[MAXN][MAXN];

void gauss_elimination(Matrix d, int n) {
	for (int i = 0; i < n; ++i) {
		int r = i;
		for (int j = i + 1; j < n; ++j) {
			if (fabs(d[j][i]) > fabs(d[r][i])) r = j;
		}
		if (r != i) for (int j = 0; j <= n; ++j) {
			d[r][j] ^= d[i][j] ^= d[r][j] ^= d[i][j];
		}
		for (int k = i + 1; k < n; ++k) {
			double f = d[k][i] / d[i][i];
			for (int j = i; j <= n; ++j) {
				d[k][j] -= f * d[i][j];
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			d[i][n] -= d[j][n] * d[i][j];
		}
		d[i][n] /= d[i][i];
	}
}

int rank(Matrix d, int n, int m) {
	int i = 0, j = 0;
	while (i < n && j < m) {
		int r = i;
		for (int k = i; k < n; ++k) {
		}
	}
}
