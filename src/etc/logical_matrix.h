








// Input: n * m logical matrix mat[MAXN][MAXN]
// Function: find every possible sub-matrix in which 
// 			 all elements are one (or zero)
int mat[MAXN][MAXN];

int sub_matrix() {
	static int c[MAXN], l[MAXN], r[MAXN];
	int ret = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			c[j] = mat[i][j] ? c[j] + 1 : 0;
		}
		for (int j = 0; j < m; ++j) {
			l[j] = j;
			while (l[j] > 0 && c[j] <= c[ l[j] - 1 ]) {
				l[j] = l[ l[j] - 1 ];
			}
		}
		for (int j = m - 1; j >= 0; --j) {
			r[j] = j;
			while (r[j] < m - 1 && c[j] <= c[ r[j] + 1 ]) {
				r[j] = r[ r[j] + 1 ];
			}
		}
		// sub-matrix of size c[j] * (r[j] - l[j] + 1)
		// could be found consisting element mat[i][j] (equals 1 now)
		// down to row[i] so far
		//
		//
		// write code for specific task
	}

	return ret;
}

