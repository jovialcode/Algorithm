#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300000;
int D, N, o[MAX_N + 1], p[MAX_N + 1], dp[MAX_N+1];

int main(){
	scanf("%d%d", &D, &N);
	o[0] = 1000000001;
	for (int i = 1; i <= D; i++) {
		int num; scanf("%d", &num);
		o[i] = min(num, o[i - 1]);
	}
	for (int i = 1; i <= N; i++)
		scanf("%d", &p[i]);
	//입력정리

	int idx = 1;
	for (int i = D; i > 0; i--) {
		if (p[idx] > o[i]) continue;
		idx += 1;
		if (idx > N) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0;
}

