#include "etc.h"








int bin_search(int *a, int l, int r, int x) {
	while (l < r) {
		int m = l + (r - l) / 2;
		if (a[m] == x) return m;
		a[m] > x ? r = m : l = m + 1;
	}
	return -1;
}

int lower_bound(int *a, int l, int r, int x) {
	while (l < r) {
		int m = l + (r - l) / 2;
		a[m] >= x ? r = m : l = m + 1;
	}
	return l;
}

int upper_bound(int *a, int l, int r, int x) {
	while (l < r) {
		int m = l + (r - l) / 2;
		a[m] <= x ? l = m + 1 : r = m;
	}
	return r;
}
