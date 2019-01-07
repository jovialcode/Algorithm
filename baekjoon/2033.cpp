#include <bits/stdc++.h>
using namespace std;

int N;

int l(int n) {
	int res = 0;
	while (n > 0) {
		n /= 10;
		res += 1;
	}
	return res - 1;
}

int main(){
	scanf("%d", &N);
	if (N == 0) {
		cout << 0;
		return 0;
	}
	int len = l(N), m = 0;
	while (len--) {
		int a = ((int)pow(10, m));
		N += (5 * a);
		N /= (10 * a);
		N *= (10 * a);
		m += 1;
	}
	cout << N;
}
