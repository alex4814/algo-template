








int euler(int n) {
    int ret = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            n /= i, ret *= i - 1;
            while (n % i == 0) {
                n /= i, ret *= i;
            }
        }
    }
    return ret * (n > 1 ? n - 1 : 1);
}

void euler(int n) {
    static bool prime[MAXN];
    static int p[MAXN], _n = 0;
    static int phi[MAXN];
    
    for (int i = 2; i <= n; ++i) {
        if (!prime[i]) {
            phi[i] = i - 1;
            p[_n++] = i;
        }
        for (int j = 0; j < _n && p[j] * i <= n; ++j) {
            prime[ p[j] * i ] = true;
            if (i % p[j]) {
                phi[ p[j] * i ] = phi[i] * (p[j] - 1);
            } else {
                phi[ p[j] * i ] = phi[i] * (p[j] - 0); break;
            }
        }
    }
}
