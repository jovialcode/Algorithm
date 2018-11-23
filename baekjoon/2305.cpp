#include <iostream>
#include <cstring>
using namespace std;

int N, K, f[42], t[42], dp[42];

int main() {
	scanf("%d%d", &N, &K);
	//입력정리

	f[0] = f[1] = 1;
	for (int i = 2; i <= 41; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}//피보나치

	memset(dp, 0, sizeof(dp));
	dp[1] = 0; dp[2] = 2; dp[3] = 6;
	for (int i = 4; i <= 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		for (int j = i - 1; j > 0; j--) {
			dp[i] += f[j];
		}
	}

	int L = K - 1, R = N - K;
	if (K == 1 || K == N) {
		cout << dp[L + 1] * f[R] + f[L] * dp[R + 1];
	}
	else {
		cout << dp[L + 1] * f[R] + f[L] * dp[R + 1] - f[R]*f[L];
	}
}
