








// gcd(a, b) = d, then exists x, y, s.t. ax + by = d
// extended_gcd(a, b) = ax + by
int extended_gcd(int a, int b, int &x, int &y)
{
	if (b == 0) { x = 1; y = 0; return a; }
	int d = extended_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
