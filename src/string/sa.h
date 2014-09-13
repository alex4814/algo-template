








/**** nlogn ****/
int wa[MAXN], wb[MAXN], wv[MAXN], ws[MAXN]; 
inline int cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
} 
// r 是待排序的串（长度已加 1），长度为 n，最大值小于 m
// 约定除 r[n - 1] 外所有的 r[i] 都大于 0, r[n - 1] = 0
void da(int *r, int *sa, int n, int m) {
	int i, j, p;
	int *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++) ws[i] = 0;
	for (i = 0; i < n; i++) ws[ x[i] = r[i] ]++;
	for (i = 1; i < m; i++) ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--ws[ x[i] ]] = i;
	for (j = 1, p = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i < n; i++) wv[i] = x[y[i]];
		for (i = 0; i < m; i++) ws[i] = 0;
		for (i = 0; i < n; i++) ws[ wv[i] ]++;
		for (i = 1; i < m; i++) ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--ws[ wv[i] ]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[ sa[0] ] = 0, i = 1; i < n; i++) {
			x[ sa[i] ] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
	}
}

int rank[MAXN], height[MAXN];
void cal_height(int *r, int *sa, int n) {
	 int i, j, k = 0;
	 for (i = 1; i <= n; i++) rank[ sa[i] ] = i;
	 for (i = 0; i < n; height[ rank[i++] ] = k)
	 for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
}


/**** O(n^2) ****/
// d[i][j] is the lcp of suffix(i) of s1 and suffix(j) of s2
void cal_lcp(int d[MAXN][MAXN], char *s1, char *s2) {
	int n1 = strlen(s1), n2 = strlen(s2);
	for (int i = n1; i >= 0; --i) {
		for (int j = n2; j >= 0; --j) {
			if (i == n1 || j == n2 || s1[i] != s2[j]) {
				d[i][j] = 0;
			} else {
				d[i][j] = d[i + 1][j + 1] + 1;
			}
		}
	}
}
