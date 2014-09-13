








// recursive
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// non-recursive
int gcd(int a, int b) {
	if (b == 0) return a;
	while (b ^= a ^= b ^= a %= b);
	return a;
}
