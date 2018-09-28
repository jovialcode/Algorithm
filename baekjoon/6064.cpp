#include <iostream>
using namespace std;

int lcm(int m, int n) {
	int z, a, b;
	a = m; b = n;
	while (1) {
		z = a%b;
		if (z == 0) break;
		a = b; b = z;
	}
	return (m*n) / b;
}

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int mn = lcm(m, n);
		while (x != y && x <= mn) {
			if (x < y) x += m;
			else y += n;
		}
		if (x != y) printf("-1\n");
		else printf("%d\n", x);
	}
	return 0;
}
