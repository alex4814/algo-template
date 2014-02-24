








int cantor(int *p, int n) {
	static int f[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800 };
	int c = 0;
	for (int i = 0; i < n - 1; ++i) {
		int t = 0;
		for (int j = i + 1; j < n; ++j) {
			if (p[j] < p[i]) ++t;
		}
		c += t * f[n - 1 - i];
	}
	return c + 1;
}

int uncantor(int x, int *p, int n) {
	static int f[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800 };
	static bool used[12] = { false };
	x -= 1;
	for (int i = 0; i < n; ++i) {
		int m = x / f[n - 1 - i];
		for (int j = 1; j <= n; ++j) {
			if (used[j]) continue;
			if (m == 0) break;
			m -= 1;
		}
		p[i] = j;
		used[j] = true;
		x %= f[n - 1 - i];
	}
}
