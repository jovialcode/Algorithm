#include <iostream>
#include <cstring>
#define MIN(a,b)(a>b?b:a)
#define INFI 98765432
using namespace std;

int N, K;
int coin[101];
int dp[10001];

int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];
	//입력 정리

	dp[0] = 0;
	for (int i = 1; i <= K; i++) {
		dp[i] = INFI;
		for (int j = 0; j < N; j++) {
			if(i-coin[j] >=0)
				dp[i] = MIN(dp[i], dp[i - coin[j]]+1);
		}
	}
	if (dp[K] == INFI)
		cout << "-1";
	else cout << dp[K];

	return 0;
}
