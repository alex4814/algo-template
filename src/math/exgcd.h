








// solution (x, y) in integers to ax + by = gcd(a, b)
// recursive
int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0) { x = 1; y = 0; return a; }
	int g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

// solution (x, y) in integers to ax + by = gcd(a, b)
// non-recursive
int exgcd(int a, int b, int &x, int &y) {
	int g = a, v = 0, w = b; x = 1;
	while (w != 0) {
		int q = g / w, t = g % w;
		int s = x - q * v;
		x = v, g = w;
		v = s, w = t;
	}
	y = b ? (g - a * x) / b : b;
	return g;
}

// all solutions (x, y) in integers to ax + by = c
bool linear_solution(int a, int b, int c, int &x, int &y) {
	int g = exgcd(a, b, x, y);
	if (c % g != 0) return false;
	a /= g, b /= g, c /= g;
	x *= c, y *= c;
	// x = x + b * k
	// y = y - a * k;
	return true;
}
