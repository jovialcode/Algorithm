#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
long long dp[101];

int main() {
	scanf("%d", &N);
	memset(dp, 0, sizeof(dp));
	//입력정리

	dp[1] = 1; dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - 1] + 1);

		for (int j = i - 3, k = 2; j > 0; j--, k++) {
			dp[i] = max(dp[i], dp[j] * k);
		}
	}
	cout << dp[N];
}
