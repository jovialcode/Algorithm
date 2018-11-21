#include <iostream>
using namespace std;

int main(void) {
	int T; scanf("%d", &T);
	
	while (T--) {
		int N; scanf("%d", &N);
		int dp[12] = { 0, };
		dp[0] = 1; dp[1] = 1; dp[2] = 2;
		for (int i = 3; i <= N; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		printf("%d\n", dp[N]);
	}
	return 0;
}
