








char s[MAXN], p[MAXM];
int next[MAXM];

void get_next(const char *p) {
	next[0] = -1;
	int plen = strlen(p), j = -1;
	for (int i = 1; i < plen; ++i) {
		while (j >= 0 && p[i] != p[j + 1]) { j = next[j]; }
		p[i] == p[j + 1] ? ++j : NULL;
		next[i] = j;
	}
}

// count the times string p occurs in string s
int kmp_count(const char *s, const char *p) {
	get_next(p);
	int slen = strlen(s);
	int plen = strlen(p);
	int i, j = -1, cnt = 0;
	for (i = 0; i < slen; ++i) {
		while (j >= 0 && s[i] != p[j + 1]) { j = next[j]; }
		s[i] == p[j + 1] ? ++j : NULL;
		if (j == plen - 1) { j = next[j]; ++cnt; }
	}
	return cnt;
}
