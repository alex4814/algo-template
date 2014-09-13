








// 求置换的循环节
// perm[n]为0..n-1的一个置换
// 返回置换最小周期，num返回循环节个数
int polya(int perm[], int n, int &num) {
	int v[MAXN] = { 0 }, ret = 1;
	int i, j, p;
	for (i = num = 0; i < n; ++i) {
		if (v[i]) continue;
		for (++num, j = 0, p = i; !v[p = perm[p]]; ++j) {
			v[p] = 1;
		}
		ret *= j / gcd(ret, j);
	}
	return ret;
}
