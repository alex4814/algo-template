








void heapify(int *a, int n, int i) {
	int l = 2 * i, r = l + 1;
	int ix = (l <= n && a[l] > a[i]) ? l : i;
	if (r <= n && a[r] > a[ix]) ix = r;
	if (ix != i) {
		swap(a[i], a[ix]);
		heapify(a, n, ix);
	}
}

void build_heap(int *a, int n) {
	for (int i = n / 2; i >= 1; --i) {
		heapify(a, n, i);
	}
}

int heap_extract(int *a, int n) {
	if (n < 1) return -1;
	int ret = a[1];
	a[1] = a[n--];
	heapify(a, n, 1);
	return ret;
}

void heap_increase_key(int *a, int i, int key) {
	if (key < a[i]) return;
	a[i] = key;
	while (i > 1 && a[i / 2] < a[i]) {
		swap(a[i], a[i / 2]);
		i >>= 1;
	}
}

void heap_insert(int *a, int n, int key) {
	a[++n] = -INF;
	heap_increase_key(a, n, key);
}
