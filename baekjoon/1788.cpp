#include <bits/stdc++.h>
using namespace std;

const int modi = 1000000000;
int N,  f[1000001];


int main(){
	scanf("%d", &N);
	//fn = fn-1 + fn-2

	if (N == 0) {
		cout << 0 << endl << 0;
		return 0;
	}

	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i < 1000001; i++)
		f[i] = (f[i - 1]%modi + f[i - 2] % modi) % modi;

	if (N < 0 && N%2 ==0) {
		N = abs(N);
		cout << -1 << endl << f[N];
		return 0;
	}
	N = abs(N);

	cout << 1 << endl << f[N];

}
