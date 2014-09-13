








// factorization of n
typedef pair<int, int> pii;
vector<pii> factorize(int n) {
	vector<pii> f;
	for (int i = 2; i * i <= n ; ++i) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i; ++cnt;
			}
			f.push_back(make_pair(i, cnt));
		}
	}
	if (n > 1) f.push_back(make_pair(n, 1));
	return f;
}
