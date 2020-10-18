#include <iostream>
#include <cstring>
using namespace std;

int W, E;
int dp[31][31][31];

int sol(int cnt, int west, int east) {
	if (cnt == W) return 1;
	if (west > W || east > E) return 0;

	int &ret = dp[cnt][west][east];
	if (ret != 0) return ret;

	ret = sol(cnt + 1, west + 1, east + 1) + sol(cnt, west, east + 1);

	return ret;
}

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &W, &E);
		//입력정리 
		printf("%d\n", sol(0, 1, 1));
	}
	return 0;
}