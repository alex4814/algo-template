








// sqaure matrix
typedef struct {
	int d[MAXN][MAXN];
	int n;	// size n by n

	void clear() {
		memset(d, 0, sizeof(d));
	}
	void unit() {
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; ++i) {
			d[i][i] = 1;
		}
	}
	void print() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%d ", d[i][j]);
			}
			putchar('\n');
		}
	}
} Matrix;

Matrix add(Matrix a, Matrix b) {
	Matrix c; c.clear();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c.d[i][j] = (a.d[i][j] + b.d[i][j]) % MOD;
		}
	}
	return c;
}

Matrix multiply(Matrix a, Matrix b) {
	Matrix c; c.clear();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k)
				c.d[i][j] = (c.d[i][j] + (a.d[i][k] * b.d[k][j]) % MOD) % MOD;
		}
	}
	return c;
}

Matrix quickmul(Matrix a, int exp) {
	Matrix ret; ret.unit();

	while (exp > 0) {
		if (exp & 1) ret = multiply(ret, a);
		a = multiply(a, a);
		exp >>= 1;
	}
	return ret;
}

