








bool is_prime(int n) {
	int x = sqrt(n);
	for (int i = 2; i <= x; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int p[MAXN], np;
bool f[MAXN];	// f[i] = true means that i isn't a prime.

// O(n * sqrt(n))
void get_primes(int n) {
	np = 0;
	for (int i = 2; i <= n; ++i) {
		if (is_prime(i)) { p[np++] = i; }
	}
}

// O(n)
void get_primes(int n) {
	np = 0;
	for (int i = 2; i <= n; ++i) {
		if (!f[i]) { p[np++] = i; }
		for (int j = 0; j < np && p[j] * i <= n; ++j) {
			f[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

void get_primes(int n) {
	int x = sqrt(n);
	for (int i = 2; i <= x; ++i) {
		for (int j = 2; i * j <= n; ++j) {
			f[i * j] = true;
		}
	}
	np = 0;
	for (int i = 2; i <= n; ++i) {
		if (!f[i]) { p[np++] = i; }
	}
}

