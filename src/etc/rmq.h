#include "etc.h"








// f[i][j] 代表从 i 开始，长为 2^j 的区间中的最小（大）值
int f[MAXN][20];
// 预处理 O(nlogn)
void rmq_init(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		f[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 0; i + (1 << j) <= n; ++i) {
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}
// 查询区间 [l, r] 的最小（大）值
int rmq_query(int l, int r) {
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1) ++k;
	return min(f[l][k], f[r - (1 << k) + 1][k]);
}

